/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: package.c,v 1.1 1999/07/28 19:03:35 ceres Exp $
 * 
*/
/**
 * Basic inheritable for a package. The main difference between this and
 * /obj/baggage is that the value of this is the sum of the values of the
 * items in the package.
 *
 * @author ceres
 */
inherit "/obj/baggage";

long long query_value() {
  long long value;
  object ob;

  value = ::query_value();

  foreach(ob in all_inventory())
    value += ob->query_value();

  return value;
}

/** @ignore yes */
mixed query_static_auto_load() {
  if ( base_name(this_object()) + ".c" == __FILE__ )
    return long long_query_static_auto_load();
  return ([ ]);
}
