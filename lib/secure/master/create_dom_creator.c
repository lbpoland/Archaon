// -*- LPC -*-
// /secure/master/create_dom_creator.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>
#include <player_handler.h>

#define BACKUP_DIR "/save/mages/"

int employ_creator(string name);
int create_region(string name, string high_archon);
int dismiss_creator(string str);
int eligible_creator(object player);
void backup_vaults(string, int);
void backup_bank(string, int);
void backup_quest_library(string, int);

int create_region(string name, string high_archon) {
    string file;
    object *interactives;

    if (!(master()->query_overdeity(previous_object(-1)) &&
          sizeof((interactives = filter(previous_object(-1), (: interactive($1) :)))))) {
        write("Only an Overdeity may forge a new region in the Realms!\n");
        return 0;
    }
    if (master()->query_overdeity(capitalize(name))) {
        write("A divine name cannot be used for a mortal region...\n");
        return 0;
    }
    if (file_size("/d/" + name) != -1) {
        write("This region already exists under Mystra’s gaze (or is invalid).\n");
        return 0;
    }
    if (sizeof(explode(name, "/")) > 1) {
        write("A region name cannot contain a rift (/) in its title.\n");
        return 0;
    }
    if (!PLAYER_HANDLER->test_creator(high_archon)) {
        write("The High Archon must already be a creator blessed by the gods.\n");
        return 0;
    }
    mkdir("/d/" + name);
    master()->add_high_archon(high_archon);
    file = read_file("/std/dom/master.c");
    write_file("/d/" + name + "/master.c", "#define HIGH_ARCHON \"" + high_archon + "\"\n");
    write_file("/d/" + name + "/master.c", "#define REGION \"" + name + "\"\n");
    write_file("/d/" + name + "/master.c", file);
    file = read_file("/std/dom/common.c");
    write_file("/d/" + name + "/common.c",
               "#define REGION_TITLE \"the sacred region of " + name + "\"\n");
    write_file("/d/" + name + "/common.c", "#define HIGH_ARCHON \"" + high_archon + "\"\n");
    write_file("/d/" + name + "/common.c", "#define REGION \"" + name + "\"\n");
    write_file("/d/" + name + "/common.c", file);
    file = read_file("/std/dom/loader.c");
    write_file("/d/" + name + "/loader.c", "#define REGION \"" + name + "\"\n");
    write_file("/d/" + name + "/loader.c", file);
    master()->save_master_data();
    write("The region of " + name + " has been forged under Mystra’s blessing.\n");
    LOG_HANDLER->log("ASCENSION", "Region " + name + " forged with High Archon " +
                    high_archon + " by " + geteuid(interactives[0]) + " at " + ctime(time()) + "\n");
    return 1;
}

