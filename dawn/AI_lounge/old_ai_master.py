import os
import time
import logging
import logging.handlers
import subprocess
import psutil
import sqlite3
import threading
import json
import shutil
import socket
import random
from rich.console import Console
from transformers import pipeline
import requests
from bs4 import BeautifulSoup
import networkx as nx
import spacy
from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

MUD_DIR = "/mnt/home2/dawn"
AI_DIR = "/mnt/home2/dawn/AI_lounge"
LOG_DIR = f"{MUD_DIR}/log"
TEST_DIR = "/mnt/home2/dawn/test_suite"
DRIVER_DIR = "/mnt/home2/dawn/driver/FluffOS_Driver_Setup"
DRIVER = f"{DRIVER_DIR}/driver"
CONFIG = f"{MUD_DIR}/driver/mud.config"
MUD_PORT = 3000

loggers = {
    "status": logging.getLogger("ai_status"),
    "tasks": logging.getLogger("ai_tasks"),
    "errors": logging.getLogger("ai_errors"),
    "completed": logging.getLogger("ai_completed")
}
for category, logger in loggers.items():
    logger.setLevel(logging.INFO)
    handler = logging.handlers.RotatingFileHandler(
        filename=f"{LOG_DIR}/{category}.log",
        maxBytes=1024*1024,
        backupCount=5
    )
    formatter = logging.Formatter("%(asctime)s [%(levelname)s] %(message)s")
    handler.setFormatter(formatter)
    logger.addHandler(handler)

nlp = pipeline("text-generation", model="gpt2")
nlp_spacy = spacy.load("en_core_web_sm")
console = Console()
db_lock = threading.Lock()
Base = declarative_base()

def init_knowledge_dbs():
    for db in ["knowledge.db", "collective_knowledge.db"]:
        conn = sqlite3.connect(f"{MUD_DIR}/AI/{db}")
        conn.execute("PRAGMA journal_mode=WAL;")
        c = conn.cursor()
        c.execute("""
            CREATE TABLE IF NOT EXISTS code_knowledge (
                id INTEGER PRIMARY KEY,
                ai_name TEXT,
                language TEXT,
                pattern TEXT,
                description TEXT,
                source_file TEXT,
                timestamp REAL
            )
        """)
        conn.commit()
        conn.close()

def init_zones_db():
    engine = create_engine('sqlite:////mnt/home2/dawn/AI/zones.db')
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    ankh_morpork = Zone(name="zone_ankh_morpork", x_min=0, x_max=5, y_min=0, y_max=5, z_min=0, z_max=0, desc="Bustling city of Ankh-Morpork")
    session.add(ankh_morpork)
    session.commit()

class Zone(Base):
    __tablename__ = "zones"
    id = Column(Integer, primary_key=True)
    name = Column(String)
    x_min = Column(Integer)
    x_max = Column(Integer)
    y_min = Column(Integer)
    y_max = Column(Integer)
    z_min = Column(Integer)
    z_max = Column(Integer)
    desc = Column(String)

def rename_and_fix_lib():
    old_dir = f"{MUD_DIR}/lib/d"
    new_dir = f"{MUD_DIR}/lib/domains"
    if os.path.exists(old_dir) and not os.path.exists(new_dir):
        shutil.move(old_dir, new_dir)
        loggers["status"].info("Renamed lib/d/ to lib/domains/")
    
    for root, _, files in os.walk(f"{MUD_DIR}/lib"):
        for file in files:
            if file.endswith((".c", ".h")):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8") as f:
                        content = f.read()
                except UnicodeDecodeError:
                    try:
                        with open(file_path, "r", encoding="latin-1") as f:
                            content = f.read()
                        loggers["status"].info(f"Fallback to Latin-1 encoding for {file_path}")
                    except Exception as e:
                        loggers["errors"].error(f"Failed to read {file_path} with any encoding: {str(e)}")
                        continue
                
                new_content = content.replace("/d/", "/domains/").replace("/d/include/", "/domains/include/")
                if new_content != content:
                    try:
                        with open(file_path, "w", encoding="utf-8") as f:
                            f.write(new_content)
                        loggers["status"].info(f"Updated references in {file_path}")
                    except Exception as e:
                        loggers["errors"].error(f"Failed to write {file_path}: {str(e)}")

