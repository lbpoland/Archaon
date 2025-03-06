// -*- LPC -*-
// /secure/master/file_exists.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>

// New Features:
// - file_exists: Checks if a tome exists in the Weave (Input: string path, Output: int) - Added by Grok3
// Usage Notes: Call file_exists("/path/to/tome") to check existence; returns 1 if found, 0 if not.
int file_exists(string path) {
    int size;

    if (!path || !stringp(path)) {
        LOG_HANDLER->log("ERROR", "Invalid path sought in the Weave at " + ctime(time()) + "\n");
        return 0;
    }

    size = file_size(path);
    if (size > 0 || size == -2) { // File or directory exists
        LOG_HANDLER->log("EVENT", "Tome " + path + " found in the Weave at " + ctime(time()) + "\n");
        return 1;
    }
    LOG_HANDLER->log("EVENT", "Tome " + path + " not found in the Weave at " + ctime(time()) + "\n");
    return 0;
}