int employ_creator(string name) {
    object *interactives;
    string fname;

    if (!(master()->query_high_archon(previous_object(-1)) &&
          sizeof((interactives = filter(previous_object(-1), (: interactive($1) :))))))
        return 0;
    if (!PLAYER_HANDLER->test_user(name)) {
        write("This mortal does not exist in the Realms.\n");
        return 1;
    }
    if (file_size("/save/mages/" + name + "/save_file.json") > 0) {
        write("This mortal’s essence has already been preserved.\n");
        return 1;
    }
    fname = PLAYER_HANDLER->query_player_file_name(name);
    if (file_size(fname + ".json.gz") > 0) {
        unguarded((: uncompress_file, fname + ".json.gz" :));
    }
    mkdir(BACKUP_DIR + name);
    unguarded((: cp, fname + ".json", "/save/mages/" + name + "/save_file.json" :));
    backup_vaults(name, 0);
    backup_bank(name, 0);
    backup_quest_library(name, 0);
    if (find_player(name)) {
        find_player(name)->set_creator(1);
        find_player(name)->save();
        tell_object(find_player(name), "You have been blessed by Mystra as a creator by " +
                    capitalize(geteuid(interactives[0])) + ".\n");
        tell_object(find_player(name), "Quit and return to the Realms to wield your new powers.\n");
        tell_object(find_player(name), "Seek the tomes of Waterdeep, especially /doc. "
                    "\"help creator\" will guide your path.\n");
        tell_object(find_player(name), "Serve the Realms with wisdom and honor, young creator.\n");
    } else {
        unguarded((: write_file, fname + ".json",
                     json_encode(([ "creator": 1, "home_dir": "/w/" + name ])) :));
    }
    unguarded((: compress_file, fname + ".json.gz" :));
    if (file_size("/w/" + name) == -1) {
        unguarded((: mkdir, "/w/" + name :));
        unguarded((: write_file, "/w/" + name + "/workroom.c",
                     "#define CREATOR \"" + name + "\"\n" :));
        unguarded((: write_file, "/w/" + name + "/workroom.c",
                     read_file("/std/creator/workroom.c") :));
        unguarded((: cp, "/std/creator/mage_kit.json", "/w/" + name + "/mage_kit.json" :));
    }
    LOG_HANDLER->log("ASCENSION", sprintf("%s: %s blessed as a creator by %s\n", ctime(time()), name,
                                           interactives[0]->query_name()));
    write(capitalize(name) + " has been blessed as a creator of the Realms.\n");
    PLAYER_HANDLER->remove_cache_entry(name);
    return 2;
}

int dismiss_creator(string str) {
    string name, reason, fname, save_file;
    object *interactives;

    if (!(master()->query_high_archon(previous_object(-1)) &&
          sizeof((interactives = filter(previous_object(-1), (: interactive($1) :))))))
        return 0;
    if (sscanf(str, "%s %s", name, reason) != 2) {
        notify_fail("You must provide a reason for this divine dismissal!\n");
        return 0;
    }
    if (!PLAYER_HANDLER->test_creator(name)) {
        return notify_fail(name + " has not been blessed as a creator!\n");
    }
    if (master()->query_high_archon(name)) {
        write("A High Archon cannot be dismissed by mortal means.\n");
        return 0;
    }
    LOG_HANDLER->log("DISMISSAL", sprintf("%s: %s stripped of creator status by %s\nReason: %s\n",
                                           ctime(time()), name, interactives[0]->query_name(), reason));
    fname = PLAYER_HANDLER->query_player_file_name(name);
    if (find_player(name)) {
        find_player(name)->set_creator(0);
        find_player(name)->save();
        tell_object(find_player(name), "Your creator powers have been revoked by " +
                    capitalize(interactives[0]->query_name()) + ".\n");
        find_player(name)->quit();
        if (file_size(fname + ".json.gz") != -1) {
            unguarded((: uncompress_file, fname + ".json.gz" :));
        }
    } else {
        if (file_size(fname + ".json.gz") != -1) {
            unguarded((: uncompress_file, fname + ".json.gz" :));
        }
        unguarded((: write_file, fname + ".json",
                     json_encode(([ "creator": 0, "home_dir": 0 ])) :));
        unguarded((: compress_file, fname + ".json" :));
    }
    write(capitalize(name) + " has been stripped of their creator status.\n");
    save_file = "/save/mages/" + name + "/save_file.json";
    if (file_size(save_file) == -1) {
        save_file = BACKUP_DIR + name + ".json";
    }
    backup_vaults(name, 1);
    backup_bank(name, 1);
    backup_quest_library(name, 1);
    if (file_size(save_file) > 0) {
        unguarded((: write_file, save_file,
                     json_encode(([ "last_log_on": time() ])) :));
        unguarded((: cp, save_file, fname + ".json" :));
        unguarded((: rm, save_file :));
        unguarded((: rm, fname + ".json.gz" :));
        unguarded((: compress_file, fname + ".json" :));
    }
    if (file_size("/w/" + name) == -2) {
        unguarded((: rename, "/w/" + name, "/w/.old_mages/" + name :));
    }
    rm(save_file);
    rmdir(BACKUP_DIR + name);
    PLAYER_HANDLER->remove_cache_entry(name);
    return 1;
}

