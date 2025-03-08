// -*- LPC -*-
// /secure/master/ed_stuff.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld editor mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>

private mapping edit_sessions = ([ ]);

void ed_start(string file, object user) {
    if (!master()->query_adept_of_mysteries(geteuid(user)) && !master()->query_overdeity(geteuid(user))) {
        tell_object(user, "Only Adepts of the Mysteries or Overdeities may weave the Weave!\n");
        return;
    }
    if (edit_sessions[user]) {
        tell_object(user, "You are already weaving a tome. Finish or abandon it first.\n");
        return;
    }
    edit_sessions[user] = ([ "file": file, "buffer": allocate(0), "line": 0 ]);
    tell_object(user, "You begin weaving the scroll of " + file + ". Type lines, 'w' to save, 'q' to quit.\n");
}

void ed_cmd(string cmd, object user) {
    string *session = edit_sessions[user];
    string err;

    if (!session) {
        tell_object(user, "No tome is being woven. Use 'ed <file>' to begin.\n");
        return;
    }

    switch (cmd) {
        case "w":
            string content = implode(session["buffer"], "\n");
            mkdir("/w/" + geteuid(user));
            err = catch(write_file("/w/" + geteuid(user) + "/" + session["file"], content, 1));
            if (err) {
                LOG_HANDLER->log("ERROR", "Failed to save " + session["file"] + " for " + geteuid(user) + ": " + err + " at " + ctime(time()) + "\n");
                tell_object(user, "The Weave rejected your scroll! Error: " + err + "\n");
            } else {
                LOG_HANDLER->log("EVENT", "Scroll " + session["file"] + " woven by " + geteuid(user) + " at " + ctime(time()) + "\n");
                tell_object(user, "The scroll of " + session["file"] + " has been saved to the Weave.\n");
            }
            map_delete(edit_sessions, user);
            break;
        case "q":
            tell_object(user, "You abandon the weaving of " + session["file"] + ".\n");
            map_delete(edit_sessions, user);
            break;
        default:
            session["buffer"] += ({ cmd });
            session["line"]++;
            tell_object(user, "Line " + session["line"] + " added to the scroll.\n");
            break;
    }
}

void ed_end(object user) {
    if (edit_sessions[user]) {
        map_delete(edit_sessions, user);
        tell_object(user, "Your weaving session has been forcibly ended by divine will.\n");
    }
}