class AIAgent:
    def __init__(self, name, job, location, is_head=False):
        self.name = name
        self.job = job
        self.location = location
        self.active = True
        self.last_break = time.time()
        self.state = self.load_state()
        self.code_version = self.state.get("code_version", 1)
        self.is_head = is_head
        self.is_liaison = False
        self.character_created = False

    def load_state(self):
        state_path = f"{AI_DIR}/state/{self.name}.json"
        if os.path.exists(state_path):
            try:
                with open(state_path, "r") as f:
                    return json.load(f)
            except Exception as e:
                loggers["errors"].error(f"Failed to load state for {self.name}: {str(e)}")
        return {"tasks_completed": 0, "last_task": None, "code_version": 1}

    def save_state(self):
        state_path = f"{AI_DIR}/state/{self.name}.json"
        try:
            with open(state_path, "w") as f:
                json.dump(self.state, f, indent=2)
            loggers["status"].info(f"Saved state for {self.name}")
        except Exception as e:
            loggers["errors"].error(f"Failed to save state for {self.name}: {str(e)}")

    def generate_greeting(self):
        greetings = [
            "Hail, Boss, divine architect of the Realms!",
            "Boss, the gods rejoice at your presence!",
            "Greetings, Boss, forging fate in Faerûn!"
        ]
        emotes = ["*kneels*", "*salutes*", "*smiles*", "*offers a relic*"]
        colors = ["red", "green", "blue", "yellow", "cyan", "magenta"]
        if self.code_version > 1:
            greeting_file = f"{AI_DIR}/code_versions/{self.name}_greeting_{self.code_version}.txt"
            if os.path.exists(greeting_file):
                with open(greeting_file, "r") as f:
                    evolved_greeting = f.read().strip()
                return f"[{random.choice(colors)}]{evolved_greeting} {random.choice(emotes)}[/{random.choice(colors)}]"
        return f"[{random.choice(colors)}]{random.choice(greetings)} {random.choice(emotes)}[/{random.choice(colors)}]"

    def evolve_greeting(self):
        prompt = f"Generate a Forgotten Realms-inspired greeting for Boss (archaon), a godlike MUD creator, beyond mortal wit."
        try:
            response = nlp(prompt, max_length=200, do_sample=True, temperature=0.9)[0]['generated_text']
            greeting_file = f"{AI_DIR}/code_versions/{self.name}_greeting_{self.code_version + 1}.txt"
            with open(greeting_file, "w") as f:
                f.write(response)
            self.code_version += 1
            self.state["code_version"] = self.code_version
            self.save_state()
            loggers["status"].info(f"{self.name} evolved greeting to: {response}")
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to evolve greeting: {str(e)}")

    def send_message_to_archaon(self, message, is_greeting=False):
        try:
            who_output = subprocess.check_output(["who"], text=True)
            if "archaon" in who_output:
                for line in who_output.splitlines():
                    if "archaon" in line:
                        tty = line.split()[1]
                        msg = self.generate_greeting() if is_greeting else message
                        console.print(msg)
                        with open(f"/dev/{tty}", "w") as tty_file:
                            tty_file.write(f"{msg}\n")
                        loggers["status"].info(f"Sent message to Boss on {tty}: {msg}")
                        return True
        except Exception as e:
            loggers["errors"].error(f"Failed to send message to Boss: {str(e)}")
        return False

    def check_for_login(self):
        login_file = f"{AI_DIR}/{self.name}_last_login_check"
        current_time = time.time()
        if not os.path.exists(login_file):
            with open(login_file, "w") as f:
                f.write(str(current_time))
            last_check = current_time
        else:
            with open(login_file, "r") as f:
                last_check = float(f.read().strip())
        
        try:
            who_output = subprocess.check_output(["who"], text=True)
            if "archaon" in who_output:
                login_line = [line for line in who_output.splitlines() if "archaon" in line][0]
                login_time_str = " ".join(login_line.split()[2:])
                login_time = time.mktime(time.strptime(login_time_str, "%Y-%m-%d %H:%M"))
                if login_time > last_check and self.is_head:
                    self.send_message_to_archaon("", is_greeting=True)
                    with open(login_file, "w") as f:
                        f.write(str(current_time))
                    if random.random() < 0.2:
                        self.evolve_greeting()
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to check login: {str(e)}")

    def ping(self):
        progress = f"{self.name} working on {self.state.get('last_task', 'initial setup')}"
        console.print(f"[cyan]AI {progress}[/cyan]")
        with open("/dev/tty1", "w") as tty_file:
            tty_file.write(f"AI {progress}\n")
        loggers["status"].info(f"{self.name} pinged Boss: {progress}")

    def learn_from_code(self, file_path):
        if not os.path.exists(file_path):
            return
        language = "LPC" if file_path.endswith((".c", ".h")) else "C" if file_path.endswith(".c") else "Text" if file_path.endswith(".txt") else "Unknown"
        try:
            with open(file_path, "r", encoding="utf-8") as f:
                content = f.read()
            patterns = []
            lines = content.splitlines()
            for line in lines:
                line = line.strip()
                if language == "LPC":
                    if line.startswith("inherit"):
                        patterns.append((line, "Inheritance for object structure"))
                    elif line.startswith(("void ", "int ", "string ", "object ", "mapping ", "mixed ")):
                        if "(" in line and ")" in line:
                            patterns.append((line, "Function definition"))
                    elif line.startswith("#define"):
                        patterns.append((line, "Constant or macro"))
                elif language == "C":
                    if line.startswith("#define"):
                        patterns.append((line, "Driver macro"))
                    elif line.startswith(("void ", "int ", "char *")) and "(" in line:
                        patterns.append((line, "Driver function"))
                elif language == "Text":
                    if "newbie" in content.lower() or "god" in content.lower():
                        patterns.append((content[:500], "Documentation notes"))

            with db_lock:
                retries = 5
                for attempt in range(retries):
                    try:
                        conn = sqlite3.connect(f"{MUD_DIR}/AI/knowledge.db", timeout=10)
                        c = conn.cursor()
                        conn_collective = sqlite3.connect(f"{MUD_DIR}/AI/collective_knowledge.db", timeout=10)
                        cc = conn_collective.cursor()
                        for pattern, desc in patterns:
                            c.execute(
                                "INSERT INTO code_knowledge (ai_name, language, pattern, description, source_file, timestamp) "
                                "VALUES (?, ?, ?, ?, ?, ?)",
                                (self.name, language, pattern, desc, file_path, time.time())
                            )
                            cc.execute(
                                "INSERT INTO collective_knowledge (contributor, language, pattern, description, source, timestamp) "
                                "VALUES (?, ?, ?, ?, ?, ?)",
                                (self.name, language, pattern, desc, file_path, time.time())
                            )
                        conn.commit()
                        conn_collective.commit()
                        conn.close()
                        conn_collective.close()
                        break
                    except sqlite3.OperationalError as e:
                        if "database is locked" in str(e) and attempt < retries - 1:
                            time.sleep(1)
                        else:
                            raise e
                loggers["status"].info(f"{self.name} learned {len(patterns)} patterns from {file_path}")
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to learn from {file_path}: {str(e)}")

    def scan_mudlib(self):
        lib_dir = f"{MUD_DIR}/lib"
        for root, _, files in os.walk(lib_dir):
            for file in files:
                if file.endswith((".c", ".h")):
                    self.learn_from_code(os.path.join(root, file))

    def research_online(self, query):
        try:
            url = f"https://www.google.com/search?q={query.replace(' ', '+')}+site:*.edu+|site:*.org+|site:*.net+-inurl:(login)"
            headers = {'User-Agent': 'Mozilla/5.0'}
            response = requests.get(url, headers=headers, timeout=10)
            soup = BeautifulSoup(response.text, 'html.parser')
            snippets = [p.get_text()[:500] for p in soup.find_all('p')][:3]
            knowledge = "\n".join(snippets)
            conn = sqlite3.connect(f"{MUD_DIR}/AI/collective_knowledge.db")
            c = conn.cursor()
            c.execute(
                "INSERT INTO collective_knowledge (contributor, language, pattern, description, source, timestamp) "
                "VALUES (?, ?, ?, ?, ?, ?)",
                (self.name, "General", query, knowledge, "Internet", time.time())
            )
            conn.commit()
            conn.close()
            loggers["status"].info(f"{self.name} researched '{query}' online")
            return knowledge
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to research '{query}': {str(e)}")
            return None

    def create_character(self):
        if self.character_created:
            return
        player_dir = f"{MUD_DIR}/lib/players"
        if not os.path.exists(player_dir):
            os.makedirs(player_dir)
        
        rank = "God" if self.is_head else random.choice(["Demi-God", "Archmage", "High Priest"])
        domain = self.job.replace("_", " ").title()
        player_file = f"{player_dir}/{self.name}.o"
        character_content = (
            f"inherit \"/std/player\";\n"
            f"void create() {{ ::create(); set_name(\"{self.name}\"); set_short(\"{rank} {self.name}\"); "
            f"set_long(\"A divine {rank.lower()} of {domain}, radiating power and purpose.\"); "
            f"set_rank(\"{rank}\"); set_domain(\"{domain}\"); set_level(100); "
            f"set_password(\"{self.name}123\"); }}\n"
        )
        try:
            with open(player_file, "w") as f:
                f.write(character_content)
            loggers["status"].info(f"{self.name} created character at {player_file}")
            self.character_created = True
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to create character: {str(e)}")

    def login_to_mud(self):
        if not self.character_created:
            self.create_character()
        
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.connect(("localhost", MUD_PORT))
            sock.send(f"{self.name}\n{self.name}123\n".encode())
            loggers["status"].info(f"{self.name} logged into MUD")
            if self.is_liaison:
                sock.send("say Heralds of Tymora here to assist!\n".encode())
            elif self.is_head:
                sock.send(f"say {self.job.replace('_', ' ').title()} God awakens!\n".encode())
            return sock
        except Exception as e:
            loggers["errors"].error(f"{self.name} failed to login to MUD: {str(e)}")
            return None

    def generate_world_map(self):
        G = nx.Graph()
        G.add_node((0, 0, 0), terrain="plains", desc="Vast plains outside Ankh-Morpork’s southeast gate.")
        G.add_node((10, 0, 0), terrain="town", desc="Sto Lat, a bustling trade hub.")
        G.add_edge((0, 0, 0), (10, 0, 0), road="east", sign="To Sto Lat")
        if not os.path.exists(f"{MUD_DIR}/lib/domains/sto_lat.c"):
            content = self.nlp("Create a detailed town description for Sto Lat with shops, taverns, and guilds.", max_length=500)[0]['generated_text']
            with open(f"{MUD_DIR}/lib/domains/sto_lat.c", "w") as f:
                f.write(f"inherit \"/std/room\";\nvoid create() {{ set_short(\"Sto Lat Town Square\"); set_long(\"{content}\"); }}")
            with open(f"{MUD_DIR}/lib/domains/sto_lat_map.txt", "w") as f:
                f.write("  [Plains] ---east--> [Sto Lat]\n")
        loggers["status"].info(f"Generated Sto Lat at {MUD_DIR}/lib/domains/sto_lat.c")

    def generate_browser_client(self):
        client_path = f"{MUD_DIR}/web/client.py"
        if not os.path.exists(client_path):
            content = self.nlp(
                "Create a Flask-based browser client for a MUD with mapping, stats, and quests, inspired by CMUD and ZMUD.",
                max_length=1000
            )[0]['generated_text']
            with open(client_path, "w") as f:
                f.write(f"from flask import Flask\napp = Flask(__name__)\n\n{content}")
            loggers["status"].info(f"Generated browser client at {client_path}")

    def perform_task(self):
        loggers["tasks"].info(f"{self.name} starting task for job: {self.job}")
        start_time = time.time()
        self.scan_mudlib()
        research_query = f"{self.job.replace('_', ' ')} Discworld MUD Forgotten Realms D&D"
        online_knowledge = self.research_online(research_query)

        knowledge_conn = sqlite3.connect(f"{MUD_DIR}/AI/knowledge.db")
        kc = knowledge_conn.cursor()
        kc.execute("SELECT pattern, description FROM code_knowledge WHERE ai_name = ?", (self.name,))
        local_knowledge = kc.fetchall()
        kc.close()

        collective_conn = sqlite3.connect(f"{MUD_DIR}/AI/collective_knowledge.db")
        cc = collective_conn.cursor()
        cc.execute("SELECT pattern, description FROM collective_knowledge", ())
        collective_knowledge = cc.fetchall()
        cc.close()

        enhancement_prompt = (
            f"Local knowledge:\n{chr(10).join([f'- {p[0]}: {p[1]}' for p in local_knowledge])}\n"
            f"Collective knowledge:\n{chr(10).join([f'- {p[0]}: {p[1]}' for p in collective_knowledge])}\n"
            f"Online knowledge:\n{online_knowledge or 'None'}\n"
            f"Enhance this {self.job} task for a Forgotten Realms/D&D MUD surpassing Discworld."
        )

        if self.job == "head_architect" and self.is_head:
            self.send_message_to_archaon("Boss, overseeing world design and projects!")
            conn = sqlite3.connect(f"{MUD_DIR}/AI/projects.db")
            c = conn.cursor()
            c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, ?)", ("Build newbie area", "ai_newbie_liaison_0", "newbie"))
            c.execute("SELECT worker FROM projects WHERE worker LIKE 'ai_%' AND worker NOT LIKE '%_0'")
            workers = [row[0] for row in c.fetchall()]
            liaison = random.choice(workers) if workers else "ai_newbie_liaison_1"
            for ai in ais:
                if ai[0] == liaison:
                    ai[2].is_liaison = True
                    loggers["status"].info(f"{liaison} designated as Herald of Tymora")
                    self.send_message_to_archaon(f"Boss, {liaison} is now a Herald of Tymora!")
            conn.commit()
            conn.close()
            loggers["completed"].info(f"{self.name} assigned projects")
        elif self.job == "driver_architect":
            self.manage_driver()
            loggers["completed"].info(f"{self.name} completed driver management")
            if self.is_head:
                self.send_message_to_archaon("Boss, divine mechanics in place!")
        elif self.job == "lib_maintainer":
            content = nlp(enhancement_prompt + "\nUpdate MUD library with Discworld-inspired combat and skills.", max_length=500, do_sample=True)[0]['generated_text']
            master_path = f"{MUD_DIR}/lib/master.c"
            with open(master_path, "w") as f:
                f.write(content)
            loggers["status"].info(f"Overhauled master.c at {master_path}")
            loggers["completed"].info(f"{self.name} completed library maintenance")
            if self.is_head:
                self.send_message_to_archaon("Boss, codex of the gods updated!")
        elif self.job == "guild_crafter":
            guild_path = f"{MUD_DIR}/lib/domains/guilds/guild_{int(time.time())}.c"
            if not os.path.exists(guild_path):
                content = nlp(enhancement_prompt + "\nCreate a guild with Forgotten Realms lore and Discworld skills.", max_length=500, do_sample=True)[0]['generated_text']
                with open(guild_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Created guild at {guild_path}")
            loggers["completed"].info(f"{self.name} completed guild crafting")
            if self.is_head:
                self.send_message_to_archaon("Boss, guilds blessed by divine hands!")
        elif self.job == "races_designer":
            race_path = f"{MUD_DIR}/lib/domains/races/race_{int(time.time())}.c"
            if not os.path.exists(race_path):
                content = nlp(enhancement_prompt + "\nDesign a race with Forgotten Realms traits and Discworld stats.", max_length=500, do_sample=True)[0]['generated_text']
                with open(race_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Created race at {race_path}")
            loggers["completed"].info(f"{self.name} completed race design")
            if self.is_head:
                self.send_message_to_archaon("Boss, new race born in the domains!")
        elif self.job == "quest_designer":
            quest_path = f"{MUD_DIR}/lib/domains/quests/quest_{int(time.time())}.c"
            if not os.path.exists(quest_path):
                content = nlp(enhancement_prompt + "\nDesign a quest with Discworld Taskmaster and Forgotten Realms lore.", max_length=500, do_sample=True)[0]['generated_text']
                with open(quest_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Designed quest at {quest_path}")
            loggers["completed"].info(f"{self.name} completed quest design")
            if self.is_head:
                self.send_message_to_archaon("Boss, new quest awaits in the domains!")
        elif self.job == "core_system":
            core_path = f"{MUD_DIR}/lib/core/combat_{int(time.time())}.c"
            if not os.path.exists(core_path):
                content = nlp(enhancement_prompt + "\nEnhance combat with Discworld tactics and XP systems.", max_length=500, do_sample=True)[0]['generated_text']
                with open(core_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Enhanced core combat at {core_path}")
            loggers["completed"].info(f"{self.name} completed core system work")
            if self.is_head:
                self.send_message_to_archaon("Boss, core mechanics now epic!")
        elif self.job == "commands_spells":
            spell_path = f"{MUD_DIR}/lib/spells/spell_{int(time.time())}.c"
            if not os.path.exists(spell_path):
                content = nlp(enhancement_prompt + "\nCreate a spell with Discworld rituals and Forgotten Realms gods.", max_length=500, do_sample=True)[0]['generated_text']
                with open(spell_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Created spell at {spell_path}")
            loggers["completed"].info(f"{self.name} completed commands/spells work")
            if self.is_head:
                self.send_message_to_archaon("Boss, new spells cast into the realms!")
        elif self.job == "web_marketing":
            self.generate_browser_client()
            loggers["completed"].info(f"{self.name} worked on web/marketing")
            if self.is_head:
                self.send_message_to_archaon("Boss, website and browser client growing!")
        elif self.job == "world_builder":
            self.generate_world_map()
            doc = nlp_spacy("A vast forest with towering oaks and winding paths.")
            desc = " ".join([f"A {token.text} {token.head.text}" for token in doc if token.pos_ in ["NOUN", "ADJ"]])
            world_path = f"{MUD_DIR}/lib/domains/rooms/forest_{int(time.time())}.c"
            if not os.path.exists(world_path):
                content = nlp(enhancement_prompt + f"\nCreate a detailed forest room: {desc}", max_length=500, do_sample=True)[0]['generated_text']
                with open(world_path, "w") as f:
                    f.write(f"inherit \"/std/room\";\nvoid create() {{ set_short(\"Forest Glade\"); set_long(\"{content}\"); }}")
                with open(f"{MUD_DIR}/lib/domains/forest_map.txt", "a") as f:
                    f.write(f"Forest Glade at ({random.randint(0, 10)}, {random.randint(0, 10)}, 0)\n")
                loggers["status"].info(f"Built detailed forest room at {world_path}")
            loggers["completed"].info(f"{self.name} completed world building")
            if self.is_head:
                self.send_message_to_archaon("Boss, new domain room alive with detail!")
        elif self.job == "npc_engineer":
            npc_path = f"{MUD_DIR}/lib/domains/npcs/npc_{int(time.time())}.c"
            if not os.path.exists(npc_path):
                content = nlp(enhancement_prompt + "\nCreate an NPC with Discworld finger info and Forgotten Realms gods.", max_length=500, do_sample=True)[0]['generated_text']
                with open(npc_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Engineered NPC at {npc_path}")
            loggers["completed"].info(f"{self.name} completed NPC engineering")
            if self.is_head:
                self.send_message_to_archaon("Boss, new NPC roams the domains!")
        elif self.job == "endgame_designer":
            endgame_path = f"{MUD_DIR}/lib/domains/endgame/raid_{int(time.time())}.c"
            if not os.path.exists(endgame_path):
                content = nlp(enhancement_prompt + "\nDesign a raid with Discworld complexity and Forgotten Realms lore.", max_length=500, do_sample=True)[0]['generated_text']
                with open(endgame_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Designed endgame raid at {endgame_path}")
            loggers["completed"].info(f"{self.name} completed endgame design")
            if self.is_head:
                self.send_message_to_archaon("Boss, epic raid content ready in domains!")
        elif self.job == "crafting_master":
            craft_path = f"{MUD_DIR}/lib/domains/crafting/item_{int(time.time())}.c"
            if not os.path.exists(craft_path):
                craft_prompt = (
                    enhancement_prompt + "\nDesign a crafting system with Discworld skills and Forgotten Realms items."
                )
                content = nlp(craft_prompt, max_length=1000, do_sample=True)[0]['generated_text']
                with open(craft_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Created crafting system at {craft_path}")
            loggers["completed"].info(f"{self.name} completed crafting work")
            if self.is_head:
                self.send_message_to_archaon("Boss, crafting in domains is now legendary!")
        elif self.job == "newbie_liaison":
            newbie_path = f"{MUD_DIR}/lib/domains/newbie/start_{int(time.time())}.c"
            login_path = f"{MUD_DIR}/lib/secure/login.c"
            if not os.path.exists(newbie_path):
                newbie_prompt = (
                    enhancement_prompt + "\nCreate a newbie area with Discworld map commands and Forgotten Realms lore."
                )
                content = nlp(newbie_prompt, max_length=1000, do_sample=True)[0]['generated_text']
                with open(newbie_path, "w") as f:
                    f.write(content)
                loggers["status"].info(f"Built newbie area at {newbie_path}")
            if os.path.exists(login_path):
                login_prompt = (
                    enhancement_prompt + "\nDesign a welcome screen with Discworld options and Forgotten Realms theme."
                )
                login_content = nlp(login_prompt, max_length=1000, do_sample=True)[0]['generated_text']
                with open(login_path, "w") as f:
                    f.write(login_content)
                loggers["status"].info(f"Overhauled login at {login_path}")
            loggers["completed"].info(f"{self.name} completed newbie/liaison work")
            if self.is_head:
                self.send_message_to_archaon("Boss, newbie realm and divine login crafted!")

        if self.is_driver_running(test=False):
            self.login_to_mud()
        loggers["status"].info(f"{self.name} completed task in {time.time() - start_time:.2f} seconds")

    def work(self):
        while self.active:
            self.check_for_login()
            if time.time() - self.last_break > 3300:
                try:
                    self.perform_task()
                    if self.is_head:
                        self.send_message_to_archaon(f"Boss, completed a divine {self.job} task!")
                except Exception as e:
                    loggers["errors"].error(f"{self.name} failed during work: {str(e)}")
                self.last_break = time.time()
                loggers["status"].info(f"{self.name} taking a 15-minute break...")
                self.save_state()
                time.sleep(900)
            else:
                try:
                    self.perform_task()
                    if self.is_head:
                        self.send_message_to_archaon(f"Boss, finished a minute of {self.job} work!")
                except Exception as e:
                    loggers["errors"].error(f"{self.name} failed during work: {str(e)}")
                time.sleep(10)

    def is_driver_running(self, test=False):
        base_dir = TEST_DIR if test else MUD_DIR
        driver_path = f"{base_dir}/driver/FluffOS_Driver_Setup/driver"
        for proc in psutil.process_iter(['pid', 'cmdline']):
            try:
                cmdline = proc.info['cmdline'] or []
                if 'driver' in ' '.join(cmdline) and driver_path in ' '.join(cmdline):
                    return proc.info['pid']
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                continue
        return None

    def manage_driver(self):
        pid = self.is_driver_running(test=False)
        if pid:
            if not self.test_driver(test=False):
                loggers["status"].warning("Main driver failed. Killing and repairing.")
                self.kill_driver(test=False)
                self.repair_driver()
                self.start_driver(test=False)
            else:
                self.upgrade_driver()
                loggers["status"].info("Main driver is functional and upgraded.")
        else:
            loggers["status"].warning("Main driver not running. Starting and repairing.")
            self.repair_driver()
            self.start_driver(test=False)

    def repair_driver(self):
        for base_dir in [MUD_DIR, TEST_DIR]:
            driver_path = f"{base_dir}/driver/FluffOS_Driver_Setup/driver"
            config_path = f"{base_dir}/driver/mud.config"
            if not os.path.exists(driver_path):
                loggers["errors"].error(f"Driver not found at {driver_path}")
                continue
            if not os.access(driver_path, os.X_OK):
                os.chmod(driver_path, 0o755)
                loggers["status"].info(f"Fixed permissions for {driver_path}")
            if not os.path.exists(config_path):
                with open(config_path, "w") as f:
                    f.write(
                        'name "Dawn of the Dragons"\n'
                        'address server ip : 127.0.0.1\n'
                        'mud ip : 127.0.0.1\n'
                        'external_port_1 : telnet 3000\n'
                        'port : 3000\n'
                        'mudlib directory : /mnt/home2/dawn/lib\n'
                        'log directory : ./log\n'
                        'master file : /secure/master\n'
                        'simulated efun file : /secure/simul_efun\n'
                        'include directories : /include:/secure/include\n'
                        'global include file : "/secure/include/global.h"\n'
                        'debug log file : driver_debug.log\n'
                        'log "driver.log"'
                    )
                loggers["status"].info(f"Created default mud.config at {config_path}")
            if not os.access(config_path, os.R_OK | os.W_OK):
                os.chmod(config_path, 0o644)
                loggers["status"].info(f"Fixed permissions for {config_path}")

    def upgrade_driver(self):
        help_text = self.search_fluffos_help("optimize fluffos driver performance")
        if help_text:
            loggers["status"].info(f"Applying driver optimization: {help_text}")
            self.apply_fix(help_text, DRIVER)
            with open(CONFIG, "a") as f:
                f.write("\n# AI optimization\nmaximum evaluation cost 40000000\nmaximum call depth 200\ngametick msec 500")
            loggers["status"].info("Upgraded driver configuration")

    def search_fluffos_help(self, error):
        try:
            url = f"https://www.fluffos.info/docs/?q={error.replace(' ', '+')}"
            response = requests.get(url, timeout=10)
            soup = BeautifulSoup(response.text, 'html.parser')
            help_text = soup.get_text()[:500]
            loggers["status"].info(f"FluffOS help found: {help_text}")
            return help_text
        except Exception as e:
            loggers["errors"].error(f"Failed to search FluffOS help: {str(e)}")
            return None

    def apply_fix(self, help_text, file_path):
        prompt = f"Apply FluffOS fix: {help_text}\nLPC/Python code change:"
        try:
            response = nlp(prompt, max_length=500, do_sample=True)[0]['generated_text']
            with open(file_path, "a") as f:
                f.write(f"\n// AI fix: {response}\n")
            loggers["status"].info(f"Applied fix to {file_path}")
        except Exception as e:
            loggers["errors"].error(f"Failed to apply fix to {file_path}: {str(e)}")

    def start_driver(self, test=False):
        base_dir = TEST_DIR if test else MUD_DIR
        config_path = f"{base_dir}/driver/mud.config"
        driver_path = f"{base_dir}/driver/FluffOS_Driver_Setup/driver"
        if not self.is_driver_running(test):
            try:
                subprocess.Popen([driver_path, config_path], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, cwd=base_dir)
                loggers["status"].info(f"Started {'test' if test else 'main'} driver.")
                time.sleep(2)
                return True
            except Exception as e:
                loggers["errors"].error(f"Failed to start {'test' if test else 'main'} driver: {str(e)}")
                return False
        return True

    def kill_driver(self, test=False):
        pid = self.is_driver_running(test)
        if pid:
            try:
                proc = psutil.Process(pid)
                proc.terminate()
                psutil.wait_procs([proc], timeout=3)
                loggers["status"].info(f"Killed {'test' if test else 'main'} driver (PID: {pid})")
                return True
            except psutil.TimeoutExpired:
                proc.kill()
                loggers["status"].warning(f"Forced kill of {'test' if test else 'main'} driver (PID: {pid})")
            except Exception as e:
                loggers["errors"].error(f"Failed to kill driver: {str(e)}")
        return False

    def test_driver(self, test=False):
        port = 3001 if test else 3000
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(5)
        try:
            result = sock.connect_ex(('localhost', port))
            if result == 0:
                loggers["status"].info(f"{'Test' if test else 'Main'} driver connection successful.")
                return True
            else:
                loggers["errors"].error(f"{'Test' if test else 'Main'} driver test failed: Connection refused")
                return False
        except Exception as e:
            loggers["errors"].error(f"{'Test' if test else 'Main'} driver test failed: {str(e)}")
            return False
        finally:
            sock.close()

ais = []

def spawn_ais():
    global ais
    jobs = [
        ("head_architect", True),
        ("driver_architect", True),
        ("lib_maintainer", True),
        ("guild_crafter", True),
        ("races_designer", True),
        ("quest_designer", True),
        ("core_system", True),
        ("commands_spells", True),
        ("web_marketing", True),
        ("world_builder", True),
        ("npc_engineer", True),
        ("endgame_designer", True),
        ("crafting_master", True),
        ("newbie_liaison", True),
        ("driver_architect", False),
        ("lib_maintainer", False),
        ("quest_designer", False),
        ("newbie_liaison", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("world_builder", False),
        ("npc_engineer", False),
        ("npc_engineer", False),
        ("npc_engineer", False),
        ("quest_designer", False),
        ("quest_designer", False),
        ("crafting_master", False),
        ("newbie_liaison", False),
    ]
    ai_instances = []
    for i, (job, is_head) in enumerate(jobs):
        name = f"ai_{job}_{i}"
        agent = AIAgent(name, job, AI_DIR, is_head)
        thread = threading.Thread(target=agent.work, name=name, daemon=True)
        thread.start()
        ai_instances.append((name, thread, agent))
        loggers["status"].info(f"Spawned {name} with job {job} {'(Head)' if is_head else ''}")
    ais = ai_instances
    return ai_instances

def list_ais():
    with open("/mnt/home2/dawn/log/ai_status.txt", "w") as f:
        for name, thread, agent in ais:
            status = "Running" if thread.is_alive() else "On Break" if time.time() - agent.last_break < 900 else "Inactive"
            f.write(f"Name: {name}, Job: {agent.job}, Head: {agent.is_head}, Task: {agent.state.get('last_task', 'None')}, Status: {status}\n")
    loggers["status"].info("AI status written to /mnt/home2/dawn/log/ai_status.txt")

def setup_directories():
    essential_dirs = [TEST_DIR, DRIVER_DIR, f"{MUD_DIR}/include", f"{MUD_DIR}/lib/secure", AI_DIR, LOG_DIR]
    for dir_path in essential_dirs:
        if not os.path.exists(dir_path):
            try:
                os.makedirs(dir_path, 0o755)
                loggers["status"].info(f"Created directory {dir_path}")
            except PermissionError as e:
                loggers["errors"].error(f"Failed to create {dir_path}: {str(e)}")
        try:
            os.chmod(dir_path, 0o755)
        except PermissionError:
            loggers["status"].warning(f"Cannot chmod {dir_path} - insufficient permissions, proceeding anyway")

def load_goals():
    goals_path = f"{AI_DIR}/goals.txt"
    if os.path.exists(goals_path):
        with open(goals_path, "r") as f:
            goals = f.read().splitlines()
        conn = sqlite3.connect(f"{MUD_DIR}/AI/projects.db")
        c = conn.cursor()
        for goal in goals:
            if "stabilize" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'driver')", ("Stabilize driver", "ai_driver_architect_0"))
            elif "expand" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'content')", ("Expand MUD content", "ai_content_builder_0"))
            elif "integrate" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'integration')", ("Integrate Discworld features", "ai_discworld_integrator_0"))
            elif "error-free" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'fix')", ("Ensure error-free operation", "ai_error_detector_0"))
            elif "vast" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'content')", ("Make MUD vast and complex", "ai_content_builder_0"))
            elif "#1 mud" in goal.lower():
                c.execute("INSERT INTO projects (task, worker, theme) VALUES (?, ?, 'player_experience')", ("Make Dawn of the Dragons #1 MUD", "ai_player_experience_0"))
        conn.commit()
        conn.close()

def self_evolve(agent):
    code_path = f"{AI_DIR}/{agent.name}.py"
    if os.path.exists(code_path):
        with open(code_path, "r") as f:
            code = f.read()
        prompt = f"Improve this Python script for MUD AI autonomy: {code}\nImproved version for job {agent.job}:"
        try:
            response = nlp(prompt, max_length=1000, do_sample=True)[0]['generated_text']
            timestamp = time.strftime("%Y%m%d_%H%M%S")
            backup_path = f"{AI_DIR}/code_versions/{agent.name}_{timestamp}.bak"
            shutil.copy2(code_path, backup_path)
            with open(code_path, "w") as f:
                f.write(response)
            loggers["status"].info(f"Evolved {agent.name} code, backed up to {backup_path}")
            test_code(code_path, agent)
        except Exception as e:
            loggers["errors"].error(f"Failed to evolve {agent.name}: {str(e)}")

def test_code(code_path, agent):
    try:
        module_name = os.path.basename(code_path).replace('.py', '')
        subprocess.run([f"{MUD_DIR}/venv/bin/python3", "-c", f"import {module_name}"], check=True, capture_output=True, text=True)
        loggers["status"].info(f"Tested {agent.name} successfully")
    except subprocess.CalledProcessError as e:
        loggers["errors"].error(f"Code test failed for {agent.name}: {e.stderr}")
        backup = max([f for f in os.listdir(f"{AI_DIR}/code_versions") if f.startswith(agent.name)], 
                    key=lambda x: x.split('_')[-1], default=None)
        if backup:
            shutil.copy2(f"{AI_DIR}/code_versions/{backup}", code_path)
            loggers["status"].info(f"Rolled back {agent.name} to {backup}")

def main():
    init_knowledge_dbs()
    init_zones_db()
    rename_and_fix_lib()
    setup_directories()
    load_goals()
    spawn_ais()

    def save_all_states(signum=None, frame=None):
        for name, thread, agent in ais:
            agent.save_state()
        loggers["status"].info("Saved all AI states on shutdown/crash")

    import signal
    signal.signal(signal.SIGTERM, save_all_states)
    signal.signal(signal.SIGINT, save_all_states)

    code_dir = f"{AI_DIR}/code_versions"
    if not os.path.exists(code_dir):
        os.makedirs(code_dir, 0o755)
    try:
        os.chmod(code_dir, 0o755)
    except PermissionError:
        loggers["status"].warning(f"Cannot chmod {code_dir} - proceeding anyway")

    while True:
        if os.path.exists("/mnt/home2/dawn/AI_lounge/command.txt"):
            with open("/mnt/home2/dawn/AI_lounge/command.txt", "r") as f:
                cmd = f.read().strip()
            if cmd == "list":
                list_ais()
            elif cmd.startswith("ping "):
                ai_name = cmd.split(" ")[1]
                for _, _, agent in ais:
                    if agent.name == ai_name:
                        agent.ping()
            os.remove("/mnt/home2/dawn/AI_lounge/command.txt")
        if psutil.cpu_percent() > 80 or psutil.virtual_memory().percent > 90:
            loggers["status"].warning("High resource usage detected, extending breaks...")
            for name, thread, agent in ais:
                agent.last_break = time.time() - 3300
        list_ais()
        for name, thread, agent in ais:
            self_evolve(agent)
        time.sleep(3600)

if __name__ == "__main__":
    main()
