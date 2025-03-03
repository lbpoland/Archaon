/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: intermud.c,v 1.16 2003/05/03 07:42:44 ceres Exp $
 */
/*    /daemon/intermud.c
 *    from the Nightmare IV LPC Library
 *    daemon handling the InterMUD-3 Protocol
 *    created by Descartes of Borg 950506
 *    modified for the Discworld mudlib by Turrican 30-10-95
 */

#ifndef __PACKAGE_SOCKETS__
#error You should not try and load /daemon/intermud.c with no sockets package.
#else

#include <network.h>

inherit CLIENT;

#include "intermud.h"

private int ChosenServer;
private int Password;
private class list MudList, ChannelList;
private mapping Banned;
private int Tries;
nosave private mixed *ConstantNameservers;
nosave private mixed *Nameservers;
private nosave int Connected, Fd;

void do_disconnect() {
      SERVICES_D->eventSendChannel("URLbot", "bot", sprintf("%%^RED%%^Oh SHIT!%%^RESET%%^ Try %d...", Tries));
      //unguarded((: eventSocketClose(Fd) :));
      eventSocketClose(Fd);
}

protected int tryAgain() {
    Tries++;
    if( Tries > 3 ) {
        Tries = 0;
        ChosenServer++;
        if( ChosenServer >= sizeof(Nameservers) )
            ChosenServer = 0;
    }
    unguarded((: save_object, SAVE_INTERMUD, 1 :));

    return Tries * 20;
}

void trySuccess() {
    Tries = 0;
    unguarded((: save_object, SAVE_INTERMUD, 1 :));
}

void nextServer() {
    Tries = 0;
    SERVICES_D->eventSendChannel("URLbot", "bot", sprintf("%%^RED%%^Switching away from %s%%^RESET%%^", Nameservers[ChosenServer][0]));
    ChosenServer++;
    if( ChosenServer >= sizeof(Nameservers) )
        ChosenServer = 0;
    unguarded((: save_object, SAVE_INTERMUD, 1 :));
    SERVICES_D->eventSendChannel("URLbot", "bot", sprintf("%%^YELLOW%%^Switching to %s%%^RESET%%^", Nameservers[ChosenServer][0]));
    //unguarded((: call_out( (: Setup :), 2) :));
    call_out( (: Setup :), 2);
}

protected void create() {
  client::create();
  ChosenServer = 0;
  Connected = 0;
  Password = 0;
  Tries = 0;
  Fd = 0;
  Banned = ([]);
  ConstantNameservers = ({ 
        ({ "*Kelly", "45.64.56.66 8080" }),         // Herne Hill, Victoria (VIC), Australia (AU), Oceania (OC)
        //({ "*dalet", "97.107.133.86 8787" }),       // Newark, New Jersey (NJ), United States (US), North America (NA)
        //({ "*wpr", "195.242.99.94 8080" }),         // Netherlands (NL), Europe (EU)
        //({ "*i4", "204.209.44.3 8080" }),           // Edmonton, Alberta (AB), Canada (CA), North America (NA)
        //({ "*gjs", "198.144.203.194 9000" }),       // Old, defunct I3 server (San Bruno, California (CA), United States (US), North America (NA))
        //({ "*Kelly-old", "150.101.219.57 8080" }),  // Herne Hill, Victoria (VIC), Australia (AU), Oceania (OC)
  });

  MudList = new(class list);
  ChannelList = new(class list);
  MudList->ID = -1;
  MudList->List = ([]);
  ChannelList->ID = -1;
  ChannelList->List = ([]);
  if( file_size( SAVE_INTERMUD __SAVE_EXTENSION__ ) > 0 )
    unguarded((: restore_object, SAVE_INTERMUD, 1 :));

  // To force the list to remain constant
  Nameservers = ConstantNameservers;

  // I3 is too flaky for this...
  //if(ChosenServer >= sizeof(Nameservers))
      ChosenServer = 0;
  SetSocketType(MUD);
  SetDestructOnClose(1);
  call_out( (: Setup :), 2);
}

