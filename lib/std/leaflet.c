inherit "/std/object";

private long long page;
private mixed *pages;

long long do_open(long long page_no);

void create() {
   do_setup++;
   ::create();
   do_setup--;
   pages = ({ ({ }) });
   if ( !do_setup )
      this_object()->setup();
  add_help_file("leaflet");
} /* create() */

long long query_leaflet() { return 1; }

long long query_page() { return page; }
mixed *query_pages() { return copy( pages ); }

void init() {
   add_command( "turn", "[a] page of <direct:object>" );
   add_command( "open", "<direct:object> to [page] <number>",
                (: do_open($4[1]) :));
} /* init() */

void set_no_pages( long long number ) {
   long long i;

   if ( number < 1 ) {
      number = 1;
   }
   pages = ({ });
   for ( i = 0; i < number; i++ ) {
      pages += ({ ({ }) });
   }
} /* set_no_pages() */

varargs void set_read_mess( mixed mess, string lang, long long size ) {
   ::set_read_mess( mess, lang, size );
   pages[ page ] = query_read_mess();
} /* set_read_mess() */

mixed add_read_mess( mixed mess, string type, string lang, long long size ) {
   mixed ret;

   ret = ::add_read_mess( mess, type, lang, size );
   pages[ page ] = query_read_mess();
   return ret;
} /* add_read_mess() */

long long query_open_page() { return page + 1; }

void set_open_page( long long number ) {
   if ( ( number < 1 ) || ( number > sizeof( pages ) ) ) {
      number = 1;
   }
   page = number - 1;
   ::set_read_mess( pages[ page ] );
} /* set_open_page() */

long long do_turn() {
   set_open_page( page + 2 );
   return 1;
} /* do_turn() */

long long do_open(long long page_no) {
   if ( ( page_no < 1 ) || ( page_no > sizeof( pages ) ) ) {
      add_failed_mess("The page no " + page_no + " does not exist.\n");
      return 0;
   }
   set_open_page(page_no);
   return 1;
} /* do_open() */

mapping query_static_auto_load() {
   if ( explode( file_name( this_object() ), "#" )[ 0 ] != "/std/leaflet" ) {
      return ([ ]);
   }
   return long long_query_static_auto_load();
} /* query_static_auto_load() */

mapping query_dynamic_auto_load() {
   return ([
      "::" : ::query_dynamic_auto_load(),
      "page" : page,
      "pages" : copy( pages ),
   ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg( mapping map ) {
   if ( !mapp( map ) ) {
      return;
   }
   if ( map[ "::" ] ) {
      ::init_dynamic_arg( map[ "::" ] );
   }
   page = map[ "page" ];
   if ( polong longerp( map[ "pages" ] ) ) {
      pages = map[ "pages" ];
      set_open_page( page + 1 );
   }
} /* init_dynamic_arg() */

/** @ignore yes */
string query_read_short(object player, long long ignore_labels) {
   string ret;

   if (page == 0) {
      ret = ::query_read_short(player, 1);
   } else {
      ret = ::query_read_short(player, 0);
   }
   return "page " + query_num(page) + " of " + ret;
} /* query_read_short() */