int eligible_creator(object player) {
    int age, level;
    string age_str, reasoning;

    reasoning = "  The path to creation in the Forgotten Realms is not a birthright. Prove your worth through deeds.\n"
                "  Seek the favor of the High Archons by reporting arcane anomalies or contributing to the libraries of Waterdeep.\n"
                "  Those who cause chaos will not be chosen. Wielding the Weave is a sacred responsibility.\n"
                "  Dedicate time to the Realms to show your loyalty to Mystra’s cause.\n\n";

    age = -(player->query_time_on());
    level = player->query_level();

    if (level >= 150 && age > 432000) { // Matches Discworld wiki criteria
        write("  You have met the minimum requirements to seek Mystra’s blessing as a creator in the Forgotten Realms.\n"
              "  You must now pass the judgment of the High Archons.\n" + reasoning);
        return 1;
    }

    age_str = "";
    if (age > 86400) age_str += sprintf("%d day", age / 86400);
    if (age > 172800) age_str += "s";
    if (age % 86400 > 3600) {
        if (age > 86400) age_str += " and ";
        age_str += sprintf("%d hour", (age % 86400) / 3600);
    }
    if (age % 86400 > 7200) age_str += "s";

    write("  To seek Mystra’s blessing as a creator in the Forgotten Realms, you must be level 150 in your guild and at least five days old.\n"
          "  You are level " + level + ", and your age is " + age_str + ".\n" + reasoning);
    return 0;
}

private void backup_vaults(string name, int restore) {
    string base = "/save/vaults/";
    string creator_dir = BACKUP_DIR + name + "/vaults/";
    string *vaults, *tmp;
    string file;

    if (!restore) {
        vaults = get_dir(base);
        mkdir(creator_dir);
        foreach (string vault in vaults) {
            file = base + vault + "/" + name + ".json";
            if (file_size(file) != -1) {
                cp(file, creator_dir + "/" + vault + ".json");
            }
        }
    } else {
        if (file_size(creator_dir) == -1) return;
        vaults = get_dir(base);
        foreach (string vault in vaults) {
            file = base + vault + "/" + name + ".json";
            if (file_size(file) != -1) rm(file);
        }
        vaults = get_dir(creator_dir);
        foreach (string vault in vaults) {
            tmp = explode(vault, ".");
            cp(creator_dir + vault, base + tmp[0] + "/" + name + ".json");
            rm(creator_dir + vault);
        }
        rmdir(creator_dir);
    }
}

private void backup_bank(string name, int restore) {
    string base = "/save/bank_accounts/";
    string bank_file = base + name[0..0] + "/" + name + ".json";
    string bank_dir = BACKUP_DIR + name + "/bank_account/";
    string saved_file;

    if (!restore) {
        mkdir(bank_dir);
        if (file_size(bank_file) == -1) return;
        cp(bank_file, bank_dir + name + ".json");
    } else {
        saved_file = bank_dir + name + ".json";
        if (file_size(bank_dir) == -1) return;
        rm(bank_file);
        if (file_size(saved_file) == -1) return;
        cp(saved_file, bank_file);
        rm(saved_file);
        rmdir(bank_dir);
    }
}

private void backup_quest_library(string name, int restore) {
    string base = "/save/library/";
    string library_file = base + name[0..0] + "/" + name + ".json";
    string library_dir = BACKUP_DIR + name + "/quest_library/";
    string saved_file;

    if (!restore) {
        mkdir(library_dir);
        if (file_size(library_file) == -1) return;
        cp(library_file, library_dir + name + ".json");
    } else {
        saved_file = library_dir + name + ".json";
        if (file_size(library_dir) == -1) return;
        rm(library_file);
        if (file_size(saved_file) == -1) return;
        cp(saved_file, library_file);
        rm(saved_file);
        rmdir(library_dir);
    }
}