void eventExternWrite( mixed *packet ) {
  return eventWrite(Fd, packet);
}

void eventWrite(int fd, mixed *packet) {
  return client::eventWrite(fd, packet);
}

protected void Setup() {
  string ip;
  int port; 

  if( !Nameservers || !sizeof(Nameservers) ) return;
  sscanf(Nameservers[ChosenServer][1], "%s %d", ip, port);
  if( (Fd = eventCreateSocket(ip, port)) < 0 ) return;
  eventWrite(Fd, ({ "startup-req-3", 5, mud_name(), 0, Nameservers[ChosenServer][0], 0,
                      Password, MudList->ID, ChannelList->ID, PORT_MUD,
                      PORT_OOB, 0, MUDLIB_VERSION, 
                      mud_name(), __VERSION__, "LPMud",
                      STATUS, ADMIN_ADDRESS,
                      (mapping)SERVICES_D->GetServices(), 0 }) );
}

protected void eventRead(int fd, mixed *packet) {
  mixed val;
  string cle;

  if( !packet || sizeof(packet) < 6 ) return; /* should send error */
  if( Banned[packet[1]] ) {
    /* build error packet, let them know why they are banned */
    return;
  }
  switch(packet[0]) {
  case "startup-reply":
    if( sizeof(packet) != 8 ) return; /* should send error */
    if( !sizeof(packet[6]) ) return;
    if( packet[6][0][0] == Nameservers[ChosenServer][0] ) {
      //Nameservers = packet[6];
      Connected = 1;
      Password = packet[7];
      unguarded((: save_object, SAVE_INTERMUD, 1 :));
      //SERVICES_D->kick_wileymud();
      //event(users(), "intermud_tell", "URLbot@Disk World", sprintf("%%^GREEN%%^I'm ALIVE!%%^RESET%%^  Connection to %%^YELLOW%%^%s%%^RESET%%^ established!", Nameservers[ChosenServer][0]), "bot");
      SERVICES_D->eventSendChannel("URLbot", "bot", sprintf("%%^GREEN%%^I'm ALIVE!%%^RESET%%^  Connection to %%^YELLOW%%^%s%%^RESET%%^ established! Try %d", Nameservers[ChosenServer][0], Tries));
      reload_object(find_object(SERVICES_D));
    } else {
      //Nameservers = packet[6];
      Connected = 1;
      Password = packet[7];
      unguarded((: save_object, SAVE_INTERMUD, 1 :));
      SERVICES_D->eventSendChannel("URLbot", "bot", sprintf("%%^RED%%^Uh oh!%%^RESET%%^  I seem to be on %s, but should be on %s...%%^RESET%%^ Try %d", packet[6][0][0], Nameservers[ChosenServer][0], Tries));
      reload_object(find_object(SERVICES_D));
      //do_disconnect();
      //Setup();
    }
    return;
  case "mudlist":
    if( sizeof(packet) != 8 ) return;
    // Due to changes in the way the mudlist is broken into multiple packets,
    // this check is no longer valid.
    //if( packet[6] == MudList->ID ) return; 
    if( packet[2] != Nameservers[ChosenServer][0] ) return;
    MudList->ID = packet[6];
    foreach(cle, val in packet[7]) {
      if( !val && MudList->List[cle] != 0 ) 
        map_delete(MudList->List, cle);
      else if( val ) MudList->List[cle] = val;
    }
    unguarded((: save_object, SAVE_INTERMUD, 1 :));
    return;
  case "auth-mud-req":
    SERVICES_D->eventReceiveAuthRequest(packet);
    break;
  case "auth-mud-reply":
    SERVICES_D->eventReceiveAuthReply(packet);
    break;
  case "channel-e":
    SERVICES_D->eventReceiveChannelEmote(packet);
    break;
  case "channel-m":
    //event(users(), "intermud_tell", sprintf("%s@%s", packet[7], packet[2]),
    //               "Got channel message", "DEBUG__" + (string)packet[6]);
    SERVICES_D->eventReceiveChannelMessage(packet);
    break;
  case "chan-who-reply":
    SERVICES_D->eventReceiveChannelWhoReply(packet);
    break;
  case "chan-who-req":
    SERVICES_D->eventReceiveChannelWhoRequest(packet);
    break;
  case "chan-user-req":
    SERVICES_D->eventReceiveChannelUserRequest(packet);
    break;
  case "chanlist-reply":
    //    if( packet[6] == ChannelList->ID ) return; 
    if( packet[2] != Nameservers[ChosenServer][0] ) return;
    ChannelList->ID = packet[6];
    foreach(cle, val in packet[7]) { 
      if( !val && ChannelList->List != 0 ) 
        map_delete(ChannelList->List, cle);
      else if( val ) ChannelList->List[cle] = val;
    } 
    unguarded((: save_object, SAVE_INTERMUD, 1 :));
    SERVICES_D->eventRegisterChannels(packet[7]);
    return;
  case "emoteto":
    SERVICES_D->eventReceiveEmote(packet);
    break;
  case "finger-req":
    SERVICES_D->eventReceiveFingerRequest(packet);
    break;
  case "finger-reply":
    SERVICES_D->eventReceiveFingerReply(packet);
    break;
  case "locate-req":
    SERVICES_D->eventReceiveLocateRequest(packet);
    break;
  case "locate-reply":
    SERVICES_D->eventReceiveLocateReply(packet);
    break;
  case "tell":
    SERVICES_D->eventReceiveTell(packet);
    break;
  case "who-req":
    SERVICES_D->eventReceiveWhoRequest(packet);
    break;
  case "who-reply":
    SERVICES_D->eventReceiveWhoReply(packet);
    break;
  case "error":
    SERVICES_D->eventReceiveError(packet);
    break;
  default:
    break;
  }
}

