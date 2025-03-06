// -*- LPC -*-
// /secure/master.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating live Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>
#include <player_handler.h>

inherit "/secure/master/directory_assignments";

#define ROOT "Root"

// Deity-inspired hierarchy (Forgotten Realms-themed, mapping Discworld roles)
#define OVERDEITY         1  // Top tier (Discworld TRUSTEE)
#define HIGH_ARCHON       2  // Mid tier (Discworld DIRECTOR)
#define ADEPT_OF_MYSTERIES 3  // Lower tier (Discworld SENIOR)
#define CHOSEN_EMISSARY   4  // Special role (Discworld LIAISON)

// Permission masks (from Discworld /helpdir/access)
#define READ_MASK   1
#define WRITE_MASK  2
#define GRANT_MASK  4
#define LOCK_MASK   8

private mapping positions;      // Role assignments
private mapping overdeities;   // Top-tier deity-like admins
private mapping permissions;   // File permissions (mirrors /helpdir/permissions)
private mapping checked_master; // Loaded domain masters
private mapping snoop_list;    // Snooping list (from /helpdir/snoop)
private object  unguarded_ob;  // Unguarded operation object

private mapping save_data;     // Persistent data (replaces .o files)

protected void create() {
    set_eval_limit(2000000); // Standard Discworld limit
    permissions = ([ ]);
    positions   = ([ ]);
    checked_master = ([ ]);
    snoop_list = ([ ]);
    unguarded_ob = 0;
    overdeities = ([ ROOT: 1, "archaon": 1 ]); // Initial Overdeities
    save_data = ([ ]);

    // Load persistent data (replaces restore_object, fixes permission errors)
    string save_file = "/secure/save/master.json";
    if (file_size(save_file) > 0) {
        mixed data = json_decode(read_file(save_file));
        if (mappingp(data)) {
            positions = data["positions"] || ([ ]);
            overdeities = data["overdeities"] || overdeities;
            permissions = data["permissions"] || ([ ]);
        } else {
            LOG_HANDLER->log("ERROR", "Failed to load master save file at " + ctime(time()) + "\n");
        }
    }
}

string query_name() { return "Root"; }

object connect(int port) {
    object ob;

    if (!find_object("/secure/login")) {
        LOG_HANDLER->log("REBOOT", "The Realms of Toril reawakened at " + ctime(time()) + "[" + time() + "]\n");
    }

    printf("LPmud version: %s on port %d.\n", mud_info()->query_driver_version(), port);
    switch (port) {
        case 4242: // Matches live Discworld port
            ob = clone_object("/secure/nlogin");
            if (!ob) destruct(this_object());
            break;
        default:
            ob = clone_object("/secure/login");
            break;
    }
    ob->set_login_port(port);
    return ob;
}

// Overdeity (God/Goddess) check
int query_overdeity(mixed str) {
    if (pointerp(str)) {
        str = filter(str, (: interactive($1) :));
        return sizeof(filter((object *)str,
                             (: geteuid($1) == ROOT ||
                                positions[geteuid($1)] == OVERDEITY ||
                                overdeities[geteuid($1)] :))) == sizeof(str);
    }
    return (str == ROOT) || (positions[str] == OVERDEITY) || (overdeities[str]);
}

string query_divine_title(string name) {
    object player = find_player(name);
    if (!player || !query_overdeity(name)) return "Mortal";
    // Placeholder: Needs Discworld gender check (e.g., from /global/player.c)
    return random(2) ? "God of the Realms" : "Goddess of the Realms";
}

int query_administrator(mixed str) { return query_overdeity(str); }
int query_high_priest(mixed str) { return query_overdeity(str); } // Aligns with /concepts/religion

// High Archon (Greater Deity)
int query_high_archon(mixed arg) {
    if (pointerp(arg)) {
        arg = filter(arg, (: interactive($1) :));
        return sizeof(filter((object *)arg,
                             (: (positions[geteuid($1)] == HIGH_ARCHON) ||
                                query_overdeity(geteuid($1)) :))) == sizeof(arg);
    }
    return (positions[arg] == HIGH_ARCHON) || query_overdeity(arg);
}

int query_director(mixed arg) { return query_high_archon(arg); }
int query_lord(mixed arg) { return query_high_archon(arg); }

int query_only_high_archon(string word) {
    return positions[word] == HIGH_ARCHON;
}

string *query_high_archons() {
    return filter_array(keys(positions), (: query_only_high_archon($1) :), this_object());
}

