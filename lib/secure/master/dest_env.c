// -*- LPC -*-
// /secure/master/dest_env.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>

void dest_env(object env) {
    string err;
    object *contents;

    if (!env || !objectp(env)) {
        LOG_HANDLER->log("ERROR", "Attempted divine purging of invalid environment at " + ctime(time()) + "\n");
        return;
    }

    contents = all_inventory(env);
    foreach (object ob in contents) {
        err = catch(destruct(ob));
        if (err) {
            LOG_HANDLER->log("ERROR", "Failed to purge " + file_name(ob) + " from " + file_name(env) + ": " + err + " at " + ctime(time()) + "\n");
        }
    }

    err = catch(destruct(env));
    if (err) {
        LOG_HANDLER->log("ERROR", "Divine purging of " + file_name(env) + " failed: " + err + " at " + ctime(time()) + "\n");
        notify_fail("The realm resists Talos’s wrath!\n");
    } else {
        LOG_HANDLER->log("EVENT", "Realm " + file_name(env) + " purged by divine storm at " + ctime(time()) + "\n");
    }
}