protected void OLDeventSocketClose(int fd) {
  int extra_wait;

  extra_wait = (Tries++) * 20;
  if( extra_wait > 60 ) {
      extra_wait = 0;
      Tries = 0;
      ChosenServer++;
      if(ChosenServer >= sizeof(Nameservers))
          ChosenServer = 0;
  }
  Connected = 0;
  Fd = 0;
  call_out( (: Setup :), 20 + extra_wait);
}

protected void eventSocketClose(int fd) {
    int extra_wait;

    Connected = 0;
    Fd = 0;
    extra_wait = tryAgain();

    call_out( (: Setup :), 5 + extra_wait);
}

protected void eventConnectionFailure() {
  if( Connected ) return;
  error("Failed to find a useful name server.\n");
}

int SetSocketType(int x) { return client::SetSocketType(MUD); }

int SetDestructOnClose(int x) { return 0; }

string GetMudName(string mud) {
  string *lc, *uc;
  int x;
  
  if( MudList->List[mud] ) return mud;
  lc = map(uc = keys(MudList->List), function(string str) {
    if( !str ) return "";
    else return lower_case(str);
  });
  x = member_array(lower_case(mud), lc);
  if( x < 0 ) return 0;
  else return uc[x];
}

mapping GetMudList() { return copy(MudList->List); }

string *GetMuds() { return keys(MudList->List); }

mapping GetChannelList() { return copy(ChannelList->List); }

string *GetChannels() { return keys(ChannelList->List); }

string *GetMatch(string mud) {
  string *uc, *lc;
  
  mud = lower_case(mud);
  lc = map(uc = keys(MudList->List), (: lower_case :));
  return map(filter(regexp(lc, "^"+mud, 1), (: intp :)), (: $(uc)[$1] :));
}

string GetNameserver() { return Nameservers[ChosenServer][0]; }

#endif                          /* __PACKAGE_SOCKETS__ */