// Adept of the Mysteries (Intermediate Deity)
int query_adept_of_mysteries(mixed arg) {
    if (pointerp(arg)) {
        return sizeof(filter((object *)arg,
                             (: (positions[geteuid($1)] == ADEPT_OF_MYSTERIES) ||
                                query_high_archon(geteuid($1)) :))) == sizeof(arg);
    }
    return (positions[arg] == ADEPT_OF_MYSTERIES) || query_high_archon(arg);
}

int query_senior(mixed arg) { return query_adept_of_mysteries(arg); }

string *query_all_adepts_of_mysteries() {
    return filter_array(keys(positions), (: query_adept_of_mysteries($1) :), this_object());
}

// Chosen Emissary (Lesser Deity)
int query_chosen_emissary(mixed arg) {
    if (pointerp(arg)) {
        arg = filter(arg, (: interactive($1) :));
        return sizeof(filter((object *)arg,
                             (: (positions[geteuid($1)] == CHOSEN_EMISSARY) ||
                                query_high_archon(geteuid($1)) :))) == sizeof(arg);
    }
    return (positions[arg] == CHOSEN_EMISSARY) || query_high_archon(arg);
}

int query_liaison_deputy_or_high_archon(mixed arg) {
    if (pointerp(arg)) {
        arg = filter(arg, (: interactive($1) :));
        return sizeof(filter((object *)arg,
                             (: query_high_archon(geteuid($1)) ||
                                (positions[geteuid($1)] == CHOSEN_EMISSARY) :))) == sizeof(arg);
    }
    return (positions[arg] == CHOSEN_EMISSARY) || query_high_archon(arg);
}

int is_chosen_emissary_of(string person, string domain) {
    return ("/d/" + domain + "/master")->query_deputy(person);
}

int query_player_overdeity(string str) {
    return query_overdeity(str) && PLAYER_HANDLER->test_user(str);
}

string *overdeities_list() { return keys(overdeities); }
string *query_domains() {
    string *domains = get_dir("/d/") - ({ "lost+found", "core" });
    return filter(domains, (: $1[<4..] != "_dev" :));
}

int valid_load(string path, mixed euid, string func) { return 1; }

string get_root_uid() { return ROOT; }
string get_bb_uid() { return "Room"; }

string *define_include_dirs() {
    return ({ "/include/%s" });
}

int valid_trace() { return 1; }

void shut(int min) {
    "/obj/shut"->shut(min);
}

void remove_checked_master(string name) {
    map_delete(checked_master, name);
}

mapping query_checked_master() { return copy(checked_master); }

varargs mixed apply_unguarded(function f, int local) {
    object previous_unguarded;
    string err;
    mixed val;

    if (base_name(previous_object(0)) != "/secure/simul_efun") {
        error("Illegal unguarded apply.");
        return 0;
    }
    previous_ungarded = unguarded_ob;
    if (local)
        unguarded_ob = master();
    else
        unguarded_ob = previous_object(1);
    err = catch(val = evaluate(f));
    unguarded_ob = previous_unguarded;
    if (err) error(err);
    return val;
}

// Save method (modernized, aligns with /helpdir/save)
private void save_master_data() {
    string save_file = "/secure/save/master.json";
    save_data["positions"] = positions;
    save_data["overdeities"] = overdeities;
    save_data["permissions"] = permissions;
    write_file(save_file, json_encode(save_data), 1);
    LOG_HANDLER->log("SAVE", "Master data saved at " + ctime(time()) + "\n");
}

// Include other master functionalities (to be recoded)
#include "/secure/master/permission.c"
#include "/secure/master/crash.c"
#include "/secure/master/create_dom_creator.c"
#include "/secure/master/creator_file.c"
#include "/secure/master/dest_env.c"
#include "/secure/master/ed_stuff.c"
#include "/secure/master/file_exists.c"
#include "/secure/master/logging.c"
#include "/secure/master/parse_command.c"
#include "/secure/master/preload.c"
#include "/secure/master/query_pl_level.c"
#include "/secure/master/simul_efun.c"
#include "/secure/master/snoop.c"
#include "/secure/master/valid_database.c"
#include "/secure/master/valid_exec.c"
#include "/secure/master/valid_hide.c"
#include "/secure/master/valid_ident.c"
#include "/secure/master/valid_link.c"
#include "/secure/master/valid_override.c"
#include "/secure/master/valid_read.c"
#include "/secure/master/valid_seteuid.c"
#include "/secure/master/valid_shadow.c"
#include "/secure/master/valid_socket.c"
#include "/secure/master/valid_write.c"
#include "/secure/master/valid_copy.c"
#include "/secure/master/virtual_objects.c"
#include "/secure/master/valid_bind.c"
#include "/secure/master/valid_to_c.c"
#include "/secure/master/valid_binary.c"
