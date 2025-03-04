
inherit "/lib/std/object";
void create() {
    ::create();
    set_name(this_player()->query_name());
    set_short(sprintf("%s, %s of %s", this_player()->query_name(), this_player()->query_deity(), this_player()->query_domain()));
    set_long(sprintf("%s, a %s %s, governs %s with %s demeanor.", this_player()->query_name(), this_player()->query_rank_name(), this_player()->query_deity(), this_player()->query_domain(), this_player()->query_personality()));
}
void init() {
    add_action("promote", "promote");
}
int promote(string target) {
    object player = find_player(target);
    if (!player || this_player()->query_rank() < 100) return notify_fail("Only Ao can promote!\n");
    player->set_rank(this_player()->query_rank() - 10);
    player->set_deity(this_player()->query_deity());
    player->set_domain(this_player()->query_domain());
    player->set_personality(this_player()->query_personality());
    write(sprintf("Promoted %s to %s, rank %d in %s!\n", target, player->query_deity(), player->query_rank(), player->query_domain()));
    return 1;
}
int query_rank() { return this_player()->query_property("rank") || 0; }
string query_rank_name() {
    mapping ranks = ([100: "Overdeity", 80: "Greater Deity", 70: "Intermediate Deity", 60: "Lesser Deity", 50: "Demigod", 40: "Exarch", 30: "Avatar"]);
    return ranks[this->query_rank()] || "Mortal";
}
