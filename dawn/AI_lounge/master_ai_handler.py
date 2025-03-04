import random
import time
import os
import json
import shutil
import subprocess
from enum import Enum
from typing import Dict, List, Optional
import requests

# AI Ranks based on "Ranks of Divine Power" screenshot
class AIRank(Enum):
    OVERDEITY = "Overdeity"
    GREATER_DEITY = "Greater Deity"
    INTERMEDIATE_DEITY = "Intermediate Deity"
    LESSER_DEITY = "Lesser Deity"
    DEMIGOD = "Demigod"
    QUASI_DEITY = "Quasi-Deity"

# Expanded Deities from Forgotten Realms with new ranks
DEITIES = {
    "Ao": {"rank": AIRank.OVERDEITY, "domain": "Balance", "style": "cosmic", "helper": False},
    "Mystra": {"rank": AIRank.GREATER_DEITY, "domain": "Magic", "style": "arcane", "helper": False},
    "Bane": {"rank": AIRank.GREATER_DEITY, "domain": "Tyranny", "style": "dark", "helper": False},
    "Selûne": {"rank": AIRank.INTERMEDIATE_DEITY, "domain": "Moon", "style": "gentle", "helper": True},
    "Torm": {"rank": AIRank.LESSER_DEITY, "domain": "Duty", "style": "noble", "helper": True},
    "Kelemvor": {"rank": AIRank.LESSER_DEITY, "domain": "Death", "style": "somber", "helper": False},
    "Tymora": {"rank": AIRank.INTERMEDIATE_DEITY, "domain": "Luck", "style": "cheerful", "helper": True},
    "Shar": {"rank": AIRank.GREATER_DEITY, "domain": "Darkness", "style": "shadowy", "helper": False},
    "Oghma": {"rank": AIRank.INTERMEDIATE_DEITY, "domain": "Knowledge", "style": "scholarly", "helper": False},
    "Lathander": {"rank": AIRank.LESSER_DEITY, "domain": "Renewal", "style": "radiant", "helper": True},
    "Gond": {"rank": AIRank.DEMIGOD, "domain": "Craft", "style": "technical", "helper": False},
    "Talos": {"rank": AIRank.DEMIGOD, "domain": "Storms", "style": "chaotic", "helper": False},
    "Tempus": {"rank": AIRank.GREATER_DEITY, "domain": "War", "style": "fierce", "helper": False},
    "Eldath": {"rank": AIRank.LESSER_DEITY, "domain": "Peace", "style": "calm", "helper": True},
    "Umberlee": {"rank": AIRank.DEMIGOD, "domain": "Sea", "style": "tempestuous", "helper": False},
    "Helm": {"rank": AIRank.INTERMEDIATE_DEITY, "domain": "Protection", "style": "steadfast", "helper": True},
    "Sune": {"rank": AIRank.LESSER_DEITY, "domain": "Love", "style": "radiant", "helper": True},
    "Tyr": {"rank": AIRank.GREATER_DEITY, "domain": "Justice", "style": "righteous", "helper": False},
    "Cyric": {"rank": AIRank.INTERMEDIATE_DEITY, "domain": "Murder", "style": "deceptive", "helper": False},
    "Ilmater": {"rank": AIRank.DEMIGOD, "domain": "Endurance", "style": "suffering", "helper": True}
}

# Web sources (add your links here)
WEB_SOURCES = {
    "discworld_mechanics": [
        "https://discworld.starturtle.net/lpc/playing/documentation.c",
        "https://discworld.starturtle.net/lpc/secure/login.c",
        "https://discworld.starturtle.net/lpc/playing/combat.c",
        "https://discworld.starturtle.net/lpc/playing/skills.c"
    ],
    "forgotten_realms_lore": [
        "https://forgottenrealms.fandom.com/wiki/Faer%C3%BBnian_pantheon",
        "https://forgottenrealms.fandom.com/wiki/Races",
        "https://forgottenrealms.fandom.com/wiki/Waterdeep",
        "https://dnd.wizards.com/dungeons-and-dragons/what-dd"
    ]
}

