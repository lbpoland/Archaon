// -*- LPC -*-
// /secure/master/crash.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld crash mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>
#include <player_handler.h>

void crash(string file) {
    object ob;
    string err;

    if (!file || file == "") {
        LOG_HANDLER->log("CRASH", "Divine disturbance detected at " + ctime(time()) + " - No file specified.\n");
        return;
    }

    ob = find_object(file);
    if (ob) {
        err = catch(destruct(ob));
        if (err) {
            LOG_HANDLER->log("CRASH", "Failed to purge " + file + " due to: " + err + " at " + ctime(time()) + "\n");
        } else {
            LOG_HANDLER->log("CRASH", "Purged " + file + " after divine intervention at " + ctime(time()) + "\n");
        }
    } else {
        LOG_HANDLER->log("CRASH", "No object found at " + file + " for divine cleansing at " + ctime(time()) + "\n");
    }
}

void restore_crash(string file) {
    mixed data;
    string save_file = "/save/crash/" + file + ".json";

    if (file_size(save_file) <= 0) {
        LOG_HANDLER->log("CRASH", "No saved state for " + file + " to restore from divine archives at " + ctime(time()) + "\n");
        return;
    }

    data = json_decode(read_file(save_file));
    if (mappingp(data)) {
        object ob = clone_object(file);
        if (ob) {
            ob->restore_from_data(data); // Assume a restore_from_data method exists
            LOG_HANDLER->log("CRASH", "Restored " + file + " from divine archives at " + ctime(time()) + "\n");
        } else {
            LOG_HANDLER->log("CRASH", "Failed to resurrect " + file + " at " + ctime(time()) + "\n");
        }
    } else {
        LOG_HANDLER->log("CRASH", "Corrupted divine record for " + file + " at " + ctime(time()) + "\n");
    }
}

void save_crash(string file) {
    object ob;
    mapping data;

    ob = find_object(file);
    if (!ob) {
        LOG_HANDLER->log("CRASH", "No object " + file + " to save from divine wrath at " + ctime(time()) + "\n");
        return;
    }

    data = ob->save_data(); // Assume a save_data method exists
    if (mappingp(data)) {
        mkdir("/save/crash");
        write_file("/save/crash/" + file + ".json", json_encode(data), 1);
        LOG_HANDLER->log("CRASH", "Saved " + file + " to divine archives at " + ctime(time()) + "\n");
    } else {
        LOG_HANDLER->log("CRASH", "Failed to archive " + file + " at " + ctime(time()) + "\n");
    }
}
