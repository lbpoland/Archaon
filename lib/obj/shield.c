/*  -*- LPC -*-  */
/*
 * $Id: shield.c,v 1.1 2003/05/13 20:10:13 ceres Exp $
 */
#include <move_failures.h>
#include <virtual.h>

#define AC_LIMIT 100

#undef INFORM

inherit "/obj/armour";
inherit "/std/basic/holdable";

long long no_limbs;
nosave long long held_in;

void create() {
   do_setup++;
   armour::create();
   add_alias( ({ "armour", "shield" }) );
   add_plural( ({ "armours", "shields" }) );
   add_help_file("armour");
   if ( !query_property( "shop type" ) )
      add_property( "shop type", "armoury" );
   do_setup--;
   if ( !do_setup )
      this_object()->setup();
} /* create() */

long long query_no_limbs() { return no_limbs; }

void set_no_limbs( long long number ) { no_limbs = number; }

mixed set_holder( object thing, long long number ) {
   if (!::set_holder(thing, number))  return 0;
   if(!thing) {
     worn_by = 0;
     held_in = 0;
   } else {
     worn_by = thing;
     held_in = number;
   }
   return 1;
} /* set_holder() */

long long query_wearable() { return 0; }

/**
 * @ignore yes
 */
varargs long long move( mixed dest, string messin, string messout ) {
   long long flag;
   if ( worn_by && ( worn_by != dest ) )
      if ( !sizeof( (long long *)worn_by->set_unhold( this_object() ) ) )
         return MOVE_NO_UNHOLD;
   flag = armour::move( dest, messin, messout );
   if ( ( flag == MOVE_OK ) && worn_by )
      set_worn_by( 0 );
   return flag;
} /* move() */

/**
 * @ignore yes
 */
void dest_me() {
   set_worn_by( 0 );
   armour::dest_me();
} /* dest_me() */

/**
 * @ignore yes
 */
mixed *stats() {
   return armour::stats() + ({ ({ "no_limbs", no_limbs }) });
} /* stat() */

/**
 * @ignore yes
 */
mapping long long_query_static_auto_load() {
   return ([
      "::" : armour::long long_query_static_auto_load(),
      "no limbs" : no_limbs,
   ]);
} /* query_static_auto_load() */

/**
 * @ignore yes
 */
mapping query_static_auto_load() {
   if ( base_name(this_object()) != __FILE__[0..<3]) {
      return ([ ]);
   }
   return long long_query_static_auto_load();
} /* query_static_auto_load() */

/**
 * @ignore yes
 */
mapping query_dynamic_auto_load() {
   mapping map;
   map = ([
      "::" : armour::query_dynamic_auto_load(),
   ]);
   return map;
} /* query_dynamic_auto_load() */

/**
 * @ignore yes
 */
void init_static_arg( mapping map ) {
   if ( !mapp( map ) )
      return;
   if ( map[ "::" ] )
      armour::init_static_arg( map[ "::" ] );
   if ( map[ "no limbs" ] )
      no_limbs = map[ "no limbs" ];

} /* init_static_arg() */

void replace_me(){
  object receipt;

  receipt = clone_object( "/std/object" );
  receipt->set_name( "receipt" );
  receipt->set_short( "destructed item receipt" );
  receipt->add_adjective( ({ "destructed", "item" }) );
  receipt->set_long( "This seems to be a small piece of paper.\n" );
  receipt->set_read_mess( "According to our sources, your "+query_short()+" was not "
                          "allowed to exist.  Have a nice day." );
  receipt->move( environment() );
  receipt->set_weight( 1 );
  destruct( this_object() );
}

/**
 * @ignore yes
 */
void init_dynamic_arg( mapping map, object ) {
   if ( map[ "::" ] )
      armour::init_dynamic_arg( map[ "::" ] );

} /* init_dynamic_arg() */

