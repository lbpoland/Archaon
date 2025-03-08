// -*- LPC -*-
// /lib/cmds/base.c - Base command handler for Archaon MUD
// Purpose: Foundation for all command objects
// Last updated: March 07, 2025, 04:45 AM AEST

#include <config.h>
#include <log.h>
#include <command.h>

inherit "/std/object";

private string command_name;
private object user;
private string fail_message;

void create() {
    ::create();
}

void setup_cmd(string cmd, object who) {
    command_name = cmd;
    user = who;
}

void set_fail_message(string msg) {
    fail_message = msg;
}

object query_user() {
    return user;
}

string query_command_name() {
    return command_name;
}

void fail_msg() {
    if (fail_message) {
        tell_object(user, fail_message);
    } else {
        notify_fail("You fail to " + command_name + " in Faerûn.\n");
    }
}

int do_cmd(string str) {
    fail_msg();
    return 0;
}

void notify_usage() {
    tell_object(user, "Usage: " + command_name + " <arguments>\n");
}