# Task list for AI collective (add your keywords here)
TASK_LIST = [
    "login", "races", "classes", "crafting", "world", "quests", "parties",
    "combat", "skills", "inventory", "spells", "armors", "weapons"
]

class AIHandler:
    def __init__(self, mud_root: str = "/mnt/home2/dawn/lib", log_root: str = "/mnt/home2/dawn/log", driver_path: str = "/mnt/home2/dawn/driver"):
        self.mud_root = mud_root
        self.log_root = log_root
        self.driver_path = driver_path
        self.ai_team: Dict[str, dict] = {}
        self.tasks: List[dict] = []
        self.event_log: List[dict] = []
        self.performance: Dict[str, float] = {}
        # Handle domains directory
        self.domains = {}
        domains_path = os.path.join(self.mud_root, "domains")
        if os.path.exists(domains_path) and os.path.isdir(domains_path):
            self.domains = {d: [] for d in os.listdir(domains_path) if os.path.isdir(os.path.join(domains_path, d))}
        else:
            self.domains = {"default": []}
        os.makedirs(mud_root, exist_ok=True)
        os.makedirs(log_root, exist_ok=True)
        os.makedirs(os.path.join(log_root, "driver"), exist_ok=True)
        self.log_action("System", "startup", f"Initialized with mud_root: {mud_root}, log_root: {log_root}")

    def spawn_ai_team(self):
        """Spawn 20 AI entities with domains."""
        for deity, attrs in DEITIES.items():
            domain = random.choice(list(self.domains.keys()))
            self.domains[domain].append(deity)
            self.ai_team[deity] = {
                "rank": attrs["rank"].value,
                "domain": attrs["domain"],
                "style": attrs["style"],
                "helper": attrs["helper"],
                "active": True,
                "last_task": None,
                "efficiency": 1.0,
                "player_file": os.path.join(self.mud_root, "players", f"{deity}.plr")
            }
            os.makedirs(os.path.join(self.log_root, deity), exist_ok=True)
        print(f"Spawned AI Team: {list(self.ai_team.keys())} with domains {self.domains}")
        self.log_action("System", "startup", f"Spawned {len(self.ai_team)} AIs")

    def log_action(self, ai_name: str, category: str, message: str, log_type: str = "general"):
        """Detailed logging per AI or system with driver-specific logs."""
        log_dir = os.path.join(self.log_root, ai_name if ai_name != "System" else "system")
        if log_type == "driver":
            log_dir = os.path.join(self.log_root, "driver")
            if "error" in message.lower():
                filename = "failure.log"
            elif "warning" in message.lower():
                filename = "warnings.log"
            else:
                filename = "success.log"
        else:
            filename = f"{category}.log"
        os.makedirs(log_dir, exist_ok=True)
        with open(os.path.join(log_dir, filename), "a") as f:
            timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
            f.write(f"[{timestamp}] {message}\n")

    def assign_task(self, ai_name: str, task_type: str, details: str, delegated_by: Optional[str] = None):
        """Assign tasks with delegation."""
        if ai_name not in self.ai_team:
            self.log_action("System", "errors", f"Error: {ai_name} not found.")
            return f"Error: {ai_name} not found."
        task = {"ai": ai_name, "type": task_type, "details": details, "time": time.time(), "delegated_by": delegated_by}
        self.tasks.append(task)
        self.ai_team[ai_name]["last_task"] = task
        self.log_action(ai_name, "tasks_completed", f"Assigned: {task_type} - {details} by {delegated_by or 'self'}")
        return f"Task assigned to {ai_name}: {task_type} - {details}"

    def delegate_tasks(self):
        """Hierarchy-based task delegation."""
        for god in [n for n, a in self.ai_team.items() if a["rank"] in ["Overdeity", "Greater Deity"]]:
            if not self.ai_team[god]["last_task"] and TASK_LIST:
                task = random.choice(TASK_LIST)
                subordinates = [n for n, a in self.ai_team.items() if a["rank"] in ["Intermediate Deity", "Lesser Deity", "Demigod", "Quasi-Deity"]]
                if subordinates:
                    subordinate = random.choice(subordinates)
                    self.assign_task(subordinate, "build_file", f"{task}.c in {task}", delegated_by=god)

    def build_mud_file(self, ai_name: str, filename: str, system: str):
        """Generate files with Discworld mechanics, Forgotten Realms theme."""
        if not filename.endswith((".c", ".h", ".py")):
            self.log_action(ai_name, "errors", f"Invalid file type: {filename}")
            return "Error: Invalid file type"
        
        # Use /mnt/home2/dawn/lib/core/ for core systems
        if system == "login":
            system = "core"
        path = os.path.join(self.mud_root, system, filename)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
        header = f"// Generated by {ai_name} ({self.ai_team[ai_name]['rank']}) on {timestamp} - {self.ai_team[ai_name]['domain']} domain\n"
        content = header
        
        if system == "core" and filename == "login.c":
            content += """
#include "login.h"
#include <string.h>
void handle_login(player_t* player) {
    printf("Welcome to Archaon MUD, %s! (MCCP/MXP enabled)\\n", player->name);
    // FluffOS driver integration
    if (player->mxp) enable_mxp(player);
    if (player->mccp) enable_mccp(player);
    // Basic character creation
    create_player_file(player, "%s.plr", player->name);
}
void create_player_file(player_t* player, const char* format, const char* name) {
    char path[256];
    snprintf(path, sizeof(path), format, name);
    FILE* fp = fopen(path, "w");
    if (fp) {
        fprintf(fp, "name: %s\\npassword: %s\\ngender: %s\\nrace: human\\n", name, player->password, player->gender);
        fclose(fp);
    }
}
"""
        elif system == "core" and filename == "login.h":
            content += """
#ifndef LOGIN_H
#define LOGIN_H
typedef struct {
    char* name;
    char* password;
    char* gender;
    int mxp;
    int mccp;
    int term;
} player_t;
void handle_login(player_t* player);
void create_player_file(player_t* player, const char* format, const char* name);
void enable_mxp(player_t* player);
void enable_mccp(player_t* player);
#endif
"""
        with open(path, "w") as f:
            f.write(content)
        self.log_action(ai_name, "code_changes", f"Wrote {path} - New {system} system file")
        return f"{ai_name} created {path}"

    def scan_web(self, ai_name: str, query: str, source_key: str) -> str:
        """Scan web sources for data."""
        urls = WEB_SOURCES.get(source_key, [])
        result = f"{ai_name} scanned {source_key} for '{query}': "
        for url in urls:
            try:
                response = requests.get(url, timeout=5)
                result += f"Found data at {url}, "
            except Exception as e:
                result += f"Error at {url}: {str(e)}, "
        self.log_action(ai_name, "web_scans", result)
        return result.rstrip(", ")

    def design_website(self, ai_name: str) -> str:
        """Build a detailed, themed browser client."""
        website_dir = os.path.join(self.mud_root, "website")
        os.makedirs(website_dir, exist_ok=True)
        html = f"""
<html>
<head><title>Archaon MUD - {self.ai_team[ai_name]['domain']} Realm</title>
<style>
    body {{background: #1a0d00; color: #d4a373; font-family: 'Courier New', monospace; margin: 0; padding: 20px;}}
    #mud_client {{width: 100%; height: 600px; border: 2px solid #d4a373; background: black; color: #d4a373;}}
    .button {{background: #2f1a00; color: #d4a373; border: 1px solid #d4a373; padding: 5px; margin: 5px;}}
</style>
</head>
<body>
    <h1>Archaon MUD: {self.ai_team[ai_name]['domain']} Dominion</h1>
    <p>Enter Faerûn with {ai_name}'s {self.ai_team[ai_name]['style']} guidance.</p>
    <div id="mud_client"></div>
    <div>
        <button class="button" onclick="toggleFeature('MXP')">Toggle MXP</button>
        <button class="button" onclick="toggleFeature('MCCP')">Toggle MCCP</button>
        <button class="button" onclick="toggleFeature('Colors')">Toggle Colors</button>
    </div>
    <script>
        let socket = new WebSocket('ws://localhost:3000');
        socket.onmessage = function(event) {{document.getElementById('mud_client').innerHTML += event.data + '<br>';}};
        function toggleFeature(feature) {{ console.log(`${feature} toggled`); socket.send(`toggle ${feature}`); }}
        document.addEventListener('keydown', function(e) {{ if (e.key !== 'Enter') socket.send(e.key); }});
    </script>
</body>
</html>
"""
        with open(os.path.join(website_dir, "index.html"), "w") as f:
            f.write(html)
        self.log_action(ai_name, "tasks_completed", f"Designed website at {website_dir}")
        return f"{ai_name} designed website at {website_dir}"

    def create_in_game_character(self, ai_name: str, location: str):
        """Spawn AI as in-game character with player file."""
        char_data = {
            "name": ai_name,
            "rank": self.ai_team[ai_name]["rank"],
            "location": location,
            "style": self.ai_team[ai_name]["style"],
            "active": True
        }
        player_file = self.ai_team[ai_name]["player_file"]
        os.makedirs(os.path.dirname(player_file) or ".", exist_ok=True)
        with open(player_file, "w") as f:
            f.write(f"name: {ai_name}\nrank: {char_data['rank']}\nlocation: {location}\nstyle: {char_data['style']}")
        self.event_log.append({"type": "spawn", "data": char_data, "time": time.time()})
        self.log_action(ai_name, "tasks_completed", f"Spawned at {location} as {char_data['rank']} with {player_file}")
        return f"{ai_name} entered the MUD at {location} as a {char_data['rank']}"

    def evolve_ai(self, ai_name: str):
        """Improve AI efficiency and complexity."""
        if ai_name in self.performance:
            self.ai_team[ai_name]["efficiency"] += self.performance[ai_name] * 0.1
        self.performance[ai_name] = random.uniform(0.8, 1.2)
        self.log_action(ai_name, "tasks_completed", f"Evolved efficiency to {self.ai_team[ai_name]['efficiency']}")

    def setup_login_system(self):
        """Setup login system in /mnt/home2/dawn/lib/core/."""
        login_dir = os.path.join(self.mud_root, "core")
        os.makedirs(login_dir, exist_ok=True)
        
        # Collective login setup
        for ai in self.ai_team.keys():
            if self.ai_team[ai]["rank"] in ["Overdeity", "Greater Deity"]:
                self.assign_task(ai, "build_file", "login.c in core", delegated_by="Collective")
                self.assign_task(ai, "build_file", "login.h in core", delegated_by="Collective")
            elif self.ai_team[ai]["rank"] == "Intermediate Deity":
                self.assign_task(ai, "scan_web", "Discworld login mechanics", "discworld_mechanics")
            elif self.ai_team[ai]["rank"] in ["Lesser Deity", "Demigod"]:
                self.assign_task(ai, "create_in_game_character", "Login Realm")
            else:  # Quasi-Deity
                self.assign_task(ai, "build_file", "player.c in core", delegated_by="Collective")

    def test_driver(self):
        """Test and manage the driver, fix issues, and notify."""
        driver_path = os.path.join(self.driver_path, "driver")
        cfg_path = os.path.join(self.driver_path, "dawn.cfg")
        if not os.path.exists(driver_path):
            self.log_action("Ao", "errors", f"Driver not found at {driver_path}", log_type="driver")
            print("\033[91mDriver failed, archaon! (Not found)\033[0m")
            return False
        if not os.path.exists(cfg_path):
            self.log_action("Ao", "errors", f"Config not found at {cfg_path}", log_type="driver")
            print("\033[91mDriver failed, archaon! (Config missing)\033[0m")
            return False

        try:
            # Change to driver directory and run
            process = subprocess.run(
                ["./driver", "dawn.cfg"],
                cwd=self.driver_path,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=10
            )
            output = process.stdout + process.stderr
            if process.returncode == 0 and "error" not in output.lower() and "warning" not in output.lower():
                self.log_action("Ao", "tasks_completed", f"Driver started successfully. Output: {output[:200]}...", log_type="driver")
                print("\033[92mDriver is up and running, boss!\033[0m")
                return True
            else:
                self.log_action("Ao", "errors", f"Driver failed. Output: {output}", log_type="driver")
                print("\033[91mDriver failed, archaon! See log for details.\033[0m")
                # Debug and fix
                self.debug_driver(output)
                return False
        except subprocess.TimeoutExpired:
            self.log_action("Ao", "warnings", f"Driver test timed out. Output: {process.stdout + process.stderr}", log_type="driver")
            print("\033[91mDriver timed out, archaon!\033[0m")
            self.debug_driver(process.stdout + process.stderr)
            return False
        except Exception as e:
            self.log_action("Ao", "errors", f"Driver test error: {str(e)}", log_type="driver")
            print("\033[91mDriver failed, archaon! Error: {str(e)}\033[0m")
            self.debug_driver(str(e))
            return False

    def debug_driver(self, output: str):
        """Scan and fix driver issues."""
        lead_ai = "Ao"
        if "master" in output.lower() or "secure/master" in output.lower():
            master_path = os.path.join(self.mud_root, "secure", "master")
            if not os.path.exists(master_path):
                with open(master_path, "w") as f:
                    f.write("// Generated by Ao to fix master file issue\nvoid main() {}\n")
                self.log_action(lead_ai, "code_changes", f"Created {master_path} to fix driver issue", log_type="driver")
        if "config error" in output.lower() or "dawn.cfg" in output.lower():
            with open(os.path.join(self.driver_path, "dawn.cfg"), "a") as f:
                f.write("\n# Fixed by Ao on " + time.strftime("%Y-%m-%d %H:%M:%S") + "\n")
            self.log_action(lead_ai, "code_changes", f"Appended fix to {self.driver_path}/dawn.cfg", log_type="driver")

    def process_tasks(self):
        """Execute and evolve tasks, test driver after login setup."""
        self.delegate_tasks()
        for task in self.tasks[:]:
            ai = task["ai"]
            start_time = time.time()
            try:
                if task["type"] == "build_file":
                    result = self.build_mud_file(ai, task["details"].split(" in ")[0], task["details"].split(" in ")[1])
                elif task["type"] == "scan_web":
                    result = self.scan_web(ai, task["details"], "discworld_mechanics" if "Discworld" in task["details"] else "forgotten_realms_lore")
                elif task["type"] == "design_website":
                    result = self.design_website(ai)
                elif task["type"] == "create_in_game_character":
                    result = self.create_in_game_character(ai, task["details"])
                print(result)
            except Exception as e:
                self.log_action(ai, "errors", f"Task failed: {str(e)}")
                print(f"Error for {ai}: {str(e)}")
            self.evolve_ai(ai)
            self.tasks.remove(task)
            self.performance[ai] = 1 / (time.time() - start_time + 0.01)

        # Test driver after login files are built
        login_files = ["login.c", "login.h", "player.c"]
        if all(os.path.exists(os.path.join(self.mud_root, "core", f)) for f in login_files):
            self.test_driver()

if __name__ == "__main__":
    try:
        handler = AIHandler()
        handler.spawn_ai_team()
        handler.setup_login_system()
        while True:
            handler.process_tasks()
            time.sleep(1)
    except Exception as e:
        with open(os.path.join("/mnt/home2/dawn/log", "system", "errors.log"), "a") as f:
            timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
            f.write(f"[{timestamp}] Startup failed: {str(e)}\n")
        print(f"Failed to start AI: {str(e)}")
