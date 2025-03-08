// -*- LPC -*-
// /secure/master/creator_file.c
// Recoded for FluffOS v2019+, themed for Forgotten Realms, integrating Discworld mechanics
// Last updated: March 07, 2025

#include <config.h>
#include <log.h>

varargs mixed creator_file(string file, int author) {
    if (!file || !stringp(file)) {
        LOG_HANDLER->log("ERROR", "Invalid file path in creator_file at " + ctime(time()) + "\n");
        return "NOONE";
    }
    string *str = explode(file, "/") - ({ "" });
    if (sizeof(str) < 2) return 0;

    switch (str[0]) {
        case "secure":
            return get_root_uid();
        case "obj":
            if (sizeof(str) > 2 && str[1] == "secure") return "ims";
        case "global":
        case "std":
        case "cmds":
        case "room":
            return get_bb_uid();
        case "net":
            return "Network";
        case "www":
            if (sizeof(str) > 2 && str[1] == "secure") return "Root";
            return "WWW";
        case "tmp":
            if (str[1] != "mon-shad") return 0;
            return "monster";
        case "failsafe":
            return "failsafe";
        case "d": // Regions (was domains)
            if (sizeof(str) < 3) return 0;
            if (!author || member_array(master()->query_domains(), str) == -1)
                return capitalize(str[1]);
            return ("/d/" + str[1] + "/master")->author_file(str);
        case "w": // Creator workspaces
            if (sizeof(str) < 3) {
                if (str[1] == "common" || str[1] == "development" || str[1] == "meeting")
                    return "arcane-council"; // Themed: was mage-council
                return 0;
            }
            return str[1];
    }
    return 0;
}

mixed author_file(mixed bing) {
    return creator_file(bing, 1);
}

mixed region_file(mixed bing) { // Themed: was domain_file
    string str = creator_file(bing);
    if (!str) return str;
    if (str[0] >= 'A' && str[0] <= 'Z') return str;
    return "Mage"; // General fallback for creators
}
