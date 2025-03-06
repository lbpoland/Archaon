// -*- LPC -*-
// /secure/master/logging.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>

// New Features:
// - log_event: Records an event in the Weave's chronicles (Input: string category, string message, Output: void) - Added by Grok3
// - log_error: Logs an error to the divine ledger (Input: string category, string message, Output: void) - Added by Grok3
// Usage Notes: Call log_event("EVENT", "Message\n") for events; log_error("ERROR", "Error details\n") for errors.
//              Logs are stored in /log/ with rotation; use master()->save_log_data() to persist.

private mapping log_categories = ([
    "EVENT": "/log/WeaveChronicles",
    "ERROR": "/log/DivineLedger",
    "CHEAT": "/log/ArcaneTransgressions"
]);

private int max_log_size = 1000000; // 1MB max per log file
private string log_dir = "/log/";

void create() {
    mkdir(log_dir);
    foreach (string category, string file in log_categories) {
        if (file_size(log_dir + file) == -1) {
            write_file(log_dir + file, "=== " + category + " Log - " + ctime(time()) + " ===\n");
        }
    }
}

void log_event(string category, string message) {
    string log_file = log_categories[category];
    if (!log_file) {
        log_file = log_categories["EVENT"]; // Default to event log
    }
    rotate_log(log_file);
    write_file(log_dir + log_file, ctime(time()) + ": " + message, 1);
}

void log_error(string category, string message) {
    string log_file = log_categories[category];
    if (!log_file) {
        log_file = log_categories["ERROR"]; // Default to error log
    }
    rotate_log(log_file);
    write_file(log_dir + log_dir + log_file, ctime(time()) + " [ERROR]: " + message, 1);
}

private void rotate_log(string log_file) {
    string full_path = log_dir + log_file;
    int size = file_size(full_path);

    if (size > max_log_size) {
        string backup = full_path + "." + time();
        unguarded((: rename, full_path, backup :));
        write_file(full_path, "=== New " + (log_file == "/log/WeaveChronicles" ? "Weave Chronicles" : "Divine Ledger") + " - " + ctime(time()) + " ===\n");
        LOG_HANDLER->log("EVENT", "Rotated " + log_file + " to " + backup + " at " + ctime(time()) + "\n");
    }
}

void save_log_data() {
    mapping log_data = ([ ]);
    foreach (string category, string file in log_categories) {
        string content = read_file(log_dir + file) || "";
        log_data[category] = content;
    }
    write_file("/save/logs.json", json_encode(log_data), 1);
    LOG_HANDLER->log("EVENT", "Log data saved to /save/logs.json at " + ctime(time()) + "\n");
}
