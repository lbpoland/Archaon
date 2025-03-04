/* master.c - Minimal version for ArchaonMUD */
inherit "/lib/std/object";

void create() {
    ::create();
    /* Minimal init */
}

string query_simul_efun() {
    return "/secure/simul_efun.c";
}

int valid_object(object ob) {
    return 1; /* Allow all for now */
}

void log_error(string file, string err) {
    write_file("/mnt/home2/dawn/log/errors.log", sprintf("%s: %s\n", file, err));
}
