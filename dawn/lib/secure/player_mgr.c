
inherit "/lib_new/core/object.c";

#define INACTIVE_THRESHOLD (90 * 24 * 60 * 60)

void create() {
    ::create();
}

int valid_player_name(string name) {
    string first_letter = name[0..0];
    string ban_path = "/lib_new/players/banished/" + first_letter + "/" + name + ".txt";
    return !file_exists(ban_path);
}

void save_player(object player) {
    string name = player->query_name();
    string first_letter = name[0..0];
    string save_dir = "/lib_new/players/save/" + first_letter;
    string save_path = save_dir + "/" + name + ".o";
    if (!file_exists(save_dir)) mkdir(save_dir);
    player->save_object(save_path);
    loggers["status"].info("Saved player " + name + " to " + save_path);
}

void backup_inactive_players() {
    foreach(string letter in "abcdefghijklmnopqrstuvwxyz") {
        string save_dir = "/lib_new/players/save/" + letter;
        string backup_dir = "/lib_new/players/backup/" + letter;
        if (!file_exists(save_dir)) continue;
        if (!file_exists(backup_dir)) mkdir(backup_dir);
        foreach(string file in get_dir(save_dir + "/*.o")) {
            string full_path = save_dir + "/" + file;
            object player = new("/lib_new/core/player.c");
            player->restore_object(full_path);
            if (time() - player->query_last_login() > INACTIVE_THRESHOLD) {
                string backup_path = backup_dir + "/" + file;
                rename(full_path, backup_path);
                loggers["status"].info("Moved inactive player " + file + " to " + backup_path);
            }
            destruct(player);
        }
    }
}

int restore_player(string name) {
    string first_letter = name[0..0];
    string save_path = "/lib_new/players/save/" + first_letter + "/" + name + ".o";
    string backup_path = "/lib_new/players/backup/" + first_letter + "/" + name + ".o";
    if (file_exists(save_path)) return 1;
    if (file_exists(backup_path)) {
        rename(backup_path, save_path);
        loggers["status"].info("Restored player " + name + " from backup");
        return 1;
    }
    return 0;
}
