
// --- MUD Extraction File: mud_extraction_part1.h ---
// Generated: 2025-03-07 07:27:40 UTC
// Source Directory: /mnt/home2/grok/lib
// Purpose: Consolidated LPC .h files for analysis and recreation with FluffOS v2019+
//          and Forgotten Realms theming, replicating discworld.starturtle.net:4242
//          with optimizations (UTF-8, JSON, strict typing).
// Note: Each file break is marked with // --- END [file_path] ---
//
// --- BEGIN [/mnt/home2/grok/lib/include/volumes.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/volumes.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
1256 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/volumes.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Include file for volumes of different items.  This should be used to 
 * make sure the volumes of bottles is correct.
 * @author Lemming
 */

#ifndef __VOLUMES_H
/** @ignore yes */
#define __VOLUMES_H

/** Volume of a shot measure */
#define VOLUME_MINIMUM_DRINKABLE      50

/** Volume of a pint */
#define VOLUME_PINT      2400

/** Volume of a gill */
#define VOLUME_GILL      600

/** Volume of a quart */
#define VOLUME_QUART     4800

/** Volume of a gallon */
#define VOLUME_GALLON    19200

/** Volume of a half pint */
#define VOLUME_HALFPINT  (VOLUME_PINT / 2)

/** Volume of a litre */
#define VOLUME_LITRE     4200

/** Volume of a shot measure */
#define VOLUME_SHOT      100

/** Volume of a standard wine glass */
#define VOLUME_WINE      750

/** Volume of a standard flute glass */
#define VOLUME_FLUTE     750

/** Volume of a standard wine bottle */
#define VOLUME_WINEBOTTLE  3100

/** Volume of a standard brandy glass */
#define VOLUME_BRANDY    1450

/** Volume of a standard tumbler */
#define VOLUME_TUMBLER   1350

/** Volume of a standard cocktail glass */
#define VOLUME_COCKTAIL  750

/** Volume of a standard teacup */
#define VOLUME_TEACUP    960

/** Volume of a standard mug */
#define VOLUME_MUG       1450

#endif
// --- END [/mnt/home2/grok/lib/include/volumes.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/living.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/living.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
767 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/living.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__LIVING
/** @ignore yes */
#define __SYS__LIVING

/** The property used to determing if someone is passed out. */
#define PASSED_OUT "passed out"
#define TRANCE "trance"
#define UNKNOWN_MOVE "unknown move"
#define RUNNING_MOVE "running move"
#define MAX_INVEN 10
#define MAX_CREATOR_INVEN 25
#define WILL_POWER 338
#define MIN_TIMES 20
#define GP_ADVANCE_MOD 5

#define OUT_COLD 1
#define ASLEEP 2

/**
 * This is the class used for nationality data.
 * @member nationality the path to the nationality object
 * @member region the region specialisation for the nationality
 * @member data any extra data associated with the nationality
 */
class living_nationality {
   string nationality;
   string region;
   mixed data;
}

#endif /* __SYS__LIVING */
// --- END [/mnt/home2/grok/lib/include/living.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/applications.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/applications.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
711 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/applications.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630142   Available: 13577496
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 *  Applications 
 *  @author Drakkos
 *  @started 31/01/2003
 *
 */
 
#ifndef __APPLICATIONS_H
#define __APPLICATIONS_H

#define APPLICATIONS_HANDLER "/obj/handlers/applications_handler"
#define APPLY_COMMAND "/cmds/player/apply"
#define APPLY_SAVE_FILE "/save/applications"


#define MINUTE 60
#define HOUR (60 * MINUTE)
#define DAY (24 * HOUR)

class application {
  string type;
  string name;
  string text;
  mapping vouches;
  int time;
  string domain;


}

class application_type {
  string type; 
  string board;
  string *questions;
  int vouches_required;
  int gl_requirement;
  int qp_requirement;
  int age_requirement;
  int timeout;
  string intro_text;
  string responsibility;
} 

#endif
// --- END [/mnt/home2/grok/lib/include/applications.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/monster.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/monster.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
157 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/monster.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__MONSTER
#define __SYS__MONSTER

#define RACE_OB "/std/race"
#define MONSTER_HAND "/obj/handlers/monster_handler"

#endif /* __SYS__MONSTER */
// --- END [/mnt/home2/grok/lib/include/monster.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/player_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/player_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
802 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/player_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main include file for the player handler.
 * @see /obj/handlers/player_change
 * @author Pinkfish
 */
#ifndef __PLAYER_HANDLER_H
/** @ignore yes */
#define __PLAYER_HANDLER_H

/**
 * The define for the location of the player handler.
 */
#define PLAYER_HANDLER "/obj/handlers/player_handler"

/**
 * The directory under the player save directory in which to put the
 * deleted files.
 */
#define DELETE_DIR "delete"

/**
 * The directory under the player save directory in which to put the
 * players who are deleted pending appeal.
 */
#define APPEAL_DIR "appeal"

/**
 * The directory in which to put the player save files.
 */
#define PLAYER_SAVE_DIR "/save/players/"

#define PLAYER_RAM_DIR "/save/ramdisk/players/"

/**
 * The banish directory
 */
#define BANISH_DIR "/banish/"

#endif
// --- END [/mnt/home2/grok/lib/include/player_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/forn.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/forn.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
10434 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/forn.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630141   Available: 13577495
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 *  Forn include file
 *  @author Drakkos
 *  @stared 28/11/2000
 */


#ifndef __FORN_H
#define __FORN_H

/* Domain define */
 
#define FORN                   "/d/forn/"

/* General defines */

#define CHARS                  FORN + "chars/" 
#define DOCS                   FORN + "docs/"
#define FORN_INCLUDE           FORN + "include/"
#define HANDLERS               FORN + "handlers/"
#define INHERITS               FORN + "inherits/"
#define HOSPITAL_DIR           FORN + "hospital/"
#define IDEAS                  FORN + "ideas/"
#define ITEMS                  FORN + "items/"
#define LOG                    FORN + "log/"
#define SECURE                 FORN + "secure/"
#define UTILS                  FORN + "utils/"
#define WEB                    FORN + "public_html/"
#define EFFECTS                FORN + "effects/"

/* Save file defines */

#define SAVE_DIR               "/save/"
#define SAVE                   SAVE_DIR + "forn/"

/* Area defines */

#define GENUA                  FORN + "genua/"

/* Miscellaneous defines */

#define POLICY                 DOCS + "policy/"
#define HELP                   DOCS + "help_files/"
#define SCRIPTS                DOCS + "scripts/"
#define WARGAME_MAPS           DOCS + "wargame_maps/"

/* Genua defines */

#define GENUA_CHARS            GENUA + "chars/"
#define GENUA_CITY             GENUA + "genua_city_dev/"
#define GENUA_EFFECTS          GENUA + "effects/"
#define GENUA_HANDLERS         GENUA + "handlers/"
#define GENUA_HOUSING          GENUA + "player_housing/"
#define GENUA_INHERITS         GENUA + "inherits/"
#define GENUA_ITEMS            GENUA + "items/"
#define GENUA_PLAYER_HOUSING   GENUA + "player_housing/"
#define GENUA_PLAYER_HOUSING   GENUA + "player_housing/"
#define GENUA_ROGUE_ENCAMPMENT GENUA + "rogue_encampment/"
#define GENUA_SHADOWS          GENUA + "shadows/"
#define GENUA_SLEEPING_CASTLE  GENUA + "sleeping_castle/"
#define GENUA_SWAMP            GENUA + "swamp/"
#define GENUA_VILLAGES         GENUA + "villages/"
#define GENUA_YELLOW_ROAD      GENUA + "yellow_brick_road/"
#define GENUA_BANKER           GENUA_INHERITS + "coffee_nostra_banker"
#define GENUA_BASE             GENUA_INHERITS + "genua_base"
#define GENUA_CITIZEN          GENUA_INHERITS + "protected_npc"
#define GENUA_CAPO             GENUA_INHERITS + "capo_inherit"
#define GENUA_CITYROOM         GENUA_INHERITS + "cityroom"
#define GENUA_CITY_GUARD       GENUA_INHERITS + "city_guard"
#define GENUA_COMMERCE         GENUA_INHERITS + "genua_commerce"
#define GENUA_CONSIGLIERE      GENUA_INHERITS + "consigliere"
#define GENUA_GENERAL_SHOP     GENUA_INHERITS + "genua_general_shop"
#define GENUA_HOTEL_INSIDE     GENUA_INHERITS + "genua_hotel_inside"
#define GENUA_HOTEL_OUTSIDE    GENUA_INHERITS + "genua_hotel_outside"
#define GENUA_INNER_RING       GENUA_INHERITS + "genua_inner_ring"
#define GENUA_INSIDE_ROOM      GENUA_INHERITS + "genua_inside_room"
#define GENUA_ITEM_SHOP        GENUA_INHERITS + "genua_item_shop"
#define GENUA_MAFIA_HOOD       GENUA_INHERITS + "coffee_nostra_hood"
#define GENUA_MAFIA_INHERIT    GENUA_INHERITS + "mafia_inherit"
#define GENUA_MARKET_INHERIT   GENUA_INHERITS + "genua_market_inherit"
#define GENUA_MONEYCHANGER     GENUA_INHERITS + "genua_bureau_de_change"
#define GENUA_MONSTER          GENUA_INHERITS + "genua_monster"
#define GENUA_OUTER_RING       GENUA_INHERITS + "genua_outer_ring"
#define GENUA_OUTSIDE_ROOM     GENUA_INHERITS + "genua_outside_room"
#define GENUA_PLAYER_HOUSE     GENUA_INHERITS + "genua_player_house"
#define GENUA_PLAYER_HOUSE_OUTSIDE GENUA_INHERITS + "genua_player_house_outside"
#define GENUA_PUB              GENUA_INHERITS + "genua_pub"
#define GENUA_PUB_OUTSIDE      GENUA_INHERITS + "genua_pub_outside"
#define GENUA_SOLDIER          GENUA_INHERITS + "genua_soldier"
#define GENUA_WATCH_INHERIT    GENUA_INHERITS + "watch_house"
#define GRAVEYARD_INHERIT      GENUA_INHERITS + "graveyard_inherit"
#define MURDER_SUSPECT         GENUA_INHERITS + "murder_suspect"

/* Handler directory defines */

#define CRIME_HANDLER_DIR      GENUA_HANDLERS + "ledger/"
#define PUNISHMENT_HANDLER_DIR GENUA_HANDLERS + "punishment/"
#define SERVICE_HANDLER_DIR    PUNISHMENT_HANDLER_DIR + "service/"

/* Genua Village Areas */

#define BOIS                   GENUA_VILLAGES + "bois/"

/* Bois Defines */

#define BOIS_BEARS_HOUSE       BOIS + "bears_house/"
#define BOIS_GRANDMA           BOIS + "grandma/"
#define BOIS_LAKE              BOIS + "lake/"
#define BOIS_MAIN_ROAD         BOIS + "main_road/"
#define BOIS_THREE_PIGS        BOIS + "three_pigs/"
#define BOIS_VILLAGE           BOIS + "village/"
#define BOIS_CHARS             GENUA_CHARS + "bois/"


/* Genua city areas */

#define BLACK_MARKET           GENUA_CITY + "black_market/"
#define CALYPSO_STREET         GENUA_CITY + "calypso_street/"
#define CARREFOUR_CRESCENT     GENUA_CITY + "carrefour_crescent/"
#define CITY_LIBRARY           GENUA_CITY + "city_library/"
#define COFFEE_NOSTRA_ROOM     GENUA_CITY + "coffee_nostra/"
#define DARLING_ROAD           GENUA_CITY + "darling_road/"
#define DAUPHIN_STREET         GENUA_CITY + "dauphin_street/"
#define DEAD_MANS_WALK         GENUA_CITY + "dead_mans_walk/"
#define DIAMOND_CRESCENT       GENUA_CITY + "diamond_crescent/"
#define DOLMEN_WALK            GENUA_CITY + "dolmen_walk/"
#define FELICITY_AVENUE        GENUA_CITY + "felicity_avenue/"
#define FLORIN_AVENUE          GENUA_CITY + "florin_avenue/"
#define GENUA_AVENUE           GENUA_CITY + "genua_avenue/"
#define GENUA_BARRACKS         GENUA_CITY + "barracks/"
#define GENUA_CASINO           GENUA_CITY + "genua_casino/"
#define GENUA_CITY_PARK        GENUA_CITY + "genua_city_park/"
#define GENUA_DOCKS            GENUA_CITY + "genua_docks/"
#define GENUA_GRAVEYARD        GENUA_CITY + "graveyard/"
#define GENUA_HAUNTED_HOUSE    GENUA_CITY + "haunted_house/"
#define GENUA_HOTEL            GENUA_CITY + "genua_hotel/"
#define GENUA_KICK_CONSORTIUM  GENUA_CITY + "kick_consortium/"
#define GENUA_MAIN_GATE        GENUA_CITY + "main_gate/"
#define GENUA_MARKET           GENUA_CITY + "genua_market/"
#define GENUA_PALACE           GENUA_CITY + "genua_palace/"
#define GENUA_RACETRACK        GENUA_CITY + "genua_racetrack/"
#define GENUA_SMUGGLERS_COVE   GENUA_CITY + "smugglers_cove/"
#define GENUA_WEDDING_CHAPEL   GENUA_CITY + "wedding_chapel/"
#define GOLDEN_KEY_CRESCENT    GENUA_CITY + "golden_key_crescent/"
#define GRIM_STREET            GENUA_CITY + "grim_street/"
#define HOUSE_OF_MUSIC         GENUA_CITY + "house_of_music/"
#define LACHAISE_ROAD          GENUA_CITY + "lachaise_road/"
#define LADY_BROOK_STREET      GENUA_CITY + "lady_brook_street/"
#define LIQUOR_ALLEY           GENUA_CITY + "liquor_alley/"
#define LOVERS_WALK            GENUA_CITY + "lovers_walk/"
#define MARKET_STREET          GENUA_CITY + "market_street/"
#define MINARET_STREET         GENUA_CITY + "minaret_street/"
#define NAWLINS_ROAD           GENUA_CITY + "nawlins_road/"
#define OKRA_AVENUE            GENUA_CITY + "okra_avenue/"
#define PARADISE_CRESCENT      GENUA_CITY + "paradise_crescent/"
#define PIRATE_AVENUE          GENUA_CITY + "pirate_avenue/"
#define QUEENS_DRAG            GENUA_CITY + "queens_drag/"
#define ROYAL_AVENUE           GENUA_CITY + "royal_avenue/"
#define RUE_EPHEBE             GENUA_CITY + "rue_ephebe/"
#define SAMEDI_CRESCENT        GENUA_CITY + "samedi_crescent/"
#define SAPPHIRE_STREET        GENUA_CITY + "sapphire_street/"
#define SAVANNAH_ROAD          GENUA_CITY + "savannah_road/"
#define SEWERS                 GENUA_CITY + "sewers/"
#define TACTICUS_ACADEMY       GENUA_CITY + "tacticus_academy/"
#define TACTICUS_ROAD          GENUA_CITY + "tacticus_road/"
#define TCHUTTIFRUITTI_STREET  GENUA_CITY + "tchuttifruitti_street/"
#define TRADE_STREET           GENUA_CITY + "trade_street/"
#define YAGA_CRESCENT          GENUA_CITY + "yaga_crescent/"
#define VIEUX_PROMENADE        GENUA_CITY + "vieux_promenade/"
#define VOODOO_LANE            GENUA_CITY + "voodoo_lane/"
#define WATCH_HOUSE            GENUA_CITY + "watch_house/"
#define ZOMBIE_WALK            GENUA_CITY + "zombie_walk/"

/* Liquor Alley Pubs */

#define ABSINTHE_HOUSE         LIQUOR_ALLEY + "absinthe_house/"
#define BAYOU_BOURBON          LIQUOR_ALLEY + "bayou_bourbon/"
#define DAIQUIRY_DELIGHTS      LIQUOR_ALLEY + "daiquiry_delights/"
#define LA_MAISON_LIQUOR       LIQUOR_ALLEY + "la_maison_liquor/"
#define LADY_BROOK_LIQUOR      LIQUOR_ALLEY + "lady_brook_liquor/"
#define MADAME_DELIGHT         LIQUOR_ALLEY + "madame_delight/"
#define SALUT                  LIQUOR_ALLEY + "salut/"

/* Specific domain object defines */

#define BROCHURE               IDEAS + "brochure_text/"     
#define CALYPSO_FLOWER_HANDLER (GENUA_HANDLERS + "calypso_blooms")
#define CASTLE_HANDLER         (GENUA_HANDLERS + "sleeping_castle_handler")
#define CHIVALRY_HANDLER       (GENUA_HANDLERS + "chivalry")
#define COMMON_ROOM            (FORN + "common")
#define GENUA_DOCKS_HANDLER    (GENUA_HANDLERS + "genua_docks_handler")
#define GENUA_EMBASSY          UTILS + "embassy/"
#define COFFEE_RUN             (GENUA_EMBASSY + "coffee_run/")
#define GENUA_HANDLER          (GENUA_HANDLERS + "general_genua_handler")
#define GENUA_LEDGER           (CRIME_HANDLER_DIR + "genua_ledger")
#define HAUNTING_HANDLER       (GENUA_HANDLERS + "haunting_handler")
#define COFFEE_NOSTRA          (GENUA_HANDLERS + "coffee_nostra")
#define INVENTORY              (GENUA_HANDLERS + "inventory_handler")
#define HOSPITAL               (HOSPITAL_DIR + "hospital")
#define INTERVIEW_ROOM         (UTILS + "interview")
#define ODD_JOBS               (GENUA_HANDLERS + "odd_jobs")
#define PACKAGE                (INHERITS + "package_inherit")
#define PEER_REVIEW            (HANDLERS + "peer_review")
#define PLAYTESTING_ROOM       (UTILS + "playtesting")
#define RUMOUR_MILL            (HANDLERS + "rumour_mill")
#define MURDER_MYSTERY         (GENUA_HANDLERS + "murder_mystery")
#define PRISON_CELL            (WATCH_HOUSE + "cell")
#define SCRIPT_INHERIT         (INHERITS + "scripting")
#define SPECIAL_INTEREST       (HANDLERS + "special_interest")
#define TRAINABLE_PET          (INHERITS + "trainable_pet")
#define WEB_HANDLER            (WEB + "misc/web_handler")
#define WHITEBOARD             (INHERITS + "whiteboard")

/* Some other stuff */

#define GENUA_DOLLAR 300
#define GENUA_CENT (GENUA_DOLLAR / 100)
#define GENUA_FORIN (GENUA_DOLLAR * 10)

#endif
// --- END [/mnt/home2/grok/lib/include/forn.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/assert.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/assert.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630138   Available: 13577492
Inodes: Total: 5242880    Free: 4960136
59 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/assert.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630138   Available: 13577492
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define assert(x) if(!(x)) error("assertion failed: " +#x)
// --- END [/mnt/home2/grok/lib/include/assert.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/tune.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/tune.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630138   Available: 13577492
Inodes: Total: 5242880    Free: 4960136
894 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/tune.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630138   Available: 13577492
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__TUNE
#define __SYS__TUNE

/* TIME_BETWEEN_HEAL is scaling factor to speed or slow the rate of healing. */

#define TIME_BETWEEN_HEAL 5

/* minimum time between guild changes - obsolete currently*/

#define MIN_TIME 2*60*60*60   

/* tuning for cost of advanncing in guilds.  STD_COST is a base and LEVEL_DIV
   is a gradient factor.  Increasing STD_COST makes skills more expensive and
   decreasing LEVEL_DIV will increase the rate at which the skills increase in
   cost.  LEVEL_DIV of 3 gives a rate of 1/3 */

#define STD_COST 125
#define LEVEL_DIV 3
#define DEFAULT_COST 10
#define COST_DIV 20

/*
 * The time_div define is how many xp per time unit is used in teaching 
 * skills.  This affects how long it takes to learn a skill.
 */
#define TIME_DIV 300

/*
 * Er, stuff to do with broadcast
 */
#define MAX_AL 10000
#define SHOUT_DISTANCE 1000

#endif /* __SYS__TUNE */
// --- END [/mnt/home2/grok/lib/include/tune.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/security.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/security.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630137   Available: 13577491
Inodes: Total: 5242880    Free: 4960136
155 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/security.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630137   Available: 13577491
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS_SECURITY_H
#define __SYS_SECURITY_H

#define SECURITY "/secure/security"
#define ACCESS "/std/basic/security"

#endif /* __SYS_SECURITY_H */
// --- END [/mnt/home2/grok/lib/include/security.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/dates.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/dates.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630137   Available: 13577491
Inodes: Total: 5242880    Free: 4960136
1161 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/dates.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630137   Available: 13577491
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* Use of month:  define+day, e.g.  JUNE+6 gives June 6th
 */
#define OFFLE -1       /* has 2-31, the first is hogswatch/crueltide */
#define FEBRUARY 30    /* has 1-30 */
#define MARCH 60       /* has 1-31 */
#define APRIL 91       /* has 1-31 */
#define MAY 122        /* has 1-31 */
#define JUNE 153       /* has 1-30 */
#define GRUNE 183      /* has 1-31 except 17, which is midsummer/small gods eve */
#define AUGUST 214     /* has 1-31 except 23, which is soul cake tuesday */
#define SPUNE 245      /* has 1-31 */
#define SEKTOBER 276   /* has 2-30, the first is sektober fools' day */
#define EMBER 306      /* has 1-31 */
#define DECEMBER 337   /* has 1-31 */
#define ICK 368        /* has 1-31 */

/* Special days
 */
#define HOGSWATCH 0
#define SMALLGODS 200
#define SOULCAKE 237
#define SEKTOBERFOOL 277
/* university terms
 * These tend to bear up with the theory that soul cakes and hogswatch
 * are the "same", just in different 'agricultural' years
#define OCTINITY    ?00
#define ROTATION    ?00
#define BACKSPINDLE ?00
#define HOGSWATCH   ?00
#define EVELYN      ?00
#define MICKLEMOTE  ?00
#define CANDLERENT  ?00
#define SOULCAKES   ?00
 */
// --- END [/mnt/home2/grok/lib/include/dates.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/language.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/language.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630136   Available: 13577490
Inodes: Total: 5242880    Free: 4960136
3543 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/language.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630136   Available: 13577490
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the file that contains the language bits needed for dealing with
 * languages.  This is for reading and so on too.
 * @author Pinkfish
 * @started in 1992 sometime
 */
#ifndef __SYS__LANGUAGE
/** @ignore yes */
#define __SYS__LANGUAGE

/** @ignore yes */
#define LANGUAGES "/obj/handlers/languages"
/**
 * The language handler.
 */
#define LANGUAGE_HAND "/obj/handlers/languages"
/**
 * The default language inheritable used in all languages so the interface
 * is consistent.
 */
#define LANGUAGE_INHERIT "/std/languages/language_inherit"

/**
 * Flag to specify that this language can be spoken.
 */
#define L_SPOKEN 1
/**
 * Flag to specify that this language can be written.
 */
#define L_WRITTEN 2
/**
 * Flag to specify that this language can be used over a distance (ie:
 * tells and shouts).
 */
#define L_DISTANCE 4
/**
 * Flag to specify that this language is magic language!  We handle these
 * somewhere differently to a normal language.
 */
#define L_MAGIC 8
/**
 * Flag to specify that the language is sized.
 */
#define L_SIZED 16
/**
 * Flag to specify that the language is always able to be spoken.
 */
#define L_ALWAYS_SPEAK 32

/**
 * The first element of the read array, the message itself.
 */ 
#define READ_MESS 0
/**
 * The first element of the read array, the message itself.
 */
#define READ_STR 0
/**
 * The second element of the read array, this is the type.  The type is
 * something like 'red splotched ink' or whatever.  It can be 0.
 */
#define READ_TYPE 1
/**
 * The third element of the read array is the language the message is written
 * in.  The language must exist and must be non-zero.
 */
#define READ_LANG 2
/**
 * The fourth element of the read array is the size of the text.  This is used
 * to make sure not too much stuff can be printed on any one page.
 */
#define READ_SIZE 3

/**
 * This is used to tag the transformation type as a say.
 * This is used inside the language inheritable to tag what type of
 * transformation is being done on the text. 
 */
#define SAY_TYPE "say"
/**
 * This is used to tag the transformation type as a whisper.
 * This is used inside the language inheritable to tag what type of
 * transformation is being done on the text. 
 */
#define WHISPER_TYPE "whisper"
/**
 * This is used to tag the transformation type as a shout.
 * This is used inside the language inheritable to tag what type of
 * transformation is being done on the text. 
 */
#define SHOUT_TYPE "shout"
/**
 * This is used to tag the transformation type as a tell.
 * This is used inside the language inheritable to tag what type of
 * transformation is being done on the text. 
 */
#define TELL_TYPE "tell"

/**
 * The start part of the languages skill tree.
 */
#define LANGUAGE_SKILL_START "other.language."
/**
 * The name of the spoken skill bit.
 */
#define SPOKEN_SKILL "spoken"
/**
 * The name of the written skill bit.
 */
#define WRITTEN_SKILL "written"

/* These are used by the say and lsay commands */
/** There is no text to say.  THis is used by the speech commands. */
#define NO_MESSAGE 0
/** The specific language is not spoken.  This is used by the speech commands. */
#define NOT_SPOKEN 1
/** The specific language is not known by the speaker.  This is used by the speech commands. */
#define NOT_KNOWN 2
/** The specific language is not allowed to be used at a distance.  This is used by the speech commands. */
#define NOT_DISTANCE 3
/** The whole message was just fine.  This is used by the speech commands. */
#define MESSAGE_OK 4
#endif /* __SYS__LANGUAGE */
// --- END [/mnt/home2/grok/lib/include/language.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ac_callback.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ac_callback.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
831 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ac_callback.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/** 
 * This file contains the classes and defines used in the 
 * armour call back system. 
 */ 

#ifndef __SYS__AC_CALLBACK
/** @ignore yes */ 
#define __SYS__AC_CALLBACK


/** 
 * This class stores armour class call back data.
 * @member ob the object that owns the callback.
 * @member id the callback id, used to remove it.
 * @member func the function called when it is triggered. (either 
 * evaluated if it is a function pointer, or call_other()'d if it 
 * is an array in the format ({ object, function }) 
 * @member priority an integer indicating the priority of the call back,
 * functions with a higher priority are evaluated first.
 * @member extra any extra data.
 */ 
class ac_callback_data { 
    object ob; 
    int id; 
    function func;
    int priority; 
    mixed extra; 
}
#endif /* __SYS__AC_CALLBACK */ 

// --- END [/mnt/home2/grok/lib/include/ac_callback.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/weezent.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/weezent.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
517 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/weezent.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define WEEZENT                "/d/sur/Weezent/"

#define BETWEENS               WEEZENT +"betweens/"
#define UNIQUES                WEEZENT +"uniques/"

#define GRFLX_NEST             WEEZENT +"grflx_nest/"
#define UNDER_WELL             WEEZENT +"under_well/"
#define VILLAGE                WEEZENT +"village/"

#define CHARS                  WEEZENT +"chars/"
#define ITEMS                  WEEZENT +"items/"
#define UTILS                  WEEZENT +"utils/"

#define HOSPITAL               ( WEEZENT +"hospital" )
// --- END [/mnt/home2/grok/lib/include/weezent.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/virtual_room.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/virtual_room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
227 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/virtual_room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630135   Available: 13577489
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__VIRTUAL_ROOM
#define __SYS__VIRTUAL_ROOM

#include <virtual.h>

#define FLAG 0
#define DELAY 1
#define CLONE 2
#define MESS 3
#define REMOVABLE 0
#define FIXED 1
#define UNIQUE 2
#endif /* __SYS__VIRTUAL_ROOM */
// --- END [/mnt/home2/grok/lib/include/virtual_room.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/armoury.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/armoury.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
1148 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/armoury.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for all the armoury stuff.
 * @author Pinkfish
 */
#ifndef __SYS__ARMOURY
#define __SYS__ARMOURY

/**
 * The path to the armour.
 */
#define ARMOURY "/obj/handlers/armoury"
/**
 * The property to use for no recycling.
 */
#define ARMOURY_NO_RECYCLING_PROP "no recycling"
/**
 * The property to use for finding the recycling area of the object.
 */
#define ARMOURY_RECYCLING_AREA_PROP "recycling area"

#ifdef UNUSED
/* comment this rubbish out.  Not needed any more I think? */
#define ARM_A_SIZE 15
#define A_OBJ 0
#define A_ANAME 1
#define A_ALIAS 2
#define A_PLURALS 3
#define A_ADJ 4
#define A_SHORT 5
#define A_LONG 6
#define A_WEIGHT 7
#define A_VALUE 8
#define A_COND 9
#define A_CHANCE 10
#define A_ATYPE 11
#define A_DEX_MINUS 12
#define A_ARMOURS 13
#define A_IMMUNE 14
/* weapons junk... */

#define WEAP_A_SIZE 14
#define W_OBJ 0
#define W_NAME 1
#define W_ALIAS 2
#define W_PLURALS 3
#define W_ADJ 4
#define W_SHORT 5
#define W_LONG 6
#define W_WEIGHT 7
#define W_VALUE 8
#define W_COND 9
#define W_DAM_CHANCE 10
#define W_SKILL 11
#define W_ATTACKS 12
#define W_UNDAMAGE 13
#endif

#endif /* __SYS__ARMOURY */
// --- END [/mnt/home2/grok/lib/include/armoury.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/board_master.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/board_master.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
1014 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/board_master.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define MAX_PAGE ((int)this_player()->query_rows()-3)
#define TP_NAME this_player()->query_name()
/* this will be a handler object... */
#define SAVE_FILE "/w/pinkfish/save/board_master"
#define BOARD_THING "/w/pinkfish/getter_master"
#define REV_BOARD "/w/pinkfish/reversi_rules"

/* used by the board getter */
#define REVERSI_OB "/w/pinkfish/board_master"
#define BOARD_PATH "/w/pinkfish/save/master/"

/* should be two weeks */
#define MIN_TIME (60*60*24*14)

#undef DEBUG
#undef DEBUG2

#define MAX_GAMES 10

#define R_PLAYER1 0
#define R_PLAYER2 1
/* This is a board number.  A offset to the board save file.
 */
#define R_BOARD 2
#define R_MOVE_NO 3
/* last move.  Saved for timeouts. */
#define R_LAST 4
#define R_LASTX 5
#define R_LASTY 6
#define R_TYPE 7

#define BOARD_COL "%^B_GREEN%^%^WHITE%^"
#define BLACK_COL "%^B_BLACK%^"
#define WHITE_COL "%^B_WHITE%^"
#define END_TILE  "%^B_GREEN%^"
#define RESET     "%^RESET%^"
#define SETUP_COL "%^B_CYAN%^"

#define P1_WON 1
#define P2_WON 2
#define DRAW 3
// --- END [/mnt/home2/grok/lib/include/board_master.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/parser.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
144 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630134   Available: 13577488
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef _PARSER_H
#define _PARSER_H

#include <tokenise.h>

#define PARSER "/global/parser"
#define TOKENISER "/obj/handlers/tokeniser"

#endif
// --- END [/mnt/home2/grok/lib/include/parser.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/expressions.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/expressions.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630133   Available: 13577487
Inodes: Total: 5242880    Free: 4960136
2116 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/expressions.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630133   Available: 13577487
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file to go with the expression handler.  You may need to use
 * the define EXPRESSION_NO_CLASSES to stop clashes occuring from includeing
 * this file into something which inherits the basic expressions file.
 * @see /std/basic/expresssions.c
 * @author Pinkfish
 * @started Mon May  8 17:01:14 PDT 2000
 */
#ifndef __EXPRESSIONS_H
/** @ignore yes */
#define __EXPRESSIONS_H

/** An integer type. */
#define EXPRESSION_TYPE_INTEGER  1
/** A string type. */
#define EXPRESSION_TYPE_STRING   2
/** An opaque array type, cannot get at the internal bits. */
#define EXPRESSION_TYPE_ARRAY    3
/** A mapping type. */
#define EXPRESSION_TYPE_MAPPING  4
/** A float type. */
#define EXPRESSION_TYPE_FLOAT    5
/** An operator type. */
#define EXPRESSION_TYPE_OPERATOR 6
/** A boolean type. */
#define EXPRESSION_TYPE_BOOLEAN  7
/** A variable type. */
#define EXPRESSION_TYPE_VARIABLE 8
/** A money type. */
#define EXPRESSION_TYPE_MONEY    9
/** A functionm type. */
#define EXPRESSION_TYPE_FUNCTION 10
/**
 * A special type, this is type (and above this) that should be used by
 * the inheriables if they wish to define special types of controls.
 */
#define EXPRESSION_TYPE_SPECIAL  11
/** A function arguement type. */
#define EXPRESSION_TYPE_FUNCTION_VARIABLE 12
/** A user defined function. */
#define EXPRESSION_TYPE_USER_FUNCTION 13
/** An object type. */
#define EXPRESSION_TYPE_OBJECT   14
/** A null array.  This is typeless, sort of. */
#define EXPRESSION_TYPE_ARRAY_NULL   15
/** This is the amount added to a type to get the array equivilant of it. */
#define EXPRESSION_TYPE_ARRAY_OFFSET  20
/** The error type. */
#define EXPRESSION_TYPE_ERROR    -1

#ifndef EXPRESSION_NO_CLASSES
/**
 * The class used to hold information about both expression nodes and
 * evaluated data.  The type is one of the types above and the value is
 * dependant on the type.
 * @element type the type of the data
 * @element value the value of the data
 * @element tree if we need to make a tree for short circuit evaluation
 */
class parse_node {
   int type;
   mixed value;
   mixed* tree;
}
#endif

#endif
// --- END [/mnt/home2/grok/lib/include/expressions.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/newudp.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/newudp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630133   Available: 13577487
Inodes: Total: 5242880    Free: 4960136
1915 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/newudp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630133   Available: 13577487
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__NEWUDP
#define __SYS__NEWUDP

#ifndef __NEWUDP_H
#define __NEWUDP_H
/* --- User Configuration. --- */

#ifdef __UDP_H
#define NEW_INETD "/net/intermud/inetd"
#else
#define INETD		"/net/intermud/inetd"
#endif
#define UDP_CMD_DIR	"/net/intermud/udp/"
#define HOST_FILE	"/net/intermud/adm/INETD_HOSTS"
#define INETD_LOG_FILE	"INETD"

#define REPLY_TIME_OUT	12
#define RETRIES		2

/* #define LOCAL_NAME	SECURITY->get_mud_name()	// CD */
#define LOCAL_NAME	MUD_NAME

/* #define LOCAL_UDP_PORT	SECURITY->do_debug("udp_port");  // CD */
/* #define LOCAL_UDP_PORT	query_imp_port() */
#define LOCAL_UDP_PORT 5756

#define INETD_DIAGNOSTICS

/* If you are running another intermud system concurrently and there is a
 * clash with the udp.h filename, rename the old udp.h file as appropriate
 * and include this line. */
/* #include <cdudp.h>	// CD */

/* Include these definitions for CD muds. */
/* #define CDLIB */
/* #define CD_UDP		"/d/Standard/obj/udp" */

/* --- End of config. --- */

#define INETD_VERSION	"0.61"

/* --- Standard header macros. --- */

#define RECIPIENT	"RCPNT"
#define REQUEST		"REQ"
#define SENDER		"SND"
/* The DATA field should be used to store the main body of any packet. */
#define DATA		"DATA"

/* These headers are reserved for system use only. */
#define HOST		"HST"
#define ID		"ID"
#define NAME		"NAME"
#define PACKET		"PKT"
#define UDP_PORT	"UDP"
#define SYSTEM		"SYS"

/* Reserved headers for diagnostics. */
#define PACKET_LOSS	"PKT_LOSS"
#define RESPONSE_TIME	"TIME"

/* --- Standard REQUEST macros. --- */

#define PING		"ping"
#define QUERY		"query"
#define REPLY		"reply"

/* --- Standard SYSTEM macros. --- */
#define TIME_OUT	"TO"

/* --- Index macros for host arrays. --- */

#define HOST_NAME	0
#define HOST_IP		1
#define HOST_UDP_PORT	2
#define LOCAL_COMMANDS	3
#define HOST_COMMANDS	4
#define HOST_STATUS	5

#endif /* __NEWUDP_H */

#endif /* __SYS__NEWUDP */
// --- END [/mnt/home2/grok/lib/include/newudp.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/housing.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/housing.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630132   Available: 13577486
Inodes: Total: 5242880    Free: 4960136
1122 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/housing.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630132   Available: 13577486
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file to deal with player housing.
 * @author Ceres
 */
#ifndef __SYS__HOUSING
/** @ignore yes */
#define __SYS__HOUSING

/** The location of the housing handler.  */
#define HOUSING "/obj/handlers/housing"
/** The location of the rental agreement. */
#define AGREEMENT "/obj/misc/agreement"
/** The location of the housing owners guide. */
#define BOOK "/obj/misc/home_owners_guide"

// These are the house ownership types.
/** Define the house ownership type as being a sale. */
#define SALE 0
/** Define the house ownership type as being a rental. */
#define RENT 1
/** Define the house ownership type as being a leasehold */
#define LEASE 2

// These are the ownership timeouts

// 1 discworld year
/** The amount of time for the owner to time out. */
#define OWNER_TIMEOUT 11520000
// 6 discworld months
/** The amount of time for the renter to time out. */
#define RENTER_TIMEOUT  5760000
// 2 discworld years
/** The default length of a lease. */
#define DEFAULT_LEASE 23040000

#define GET_COMMANDS ({"get", "take", "drag", "palm", "gather", "order", "grab", "ask"})

#endif /* __SYS__HOUSING */
// --- END [/mnt/home2/grok/lib/include/housing.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/forms.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/forms.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630132   Available: 13577486
Inodes: Total: 5242880    Free: 4960136
214 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/forms.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630132   Available: 13577486
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__FORMS
#define __SYS__FORMS

#define FLG_NEW_LINE 1
#define FLG_TEXT_ONLY 2
#define FLG_TEXT_INVIS 4
/* this one implies text only as well.... */
#define FLG_TEXT_CENTER 10

#endif /* __SYS__FORMS */
// --- END [/mnt/home2/grok/lib/include/forms.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/obj_parser.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/obj_parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630131   Available: 13577485
Inodes: Total: 5242880    Free: 4960136
4353 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/obj_parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630131   Available: 13577485
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * THis is the header file for the object parser.  It is based on some
 * code by Scatter at Dawn Whispers to achive it's parsing.
 * <pre>
 * File name    : newparser.h
 * Creator      : Scatter
 * Creation date: 2000-04-20
 * </pre>
 *                
 * Revision history:
 * Date        Creator   Desc
 * 2000-04-20  Scatter   File created.
 * 2000-05-20  Pinkfish  Modified for Discworld
 */

#ifndef ___OBJ_PARSER_H
/** @ignore yes */
#define ___OBJ_PARSER_H

#ifndef OBJ_PARSER_NO_CLASSES
/**
 * The class used for object matching returns.
 * @entry result the result of the operation
 * @entry objects the objects which were matched or errored on
 * @entry text the text which matched or was errored on
 */
class obj_match
{
   int result;
   object *objects;
   string text;
}

/**
 * This class used to retain context over various invocations of the parser.
 * @entry ordinal the ordinal number to check, ie: 1st, 2nd
 * @entry number_included used with plurals, ie: 2 frogs
 * @entry fraction the fraction of the object to get ie: ({ 1, 20 })
 * @entry ignore_rest a flag set to say that all the rest of the matches
 * are irrelvant
 * @entry him the object corresponding to the him result
 * @entry her the object corresponding to the her result
 * @entry it the object corresponding to the it result
 * @entry plural the objects matching to the 'them' result
 */
class obj_match_context
{
   int ordinal;
   int number_included;
   int* fraction;
   int ignore_rest;
   int no_ambiguous;

   object him;
   object her;
   object it;
   object* plural;
}
#endif

/** The return result was correctly matched. */
#define OBJ_PARSER_SUCCESS         100
/**
 * There was no match on the string in the text field of the obj_match
 * class.
 */
#define OBJ_PARSER_NO_MATCH        315
/**
 * It is too dark to match on the string in the text field of the obj_match
 * class.
 */
#define OBJ_PARSER_TOO_DARK        316
/**
 * It is not possible to do fractional matches on multiple objects.
 * The objects field has the objects it failed to match on and the text it
 * failed to match on.
 */
#define OBJ_PARSER_FRACTION        317
/**
 * The fraction specified is invalid.  The fraction is in the text field of
 * the class.
 */
#define OBJ_PARSER_BAD_FRACTION    318
/**
 * This is only used inside the player objects.  Means that you cannot do
 * remove player actions from this location.
 */
#define OBJ_PARSER_BAD_ENVIRONMENT 319
/**
 * This is only used inside the player object.  It says that the matched
 * objects were not living.
 */
#define OBJ_PARSER_NOT_LIVING      320
/**
 * THis means an ambiguous match was noticed.  An ambiguous match is
 * where 'bag' matches more than one bag and the player did not force
 * it to recognise a specific one.
 */
#define OBJ_PARSER_AMBIGUOUS       322
/**
 * This means that not enough of the specified object were matched.  For
 * example if someone did '5 coins' and only 3 were matched.
 */
#define OBJ_PARSER_NOT_ENOUGH      323

/** The flag to say that the match is a singular id. */
#define OBJ_PARSER_MATCH_SINGULAR 4
/** The flag to say that the match is a plural id. */
#define OBJ_PARSER_MATCH_PLURAL   16

/**
 * The value of the singular parameter, means it matches everything and 
 * ignores failure results.  These are used as flags.
 */
#define OBJ_PARSER_TYPE_EXISTENCE 1
/** Match players.  These are used as flags. */
#define OBJ_PARSER_TYPE_PLAYER    2
/**
 * Allow things like 1 carrots to match.  These are used as flags.
 */
#define OBJ_PARSER_TYPE_SLOPPY_MATCHING 4
/**
 * Disallow nested matching.  These are used as flags.
 */
#define OBJ_PARSER_TYPE_NO_NESTED 8
/**
 * Only match living things.  These are used as flags.
 */
#define OBJ_PARSER_TYPE_LIVING 16

/* Put in by Ceres in an attempt to make the mud work again! */
#define OBJ_PARSER_TYPE_OBJECT 0

/** The index of the match type in the return array. */
#define OBJ_PARSER_MATCH_TYPE     0
/** The index of the objects in the return array. */
#define OBJ_PARSER_OBJECTS        1

/**
 * This property controls if the player will be informed of ambiguous
 * references or not.
 */
#define OBJ_PARSER_AMBIGUOUS_PROP "no ambiguous"
/**
 * This property controls if the player will be use the 'and' keyword as
 * a break or as a regular character.
 */
#define OBJ_PARSER_USE_AND_AS_BREAK_PROP "use and"

#endif
// --- END [/mnt/home2/grok/lib/include/obj_parser.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/pub.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/pub.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
310 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/pub.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__PUB
#define __SYS__PUB

#define SOFTDRINK "softdrink"
#define ALCOHOL   "alcohol"
#define FOOD      "food"

#define DR_TYPE   0
#define DR_COST   1
#define DR_HEAL   2
#define DR_VOLUME 3
#define DR_INTOX  4
#define DR_DRMESS 5
#define DR_OTHMES 6
#define DR_OTHMESS 6


#endif /* __SYS__PUB */
// --- END [/mnt/home2/grok/lib/include/pub.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cpi.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cpi.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
86 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cpi.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PRICE_INDEX "/obj/handlers/cpi_handler"
#define DEFAULT_MARKET "Ankh-Morpork"
// --- END [/mnt/home2/grok/lib/include/cpi.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/terrain.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/terrain.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
227 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/terrain.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630130   Available: 13577484
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__TERRAIN
#define __SYS__TERRAIN

#define TERRAIN_MAP "/obj/handlers/terrain_handler"
#define TERRAIN_LOG "/obj/handlers/terrain_things/logroom"

#define RESTORE_PATH "/save/terrains/"

#endif /* __SYS__TERRAIN */
// --- END [/mnt/home2/grok/lib/include/terrain.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/dirs.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/dirs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630129   Available: 13577483
Inodes: Total: 5242880    Free: 4960136
1934 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/dirs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630129   Available: 13577483
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__DIRS
#define __SYS__DIRS

#define STD_ORDERS ({ \
  "north", ({ -1, 0, 0 }), "south", ({ 1, 0, 0 }), \
  "east", ({ 0, -1, 0 }), "west", ({ 0, 1, 0 }), \
  "northeast", ({ -1, -1, 0 }), "southwest", ({ 1, 1, 0 }), \
  "southeast", ({ 1, -1, 0 }), "northwest", ({ -1, 1, 0 }), \
  "up", ({ 0, 0, -1 }), "down", ({ 0, 0, 1 }) })
#define REL_DIRS ({ \
   "forward", "up ahead", "in front of you", \
   "forward-right", "ahead and to the right", "in front and to your right", \
   "right", "the right", "to your right", \
   "backward-right", "behind you and to the right", "behind you and to your right", \
   "backward", "behind you", "behind you", \
   "backward-left", "behind you and to the left", "behind you and to your left", \
   "left", "the left", "to your left", \
   "forward-left", "ahead and to the left", "in front and to your left" })
#define ABS_FACING ([ \
  "north":8, "northeast":1, \
  "east":2, "southeast":3, \
  "south":4, "southwest":5, \
  "west":6, "northwest":7 ])
#define SHORTEN ([ \
  "north":"n", "south":"s", \
  "east":"e", "west":"w", \
  "northeast":"ne", "southwest":"sw", \
  "southeast":"se", "northwest":"nw", \
  "up":"u", "down":"d", \
  "hubward":"hw", "rimward":"rw", \
  "widdershins":"ws", "turnwise":"tw", \
  "forward":"fw", "forward-right":"fr", \
  "right":"rt", "backward-right":"br", \
  "backward":"bw", "backward-left":"bl", \
  "left":"lt", "forward-left":"fl" ])
#define LENGTHEN ([ \
  "n":"north", "s":"south", \
  "e":"east", "w":"west", \
  "ne":"northeast", "sw":"southwest", \
  "se":"southeast", "nw":"northwest", \
  "u":"up", "d":"down", \
  "hw":"hubward", "rw":"rimward", \
  "ws":"widdershins", "tw":"turnwise", \
  "fw":"forward", "fr":"forward-right", \
  "rt":"right", "br":"backward-right", \
  "bw":"backward", "bl":"backward-left", \
  "lt":"left", "fl":"forward-left" ])

#define EXPAND_EXIT(x) LENGTHEN[x]?LENGTHEN[x]:x

#endif /* __SYS__DIRS */
// --- END [/mnt/home2/grok/lib/include/dirs.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/skills.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/skills.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630129   Available: 13577483
Inodes: Total: 5242880    Free: 4960136
12152 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/skills.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630129   Available: 13577483
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main skills header file.  This contains the skill tree and any bits
 * relating to the skill tree.
 * @author Pinkfish
 * @see /std/skills.c
 * @see /std/living/skills.c
 */
#ifndef __SYS__SKILLS
/** @ignore yes */
#define __SYS__SKILLS

/** The index corresponding to the skill name in the skill array. */
#define SKILL_NAM 0
/** The index corresponding to the skill level in the skill array. */
#define SKILL_LVL 1
/** The index corresponding to the skill exp in the skill array. */
#define SKILL_EXP 2
/** The index corresponding to the array of sub skills in the skill array. */
#define SKILL_BIT 3
/** The size of the skill array. */
#define SKILL_ARR_SIZE 4
/** The skill handling object. */
#define SKILL_OB "/std/skills"
/** The maximum level that you can teach someone else too. */
#define SKILL_MAX_TEACH 600

/*
 * These are used in /std/living/skills.c for the training/learning of skills.
 */
/** @ignore yes */
#define O_SKILL 0
/** @ignore yes */
#define O_NUM 1
/** @ignore yes */
#define O_LVL 2
/** @ignore yes */
#define O_XP 3
/** @ignore yes */
#define O_OTHER_PER 4

/** @ignore yes */
#define STD_SKILLS_COVERT ({ \
        "covert", 0, 0, ({ \
            "stealth", 0, 0, ({ \
                "inside", 0, 0, ({ }), \
                "outside", 0, 0, ({ }), \
                "underwater", 0, 0, ({ }), \
            }), \
            "hiding", 0, 0, ({ \
               "person", 0, 0, ({ }), \
               "object", 0, 0, ({ }), \
            }), \
            "lockpick", 0, 0, ({ \
                "doors", 0, 0, ({ }), \
                "safes", 0, 0, ({ }), \
                "traps", 0, 0, ({ }), \
            }), \
            "manipulation", 0, 0, ({ \
                "palming", 0, 0, ({ }), \
                "passing", 0, 0, ({ }), \
                "sleight-of-hand", 0, 0, ({ }), \
                "stealing", 0, 0, ({ }), \
            }), \
            "casing", 0, 0, ({ \
                "person", 0, 0, ({ }), \
                "place", 0, 0, ({ }), \
            }), \
            "items", 0, 0, ({ \
                "poisons", 0, 0, ({ }), \
                "traps", 0, 0, ({ }), \
                "weapons", 0, 0, ({ }), \
            }), \
            "points", 0, 0, ({ }), \
        }), \
    })

/** @ignore yes */
#define STD_SKILLS_CRAFTS ({ \
        "crafts", 0, 0, ({ \
            "smithing", 0, 0, ({ \
                "gold", 0, 0, ({ }), \
                "silver", 0, 0, ({ }), \
                "black", 0, 0, ({ \
                    "tools", 0, 0, ({ }), \
                    "weapons", 0, 0, ({ }), \
                    "armour", 0, 0, ({ }), \
                }), \
                "gem", 0, 0, ({ \
                    "cutting", 0, 0, ({ }), \
                    "polishing", 0, 0, ({ }), \
                    "setting", 0, 0, ({ }), \
                }), \
                "locks", 0, 0, ({ }), \
            }), \
            "mining", 0, 0, ({ \
                "gem", 0, 0, ({ }), \
                "ore", 0, 0, ({ \
                    "panning", 0, 0, ({ }), \
                }), \
                "mineral", 0, 0, ({ }), \
            }), \
            "hunting", 0, 0, ({ \
                "tracking", 0, 0, ({ }), \
                "fishing", 0, 0, ({ }), \
                "trapping", 0, 0, ({ }), \
                "foraging", 0, 0, ({ }), \
            }), \
            "carpentry", 0, 0, ({ \
                "furniture", 0, 0, ({ }), \
                "coopering", 0, 0, ({ }), \
                "turning", 0, 0, ({ }), \
                "whittling", 0, 0, ({ }), \
            }), \
            "pottery", 0, 0, ({ \
                "forming", 0, 0, ({ \
                    "throwing", 0, 0, ({ }), \
                    "shaping", 0, 0, ({ }), \
                }), \
                "glazing", 0, 0, ({ }), \
                "staining", 0, 0, ({ }), \
                "firing", 0, 0, ({ }), \
            }), \
            "materials", 0, 0, ({ \
                "tanning", 0, 0, ({ }), \
                "leatherwork", 0, 0, ({ }), \
                "weaving", 0, 0, ({ }), \
                "spinning", 0, 0, ({ }), \
                "needlework", 0, 0, ({ }), \
                "dyeing", 0, 0, ({ }), \
            }), \
            "husbandry", 0, 0, ({ \
                "plant", 0, 0, ({ \
                    "edible", 0, 0, ({ }), \
                    "herbal", 0, 0, ({ }), \
                    "milling", 0, 0, ({ }), \
                    "tree", 0, 0, ({ }), \
                }), \
                "animal", 0, 0, ({ \
                    "grooming", 0, 0, ({ }), \
                    "breeding", 0, 0, ({ }), \
                    "slaughtering", 0, 0, ({ }), \
                }), \
            }), \
            "culinary", 0, 0, ({ \
                "cooking", 0, 0, ({ }), \
                "baking", 0, 0, ({ }), \
                "butchering", 0, 0, ({ }), \
                "preserving", 0, 0, ({ }), \
                "brewing", 0, 0, ({ }), \
                "distilling", 0, 0, ({ }), \
            }), \
            "arts", 0, 0, ({ \
                "design", 0, 0, ({ }), \
                "calligraphy", 0, 0, ({ }), \
                "drawing", 0, 0, ({ }), \
                "painting", 0, 0, ({ }), \
                "printing", 0, 0, ({ }), \
                "sculpture", 0, 0, ({ }), \
            }), \
            "music", 0, 0, ({ \
                "instruments", 0, 0, ({ \
                    "percussion", 0, 0, ({ }), \
                    "wind", 0, 0, ({ }), \
                    "stringed", 0, 0, ({ }), \
                    "keyboard", 0, 0, ({ }), \
                    "vocal", 0, 0, ({ }), \
                }), \
                "special", 0, 0, ({ }), \
                "theory", 0, 0, ({ }), \
                "performance", 0, 0, ({ }), \
            }), \
            "points", 0, 0, ({ }), \
        }), \
    })

/** @ignore yes */
#define STD_SKILLS_FAITH ({ \
        "faith", 0, 0, ({ \
            "rituals", 0, 0, ({ \
                "offensive", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "defensive", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "curing", 0, 0, ({ \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "misc", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "special", 0, 0, ({ }), \
            }), \
            "items", 0, 0, ({ \
                "rod", 0, 0, ({ }), \
                "scroll", 0, 0, ({ }), \
            }), \
            "points", 0, 0, ({ }), \
        }), \
    })
/** @ignore yes */
#define STD_SKILLS_FIGHTING ({ \
        "fighting", 0, 0, ({ \
            "combat", 0, 0, ({ \
                "melee", 0, 0, ({ \
                    "sharp", 0, 0, ({ }), \
                    "pierce", 0, 0, ({ }), \
                    "blunt", 0, 0, ({ }), \
                    "unarmed", 0, 0, ({ }), \
                }), \
                "range", 0, 0, ({ \
                    "thrown", 0, 0, ({ }), \
                    "fired", 0, 0, ({ }), \
                }), \
                "parry", 0, 0, ({ \
                    "melee", 0, 0, ({ }), \
                    "range", 0, 0, ({ }), \
                }), \
                "dodging", 0, 0, ({ \
                    "melee", 0, 0, ({ }), \
                    "range", 0, 0, ({ }), \
                }), \
                "special", 0, 0, ({ \
                    "weapon", 0, 0, ({ }), \
                    "unarmed", 0, 0, ({ }), \
                    "tactics", 0, 0, ({ }), \
              }), \
            }), \
            "points", 0, 0, ({ }), \
        }), \
    })
/** @ignore yes */
#define STD_SKILLS_MAGIC ({ \
        "magic", 0, 0, ({ \
            "spells", 0, 0, ({ \
                "offensive", 0, 0, ({ }), \
                "defensive", 0, 0, ({ }), \
                "misc", 0, 0, ({ }), \
                "special", 0, 0, ({ }), \
            }), \
            "methods", 0, 0, ({ \
                "elemental", 0, 0, ({ \
                    "air", 0, 0, ({ }), \
                    "earth", 0, 0, ({ }), \
                    "fire", 0, 0, ({ }), \
                    "water", 0, 0, ({ }), \
                }), \
                "mental", 0, 0, ({ \
                    "animating", 0, 0, ({ }), \
                    "channeling", 0, 0, ({ }), \
                    "charming", 0, 0, ({ }), \
                    "convoking", 0, 0, ({ }), \
                    "cursing", 0, 0, ({ }), \
                }), \
                "physical", 0, 0, ({ \
                    "binding", 0, 0, ({ }), \
                    "brewing", 0, 0, ({ }), \
                    "chanting", 0, 0, ({ }), \
                    "dancing", 0, 0, ({ }), \
                    "enchanting", 0, 0, ({ }), \
                    "evoking", 0, 0, ({ }), \
                    "healing", 0, 0, ({ }), \
                    "scrying", 0, 0, ({ }), \
                }), \
                "spiritual", 0, 0, ({ \
                    "abjuring", 0, 0, ({ }), \
                    "banishing", 0, 0, ({ }), \
                    "conjuring", 0, 0, ({ }), \
                    "divining", 0, 0, ({ }), \
                    "summoning", 0, 0, ({ }), \
                }), \
            }), \
            "items", 0, 0, ({ \
                "held", 0, 0, ({ \
                    "wand", 0, 0, ({ }), \
                    "rod", 0, 0, ({ }), \
                    "staff", 0, 0, ({ }), \
                    "broom", 0, 0, ({ }), \
                }), \
                "worn", 0, 0, ({ \
                    "amulet", 0, 0, ({ }), \
                    "ring", 0, 0, ({ }), \
                }), \
                "scroll", 0, 0, ({ }), \
                "talisman", 0, 0, ({ }), \
            }), \
            "points", 0, 0, ({ }), \
        }), \
    })

/** @ignore yes */
#define STD_SKILLS_OTHER ({ \
        "other", 0, 0, ({ \
            "trading", 0, 0, ({ \
                 "buying", 0, 0, ({ }), \
                 "selling", 0, 0, ({ }), \
                 "valueing", 0, 0, ({ \
                    "gems", 0, 0, ({ }), \
                    "jewellery", 0, 0, ({ }), \
                    "weapons", 0, 0, ({ }), \
                    "armour", 0, 0, ({ }), \
                }), \
            }), \
            "movement", 0, 0, ({ \
                 "swimming", 0, 0, ({ }), \
                 "riding", 0, 0, ({ \
                     "horse", 0, 0, ({ }), \
                     "camel", 0, 0, ({ }), \
                 }), \
                 "climbing", 0, 0, ({ \
                     "tree", 0, 0, ({ }), \
                     "rock", 0, 0, ({ }), \
                     "rope", 0, 0, ({ }), \
                 }), \
                 "sailing", 0, 0, ({ }), \
            }), \
            "acrobatics", 0, 0, ({ \
                 "tumbling", 0, 0, ({ }), \
                 "vaulting", 0, 0, ({ }), \
                 "balancing", 0, 0, ({ }), \
            }), \
            "evaluating", 0, 0, ({ \
                "weapons", 0, 0, ({ }), \
                "armour", 0, 0, ({ }), \
            }), \
            "culture", 0, 0, ({ \
                "ankh-morporkian", 0, 0, ({ }), \
                "djelian", 0, 0, ({ }), \
                "ephebian", 0, 0, ({ }), \
                "agatean", 0, 0, ({ }), \
            }), \
            "perception", 0, 0, ({ }), \
            "direction", 0, 0, ({ }), \
            "health", 0, 0, ({ }), \
            "points", 0, 0, ({ }), \
        }), \
    })

/**
 * The complete standard skill tree.  This should be avoided being used
 * if possible.
 * @see /std/skills.c
 * @see /std/living/skills.c
 */
#define STD_SKILLS ( STD_SKILLS_COVERT + STD_SKILLS_CRAFTS + STD_SKILLS_FAITH + STD_SKILLS_FIGHTING + STD_SKILLS_MAGIC + STD_SKILLS_OTHER )
#endif /* __SYS__SKILLS */
// --- END [/mnt/home2/grok/lib/include/skills.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/fixed_random.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/fixed_random.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
105 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/fixed_random.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __FIXED_RANDOM_H
#define __FIXED_RANDOM_H

#define RANDOM_OBJ "/obj/handlers/random_num"

#endif
// --- END [/mnt/home2/grok/lib/include/fixed_random.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/wander.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/wander.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
127 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/wander.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__WANDER
#define __SYS__WANDER

#define WANDER_HANDLER "/obj/handlers/wander_handler"

#endif /* __SYS__WANDER */
// --- END [/mnt/home2/grok/lib/include/wander.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/priest.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/priest.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
793 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/priest.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#undef CLASSROOMS
#undef PRIESTCHARS

#define PRIESTTSG    "/d/am/small_gods/temple"
#define PRIESTAM     "/d/guilds/priests/Ankh-Morpork/"
#define PRIESTKLK     "/d/guilds/priests/Khot-lip-khin/"
#define PRIESTDJEL   "/d/guilds/priests/Djelibeybi/"
#define PRIESTOC    "/d/guilds/priests/Ohulan-Cutash/"

#define CLASSROOMS   "/d/guilds/priests/Ankh-Morpork/classrooms/"
#define TSG          "/d/am/priest/templeofsg/"

#define PRIESTCHARS  "/d/guilds/priests/chars/"
#define PRIESTINHERITS "/d/guilds/priests/inherits/"
#define PRIESTITEMS  "/d/guilds/priests/items/"
#define PRIESTUTILS  "/d/guilds/priests/utils/"

#define PRIESTSAVE   "/d/guilds/priests/save/"

#define PRAYERS     "/obj/rituals/"
#define BASIC       "/obj/rituals/basic"
#define HEALING     "/obj/rituals/basic_healing"
// --- END [/mnt/home2/grok/lib/include/priest.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/map_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/map_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
541 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/map_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630125   Available: 13577479
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define MH "/obj/handlers/map_helper"
#define MAP_HANDLER "/obj/handlers/map"
#define SIZE 0
#define TIME 1
#define LOAD 2

#define DESTINATION 0
#define EXIT_SIZE 1
#define EXIT_TYPE 2
#define OFFSET    3

/* tune defines
 */
#define CACHESIZE 60 
#define SKEWTIME 4

/* debug defines */
#undef LOGTO "olorin"
#undef HELPLOGTO "ceres"
#define COORDS 1
#undef PARANOID
#define LOG_EXITS 1
#define LOG_SHORTS 1

#ifdef LOGTO
#define LOG(X) \
if ( find_living( LOGTO ) ) \
  tell_object( find_living( LOGTO ), X )
#else
#define LOG(X)
#endif

// --- END [/mnt/home2/grok/lib/include/map_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/attack_messages.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/attack_messages.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
458 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/attack_messages.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the attack message handler.  Specifies the location 
 * of the attack message handler.
 * @see /obj/handlers/attack_messages
 * @author Olorin
 * @change Mon Dec  1 Pinkfish
 * Modified to be an attack message handler instead of a weapon message.
 */
#ifndef __ATTACK_MESSAGE_H
/** @ignore yes */
#define __ATTACK_MESSAGE_H

/** The weapon message handler object. */
#define ATTACK_MESSAGE "/obj/handlers/attack_messages"

#endif
// --- END [/mnt/home2/grok/lib/include/attack_messages.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/report_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/report_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
293 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/report_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define SAVEPATH  "/save/cases/"
#define RECENT    (SAVEPATH+"recent.o")
#define NEWCASES  (SAVEPATH+"new.o")
#define NO_RECENT 20

#define NAME      0
#define CHARS     1
#define CREATOR   2
#define TIME      3
#define CATEGORY  4
#define REPORT    5
#define HIGHLORD  6
#define DECISION  7

// --- END [/mnt/home2/grok/lib/include/report_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/panic.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/panic.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
745 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/panic.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630124   Available: 13577478
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the panic handler.
 * @author Pinkfish
 */
#ifndef __PANIC_H
/** @ignore yes */
#define __PANIC_H

/**
 * How many godmothers are in the handler.
 */
#define NUM_GODMOTHERS 2
/**
 * The directory to find the godmothers.
 */
#define GODMOTHER_DIR "/obj/monster/godmother/"

/**
 * The amount of time the godmother will wait for the first response.
 */
#define FIRST_WAIT_TIME 120

/**
 * The amount of time the godmother will wait for the final response.
 */
#define FINISH_WAIT_TIME 240

/**
 * The location of the panic handler.
 */
#define PANIC_HANDLER "/obj/handlers/fairy_godmothers"

/**
 * The did not panic successfuly.
 */
#define PANIC_NOT_OK 0
/**
 * They paniced successful.
 */
#define PANIC_OK 1
#endif
// --- END [/mnt/home2/grok/lib/include/panic.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/weapon_old.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/weapon_old.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
413 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/weapon_old.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__WEAPON
#define __SYS__WEAPON

#define W_ARRAY_SIZE 7
#define W_FLAG 0
#define W_CHANCE 1
#define W_BASE 2
#define W_HIT 3
#define W_DAM 4
#define W_TYPE 5
#define W_FUN 6

/* flags  */
#define F_FIXED 0
#define F_NUM 1
#define F_DIE 2
#define F_RAND 1

/* armours are here too... confusing huh? */
#define A_ARRAY_SIZE 2
#define A_NAME 0
#define A_TYPE 1
#define A_AC 0

#endif /* __SYS__WEAPON */
// --- END [/mnt/home2/grok/lib/include/weapon_old.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/bounty.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/bounty.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
134 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/bounty.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__BOUNTY
#define __SYS__BOUNTY

/*
   Bounty stuff
*/

#define BOUNTY "/obj/handlers/bounty"

#endif /* __SYS__BOUNTY */
// --- END [/mnt/home2/grok/lib/include/bounty.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/newbiehelpers.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/newbiehelpers.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
238 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/newbiehelpers.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 *  Newbiehelpers include file
 *  @author Wyvyrn
 *  @stared 10/03/2003
 */


#ifndef __NEWBIEHELPERS_H
#define __NEWBIEHELPERS_H

/* Handler define */
 
#define NEWBIEHELPERS_HANDLER            "/obj/handlers/newbiehelpers"

#endif
// --- END [/mnt/home2/grok/lib/include/newbiehelpers.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/weapon.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/weapon.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
962 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/weapon.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630123   Available: 13577477
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__WEAPON
#define __SYS__WEAPON

/**
 * These macros are used to index the array returned by query_attack_data() in
 * /std/weapon_logic.c
 */
#define W_ARRAY_SIZE 5
#define W_CHANCE     0
#define W_DAMAGE     1
#define W_TYPE       2
#define W_SKILL      3
#define W_FUNCTION   4

/**
 * The W_DAMAGE index of query_attack_data() can be an integer or a three
 * index array. These macros index that array.
 */
#define F_FIXED  0
#define F_NUM    1
#define F_DIE    2

/**
 * These macros index the armour_types data stored in /std/armour_logic.c
 * Quite why they're in weapon.h is beyond me -- Ceres.
 */
#define A_ARRAY_SIZE 2
#define A_NAME       0
#define A_TYPE       1
#define A_AC         0

/**
 * These macros are used to index the array returned by weapon_attacks() in
 * /std/weapon_logic.c
 */
#define AT_ARRAY_SIZE 4
#define AT_DAMAGE    0
#define AT_SKILL     1
#define AT_TYPE      2
#define AT_NAME      3
#endif /* __SYS__WEAPON */
// --- END [/mnt/home2/grok/lib/include/weapon.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/am_time.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/am_time.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630122   Available: 13577476
Inodes: Total: 5242880    Free: 4960136
8036 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/am_time.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630122   Available: 13577476
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file defines the array offsets for use in the am_time functions
 * and the length of things like days, minutes and seconds in the
 * am calendar.  It also defines the names of the months and days
 * and their corresponding values.
 * @see /obj/handlers/am_time_handler
 */

#ifndef __AM_TIME_H
/** @ignore yes */
#define __AM_TIME_H

/**
 * Thgis is the pointer to the handler for am time functions.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_HANDLER "/obj/handlers/am_time_handler"

/**
 * This is the month index into the am_time_array() return value.
 * @example
 * mixed *arr;
 *
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("We are in the " + arr[AM_TIME_MONTH] + " month.\n");
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_MONTH 0
/**
 * This is the day of month index into the am_time_array() return value.
 * @example
 * mixed *arr;
 *
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("We are in the " + arr[AM_TIME_DAY_OF_MONTH] + " day of month.\n");
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_DAY_OF_MONTH 1
/**
 * This is the day of week index into the am_time_array() return value.
 * @example
 * mixed *arr;
 *
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("We are in the " + arr[AM_TIME_DAY_OF_WEEK] + " day of week.\n");
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_DAY_OF_WEEK 2
/**
 * This is the hour index into the am_time_array() return value.
 * @example
 * mixed *arr;
 *
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("Time is " + arr[AM_TIME_HOUR] + ":" + arr[AM_TIME_MINUTE]".\n");
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_HOUR 3
/**
 * This is the minute index into the am_time_array() return value.
 * @example
 * mixed *arr;
 *
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("Time is " + arr[AM_TIME_HOUR] + ":" + arr[AM_TIME_MINUTE]".\n");
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_MINUTE 4
/**
 * This is the year index into the am_time_array() return value.
 * @example
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("The year is " + arr[AM_TIME_YERAR] + ".\n");
 */
#define AM_TIME_YEAR 5
/**
 * This is the primus index into the am_time_array() return value.
 * A year is primus if it is in the first 400 days, not the second.
 * @example
 * arr = AM_TIME_HANDLER->am_time_array(time());
 * write("The year is " + arr[AM_TIME_YERAR] + ".\n");
 */
#define AM_TIME_PRIMUS 6


/* The month name defines. */

/**
 * This is the value associated with the month of Offle in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_OFFLE 1
/**
 * This is the value associated with the month of Feburary in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_FEBURARY 2
/**
 * This is the value associated with the month of March in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_MARCH 3
/**
 * This is the value associated with the month of April in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_APRIL 4
/**
 * This is the value associated with the month of May in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_MAY 5
/**
 * This is the value associated with the month of June in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_JUNE 6
/**
 * This is the value associated with the month of Grune in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_GRUNE 7
/**
 * This is the value associated with the month of August in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_AUGUST 8
/**
 * This is the value associated with the month of Spune in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_SPUNE 9
/**
 * This is the value associated with the month of Sektober in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_SEKTOBER 10
/**
 * This is the value associated with the month of Ember in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_EMBER 11
/**
 * This is the value associated with the month of December in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_DECEMBER 12
/**
 * This is the value associated with the month of Ick in the 
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_ICK 13

/* This is the defines for the days of the week. */

/**
 * This is the value associated with the day Monday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_MONDAY 1
/**
 * This is the value associated with the day Tuesday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_TUESDAY 2
/**
 * This is the value associated with the day Wednessday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_WEDNESSDAY 3
/**
 * This is the value associated with the day Thursday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_THURSDAY 4
/**
 * This is the value associated with the day Friday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_FRIDAY 5
/**
 * This is the value associated with the day Saturday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_SATURDAY 6
/**
 * This is the value associated with the day Sunday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_SUNDAY 7
/**
 * This is the value associated with the day Octeday in the
 * am time calendar.
 * @see /obj/handlers/am_time_handler
 */
#define AM_TIME_OCTEDAY 8

/* the length of time defines and stuff. */

/**
 * The number of days in each year in the Ankh-Morpork calendar.
 */
#define AM_DAYS_PER_HALF_YEAR 400
/**
 * The numbers of seconds per minute in the Ankh-Morpork calenda.
 */
#define AM_SECONDS_PER_MINUTE 18
/**
 * The numbers of minutes per hour in the Ankh-Morpork calenda.
 */
#define AM_MINUTES_PER_HOUR 60
/**
 * The numbers of minutes per hour in the Ankh-Morpork calenda.
 */
#define AM_HOURS_PER_DAY 24
/**
 * The number of days per week in the Ankh-Morpork calenda.
 */
#define AM_DAYS_PER_WEEK 8
/**
 * The numbers of minutes per day in the Ankh-Morpork calenda.
 */
#define AM_MINUTES_PER_DAY (AM_MINUTES_PER_HOUR * AM_HOURS_PER_DAY)
/**
 * The numbers of seconds in each day in the Ankh-Morpork calendar.
 */
#define AM_SECONDS_PER_DAY (AM_MINUTES_PER_DAY * AM_SECONDS_PER_MINUTE)
/**
 * The numbers of seconds in each month in the Ankh-Morpork calendar.
 */
#define AM_SECONDS_PER_WEEK (AM_DAYS_PER_WEEK * AM_MINUTES_PER_DAY * AM_SECONDS_PER_MINUTE)
/**
 * The number of seconds per year in the Ankh-Morpork calendar.
 */
#define AM_SECONDS_PER_HALF_YEAR (AM_SECONDS_PER_DAY * AM_DAYS_PER_HALF_YEAR)

/**
 * The numbers of seconds per house in the Ankh-Morpork calendar.
 */
#define AM_SECONDS_PER_HOUR (AM_SECONDS_PER_MINUTE*AM_MINUTES_PER_HOUR)

/**
 * This is the offset added to the year when it is calculated from the
 * real year.
 */
#define AM_START_YEAR_DATE 1966

/**
 * A flag used to be passed into the format parameter for the amtime
 * function.  It turns off the displaying of the time; ie: 12:48am
 * disappears.
 */
#define AM_TIME_FORMAT_NO_TIME 1

/**
 * A class to hold all the information for am times.
 * @member year the year of the time
 * @member prime if the section is price (the first 400 days) or secundus
 * @member minute the minute of the time
 * @member hour the hour of the time
 * @member month the month of the time
 * @member day_of_week the day of the week
 * @member day_of_month the day of the month
 * @see /obj/handlers/am_time->query_am_time_class()
 */
class am_time {
   int year;
   int primus;
   int minute;
   int hour;
   int month;
   int day_of_week;
   int day_of_month;
   int day_of_year;
}

#endif
// --- END [/mnt/home2/grok/lib/include/am_time.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/inet.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/inet.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630120   Available: 13577474
Inodes: Total: 5242880    Free: 4960136
223 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/inet.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630120   Available: 13577474
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__INET
#define __SYS__INET

#define INETD "/net/inetd"
#define NAMESERVER "/net/nameserver"
#include "comms.h"
#define CLONE_DEMON
#define INTERCREATORD "/net/daemon/out_intercreator"

#endif /* __SYS__INET */
// --- END [/mnt/home2/grok/lib/include/inet.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/reaction.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/reaction.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630120   Available: 13577474
Inodes: Total: 5242880    Free: 4960136
3173 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/reaction.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630120   Available: 13577474
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Include file for reaction handler.
 * This file includes some useful defines for parameters passed to
 * function pointers.
 * To use these, you'd do $OBJ_A instead of $1, etc.
 * @author Jeremy
 */

#ifndef __REACTION_H
/** @ignore yes */
#define __REACTION_H

/**
 * The class used in the reaction handler.
 *
 * @element ratio Amount of first substance needed; can be a float
 * (a:b) or an array of two floats (min/max ratio)
 * @element results Resulting object path
 * @element result_amt Amount of result per total reagents (ie, if
 * 2 ounces of a and 3 ounces of b should make 5
 * ounces of result, this would be 1.0
 * @element message Message to be printed out at reaction (probably
 * obsolete; using 'func' below would be better)
 * @element func Array of call-by-value function strings or
 * function pointers
 */
class reaction {
    mixed ratio;        // Amount of first substance needed; can be a float
                        // (a:b) or an array of two floats (min/max ratio)
    string result;      // Resulting object path
    float result_amt;   // Amount of result per total reagents (ie, if
                        // 2 ounces of a and 3 ounces of b should make 5
                        // ounces of result, this would be 1.0
    string message;     // Message to be printed out at reaction (probably
                        // obsolete; using 'func' below would be better)
    mixed *func;        // Array of call-by-value function strings or
                        // function pointers
}

/*
 * Some useful defines for parameters passed to function pointers.
 * To use these, you'd do $OBJ_A instead of $1, etc.
 *
 *  OBJ_A    The first reagent in the reaction spec
 *  OBJ_B    The second reagent
 *  OBJ_X    The result of the reaction
 *  ENV      The environment in which the reaction is taking place
 *  ENV2     The environment of the environment
 *  AMT_A    The amount of obj_a that will be consumed
 *  AMT_B    The amount of obj_b that will be consumed
 *
 * These last two were necessary because the amounts aren't actually
 * consumed until after the function pointers are called.  So
 * $OBJ_A->query_amount() returns the original amount, and $AMT_A
 * is the amount actually used.
 */

/** The first reagent in the reaction spec. */
#define OBJ_A   1
/** The second reagent in the reaction spec. */
#define OBJ_B   2
/** The result of the reaction. */
#define OBJ_X   3
/** The environment in which the reaction is taking place. */
#define ENV     4
/** The environment of the environment. */
#define ENV2    5
/**
 * The amount of obj_a that will be consumed.
 * These last two were necessary because the amounts aren't actually
 * consumed until after the function pointers are called.  So
 * $OBJ_A->query_amount() returns the original amount, and $AMT_A
 * is the amount actually used.
 */
#define AMT_A   6
/**
 * The amount of obj_b that will be consumed.
 * These last two were necessary because the amounts aren't actually
 * consumed until after the function pointers are called.  So
 * $OBJ_A->query_amount() returns the original amount, and $AMT_A
 * is the amount actually used.
 */
#define AMT_B   7

#endif
// --- END [/mnt/home2/grok/lib/include/reaction.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/esc.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/esc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630119   Available: 13577473
Inodes: Total: 5242880    Free: 4960136
81 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/esc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630119   Available: 13577473
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__ESC
#define __SYS__ESC


#define esc ""

#endif /* __SYS__ESC */
// --- END [/mnt/home2/grok/lib/include/esc.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/snmp.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/snmp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630119   Available: 13577473
Inodes: Total: 5242880    Free: 4960136
548 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/snmp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630119   Available: 13577473
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define LISTEN_PORT		4161
#define COMMUNITY		"mrtg-snmpd"
#define SNMPHANDLER		"/obj/handlers/snmp_handler"
#define ID			0
#define ES			1
#define EI			2


#define	INTEGER			2
#define	BIT_STRING		3
#define OCTET_STRING		4
#define	NULL			5
#define OBJECT_IDENT		6

#define	SEQUENCE		48

#define IPADDRESS		64
#define	COUNTER			65
#define	GAUGE			66
#define	TIMETICKS		67
#define	OPAQUE			68
#define	NSAPADDRESS		69

#define	GETREQUESTPDU		160
#define	GETNEXTREQUESTPDU	161
#define	GETRESPONSEPDU		162
#define	SETREQUESTPDU		163
#define	TRAPPDU			164
// --- END [/mnt/home2/grok/lib/include/snmp.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/move_failures.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/move_failures.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
1052 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/move_failures.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * List of defines for the various typoes of move failures.  So you can figure
 * out why the move failed (if this is important to you).
 */
#ifndef __SYS__MOVE_FAILURES
/**
 * @ignore yes
 */
#define __SYS__MOVE_FAILURES

/**
 * The move succeeded.
 */
#define MOVE_OK 0
#define MOVE_EMPTY_DEST 1
/**
 * The remove function returned a fail result when the object was attempted
 * to be removed.  This can be changed with the set_get and reset_get functions.
 *
 * @see /std/basic/move->set_get()
 * @see /std/basic/move->reset_get()
 */
#define MOVE_NO_GET 2
/**
 * Unable to remove the object from the players inventory.  This is controlled
 * by the set_drop and reset_drop functions.
 *
 * @see /std/basic/move->set_drop()
 * @see /std/basic/move->reset_drop()
 */
#define MOVE_NO_DROP 3
/**
 * The object ius too heavy to go into the inventory.
 *
 * @see /std/basic/misc->set_weight()
 * @see /std/basic/misc->query_weight()
 */
#define MOVE_TOO_HEAVY 4
#define MOVE_INVALID_DEST 5
#define MOVE_NO_UNHOLD 6

#endif /* __SYS__MOVE_FAILURES */
// --- END [/mnt/home2/grok/lib/include/move_failures.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/login.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/login.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
227 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/login.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all that is needed by the login object.
 * @author Pinkfish
 */
#include <login_handler.h>

/**
 * This is the location of the login object.
 * @see /secure/login
 */
#define LOGIN_OB "/secure/login"

// --- END [/mnt/home2/grok/lib/include/login.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/corpse.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/corpse.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
531 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/corpse.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630118   Available: 13577472
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This defines all the bits needed to be used by the corpse
 * handler.
 */
#ifndef __SYS__CORPSE
/** @ignore yes */
#define __SYS__CORPSE

/** The default corpse weight. */
#define STD_CORPSE_WEIGHT 1600

/** The object to clone to get a corpse.  */
#define CORPSE_OBJECT "/obj/corpse"

/** The handler that deals with all things corpsey. */
#define CORPSE_HANDLER "/obj/handlers/corpse_handler"

/** The value to use when the corpse is in a player. */
#define CORPSE_IN_PLAYER "corpse in player"

#endif /* __SYS__CORPSE */
// --- END [/mnt/home2/grok/lib/include/corpse.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/liaison.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/liaison.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
1402 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/liaison.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 *  Liaison domain include file
 *  @author Wyvyrn
 *  @stared 2002-09-05
 */


#ifndef __LIAISON_H
#define __LIAISON_H

/* Domain define */
 
#define LIAISON                "/d/liaison/"

/* Yeth, Mathter! */

#define LIAISON_MASTER         LIAISON + "master"

/* General defines */

#define HANDLERS               LIAISON + "handlers/"
#define HELPERS                LIAISON + "helpers/"
#define IDEAS                  LIAISON + "ideas/"
#define ITEMS                  LIAISON + "items/"
#define NEWBIE                 LIAISON + "NEWBIE/"
#define SECURE                 LIAISON + "secure/"
#define TOYS                   LIAISON + "TOYS/"
#define UTILS                  LIAISON + "utils/"
#define WEB                    LIAISON + "public_html/"


/* Save file defines */

#define SAVE_DIR               "/save/"
#define SAVE                   SAVE_DIR + "liaison/"
#define LIAISON_DOMAIN_INFO    SECURE + "domain_info.txt"


/* Docs defines */

#define DOC_DIR                "/doc/creator/liaison/"
#define POLICY                 DOC_DIR + "policy/"


/* Newbie defines */

#define NEWBIE_CREATOR         NEWBIE + "CREATOR/"

#define NEWBIE_CHARS           NEWBIE + "chars/"
#define NEWBIE_DOC             NEWBIE + "doc/"
#define NEWBIE_ITEMS           ITEMS + "NEWBIE/"
#define NEWBIE_SAVE            NEWBIE + "save/"

/* Toys defines */

#define TOYS_IDEAS             TOYS + "ideas/"

#endif
// --- END [/mnt/home2/grok/lib/include/liaison.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/parse_command.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/parse_command.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
200 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/parse_command.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__PARSE_COMMAND
#define __SYS__PARSE_COMMAND

#define P_THING 0
#define P_STR 1
#define P_CUR_NUM 2
#define P_MAX_NUM 3
#define P_TOP 4
#define P_BOT 5

#endif /* __SYS__PARSE_COMMAND */
// --- END [/mnt/home2/grok/lib/include/parse_command.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cwc.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cwc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
2543 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cwc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630117   Available: 13577471
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __CWC_H
#define __CWC_H

/** 
 * The base #define for Cwc.  All defines must ultimately be built on
 * this define.
 */ 
#define CWC "/d/cwc/"

/**
 * The location of Cwc wide inheritables.
 */ 
#define INHERIT CWC "inherit/"

/**
 * The location of the base city inherit.  This file should be inherited
 * into all rooms in Cwc that link into the hospital, inside and outside.
 */ 
#define CITY_INHERIT INHERIT "city_inherit"

/**
 * The location of the Cwc hospital inheritable.
 */ 
#define HOSPITAL_INHERIT INHERIT "hospital"

/** 
 * The location of hospital data files.
 */ 
#define HOSPITAL_PATH CWC "hospital/"

/** 
 * The location for Cwc wide handlers.
 */
#define CWC_HANDLERS CWC "handlers/"

/**
 * The location of the Cwc teleport inheritable.  This inherit should be 
 * added to rooms to make them follow the restricted teleport rules 
 * for Cwc.
 */ 
#define CWC_TELEPORT_INHERIT "/d/cwc/inherit/teleport_inherit"

/**
 * The location for Bes Pelargic.  All #define's in /d/cwc/Bes_Pelargic/path.h
 * are built on this #define.
 */ 
#define BES_PELARGIC CWC "Bes_Pelargic/"

/** 
 * The location for the city of Hunghung.  All #defines in /d/cwc/Hunghung/path.h
 * are built on this #define.
 */ 
#define HUNGHUNG CWC "Hunghung/"

/** 
 * The location of the generic NPC characters directory.  Most NPCs in here
 * are generic NPCs which can be used with the hospital.  They must be then
 * configured to move and walk in the city properly.
 */ 
#define CWC_CHARS CWC "chars/"

/** 
 * The location of Cwc wide items.  The Cwc armoury accesses files in this
 * directory.
 */ 
#define CWC_ITEMS CWC "items/"

/**
 * The location of the Cwc save directory.
 */ 
#define CWC_SAVE "/save/cwc/"
#define SAVE "/save/cwc/"

/**
 * This #define points to the secure Cwc directory.  This directory is 
 * only really used for domain administrative purposes.
 */ 
#define SECURE CWC "secure/"

/** 
 * The location of the Cwc origami handler.  This handler determines 
 * how you can fold a piece of paper, and transforms a piece of paper
 * into a folded item.
 */ 
#define ORIGAMI_HANDLER CWC_HANDLERS + "origami_handler"

/**
 * The default start location for people in Cwc.  This is an absolute path
 * and should be revised at a later date.
 */ 
#define CWC_START_LOCATION "/d/cwc/Bes_Pelargic/Bad_Poo-Ning/roads/piers/pier303"

/* These are miscellaneous #define's and need to be moved around to their
 * proper places instead of being here.
 */ 

#define SHOO_LI BES_PELARGIC "Shoo_Li/"
#define CUSTOM_NPCS 0


#endif
// --- END [/mnt/home2/grok/lib/include/cwc.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/tokenise.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/tokenise.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630116   Available: 13577470
Inodes: Total: 5242880    Free: 4960136
539 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/tokenise.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630116   Available: 13577470
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__TOKENISE
#define __SYS__TOKENISE

#define TOK_PLUS 1
#define TOK_MINUS 2
#define TOK_MULT 3
#define TOK_DIV 4
#define TOK_OBRAC 5
#define TOK_CBRAC 6
#define TOK_SARRAY 7
#define TOK_EARRAY 8
#define TOK_SMAPPING 9
#define TOK_EMAPPING 10
#define TOK_COLON 11
#define TOK_COMMA 12
#define TOK_TAB 13
#define TOK_CALL 14
#define TOK_DOT 15
#define TOK_DOTDOT 16
#define TOK_LESS 17
#define TOK_GREATOR 18
#define TOK_LESSEQ 19
#define TOK_GREATOREQ 20
#define TOK_EQUAL 21
#define TOK_ASSIGN 22

#endif /* __SYS__TOKENISE */
// --- END [/mnt/home2/grok/lib/include/tokenise.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/talker.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/talker.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630115   Available: 13577469
Inodes: Total: 5242880    Free: 4960136
2276 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/talker.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630115   Available: 13577469
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main include file for the talker effect and shadow.  
 * @author Taffyd
 * @started 12/2/1998
 */

/**
 * This class stores the effect arguments for the talker.
 * @member status whether or not the talker is on or off
 * @member what channels the talker is listening to
 * @member verbose whether the talker is in verbose or brief mode. (1 is verbose, 0 is brief)
 * @member local_echo is local echo enabled
 * @member string the colour that text is displayed on the screen.
 */
class talker_args {
    int status;
    string *channels;
    int verbose;
    int local_echo;
    mixed colour;
} 

/**
 * This class is used to record channel cache data. It is used in conjunction
 * with a mapping.
 * @member playtester whether the player is a playtester or not.
 * @member apex_member whether or not the player is an apex member.
 * @member talker_quest whether or not the player has done the talker quest to
 * gain access to additional channels.
 */
class cache_data {
    int playtester;
    int talker_quest;
    int apex_member;
} 


//
// #define DEBUG 1
/**
 * This is a printf format specification field used to format the talker 
 * list output.
 * @see /std/effects/object/talker->list()
 */
#define LIST_FORMAT "   %12-s %*-=s\n"
#define HIST "/obj/handlers/hist_handler"

#define ON_PATTERN "{on|off}"
#define VERBOSE_PATTERN "{brief|verbose}"
#define CHANNEL_PATTERN "channels"
#define NEW_CHANNEL_PATTERN "<word'new channel'>"
#define SET_COLOUR_FULL_PATTERN "colour <word'channel'> <string'colour'> for <direct:object'talker'>"
#define SET_COLOUR_PATTERN "colour <word'channel'> <string'colour'>"
#define COLOUR_LIST "colour list"
#define TOGGLE_COLOUR_PATTERN "colour"
#define COLOUR_ON_OFF_PATTERN "colour {on|off|reset}"
#define DELETE_CHANNEL_PATTERN "delete <word'channel'>"
#define HISTORY_PATTERN "history"
#define HISTORY_CHANNEL_PATTERN "history <word'channel'>"
#define LIST_PATTERN "list"
#define LIST_CHANNEL_PATTERN "list <word'channel'>"
#define LIST_CHANNEL_PATTERN_BRIEF "list brief <word'channel'>"
#define ECHO_PATTERN "echo {on|off}"


#define DEFAULT_COLOUR "%^BOLD%^%^GREEN%^"
#define DEFAULT_COLOUR_SETTINGS ([ "default" : DEFAULT_COLOUR, "status" : "on" ])
#define DEFAULT_COLOUR_WITH(n) ([ "default" : (n), "status" : "on" ])
// --- END [/mnt/home2/grok/lib/include/talker.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/error_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/error_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630115   Available: 13577469
Inodes: Total: 5242880    Free: 4960136
5909 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/error_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630115   Available: 13577469
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file to handler all the basic error handler
 * code.
 * @author Pinkfish
 * @started Thu Feb  6 17:40:26 PST 2003
 */
#ifndef __ERROR_HANDLER_H
/** @ignore yes */
#define __ERROR_HANDLER_H

/**
 * This is the return value when the query is bad.
 */
#define ERROR_BAD_QUERY -1000

/** This is the path to the error handler.  */
#define ERROR_HANDLER "/obj/handlers/error_handler"

/** This is the list of valid categories. */
#define ERROR_CATEGORIES ({ "ROOM", "OBJECT", "HELP", "RITUAL", "SPELL", "COMMAND", "GENERAL" })

/** Error status open */
#define ERROR_STATUS_OPEN "OPEN"
/** Error status fixing, so it is in the middle of being fixed. */
#define ERROR_STATUS_FIXING "FIXING"
/** Error status considering the idea, not yet fixed. */
#define ERROR_STATUS_CONSIDERING "CONSIDERING"
/** Error status fixed.  The bug has been resolved and closed. */
#define ERROR_STATUS_FIXED "FIXED"
/** Error status denied.  The bug was not fixed and is marked as not being
 * a bug */
#define ERROR_STATUS_DENIED "DENIED"
/** This is the list of valid statuses. */
#define ERROR_STATUS ({ ERROR_STATUS_FIXED, ERROR_STATUS_DENIED, \
                        ERROR_STATUS_FIXING, ERROR_STATUS_CONSIDERING, \
                        ERROR_STATUS_OPEN })
/** This is the list of valid types. */
#define ERROR_TYPE ({ "BUG", "TYPO", "IDEA", "COMMENT" })

/** This define is used to order by the filename. */
#define ERROR_ORDER_BY_FILENAME "filename"
/** This define is used to order by the directory. */
#define ERROR_ORDER_BY_DIRECTORY "directory"
/** This define is used to order by the date. */
#define ERROR_ORDER_BY_DATE "date"
/** This define is used to order by the reporter. */
#define ERROR_ORDER_BY_REPORTER "reporter"

/** This is the define for the user name to use for assigned to 'no one'. */
#define ERROR_ASSIGNED_NO_ONE "nobody"

/**
 * The summary plus the details is the complete
 * error.
 * @member id the unique id of the bug
 * @member entry_date the date the bug was added
 * @member filename the filename the bug was put against
 * @member assigned_to who the bug is assigned to
 * @member reporter the person who reported the bug
 * @member category is one of ROOM | OBJECT etc
 * @member type is one of TYPO | BUG | IDEA
 * @member status is one of OPEN | CLOSED | etc
 * @member directory the directory the bug is in
 */
class error_summary {
   int id;
   int entry_date;
   string filename;
   string category;
   string assigned_to;
   string reporter;
   string type;
   string status;
   string directory;
}

/**
 * The details of the bug.
 * @member summary the summary class for the basic sumamry details
 * @member fix_date the date the bug was fixed
 * @member fixer the person who fixed the bug
 * @member report the report associated with the bug
 * @member runtime the runtime error associated with the bug
 */
class error_details {
   class error_summary summary;
   int fix_date;
   string fixer;
   string report;
   string runtime;
}

/**
 * The comments associated with the bug.
 * @member date the date the comment was added
 * @member commenter the person who commented on the bug
 * @member comment the comment about the bug
 */
class error_comment {
   int date;
   string commenter;
   string comment;
}

/**
 * The forwards associated with the bug.
 * @member date the date the forward was done
 * @member forwarder the person who forwared the bug
 * @member old_directory the old directory of the bug
 */
class error_forward {
   int date;
   string forwarder;
   string old_directory;
}

/**
 * The reply data for the error.  This is where the bug replies are
 * stored.
 * @member id the id of the bug reply
 * @member bug_id the id of the bug
 * @member sender who sent the bug reply
 * @member recipient the recipient of the bug reply
 * @member status the status of the bug reply
 * @member senddate when the bug was sent
 * @member subject the subject of the reply
 * @member message the message associated with the bug
 */
class error_replies {
   int id;
   int bug_id;
   string sender;
   string recipient;
   string status;
   int senddate;
   string subject;
   string message;
}

/**
 * All the details of the error.
 * @member details the details of the error
 * @member comments the comments associated with the error
 * @member forwards the forwards associated with the error
 * @member replies the replies associated with the error
 */
class error_complete {
   class error_details details;
   class error_comment* comments;
   class error_forward* forwards;
   class error_replies* replies;
}

/**
 * This is the class used to generate queries through the error handler.
 * You do not need to fill in all the fields, only the filled in ones will
 * be used as restrictions on the query.
 * @member no_extra_details this only works with the bug details queries
 *                          and it means that only the main data is fetched,
 *                          not comments etc.
 * @member recursive do recursive directory lookups
 * @member id look up this id specifically
 * @member id_list look up this list of ids, if this is specified it
 *                 overrides id
 * @member bug_offset the offset to use in the limit command
 * @member dir the directory to use
 * @member assigned_to who it is assigned to
 * @member file_name specific file name to lookup
 * @member reporter the reporter to lookup
 * @member fixer the person who fixed the bug
 * @member status the status of the bug
 * @member category the category of the bug
 * @member type the type of the bug
 * @member order_by one of the ordering methods
 */
class error_query {
   int no_extra_details;
   int recursive;
   int id;
   int bug_offset;
   int* id_list;
   string dir;
   string assigned_to;
   string file_name;
   string reporter;
   string fixer;
   string* status;
   string* category;
   string* type;
   string order_by;
}

#endif
// --- END [/mnt/home2/grok/lib/include/error_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/drinks.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/drinks.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
147 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/drinks.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__DRINKS
#define __SYS__DRINKS

#define D_SIZEOF 3
#define D_ALCOHOL 0
#define D_FOOD 1
#define D_DRINK 2

#endif /* __SYS__DRINKS */
// --- END [/mnt/home2/grok/lib/include/drinks.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/goal.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/goal.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
222 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/goal.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__GOAL
#define __SYS__GOAL

#define EVENT_HANDLED 5
#define EVENT_NOT_HANDLED 6
#define EVENT_PARTIALLY_HANDLED 7
#define EVENT_USED 8
#define SET_GOAL_ARG 9
#define GOAL_ACHIEVED 10

#endif /* __SYS__GOAL */
// --- END [/mnt/home2/grok/lib/include/goal.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/function.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/function.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
479 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/function.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630113   Available: 13577467
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* codes returned by the functionp() efun */

#define FP_LOCAL              2
#define FP_EFUN               3
#define FP_SIMUL              4
#define FP_FUNCTIONAL         5

/* internal use */
#define FP_G_VAR              6
#define FP_L_VAR              7
#define FP_ANONYMOUS          8
#define FP_THIS_OBJECT      0x10

/* additional flags */
#define FP_MASK             0x0f
#define FP_HAS_ARGUMENTS    0x10
#define FP_OWNER_DESTED     0x20
#define FP_NOT_BINDABLE     0x40
// --- END [/mnt/home2/grok/lib/include/function.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ftp.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ftp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630112   Available: 13577466
Inodes: Total: 5242880    Free: 4960136
7618 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ftp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630112   Available: 13577466
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__FTP
#define __SYS__FTP

#define FTP_PORT 4444

class dataconn {
  mixed data;                        /* The string/filename to be sent */
  string path;                       /* Full path to the file */
  int pos;                           /* current position in string/file */
  int parent_fd;                     /* the control connection socket */
  int type;                          /* type of transfer */
  int len;                           /* current length */
  int append;                        /* append to existing file? */
}

class session {
  int fd;                            /* control connection socket */
  string user_name;                  /* user name */
  int logged_in;                     /* are we logged in with password? */
  string cwd;                        /* current directory */
  string data_addr;                  /* host to use for data connections */
  int last_data;                     /* time of last command */
  int data_port;                     /* port to use for data connections */
  int data_fd;                       /* the data connection socket */
  int type;                          /* type of transfer (FILE or STRING) */
  int idle;                          /* idle timeout */
  string rnfr;                       /* source name for RENAME operation */
  int offset;                        /* offset in string/file */
  int use_default;                   /* use the default data connection? */
  int pasv_fd;                       /* socket on which we listen in passive
                                        mode */
  int pasv_cb;                       /* was the listen callback called? */
}

/* Wombles here after */
#define STRING 1
#define FILE 2
#define DOWNLOAD 3
#define BINARY 4

#define MASK_L  1
#define MASK_C  2
#define MASK_F  4
#define MASK_A  8
#define MASK_R 16
#define MASK_D 32

/*
-----------------------------------------------
   debugging defines.
-----------------------------------------------
*/
#define TP_CRE "turrican"

#undef DEBUG

#ifdef DEBUG

#define TP(STR) if (find_player(TP_CRE)) \
                    tell_object(find_player(TP_CRE), STR)

#define DEBUG_SEND   /* define to debug data_write_callback() */
#define DEBUG_RECEIVE /* define to debug data_{read|close}_callback() */

#else

#define TP(STR)
#undef DEBUG_SEND
#undef DEBUG_RECEIVE

#endif

/*
-----------------------------------------------
   log file defines.
-----------------------------------------------
*/
#define LOGGING

#ifdef LOGGING

#define LOG_CONNECT /* define to log all connections */
#define LOG_FILE    /* define to log all file xfers */
#define LOG_CD_SIZE /* define to log cd's and file size commands */
#define LOG_DEBUG   /* define to log debug messages */
#define LOG_FILENAME "/d/admin/log/FTPD.log"

#else

#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
#undef LOG_DEBUG

#endif

#define BLOCK_SIZE 65536


/*
-----------------------------------------------
   driver version defines.
-----------------------------------------------
*/
#define NEWDRIVER

#ifdef __VERSION__
#define VERSION __VERSION__
#else
#ifndef VERSION
#define VERSION version()
#endif
#endif

#define CHECK_LOGIN() if (!sess->logged_in) \
                      { \
                        eventWrite(fd, "530 Please login with USER and PASS.\r\n"); \
                        break; \
                      }
#define CHECK_CMD(INT) if (sizeof(bits) != INT+1) \
                       { \
                         eventWrite(fd, sprintf("500 '%s': command not understood.\r\n", \
                            str)); \
                         break; \
                       }
#define CHECK_CMD2(INT,INT2) if (sizeof(bits) < INT+1 ||\
                                 sizeof(bits) > INT2+1) \
                       { \
                         eventWrite(fd, sprintf("500 '%s': command not understood.\r\n", \
                            str)); \
                         break; \
                       }
#define CHECK_PLAYER() if (sess->logged_in == 2) \
                       { \
                         eventWrite(fd, "553 Permission denied (you are not a creator)\r\n"); \
                         break; \
                       }
#define CHECK_STRING sess->type == STRING
#define UNAME sess->user_name

#define HOME_DIR(NAME) "/w/"+NAME

protected void setup_ftp();
protected string get_path(int fd, string str);
protected void do_update(string name, int fd);
protected void data_write_callback(int fd);

/*
 * List of recognized commands in order defined in RFC 765
 *   ({ Command, Implemented?, Help text })
 */
mapping cmdtab = ([
    "user" : ({ "USER", 1, "<sp> username" }),
    "pass" : ({ "PASS", 1, "<sp> password" }),
    "acct" : ({ "ACCT", 0, "(specify account)" }),
    "smnt" : ({ "SMNT", 0, "(structure mount)" }),
    "rein" : ({ "REIN", 0, "(reinitialize server state)" }),
    "quit" : ({ "QUIT", 1, "(terminate service)", }),
    "port" : ({ "PORT", 1, "<sp> b0, b1, b2, b3, b4" }),
    "pasv" : ({ "PASV", 0, "(set server in passive mode)" }),
    "type" : ({ "TYPE", 1, "<sp> [ A | E | I | L ]" }),
    "stru" : ({ "STRU", 0, "(specify file structure)" }),
    "mode" : ({ "MODE", 0, "(specify transfer mode)" }),
    "retr" : ({ "RETR", 1, "<sp> file-name" }),
    "stor" : ({ "STOR", 1, "<sp> file-name" }),
    "appe" : ({ "APPE", 1, "<sp> file-name" }),
    "mlfl" : ({ "MLFL", 0, "(mail file)" }),
    "mail" : ({ "MAIL", 0, "(mail to user)" }),
    "msnd" : ({ "MSND", 0, "(mail send to terminal)" }),
    "msom" : ({ "MSOM", 0, "(mail send to terminal or mailbox)" }),
    "msam" : ({ "MSAM", 0, "(mail send to terminal and mailbox)" }),
    "mrsq" : ({ "MRSQ", 0, "(mail recipient scheme question)" }),
    "mrcp" : ({ "MRCP", 0, "(mail recipient)" }),
    "allo" : ({ "ALLO", 1, "allocate storage (vacuously)" }),
    "rest" : ({ "REST", 1, "(restart command)" }),
    "rnfr" : ({ "RNFR", 1, "<sp> file-name" }),
    "rnto" : ({ "RNTO", 1, "<sp> file-name" }),
    "abor" : ({ "ABOR", 1, "(abort operation)" }),
    "dele" : ({ "DELE", 1, "<sp> file-name" }),
    "cwd"  : ({ "CWD" , 1, "[ <sp> directory-name ]" }),
    "xcwd" : ({ "XCWD", 1, "[ <sp> directory-name ]" }),
    "list" : ({ "LIST", 1, "[ <sp> path-name ]" }),
    "nlst" : ({ "NLST", 1, "[ <sp> path-name ]" }),
    "site" : ({ "SITE", 1, "site-cmd [ <sp> arguments ]" }),
    "syst" : ({ "SYST", 1, "(get type of operating system)" }),
    "stat" : ({ "STAT", 1, "[ <sp> path-name ]" }),
    "help" : ({ "HELP", 1, "[ <sp> <string> ]" }),
    "noop" : ({ "NOOP", 1, "" }),
    "mkd"  : ({ "MKD" , 1, "<sp> path-name" }),
    "xmkd" : ({ "XMKD", 1, "<sp> path-name" }),
    "rmd"  : ({ "RMD" , 1, "<sp> path-name" }),
    "xrmd" : ({ "XRMD", 1, "<sp> path-name" }),
    "pwd"  : ({ "PWD" , 1, "(return current directory)" }),
    "xpwd" : ({ "XPWD", 1, "(return current directory)" }),
    "cdup" : ({ "CDUP", 1, "(change to parent directory)" }),
    "xcup" : ({ "XCUP", 1, "(change to parent directory)" }),
    "stou" : ({ "STOU", 0, "<sp> file-name" }),
    "size" : ({ "SIZE", 1, "<sp> path-name" }),
    "mdtm" : ({ "MDTM", 1, "<sp> path-name" })
]);

mapping sitecmdtab = ([
    "idle"  : ({ "IDLE",  1, "[ <sp> timeout ]" }),
    "help"  : ({ "HELP",  1, "[ <sp> <string> ]" }),
    "newer" : ({ "NEWER", 0, "<sp> YYYYMMDDHHMMSS [ <sp> path-name ]" }),
    "minfo" : ({ "MINFO", 0, "<sp> YYYYMMDDHHMMSS [ <sp> path-name ]" }),
    "time"  : ({ "TIME",  1, "(prints local time)" }),
    "upd"   : ({ "UPD",   1, "<sp> path-name" })
]);

#define FTP_VERSION "Version 13.2"
#define LOGIN_OB "/secure/login"

#endif /* __SYS__FTP */
// --- END [/mnt/home2/grok/lib/include/ftp.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ls.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ls.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
234 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ls.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __LS_H
#define __LS_H

#define MASK_L 1
#define MASK_C 2
#define MASK_F 4
#define MASK_A 8
#define MASK_D 16
#define MASK_O 32
#define MASK_T 64

#define LS_COMMAND_NICKNAME_PROPERTY "expand ls nicknames"

#endif /* __LS_H */
// --- END [/mnt/home2/grok/lib/include/ls.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/dst.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/dst.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
401 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/dst.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the header file for the daylight savings time.
 */
#ifndef __SYS__DST
/** @ignore yes */
#define __SYS_DST

/** The Australian daylight saving time offset. */
#define AUS_DST -1
/** The UK daylight saving time offset. */
#define UK_DST 0
/** The US daylight saving time offset. */
#define US_DST 0
/** The Canada daylight saving time offset. */
#define CA_DST 0

#endif /* __SYS_DST */
// --- END [/mnt/home2/grok/lib/include/dst.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mission.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mission.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
158 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mission.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630110   Available: 13577464
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__MISSION
#define __SYS__MISSION

#define NOT_SUITABLE 4
#define TOO_HIGH 3
#define JUST_RIGHT 2
#define TOO_LOW 1


#endif /* __SYS__MISSION */
// --- END [/mnt/home2/grok/lib/include/mission.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/map.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/map.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
72 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/map.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define MAP "/obj/handlers/map"
#define MAP_HANDLER "/obj/handlers/map"
// --- END [/mnt/home2/grok/lib/include/map.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/fighter.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/fighter.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
196 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/fighter.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
// Include file for the fighters guilds

#define GUILD_OB "/std/guilds/fighter"

#define FIGHTER "/d/guilds/fighters/"

#define FIGHTERCHARS FIGHTER+"chars/"
#define FIGHTERITEMS FIGHTER+"items/"
// --- END [/mnt/home2/grok/lib/include/fighter.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/origin.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/origin.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
530 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/origin.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* codes returned by the origin() efun */

#define ORIGIN_BACKEND       "driver" /* backwards compat */
#define ORIGIN_DRIVER        "driver"
#define ORIGIN_LOCAL         "local"
#define ORIGIN_CALL_OTHER    "call_other"
#define ORIGIN_SIMUL_EFUN    "simul"
#define ORIGIN_CALL_OUT      "call_out"
#define ORIGIN_EFUN          "efun"
/* pseudo frames for call_other function pointers and efun pointer */
#define ORIGIN_FUNCTION_POINTER   "function_pointer"
/* anonymous functions */
#define ORIGIN_FUNCTIONAL         "functional"
// --- END [/mnt/home2/grok/lib/include/origin.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/unseen.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/unseen.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
304 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/unseen.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630109   Available: 13577463
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define UNIVERSITY            "/d/guilds/wizards/Ankh-Morpork/"

#define ANCIENT_ASSEMBLY      UNIVERSITY +"ancient_assembly/"
#define NEW_HALL              UNIVERSITY +"new_hall/"
#define TURNWISE_COURT        UNIVERSITY +"turnwise_court/"
#define WIDDERSHINS_COURT     UNIVERSITY +"widdershins_court/"
// --- END [/mnt/home2/grok/lib/include/unseen.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/access.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/access.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
509 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/access.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__ACCESS
#define __SYS__ACCESS

#define ERROR     0
#define ACCESS    1
#define NO_NEW    2
#define NO_ACCESS 3
#define AUTH_NEW  4

#define DEFAULT ACCESS

#define ACCESS_LEVEL   0
#define ACCESS_REASON  1
#define ACCESS_TIMEOUT 2

#define MULTI_LEVEL 0
#define MULTI_TIMEOUT 1

#define SUSPEND_TIME   0
#define SUSPEND_REASON 1

#define PERM_NAMES ({ "error", "normal access", "no new characters", \
                      "no access", "new requires authorisation" })
#endif /* __SYS__ACCESS */
// --- END [/mnt/home2/grok/lib/include/access.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmr.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmr.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
889 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmr.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__CMR
#define __SYS__CMR

/**
 * This file defines useful things for the cmr_handler and cmr_library.
 * In particular it defines the MINERALS, MINERAL_ADJECTIVES and SKILLS arrays
 * used when adding materials to the handler.
 * @author Deutha
 * @see add_material
 */
#define MINERALS 0
#define GEMS 1
#define METALS 2
#define WOODS 3
#define MATERIALS ({ "mineral", "gem", "metal", "wood" })
#define MATERIAL_ADJECTIVES ({ "mineral", "gem", "metallic", "wooden" })

#define KNOWN 0
#define MAGIC 1
#define OS 2
#define OW 3
#define OVG 4
#define OVJ 5
#define LEARNT 99
#define SKILLS ({ \
      "none", \
      "magic", \
      "crafts.smithing", \
      "crafts.carpentry", \
      "other.valueing.gems", \
      "other.valueing.jewellery", \
   })

#define CMR_HANDLER "/obj/handlers/cmr_handler"
#define CMR_LIBRARY "/obj/handlers/cmr_library"

#endif /* __SYS__CMR */
// --- END [/mnt/home2/grok/lib/include/cmr.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/pub_shop.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/pub_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
6096 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/pub_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630108   Available: 13577462
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the main include file for the pub_shop.c inheritable.
 * The file reaction.h contains a series of defines for sizes of
 * containers.
 * @author Lemming
 * @started 23/10/1999
 * @see /include/reaction.h
 */

#ifndef __SYS__PUB_SHOP

/** @ignore */
#define __SYS__PUB_SHOP

/**
 * This tells add_menu_item() that the new item is an appetiser.
 */
#define PUB_APPETISER   0
/**
 * This tells add_menu_item() that the new item is a main course.
 */
#define PUB_MAINCOURSE  1
/**
 * This tells add_menu_item() that the new item is a dessert.
 */
#define PUB_DESSERT     2
/**
 * This tells add_menu_item() that the new item is an alcoholic drink.
 */
#define PUB_ALCOHOL     3
/**
 * This tells add_menu_item() that the new item is a soft drink.
 */
#define PUB_SOFTDRINK   4
/**
 * This tells add_menu_item() that the new item is a hot drink.
 */
#define PUB_HOTDRINK    5

/**
 * This is the path where the menu file is held.
 */
#define PUB_MENU_FILE     "/obj/misc/menu"
/**
 * This is the path where the counter file is held.
 */
#define PUB_COUNTER_FILE  "/std/shops/objs/counter"

/**
 * This is the path where the standard glasses are held.
 */
#define PUB_GLASS_PATH    "/obj/misc/glasses/"

/**
 * This is the path for the standard tankard.
 * Volume 4000.
 */
#define PUB_STD_TANKARD   PUB_GLASS_PATH + "std_tankard.ob"
/**
 * This is the path for the standard pint glass.
 * Volume 2200.
 */
#define PUB_STD_PINT      PUB_GLASS_PATH + "std_pint_glass.ob"
/**
 * This is the path for the standard half-pint glass.
 * Volume 1100.
 */
#define PUB_STD_HALFPINT  PUB_GLASS_PATH + "std_half_glass.ob"
/**
 * This is the path for the standard shot glass.
 * Volume 200.
 */
#define PUB_STD_SHOT      PUB_GLASS_PATH + "std_shot_glass.ob"
/**
 * This is the path for the standard wine glass.
 * Volume 960.
 */
#define PUB_STD_WINE      PUB_GLASS_PATH + "std_wine_glass.ob"
/**
 * This is the path for the standard brandy glass.
 * Volume 700.
 */
#define PUB_STD_BRANDY    PUB_GLASS_PATH + "std_brandy_glass.ob"
/**
 * This is the path for the standard tumbler.
 * Volume 1100.
 */
#define PUB_STD_TUMBLER   PUB_GLASS_PATH + "std_tumbler.ob"
/**
 * This is the path for the standard cocktail glass.
 * Volume 750.
 */
#define PUB_STD_COCKTAIL  PUB_GLASS_PATH + "std_cocktail_glass.ob"
/**
 * This is the path for the standard flute glass (champagne, etc).
 * Volume 750.
 */
#define PUB_STD_FLUTE     PUB_GLASS_PATH + "std_flute_glass.ob"
/**
 * This is the path for the standard teacup.
 * Volume 550.
 */
#define PUB_STD_TEACUP    PUB_GLASS_PATH + "std_teacup.ob"
/**
 * This is the path for the standard mug.
 * Volume 800.
 */
#define PUB_STD_MUG       PUB_GLASS_PATH + "std_mug.ob"

/**
 * This is the path where the standard plates are held.
 */
#define PUB_PLATE_PATH    "/obj/misc/plates/"

/**
 * This is the path for the standard plate.
 * Maximum weight 50.
 */
#define PUB_STD_PLATE         PUB_PLATE_PATH + "std_plate.ob"
/**
 * This is the path for the standard dish.
 * Maximum weight 30.
 */
#define PUB_STD_DISH          PUB_PLATE_PATH + "std_dish.ob"
/**
 * This is the path for the standard bowl.
 * Maximum weight 30.
 */
#define PUB_STD_BOWL          PUB_PLATE_PATH + "std_bowl.ob"
/**
 * This is the path for the standard soup dish.
 * Maximum weight 30.
 */
#define PUB_STD_SOUPDISH      PUB_PLATE_PATH + "std_soup_dish.ob"
/**
 * This is the path for the standard dinner plate.
 * Maximum weight 50.
 */
#define PUB_STD_DINNERPLATE   PUB_PLATE_PATH + "std_dinner_plate.ob"
/**
 * This is the path for the standard side plate.
 * Maximum weight 30.
 */
#define PUB_STD_SIDEPLATE     PUB_PLATE_PATH + "std_side_plate.ob"
/**
 * This is the path for the standard dessert plate.
 * Maximum weight 30.
 */
#define PUB_STD_DESSERTPLATE  PUB_PLATE_PATH + "std_dessert_plate.ob"
/**
 * This is the path for the standard dessert dish.
 * Maximum weight 30.
 */
#define PUB_STD_DESSERTDISH   PUB_PLATE_PATH + "std_dessert_dish.ob"

/**
 * This is the class used for all the menu items.
 * @element type The type of the item, as defined in this file
 * @element cost The cost of the item
 * @element item The path to use to get the item from
 * @element container The path to use to get the container from
 * @element volume The volume of the liquid to put in the glass
 * @element intox The intoxication parameter, this is used by the
 * npcs for drinking themselves silly
 */
class menu_item {
   int type;
   int cost;
   string item;
   string container;
   int volume;
   int intox;
}

/**
 * This is the event called when a specific item is not on the menu.  The
 * parameters to this are the shop, the player and the item the player asked
 * for.
 */
#define PUB_EVENT_NOT_AVAILABLE "not_available"

/**
 * This is the event called when the shop is not open.
 */
#define PUB_EVENT_NOT_OPEN "not_open"

/**
 * This is the event called when some stuff is bought.  The parameter to this
 * are the shop, the player and the people (object*) for who the stuff was
 * bought and the second (string)
 * parameter is
 * the stuff that was bought.
 */
#define PUB_EVENT_BOUGHT_STUFF "bought_stuff"

/**
 * This is the event called when someonthing was attempted to be sold to some
 * dead people. The parameter to this
 * are the shop, the player and the people (object*) for who the stuff was
 * bought and the second (string)
 * parameter is
 * the stuff that was bought.
 */
#define PUB_EVENT_DEAD_PEOPLE "dead_people"

/**
 * This is the event called when the people were unable to be sold something
 * The parameter to this
 * are the shop, the player and the people (object*) for who the stuff was
 * bought and the second (string)
 * parameter is
 * the stuff that was bought.
 */
#define PUB_EVENT_FAILED_PEOPLE "failed_people"

/**
 * This is the event called when you are too poor to buy the stuff.
 * The parameter to this
 * are the shop, the player and the people (object*) for who the stuff was
 * bought and the second (string)
 * parameter is
 * the stuff that was bought.
 */
#define PUB_EVENT_POOR_PERSON "poor_people"


#endif /* __SYS__PUB_SHOP */
// --- END [/mnt/home2/grok/lib/include/shops/pub_shop.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/bank.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/bank.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630106   Available: 13577460
Inodes: Total: 5242880    Free: 4960136
391 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/bank.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630106   Available: 13577460
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for bank stuff.
 * @author Pinkfish
 * @started Mon Jun 18 16:47:06 PDT 2001
 */
#ifndef __SHOPS_BANK_H
/** @ignore yes */
#define __SHOPS_BANK_H

/**
 * This is the path to the bank credit note.
 */
#define BANK_CREDIT_NOTE "/obj/misc/bank_credit_note"

/**
 * The location of the bank handler.
 */
#define BANK_HANDLER "/obj/handlers/bank_handler"


#endif
// --- END [/mnt/home2/grok/lib/include/shops/bank.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/craft_shop.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/craft_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630106   Available: 13577460
Inodes: Total: 5242880    Free: 4960136
2165 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/craft_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630106   Available: 13577460
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the craft shop inheritable.
 * @author Pinkfish
 * @started Thu Sep 10 21:13:26 PDT 1998
 */
#ifndef __CRAFT_SHOP_H
/** @ignore yes */
#define __CRAFT_SHOP_H

/**
 * The path of the craft shop inheritable.
 */
#define CRAFT_SHOP_INHERIT "/std/shops/craft_shop"
/**
 * The path of the craft shop controller.
 */
#define CRAFT_SHOP_CONTROLLER "/std/shops/craft_shop_controller"

/**
 * This method defines the maximum number of letters a name in a 
 * craft shop can be.
 */
#define CRAFT_SHOP_MAX_NAME_LENGTH 50

/**
 * This means the main data file is being save.
 * This is the control type for the save/load functions. 
 */
#define CRAFT_SHOP_MAIN_SAVE_FILE 1
/**
 * This means the individual shop item is being saved.
 * This is the control type for the save/load functions. 
 */
#define CRAFT_SHOP_DATA_SAVE_FILE 2
/**
 * This means the individual shop item is being removed because it is no
 * longer used.  This will only be passed to the save function.
 * This is the control type for the save/load functions. 
 */
#define CRAFT_SHOP_REMOVE_DATA_SAVE_FILE 3

/**
 * The state of the category when it is being nominated as a new
 * position.
 */
#define CRAFT_CATEGORY_STATE_NOMINATING 1
/**
 * The state of the category when it is being voted into a real category
 * position.
 */
#define CRAFT_CATEGORY_STATE_VOTING     2
/**
 * The state of the category when it has been accepted and is happy about
 * it.
 */
#define CRAFT_CATEGORY_STATE_ACCEPTED   3
/**
 * The state of the category when it is being setup for deletion.
 */
#define CRAFT_CATEGORY_STATE_DELETEING  4

/**
 * This is the arguement for a yes vote.
 */
#define CRAFT_CATEGORY_CHOICE_YES 1
/**
 * This is the argument for a no vote.
 */
#define CRAFT_CATEGORY_CHOICE_NO 2
/**
 * This is the argument for a abstain vote.
 */
#define CRAFT_CATEGORY_CHOICE_ABSTAIN 3

/**
 * This is the value returned as an error from methods that normally return
 * nice happy values.
 */
#define CRAFT_CATEGORY_ERROR -1

/**
 * This is the directory to use to get help on the function names.
 */
#define CRAFT_SHOP_EXPRESSION_HELP_DIR "/doc/furniture/expressions/"

#endif
// --- END [/mnt/home2/grok/lib/include/shops/craft_shop.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/newspaper_archive.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/newspaper_archive.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630105   Available: 13577459
Inodes: Total: 5242880    Free: 4960136
1688 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/newspaper_archive.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630105   Available: 13577459
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the newspaper archive shop.
 * @author Pinkfish
 * @started Wed May 23 16:31:59 PDT 2001
 */
#ifndef __NEWSPAPER_HANDLER
/** @ignore yes */
#define __NEWSPAPER_HANDLER

/**
 * This is the event called when there are no papers to list.
 */
#define NEWSPAPER_ARCHIVE_EVENT_NO_PAPERS "no_papers"

/**
 * This is the event called when the listing is attempted to be done.
 * The extra arguments are the default output string and the
 * array of papers.
 */
#define NEWSPAPER_ARCHIVE_EVENT_LIST "list"

/**
 * This is the event called when the paper asked to be listed is 
 * non-existant.  The extra argyment to this is the paper which 
 * was entered and unable to be matched.
 */
#define NEWSPAPER_ARCHIVE_EVENT_INVALID_PAPER "invalid_paper"

/**
 * This is the event called when the edition being bought is invalid.  The
 * extra arguments are the paper name, the edition being checked.
 */
#define NEWSPAPER_ARCHIVE_EVENT_INVALID_EDITION "invalid_edition"

/**
 * This event is called when the paper is too expensive to be bought.
 * The extra arguments are the paper name, the edition being bought
 * and how much it cost.
 */
#define NEWSPAPER_ARCHIVE_EVENT_TOO_POOR "too_poor"

/**
 * This event is called to move the paper into the person's inventory.
 * The extra arguements are the paper being bought, the edition number,
 * the cost and the newspaper object.
 */
#define NEWSPAPER_ARCHIVE_EVENT_MOVE_PAPER "move_paper"

/**
 * This event is called when the paper is finally bought.  The extra
 * arguments are the paper name, the edition being bought, the cost
 * and the paper object itself.
 */
#define NEWSPAPER_ARCHIVE_EVENT_BOUGHT "bought"

#endif
// --- END [/mnt/home2/grok/lib/include/shops/newspaper_archive.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/item_shop.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/item_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630104   Available: 13577458
Inodes: Total: 5242880    Free: 4960136
2002 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/item_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630104   Available: 13577458
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for dealing with an item shop.
 * This defines all the events and anything else needed to handle
 * the shop.
 * @author Pinkfish
 * @started Thu May  3 15:12:42 PDT 2001
 */
#ifndef __SYS_SHOPS_ITEM_SHOP
/** @ignore yes */
#define __SYS_SHOPS_ITEM_SHOP

/**
 * This is the main inherit for an item shop.
 */
#define ITEM_SHOP_INHERIT "/std/shops/item_shop"
/**
 * This is the main inherit for an item shop.
 */
#define ITEM_SHOP_OUTSIDE_INHERIT "/std/shops/item_shop_outside"

/**
 * Where to find any items used by the item shop.
 */
#define ITEM_SHOP_ITEMS "/obj/misc/shops/"

/**
 * The event when the shop is closed.
 */
#define ITEM_SHOP_EVENT_CLOSE "close"
/**
 * The event when the shop has nothing to list.
 */
#define ITEM_SHOP_EVENT_NOTHING "nothing"
/**
 * The event when the shop has nothing to list.
 */
#define ITEM_SHOP_EVENT_NOTHING "nothing"
/**
 * The event when the shop is listing something.  The extra argument
 * to this is the generated list message.
 */
#define ITEM_SHOP_EVENT_LIST "list"
/**
 * The event when the shop has been given a bad item label.
 * The extra argument to this it the label they typed incorrectly.
 */
#define ITEM_SHOP_EVENT_BAD_LABEL "bad_label"
/**
 * The event when the shop has sold out of something.  The extra
 * argument to this is the thing they have sold out of.
 */
#define ITEM_SHOP_EVENT_SOLD_OUT "sold_out"
/**
 * The event when the item is too expensive to buy.  The extra
 * arguments to this is the item that is too expensive, the cost of
 * the item and the amount the player has left.
 */
#define ITEM_SHOP_EVENT_TOO_EXPENSIVE "too_expensive"
/**
 * The event when the shop is being browsed.  The extra argument
 * to this event is the objects to browse and the message made by the
 * system.
 */
#define ITEM_SHOP_EVENT_BROWSE "browse"
/**
 * The event when the shop is being bought from.  The extra argument
 * to this event is the item being bought.
 */
#define ITEM_SHOP_EVENT_BUY_THING "buy_thing"

#endif
// --- END [/mnt/home2/grok/lib/include/shops/item_shop.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shops/engrave.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shops/engrave.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630104   Available: 13577458
Inodes: Total: 5242880    Free: 4960136
222 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shops/engrave.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630104   Available: 13577458
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The shop engrave include.
 */
#ifndef __SYS_SHOP_ENGRAVE
/** @ignore yes */
#define __SYS_SHOP_ENGRAVE

/**
 * The property to check to see if the item is engraveable.
 */
#define ENGRAVE_PROP "engraveable"

#endif
// --- END [/mnt/home2/grok/lib/include/shops/engrave.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mail_track.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mail_track.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
213 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mail_track.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__MAIL_TRACK
#define __SYS__MAIL_TRACK

class mailing_list {
  string *members;
  string *controllers;
  string creator;
}

#define MAIL_ROOM "/d/admin/room/mail_room"

#endif /* __SYS__MAIL_TRACK */
// --- END [/mnt/home2/grok/lib/include/mail_track.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/twilight.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/twilight.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
163 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/twilight.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define NEVER 2
#define DAY   1
#define NIGHT 0
#define WEATHER_HANDLER         "/obj/handlers/weather.c"
#define CHANGING_OUTSIDE_OBJECT "/std/room/twilight.c"  
// --- END [/mnt/home2/grok/lib/include/twilight.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/gossip.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/gossip.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
643 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/gossip.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The header file for use with the gossip effects.
 * @author Pinkfish
 * @see /obj/handlers/gossip_handler.c
 * @see /std/effects/npc/gossip.c
 */
#ifndef __GOSSIP_H
/** @ignore yes */
#define __GOSSIP_H

/**
 * The path of the gossip handler. 
 * The handler keep tracks of the
 * saved gossip.
 * @see /obj/handlers/gossip_handler.c
 */
#define GOSSIP_HANDLER "/obj/handlers/gossip_handler"

/** The number of gossip message to save. */
#define GOSSIP_KEEP_LEVEL 50
/** The number of rumour messages to save */
#define RUMOUR_KEEP_LEVEL 20


/** Where to save the gossip information. */
#define GOSSIP_SAVE_FILE "/save/gossip"

#endif
// --- END [/mnt/home2/grok/lib/include/gossip.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/card_base.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/card_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
1431 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/card_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630103   Available: 13577457
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is a base to make up randomised decks of cards.
 * @author Pinkfish
 * @started Thu Dec  7 07:34:10 PST 2000
 */
#ifndef __CARD_BASE_H
/** @ignore yes */
#define __CARD_BASE_H

/** The suit define for hearts. */
#define CARD_SUIT_HEARTS   1
/** The suit define for diamonds. */
#define CARD_SUIT_DIAMONDS 2
/** The suit define for clubs. */
#define CARD_SUIT_CLUBS    3
/** The suit define for spades. */
#define CARD_SUIT_SPADES   4
/** The suit define for jokers. */
#define CARD_SUIT_JOKER    5

/** The number for a jack. */
#define CARD_NUMBER_JACK    11
/** The number for a jack. */
#define CARD_NUMBER_QUEEN   12
/** The number for a jack. */
#define CARD_NUMBER_KING    13
/** The number for an ace. */
#define CARD_NUMBER_ACE     1

/** When generating a hand this makes a 3x3 card. */
#define CARD_HAND_THREE         1
/** When generating a hand this makes a 3x1 card. */
#define CARD_HAND_SINGLE        2
/** When generating a hand this makes a 2x2 card. */
#define CARD_HAND_TWO           4
/** When generating a hand, this leaves off all the frilly bits. */
#define CARD_HAND_NO_ADORNMENTS 8
/** Put a set of letters over the top of the cards to match up. */
#define CARD_HAND_LETTERS       16

#ifndef CARD_BASE_NO_CLASSES
/**
 * The playing card class.
 * @element suit the suit of the card
 * @element number the number of the card
 */
class playing_card {
   int suit;
   int number;
}
#endif

#endif
// --- END [/mnt/home2/grok/lib/include/room/card_base.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/club_room.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/club_room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630102   Available: 13577456
Inodes: Total: 5242880    Free: 4960136
1737 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/club_room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630102   Available: 13577456
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This it the include file for club rooms.  It contains all the useful stuff
 * that makes club rooms thatm uch more fun.
 * @author Pinkfish
 * @started June 15th 1999
 * @see /std/room/club_room.c
 * @see /std/room/controller/club_room_controller.c
 */
#ifndef __ROOM_CLUB_ROOM_H
/** @ignore yes */
#define __ROOM_CLUB_ROOM_H

/**
 * This define sets the owned item to be controlled by discussion items.
 * @see /std/room/club_room->add_controlled_ownership()
 */
#define CLUB_ROOM_CONTROLLER_DISCUSSED 0
/**
 * This define sets the owned item to be fixed in its control.  So that
 * the default owner is the person who really owns it all the time.
 * @see /std/room/controller/club_room_controller->add_controlled_ownership()
 */
#define CLUB_ROOM_CONTROLLED_FIXED     1

/**
 * This means that the controlled item is owned by a person.
 */
#define CLUB_ROOM_OWNED_PERSON   0
/**
 * THis means that the controlled item is owned by a position.  A
 * position is something like 'president' or whatever.
 */
#define CLUB_ROOM_OWNED_POSITION 1

/**
 * This is the option stored for the club on the club controller to keep
 * track of how many boards a club has.  This allows the board to be
 * removed when the club runs out of boards.
 * @see /std/room/controller/club_room_controller.c
 */
#define CLUB_ROOM_BOARD_COUNT "board count"

/**
 * This is the bit of string put at the start of the name to check to see if
 * the marked position is a position or a person.
 * @see /std/room/controller/club_room_controller.c
 */
#define CLUB_ROOM_POSITION_START "position "

/**
 * This is the name of the main club rooms save file used by the club room
 * controller.
 */
#define CLUB_ROOM_CONTROLLER_SAVE_FILE "club_controller"

#endif
// --- END [/mnt/home2/grok/lib/include/room/club_room.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/carriage.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/carriage.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
1305 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/carriage.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the carriages.
 * @author Pinkfish
 * @started Thu Aug 15 17:29:16 PDT 2002
 */
#ifndef __CARRIAGE_H__
/** @ignore yes */
#define __CARRIAGE_H__

/**
 * The class for the stop details.
 * @member name the name of the stop
 * @member path the path to the stop
 * @member delay how long to tarry at the stop
 */
class stop_details {
   string name;
   string path;
   int delay;
}

/**
 * This is the details of each stop.
 * @member id the id of the stop
 * @member travel_time how long it takes to get here from the last stop
 */
class stop_list_details {
   string id;
   int travel_time;
}

/**
 * The specific details of the route.
 * @member colour the colour of the carriage
 * @member return_along the carriage returns along the same route
 * @member stops the details of exactly where to stop and in what order
 */
class route_details {
   string colour;
   int return_along;
   class stop_list_details* stops;
}

/** The path of the handler inherit */
#define CARRIAGE_HANDLER_INHERIT "/std/room/inherit/carriage/handler"
/** The path of the carriage inherit */
#define CARRIAGE_CARRIAGE_INHERIT "/std/room/inherit/carriage/carriage"
/** The path of the default carriage pole */
#define CARRIAGE_CARRIAGE_POLE "/std/room/inherit/carriage/carriage_pole"

#endif
// --- END [/mnt/home2/grok/lib/include/room/carriage.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/document_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/document_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
301 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/document_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __DOCUMENT_HANDLER_H
/** @ignore yes */
#define __DOCUMENT_HANDLER_H

/** Sets the type of the document as html. */
#define DOCUMENT_HTML  2
/** Sets the type of the document as nroff. */
#define DOCUMENT_NROFF 1
/** Sets the type of the document as plain. */
#define DOCUMENT_PLAIN 0

#endif
// --- END [/mnt/home2/grok/lib/include/room/document_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/room_rental.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/room_rental.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
1366 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/room_rental.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630101   Available: 13577455
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the room rental handler.
 * @author Goldenthread
 */
#ifndef __ROOM_RENTAL_H
/** @ignore yes */
#define __ROOM_RENTAL_H

/** The path of the handler. */
#define ROOM_RENTAL_HANDLER               "/obj/handlers/room_rental"
/** The path of the save file. */
#define ROOM_RENTAL_SAVE_FILE             "/save/rental_save_file"

/** The inherit for the rental rooms. */
#define ROOM_RENTAL_INHERIT_ROOM          "/std/room/inherit/room_rental"
/** The inherit for the rental office. */
#define ROOM_RENTAL_INHERIT_OFFICE        "/std/room/inherit/room_rental_office"

/** The inherit for the rental rooms ( including /std/room/basic_room ). */
#define ROOM_RENTAL_INHERIT_BASIC_ROOM    "/std/room/room_rental"
/** The inherit for the rental office ( including /std/room/basic_room ). */
#define ROOM_RENTAL_INHERIT_BASIC_OFFICE  "/std/room/room_rental_office"

/** Means the rental was successful. */
#define RENTAL_SUCCESS         0
/** Couldn't find the room to rent. */
#define RENTAL_NO_SUCH_ROOM    1
/** The room was already rented to someone else. */
#define RENTAL_ALREADY_RENTED  2
/** The room is available. */
#define RENTAL_AVAILABLE       3
/** The person trying to rent does not have enough money */
#define RENTAL_NO_MONEY        4
/** One day in seconds. (60 * 60 * 24) */
#define ONE_DAY                86400

#endif
// --- END [/mnt/home2/grok/lib/include/room/room_rental.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/auction.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/auction.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630100   Available: 13577454
Inodes: Total: 5242880    Free: 4960136
4092 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/auction.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630100   Available: 13577454
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The auction house include file.
 * @author Pinkfish
 * @started Tue May  1 01:26:28 PDT 2001
 */
#ifndef __SYS_ROOM_AUCTION_H
/** @ignore yes */
#define __SYS_ROOM_AUCTION_H

/**
 * This define is used in the function for the item for the
 * finish auction phase.
 */
#define AUCTION_FINISH_PHASE 1
/**
 * This define is used in the function for the item for the
 * withdraw auction phase.
 */
#define AUCTION_WITHDRAW_PHASE 2
/**
 * This define is used in the function for the item for the
 * claim the item auction phase.
 */
#define AUCTION_CLAIM_PHASE 3
/**
 * This define is used in the function for the item for the
 * claim the item auction phase.
 */
#define AUCTION_RETRY_PHASE 4

/**
 * The event for listing the contents of the shop.  The extra arguement is
 * the generated shoip list text.
 */
#define AUCTION_EVENT_LIST "list"
/**
 * The event for browsing a specific item for auction.  The extra arguments
 * are the auction class, the objects and the generated string.
 */
#define AUCTION_EVENT_BROWSE "browse"
/**
 * The item index was bad, unable to find the item. The extra argument is the
 * id that was bad.
 */
#define AUCTION_EVENT_BAD_ITEM "bad_item"
/**
 * The event when the bid is too small.  The extra arguements are the
 * auction class, the value of the placed bid, the new minimum bid.
 */
#define AUCTION_EVENT_BID_TOO_SMALL "bid_to_small"
/**
 * The event when the bid is below the reserve.  The extra arguements are the
 * auction class, the value of the placed bid, the reserve.
 */
#define AUCTION_EVENT_BID_BELOW_RESERVE "bid_below_reserve"
/**
 * The even when a bid is made.  The extra arguements are the auction
 * class and the bid made.
 */
#define AUCTION_EVENT_BID "bid"
/**
 * The event when the bidder is too poor.  The extra arguements are
 * auction class, the players money, the value of the placed bid.
 */
#define AUCTION_EVENT_TOO_POOR "too_poor"
/**
 * The event when an item is withdrawn.  The extra arguements are
 * the auction class of the withdrawn item.
 */
#define AUCTION_EVENT_WITHDRAW "withdraw"
/**
 * The event when an item is unable to be withdrawn.  The extra arguements are
 * the auction class of the withdrawn item.
 */
#define AUCTION_EVENT_CANNOT_WITHDRAW "cannot_withdraw"
/**
 * The event when an item is to be claimed.  The extra arguements are
 * the auction class of the claimed item, the bid and the objects claimed.
 */
#define AUCTION_EVENT_CLAIM "claim"
/**
 * The event when the person has nothing to claim.  No extra arguements.
 */
#define AUCTION_EVENT_NOTHING_TO_CLAIM "nothing_to_claim"
/**
 * The event when the shop is too full to handle the extra item.  The
 * extra arguments are the name to sell it as, the objects to sell,
 * the reserve code and the length of the auction.
 */
#define AUCTION_EVENT_FULL "full"
/**
 * The event when the player is giving a bad money spec.   The
 * extra arguments are the name to sell it as, the objects to sell,
 * the reserve code and the length of the auction.
 */
#define AUCTION_EVENT_BAD_MONEY "bad_money"
/**
 * The event when the player is about to try and add something into the shop.
 * The extra arguments are the name to sell it as, the objects to sell,
 * the reserve code and the length of the auction and the generated
 * default string.
 */
#define AUCTION_EVENT_ADD_AUCTION "add_auction"
/**
 * Ths event when the player has aborted adding an auction to the shop.
 * The extra arguments are the name to sell it as, the objects to sell,
 * the reserve code and the length of the auction.
 */
#define AUCTION_EVENT_ADD_ABORT "add_abort"
/**
 * Ths event when the player has completely added the auction to the shop.
 * The extra arguments are the name to sell it as, the objects to sell,
 * the reserve code and the length of the auction and the generated
 * default string.
 */
#define AUCTION_EVENT_CONFIRM_AUCTION "confirm_auction"
/**
 * This event is when the player does an 'info' command to find out
 * how long each of the auctions is.  The extra argument is the generated
 * info string.
 */
#define AUCTION_EVENT_INFO "info"

#endif
// --- END [/mnt/home2/grok/lib/include/room/auction.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/newspaper.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/newspaper.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630099   Available: 13577453
Inodes: Total: 5242880    Free: 4960136
2993 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/newspaper.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630099   Available: 13577453
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file support stuff for newspaper offices and the 
 * newspaper controller.
 * @author Pinkfish
 * @started Fri Apr 27 17:19:23 PDT 2001
 */
#ifndef __NEWSPAPER_H
/** @ignore yes */
#define __NEWSPAPER_H

/**
 * The location of the press creditials file.
 */
#define NEWSPAPER_PRESS_CREDITIALS "/obj/misc/press_credentials"
/**
 * The location of the newspaper handler.
 */
#define NEWSPAPER_HANDLER "/obj/handlers/newspaper"
/**
 * The location of the newspaper object itself.
 */
#define NEWSPAPER_OB "/obj/misc/newspaper"
/**
 * The location of the housing subscription box.
 */
#define NEWSPAPER_SUBSCRIPTION_OB "/obj/furnitures/misc/newspaper_box"

/**
 * This is the start bit of the file name used for the file name of the
 * newspaper logo images.
 */
#define NEWSPAPER_WWW_LOGO_BASE "/external/newspaper/logos/logo"

/**
 * This means the article is plain text type.
 */
#define NEWSPAPER_ARTICLE_TYPE_PLAIN 1
/**
 * This means the article is html.
 */
#define NEWSPAPER_ARTICLE_TYPE_HTML 2
/**
 * This means the article is nroff.
 */
#define NEWSPAPER_ARTICLE_TYPE_NROFF 3
/**
 * This means the article is a section header.
 */
#define NEWSPAPER_ARTICLE_TYPE_SECTION 4
/**
 * This means the article is the advert insert point.
 */
#define NEWSPAPER_ARTICLE_TYPE_ADVERTS 5
/**
 * This is the mask to get the nroff type stuff.
 */
#define NEWSPAPER_ARTICLE_TYPE_MASK 7

/**
 * This means the article is anonymous.
 */
#define NEWSPAPER_ARTICLE_ANONYMOUS_FLAG 1024
/**
 * This means the article has no xp given for it.
 */
#define NEWSPAPER_ARTICLE_NO_XP_FLAG     2048

/**
 * The revenue for each hit on the web page. (10 pence).
 */
#define NEWSPAPER_WEB_HIT_REVENUE 40

/**
 * This is the amount of xp a reporter gets for making an article.
 */
#define NEWSPAPER_XP_PER_ARTICLE 60000

/**
 * This is the amount of xp an editor gets as a base for publishing an
 * issue.  They also get 10% of the total reporter xp.
 */
#define NEWSPAPER_XP_EDITOR 120000

/**
 * Information about an article to be published in a newspaper.
 * @element file_name the file which has the text in it
 * @element title the title of the article
 * @element author the author of the article
 * @element date_written the date the article was written at
 * @element type the type of text that is stored, html, nroff or plain
 * @element shown_name the name to show everyone
 * @element colour the colour of the article
 */
class article {
   string file_name;
   string title;
   string author;
   int date_written;
   int type;
   string shown_name;
   string colour;
}

/**
 * Information about an advert to be published in a newspaper.
 * @element text the text of the add
 * @element title the title of the advert
 * @element author the author of the advert
 * @element category the category the advert is in
 * @element date_written the date the advert was written at
 */
class advert {
   string text;
   string author;
   string category;
   int date_written;
   int value;
}

#endif
// --- END [/mnt/home2/grok/lib/include/room/newspaper.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room/placement.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room/placement.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630098   Available: 13577452
Inodes: Total: 5242880    Free: 4960136
1050 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room/placement.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630098   Available: 13577452
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is used in conjunction with the placement inherit to handle
 * how things are placed into the room.
 */
#ifndef __ROOM_PLACEMENT_H__
/** @ignore yes */
#define __ROOM_PLACENENT_H__

/**
 * This property is used for handling the current room verb.  This is used
 * after the item has been placed.
 */
#define PLACEMENT_CURRENT_ROOM_VERB "current room verb"
/**
 * This property is used for handling the current object 'other'.  The
 * other is the 'against', 'beside' etc things.
 * This is used
 * after the item has been placed.
 */
#define PLACEMENT_CURRENT_ROOM_OTHER "current room other"
/**
 * This property is used for handling the current object position.  The
 * position is what it is beside, like 'wall', 'ceiling' etc.
 * This is used
 * after the item has been placed.
 */
#define PLACEMENT_CURRENT_ROOM_POSITION "current room position"
/**
 * This property is used to make items in the room as fixed in their current
 * place.  This way they cannot be removed or replaced.
 */
#define PLACEMENT_IMMOVABLE "immovable"

#endif
// --- END [/mnt/home2/grok/lib/include/room/placement.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/playtesters.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/playtesters.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630098   Available: 13577452
Inodes: Total: 5242880    Free: 4960136
1400 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/playtesters.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630098   Available: 13577452
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 *  Playtester header file
 *  @author Drakkos
 *  @started 23/07/2002
 *
 */
 
#ifndef __SYS__PLAYTESTER
#define __SYS__PLAYTESTER

// Domain define
#define PLAYTESTERS               "/d/playtesters/"


// General defines
#define PT_LOGS                   "/log/secure/playtesters"
#define PT_SAVE                   "/save/playtesters"
#define PLAYTESTER_HAND           "/obj/handlers/playtesters"


// Playtester domain defines
#define PLAYTESTER_CHARS          PLAYTESTERS + "chars/"
#define PLAYTESTER_DOCS           PLAYTESTERS + "doc/"
#define PLAYTESTER_ITEMS          PLAYTESTERS + "items/"
#define PLAYTESTER_PALACE         PLAYTESTERS + "palace_rooms/"
#define PLAYTESTER_INHERITS       PLAYTESTERS + "inherits/"
#define PLAYTESTER_SECURE         PLAYTESTERS + "secure/"
#define PLAYTESTER_HANDLERS       PLAYTESTERS + "handlers/"

// Doc Defines

#define PLAYTESTER_HELP           PLAYTESTER_DOCS + "help_dir/"

// Palace defines

#define PLAYTESTER_ARMOURY        (PLAYTESTER_PALACE + "armoury")
#define PLAYTESTER_ARENA          PLAYTESTER_PALACE + "arena/"
#define PLAYTESTER_COURSE         PLAYTESTER_PALACE + "course/"


// General domain object defines

#define PT_OBSTACLE_COURSE        (PLAYTESTER_INHERITS + "obstacle_course")
#define PLAYTESTER_INTERVIEW      (PLAYTESTER_PALACE + "interview")
#define PT_APPLICATION_HANDLER    (PLAYTESTER_HANDLERS + "applications")

#endif
// --- END [/mnt/home2/grok/lib/include/playtesters.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/board.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/board.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630097   Available: 13577451
Inodes: Total: 5242880    Free: 4960136
3944 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/board.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630097   Available: 13577451
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Defines and support stuff for the board handler.  This is one of the very
 * early objects/files.  One which has not changed overly much either.
 * @author Pinkfish
 */
#ifndef __SYS__BOARD
/** @ignore yes */
#define __SYS__BOARD

/**
 * The master object.
 */
#define MASTER_OB "/secure/master"
/**
 * The name of the property on the player that has the news rc.  The news RC
 * is the last time each board was read.
 */
#define NEWS_RC "news rc"
/**
 * This is the property on the player that stores the board order.  The
 * board order is the order in which the boards are read from the web and
 * by using the 'new' word inside the mud itself.
 */
#define BOARD_ORDER "board order"
/**
 * This is the main save file for the board handler.  It has the current
 * boards, subjects, permissions etc saved to it.
 */
#define BOARD_FILE "/save/boards.o"
/**
 * This is the directory into which the individual board messages are
 * saved.
 */
#define BOARD_DIR "/save/boards/"

/**
 * This is the directory into which the individual board messages are
 * saved temporarily.
 */
#define BOARD_RAM_DIR "/save/ramdisk/boards/"

/**
 * The path to the board handler object itself.
 */
#define BOARD_HAND "/obj/handlers/board_handler"
/**
 * The path to the web board reader.
 */
#define BOARD_WEB "/www/boards"

/**
 * The index into the subject array that is the subject.
 * @see /obj/handlers/board_handler->get_subjects()
 */
#define B_SUBJECT 0
/**
 * The index into the subject array that is the name of the person who
 * posted the note.
 */
#define B_NAME 1
/**
 * The index into the subject array that is the note number associated with
 * the note.
 */
#define B_NUM 2
/**
 * The index into the subject array that contains the time the note was
 * posted.
 */
#define B_TIME 3
/**
 * The index into the subject array that determines who the followups and
 * replies to the note should go to.  If this value is 0 then the
 * followups go to the board and the replies go to the person who
 * posted it.  If it is a string then the followups and replies go to the
 * person in the string.
 */
#define B_REPLY_TYPE 4
/**
 * The index into the subject array that points back to the message we
 * followed up to.
 */
#define B_REPLY_NUM 5

class reply_type {
   int type;
   mixed data;
}

/**
 * This is the type to use if the reply should be mailed to the
 * poster.
 */
#define B_REPLY_POSTER 1
/**
 * This is the type to use if the reply should be mailed to the specified
 * person in the data field.
 */
#define B_REPLY_NAMED 2

/**
 * This is the parameter passed in the access method if the check is for
 * reading.
 */
#define B_ACCESS_READ 1
/**
 * This is the parameter passed in the access method if the check is for
 * writing.
 */
#define B_ACCESS_WRITE 2
/**
 * This is the parameter passed in the access method if the check is for
 * deleting.
 */
#define B_ACCESS_DELETE 3
/**
 * This is the parameter passed in the access method if the check is for
 * approving a post.
 */
#define B_ACCESS_APPROVE 4
/**
 * This is the parameter passed in the access method when an inform
 * is required.
 */
#define B_ACCESS_INFORM 5

/**
 * The default privilages for a board.
 */
#define B_PRIV_NORMAL                 0
/**
 * Make the board read only.
 */
#define B_PRIV_READ_ONLY              1
/**
 * Restrict access to a specified group of people.
 */
#define B_PRIV_ACCESS_RESTRICTED      2
/**
 * Restrict access to a specified group of files.
 */
#define B_PRIV_ACCESS_RESTRICTED_FILE 3
/**
 * Don't inform people when messages are posted.
 */
#define B_PRIV_NO_INFORM              256
/**
 * The type mask.
 */
#define B_PRIV_TYPE_MASK              255
/**
 * Do all the access checks and everything through another function check in
 * another file.
 */
#define B_PRIV_ACCESS_RESTRICTED_METHOD 4

/**
 * This amount of social points used to post to the boards.
 */
#define BOARD_SOCIAL_POINT_COST 50

#endif /* __SYS__BOARD */
// --- END [/mnt/home2/grok/lib/include/board.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/socket.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/socket.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630096   Available: 13577450
Inodes: Total: 5242880    Free: 4960136
222 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/socket.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630096   Available: 13577450
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__SOCKET
#define __SYS__SOCKET

#include <socket_errors.h>

#define MUD 0
#define STREAM 1
#define DATAGRAM 2
#define STREAM_BINARY 3
#define DATAGRAM_BINARY 4
#define INETD_TYPE 5

#endif /* __SYS__SOCKET */
// --- END [/mnt/home2/grok/lib/include/socket.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/udp.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/udp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630096   Available: 13577450
Inodes: Total: 5242880    Free: 4960136
1484 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/udp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630096   Available: 13577450
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__UDP
#define __SYS__UDP

#ifndef __UDP_H
#define __UDP_H
#define NAMESERVER_CD "/net/nameserver_cd"
#define UDP_PATH "/net/udp/"
#define NETMAIL_D "/net/daemon/netmaild"

#define PING_Q (UDP_PATH+"ping_q")
#define PING_A (UDP_PATH+"ping_a")

/* #define MUDLIST_UDP ({ "milou.cd.chalmers.se", 2500 }) */
/* #define MUDLIST_UDP ({ "199.199.122.10", 1709 })
 * We need the ip number, the current socket efuns don't handle using names.
 */
#define MUDLIST_UDP ({ "165.95.7.122", 5678, "199.199.122.10", 1709, "129.16.117.21", 2500, "198.69.82.2", 5563, "129.10.114.86", 5563 })


/* The currently known types */
#define UDP_STARTUP "startup"
#define UDP_SHUTDOWN "shutdown"
#define UDP_BOARD_Q "board_q"
#define UDP_PING_Q "ping_q"
#define UDP_PING_A "ping_a"
#define UDP_SUPPORT_Q "support_q"
#define UDP_SUPPORT_A "support_a"
#define UDP_RWHO_Q "rwho_q"
#define UDP_RWHO_A "rwho_a"
#define UDP_MUDLIST_Q "mudlist_q"
#define UDP_MUDLIST_A "mudlist_a"
#define UDP_GFINGER_Q "gfinger_q"
#define UDP_GFINGER_A "gfinger_a"
#define UDP_WARNING "warning"
#define UDP_GTELL "gtell"
#define UDP_GWIZMSG "gwizmsg"
#define UDP_AFFIRMATION_A "affirmation_a"
#define UDP_MAIL_A "mail_a"
#define UDP_MAIL_Q "mail_q"
#define UDP_LOCATE_Q "locate_q"
#define UDP_LOCATE_A "locate_a"

/*
 * This is the number of retrys we ping the mud for before we decide
 * it has gone down.
 */
#define MAX_RETRYS 2
#define UDP_NO_CONTACT "_udp_no_contact"
#endif /* __UDP_H */

#endif /* __SYS__UDP */
// --- END [/mnt/home2/grok/lib/include/udp.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/underworld.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/underworld.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630095   Available: 13577449
Inodes: Total: 5242880    Free: 4960136
1081 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/underworld.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630095   Available: 13577449
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming

#define UNDERWORLD  "/d/underworld/"

#define DEATH           "/d/underworld/death/"
#define DEATH_INSIDE    DEATH +"inside/"
#define DEATH_OUTSIDE   DEATH +"outside/"
#define DEATH_LIFE      DEATH +"life_rooms/"
#define DEATH_CHARS     DEATH +"chars/"
#define DEATH_ITEMS     DEATH +"items/"

#define DEATH_NEW       UNDERWORLD + "death_new/"

#define DOPPLES         UNDERWORLD + "dopples/"
#define DOPPLES_SAVE    DOPPLES + "save/"

#define MOVING_SHOP             UNDERWORLD + "moving_shop/"
#define MOVING_SHOP_INHERITS    MOVING_SHOP +"inherits/" 
#define MOVING_SHOP_CHARS       MOVING_SHOP +"chars/"
#define MOVING_SHOP_EFFECTS     MOVING_SHOP +"effects/"
#define MOVING_SHOP_ITEMS       MOVING_SHOP +"items/"
#define MOVING_SHOP_ROOMS       MOVING_SHOP +"rooms/"
#define MOVING_SHOP_SHADOWS     MOVING_SHOP +"shadows/"
#define MOVING_SHOP_SPELLS      MOVING_SHOP +"spells/"

#define PLANES "/d/underworld/planes/"
#define AWFFICE PLANES +"awffice/"

#define DEMONS "/d/underworld/demons/"
#define ELEMENTALS "/d/underworld/elementals/"
#define IMPS "/d/underworld/imps/"
// --- END [/mnt/home2/grok/lib/include/underworld.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mineral.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mineral.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630095   Available: 13577449
Inodes: Total: 5242880    Free: 4960136
159 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mineral.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630095   Available: 13577449
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__MINERAL
#define __SYS__MINERAL

#define PEBBLE 5
#define STONE 20
#define ROCK 1000
#define MINERAL "/obj/mineral"

#endif /* __SYS__MINERAL */
// --- END [/mnt/home2/grok/lib/include/mineral.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/creator.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/creator.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630094   Available: 13577448
Inodes: Total: 5242880    Free: 4960136
456 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/creator.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630094   Available: 13577448
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef _CREATOR_H
#define _CREATOR_H

#define WIZ_PRESENT "/global/wiz_present"
#define PEOPLER "/obj/handlers/peopler"
#define RCS_HANDLER "/secure/rcs_handler"

#define NO_CHANNELS ({ "admin", "fluffy", "liaison", "playtesters" })
#define ADDITIONAL_CHANNELS ({ "code", "cre", "liaison" })
#define INTERMUD_MAP ([ "dwchat" : "discworld-chat", "dwcre" : "discworld-cre", "intergossip" : "imud_gossip", "intercre" : "imud_code"])

#endif /* _CREATOR_H */
// --- END [/mnt/home2/grok/lib/include/creator.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/terrain_map.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/terrain_map.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630094   Available: 13577448
Inodes: Total: 5242880    Free: 4960136
6672 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/terrain_map.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630094   Available: 13577448
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the terrain map system.
 * @author Dek
 */
#ifndef __TERRAIN_MAP_H
/** @ignore yes */
#define __TERRAIN_MAP_H

/**
 * The location of the world map controller.  Any terrain map that has
 * a real co-ordinate registers itself with the map controller.
 */
#define TERRAIN_MAP_WORLD_MAP "/obj/handlers/world_map"

/**
 * The location of the terrain map files.
 */
#define TERRAIN_MAP              "/std/room/inherit/terrain_map/"

/**
 * The define for the inherit for the local feature base.
 */
#define TERRAIN_MAP_FEATURE_LOCAL  TERRAIN_MAP + "feature_local"
/**
 * The define for the inherit for the simple feature base.
 */
#define TERRAIN_MAP_SIMPLE_FEATURE_BASE  TERRAIN_MAP + "simple_feature"
/**
 * The define for the inherit for the feature base.
 */
#define TERRAIN_MAP_FEATURE_BASE  TERRAIN_MAP + "feature_base"
/**
 * The define for the inherit for the distance stuff.
 */
#define TERRAIN_MAP_DISTANCE_BASE  TERRAIN_MAP + "distance_str"

/**
 * The define for the region class for rectangular regions.
 */
#define TERRAIN_MAP_REGION_RECTANGULAR  TERRAIN_MAP + "region_rect"
/**
 * The define for the region class for polygon regions.
 */
#define TERRAIN_MAP_REGION_POLYGON  TERRAIN_MAP + "region_poly"
/**
 * The define for the region class for line regions.
 */
#define TERRAIN_MAP_REGION_LINE  TERRAIN_MAP + "region_line"

/**
 * The define for the inherit for the terrain handler.
 */
#define TERRAIN_MAP_HANDLER_BASE  TERRAIN_MAP + "handler_base.c"
/**
 * The define for the inherit for the factory type of an inherit.
 * THis is used in the case where you want to define something about
 * a group of shared rooms (shared between other factories) and yet
 * want to customise some specific part about they work.  For
 * example see the seas.
 */
#define TERRAIN_MAP_FACTORY     TERRAIN_MAP + "factory.c"
/**
 * The base to use for factories.  Do not include this into
 * production code.
 */
#define TERRAIN_MAP_FACTORY_BASE     TERRAIN_MAP + "factory_base.c"
/**
 * The define for the inherit for the basic room functionality.  This
 * will need to be inherited into any room used in the terrain.
 */
#define TERRAIN_MAP_ROOM_BASE     TERRAIN_MAP + "terrain_room.c"
/**
 * The base file for outside areas.
 */
#define TERRAIN_MAP_OUTSIDE_BASE  TERRAIN_MAP + "outside_base.c"
/**
 * The base file for outside water areas.
 */
#define TERRAIN_MAP_WATER_OUTSIDE_BASE  TERRAIN_MAP + "water_outside_base.c"
/**
 * The base file for inside water areas.
 */
#define TERRAIN_MAP_WATER_INSIDE_BASE  TERRAIN_MAP + "water_inside_base.c"
/**
 * The base file for inside areas.
 */
#define TERRAIN_MAP_INSIDE_BASE   TERRAIN_MAP + "inside_base.c"
/**
 * The base for for air rooms.
 */
#define TERRAIN_MAP_AIR_BASE TERRAIN_MAP + "air_base.c"

/**
 * This is the size
 * of one mile in co-ordinates.
 */
#define TERRAIN_MAP_ONE_MILE 73920
/**
 * This is the size
 * of one mile in co-ordinates.
 */
#define TERRAIN_MAP_HALF_MILE 36960

/**
 * Smallest terrain we will deal with in the terrain system.
 * (7 miles).
 */
#define TERRAIN_MAP_GRID_SIZE (7 * TERRAIN_MAP_ONE_MILE)

/**
 * This is the property to check on the player to see if the map should
 * be displayed in the long or not.
 */
#define TERRAIN_MAP_IN_LOOK_PROP "terrain map look"
/**
 * This is the property to check on the player to see if you should jump
 * or not.
 */
#define TERRAIN_MAP_LONG_JUMP_PROPERTY "terrain map jump"

/**
 * This is the flag to use for making the feature use whole sentances.
 */
#define TERRAIN_MAP_WHOLE_SENTANCE_FLAG 1
/**
 * This is the flag to use for making the feature blocking.  If a feature
 * is blocking then you cannot see other features behind it.
 */
#define TERRAIN_MAP_BLOCKING_FLAG       2

/**
 * This is the start bit for a 'journey' exit.
 */
#define TERRAIN_MAP_JOURNEY_EXIT "journey "
/**
 * This is the start bit for a 'walk' exit.
 */
#define TERRAIN_MAP_WALK_EXIT "walk "

/**
 * This is the air room to use if nothing else is specfied.
 */
#define TERRAIN_MAP_DEFAULT_AIR_ROOM "/room/air_terrain"

/**
 * The class with the coordinate definitions in it.
 * @member x the x coordinate
 * @member y the y coordinate
 * @member z the z coordinate
 */
class coord {
   int x;
   int y;
   int z;
}

/**
 * This define is used by the world map to determine where to put
 * areas in the world.
 */
#define TERRAIN_MAP_WORLD_BOUNDARY (56 * TERRAIN_MAP_ONE_MILE)
/**
 * This define is used by the world map to determine how many areas are
 * in each region.  An area is each terrain map square, if you look
 * at the co-ordinates in the terrain handlers it fits to these values.
 */
#define TERRAIN_MAP_WORLD_REGION_SIZE 15
/**
 * This define is used by the world map to detmine the boundary of a
 * region.  You add the offset onto the co-ordinate and divide by the
 * boundary to get the area.  You then divide by the region size to get
 * the region.
 */
#define TERRAIN_MAP_WORLD_REGION_BOUNDARY (TERRAIN_MAP_WORLD_REGION_SIZE * BOUNDARY)
/**
 * This define is used by the world map to detmine the offset value to
 * co-ordinates.  This makes sure all the region values are positive.
 * You add the offset onto the co-ordinate and divide by the
 * boundary to get the area.  You then divide by the region size to get
 * the region.
 */
#define TERRAIN_MAP_WORLD_OFFSET (100 * TERRAIN_MAP_WORLD_BOUNDARY)
/**
 * This is the width of the region in areas.
 */
#define TERRAIN_MAP_WORLD_REGION_WIDTH 15

/**
 * This is the size of the world in pixels.  There are 4 pixels to a terrain
 * map, so 4 to an area.
 */
#define TERRAIN_MAP_WORLD_PIXEL_WIDTH 768

/**
 * This is the lowest x coordinate of the world.
 */
#define TERRAIN_MAP_WORLD_LOW_X (-(TERRAIN_MAP_WORLD_PIXEL_WIDTH / 2) * TERRAIN_MAP_GRID_SIZE * 10)
/**
 * This is the lowest y coordinate of the world.
 */
#define TERRAIN_MAP_WORLD_LOW_Y (-(TERRAIN_MAP_WORLD_PIXEL_WIDTH / 2) * TERRAIN_MAP_GRID_SIZE * 10)
/**
 * This is the highest x coordinate of the world.
 */
#define TERRAIN_MAP_WORLD_HIGH_X ((TERRAIN_MAP_WORLD_PIXEL_WIDTH / 2) * TERRAIN_MAP_GRID_SIZE * 10)
/**
 * This is the highest y coordinate of the world.
 */
#define TERRAIN_MAP_WORLD_HIGH_Y ((TERRAIN_MAP_WORLD_PIXEL_WIDTH / 2) * TERRAIN_MAP_GRID_SIZE * 10)

/**
 * This is the type to use when doing a find for the exactly room.
 */
#define TERRAIN_MAP_ROOM_EXACT 0
/**
 * This is the type to use when doing a find for a room to use for
 * the map.
 */
#define TERRAIN_MAP_ROOM_MAP   1
/**
 * This is the type to use when doing a find for a possible climbing
 * room.  A climbing room is a room which goes up or down from the
 * current height location.
 */
#define TERRAIN_MAP_ROOM_CLIMB 2


#endif
// --- END [/mnt/home2/grok/lib/include/terrain_map.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/assassin.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/assassin.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630092   Available: 13577446
Inodes: Total: 5242880    Free: 4960136
1633 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/assassin.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630092   Available: 13577446
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <guilds.h>

#ifndef __ASSASSIN_H
#define __ASSASSIN_H

#define ASSASSIN              "/std/guilds/assassin"
#define ASSASSINS             ( GUILDS + "assassins/" )
#define ASSASSIN_INHERIT      ( ASSASSINS + "inherit/" )
#define ASSASSIN_HANDLERS     "/obj/handlers/guild_things/"

#define ASSASSIN_AM           ( ASSASSINS + "Ankh-Morpork/" )
#define ASSASSIN_GENUA        ( ASSASSINS + "Genua_dev/" )
#define ASSASSIN_OC           ( ASSASSINS + "Ohulan-Cutash/" )
#define ASSASSIN_KLK          ( ASSASSINS + "Khot-lip-khin/" )
#define ASSASSIN_SHEEPRIDGE   ( ASSASSINS + "Sheepridge/" )

#define ASSASSINCHARS         ( ASSASSINS + "chars/" )
#define ASSASSINITEMS         ( ASSASSINS + "items/" )

#define ASSASSIN_SAVE         ( GUILDSAVE + "assassins/" )
#define ASSASSIN_WARDROBES    ( ASSASSIN_SAVE + "wardrobes/" )
#define ASSASSIN_VOTES        ( ASSASSIN_SAVE + "votes/" )
#define ASSASSIN_AM_SAVE      ( ASSASSIN_SAVE + "Ankh-Morpork/" )
#define ASSASSIN_OC_SAVE      ( ASSASSIN_SAVE + "Ohulan-Cutash/" )

#define RUN_HANDLER           ( ASSASSIN_HANDLERS + "run" )
#define ROOM_TRACKER          ( ASSASSIN_HANDLERS + "assassins_gm_room_tracker" )

#define GUILDROOM             ( ASSASSIN_INHERIT + "guildroom" )
#define RUNROOM               ( ASSASSIN_INHERIT + "runroom" )
#define INSIDERUN             ( ASSASSIN_INHERIT + "insiderun" )
#define OUTSIDERUN            ( ASSASSIN_INHERIT + "outsiderun" )
#define ASSASSINS_SHOP        ( ASSASSIN_INHERIT + "assassins_shop" )
#define INHUMATION_OFFICE     ( ASSASSIN_INHERIT + "inhumation_office" )

#define DISAVOWED             "/std/guilds/disavowed"

#endif
// --- END [/mnt/home2/grok/lib/include/assassin.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/philosophies.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/philosophies.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630092   Available: 13577446
Inodes: Total: 5242880    Free: 4960136
267 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/philosophies.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630092   Available: 13577446
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __PHILOSOPHIES_H__
#define __PHILOSOPHIES_H__

/**
 * This file defines all the paths needed for the philosophies handler.
 * @author Deutha
 */

/**
 * The path to the philosophies handler.
 */
#define PHILOSOPHY_HANDLER "/obj/handlers/philosophies"

#endif
// --- END [/mnt/home2/grok/lib/include/philosophies.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/quest_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/quest_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
146 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/quest_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__QUEST_HANDLER
#define __SYS__QUEST_HANDLER

#define QUEST_HANDLER "/obj/handlers/quest_handler"

#endif /* __SYS__QUEST_HANDLER */
// --- END [/mnt/home2/grok/lib/include/quest_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ed.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ed.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
281 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ed.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__ED
#define __SYS__ED

#define LOG_FILE "/save/board/LOG"
#define TEMP_DIR "/tmp/"
#define TMP_FILE TEMP_DIR+"board."+(string)this_player()->query_name()+".tmp"
#define ED_HELP_FILE "/doc/concepts/edit_help"
#define PRESTOS_ED "/global/magic"

#endif /* __SYS__ED */
// --- END [/mnt/home2/grok/lib/include/ed.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/effects/stat_adjustment.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/effects/stat_adjustment.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
338 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/effects/stat_adjustment.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This include file contains all the defines for the stat adjustment
 * effects.
 * @author Pinkfish
 * @started Sun May  7 14:56:44 PDT 2000
 */
#ifndef __STAT_ADJUSTMENT
/** @ignore yes */
#define __STAT_ADJUSTMENT

/**
 * The path to the effects.
 */
#define STAT_ADJUSTMENT_EFFECT "/std/effects/attached/stat_adjustment"

#endif
// --- END [/mnt/home2/grok/lib/include/effects/stat_adjustment.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/player.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/player.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
6701 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/player.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630091   Available: 13577445
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file conatins all the defintions and stuff to handle the player
 * object.
 * @author Pinkfish
 */
#ifndef __SYS__PLAYER
/** @ignore yes */
#define __SYS__PLAYER

#include <playtesters.h>

/** The message to print for not having enough social points. */
#define NO_POWER "Insufficient Social Points.\n"
/** The message to print when you do not have the ability to do something. */
#define NOT_ALLOWED "You do not have that ability yet.\n"
/** The base cost of a shout in social points. */
#define SHOUT_COST 10
/** The base cost of a tell in social points. */
#define TELL_COST 1
/** The base cost of an emote in social points. */
#define EMOTE_COST 1
/** The base cost of a remote in social points. */
#define REMOTE_COST 5
/** The base cost of an echo in social points. */
#define ECHO_COST 1
/** The base cost of an echoto in social points. */
#define ECHOTO_COST 40
/** The base cost of an emoteall in social points. */
#define EMOTEALL_COST 8
/** The base cost of a soul in social points. */
#define SOUL_COST 3
/** The cost of setting a position with the 'position' command */
#define SET_POSITION_COST 100
/** The property which keeps track of if new lines are printed or not. */
#define NO_LINE_PROP "no new line"
/** The standard race used by all players. */
#define RACE_STD "/std/races/human"
/** The maximum amount of idle time for a player. */
#define MAX_IDLE 900
/** The idle time at which they can be kicked off if the mud is full. */
#define FULL_IDLE 300
/**
 * The age in days at which you are considered to be mature.
 * @see /globla/player->query_mature()
 */
#define MATURITY 18

/** The character which is death.  This is the path to the poor thing. */
#define DEATH "/d/underworld/death/chars/death"
/** The book to give to people when they die. */
#define DEAD_BOOK "/obj/misc/dead_book"
/** The shadow to use when your dead, to stop most things from happening. */
#define DEATH_SHADOW "/std/shadows/misc/death_shadow"
/** The object which is offler.  This is used to shut the mud down. */
#define OFFLER "/obj/shut"
/**
 * The shadow offler gives you when your close to shutdown to stop certain
 * things from happening.
 */
#define OFFLER_SHADOW "/std/shadows/misc/offler_shadow"

/**
 * This is the amount of time between the muds automatic saves of the
 * players data.
 */
#define TIME_BETWEEN_SAVES 450
/** The property that is defined on a person when they pass out. */
#define PASSED_OUT_PROP "passed out"

/** The size of the tell history. */
#define MAX_TELL_HIS 20

/** The default amount of time in each round (heart_beat). */
#define ROUND_TIME 40
/** The default amount of time an action will take. */
#define DEFAULT_TIME 20 /* Time for a move or a look. */

/** The speed at which combat occurs, number of attacks a round. */
#define COMBAT_SPEED 2
/** Something neato to do with combat damage. */
#define COMBAT_DAMAGE 2

/**
 * The time at which to start warming people that the person being told is
 * idle.
 */
#define TELL_WARN_TIME 120
/** The maximum size allowed to be set for your description. */
#define MAX_DESC 2048

/** The object which defines all the stuff you get when you start the game. */
#define START_PLAYER "/global/newbie_junk"

/** The property to be used for defining a player killer. */
#define PKER "player_killer"
/** The misspelt property to be used for defining a player killer. */
#define PKER_MISSPELL "player killer"
/** The age you need to be to become a player killer. (2 days). */
#define PKER_MINIMUM_AGE (60 * 60 * 24 * 2)
/**
 * This property (if set on a player) means that they cannot become a
 * player killer.
 */
#define PKER_NOT_ALLOWED "not to be pk"

/** role playing mode property */
#define RPMODE "role_playing"

/** Minimum time between saves using save command. */
#define MIN_SAVE_REPEAT 900

/** The path to the player file. */
#define PLAYER_OB "/global/player"
/** The path to the creator file.  */
#define CREATOR_OB "/global/creator"
/** The path to the lord file.  */
#define LORD_OB "/global/lord"

/** The path to the auto load object. */
#define AUTO_LOAD_OB "/global/auto_load"
/** The missing item receipt path. */
#define PLAYER_RECEIPT "/obj/misc/al_receipt"

/** The unknown birthday type. */
#define UNKNOWN_BIRTHDAY "Unknown"

/** This is where the bodies of dead players are sent. */
#define PLAYER_MORGUE "/room/morgue"

/** This property is set on the player if they wish to allow
 * coloured souls to be received.
 */
#define PLAYER_ALLOW_COLOURED_SOULS "coloured souls"

/** This property is set on the player if they wish to see terrain
 * maps without colour
 */
#define PLAYER_PLAIN_MAPS "plain maps"

/**
 * This is the path to the title handler for the player.  Does all the
 * wonderful stuff to do with player title control.
 */
#define PLAYER_TITLE_HANDLER "/obj/handlers/title_handler"
/**
 * This is the path to the multiplayer handler.
 */
#define PLAYER_MULTIPLAYER_HANDLER "/obj/handlers/multiplayer"

/**
 * This it the maximum length that a friend tag can be.
 */
#define PLAYER_MAX_FRIEND_TAG_LEN 50

/** The property for earmuffs. */
#define PLAYER_EARMUFF_PROP "earmuffs"
/** The value to the earmuff that allows friends through */
#define PLAYER_ALLOW_FRIENDS_EARMUFF 2
/** The value to the earmuff that turns on earmuffs normally. */
#define PLAYER_EARMUFF_ON 1
/** The value to the earmuff that turns on earmuffs normally. */
#define PLAYER_EARMUFF_OFF 0

/** This is the flag to use in the flags variable to test for pk status. */
#define PLAYER_KILLER_FLAG 1

/** @ignore yes
 * Default nationality & region for guests
 */
#define DEFAULT_NATIONALITY "/std/nationality/morpork"
/** The default region for a player to be in. */
#define DEFAULT_REGION "Ankh-Morpork"

/**
 * The property to use for testing to see what errors should be shown
 * to creators.
 */
#define PLAYER_SHOW_ERRORS_PROP "show errors"

/**
 * This property to control how follow is responded to.
 */
#define PLAYER_OPTIONS_CONTROL_PROP "follow control"

#ifdef PLAYER_OPTIONS_CLASS
/**
 * The options control class.  Deals with all the properties of following
 * someone.
 * @member follow_friends allow the person to follow friends
 * @member follow_groups allow the person to follow groups
 * @member follow_everyone allow the person to auto follow everyone
 * @member lead_behind leads from behind
 * @member mxp_toggle the mxp toggle
 * @member extra any extra options
 */
class player_options_control {
   int follow_friends;
   int follow_groups;
   int follow_everyone;
   int lead_behind;
   int mxp_disable;
   mapping extra;
}
#endif

/**
 * THis is the path to the drunk effect.
 */
#define PLAYER_DRUNK_EFFECT "/std/effects/ingested/drunk"

#endif /* __SYS__PLAYER */
// --- END [/mnt/home2/grok/lib/include/player.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/vault.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/vault.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630089   Available: 13577443
Inodes: Total: 5242880    Free: 4960136
819 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/vault.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630089   Available: 13577443
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The basic include file for vaults.
 */
#ifndef __VAULT_H
/** @ignore yes */
#define __VAULT_H

#include <money.h>

/**
 * The basic cost of a vault.
 */
#define FEE_AMT 100
/**
 * The amount of a vault.
 */
#define INIT_AMT 2000

//#define FEE_AMT_STRING "twenty five pence"
/**
 * Turn the basic cost into a string based on the current
 * currency of the room.
 */
#define FEE_AMT_STRING (string)(MONEY_HAND->money_value_string(100, this_object()->query_property("place")))
     
//#define INIT_AMT_STRING "five dollars"
/**
 * Turn the initial cost into a string based on the current
 * currency of the room.
 */
#define INIT_AMT_STRING (string)(MONEY_HAND->money_value_string(2000, this_object()->query_property("place")))

/**
 * The save directory for vaults.
 */
#define VAULT_SAVE "/save/vaults/"

#endif
// --- END [/mnt/home2/grok/lib/include/vault.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mudwho.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mudwho.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630088   Available: 13577442
Inodes: Total: 5242880    Free: 4960136
109 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mudwho.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630088   Available: 13577442
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__MUDWHO
#define __SYS__MUDWHO

#define CMWHOD "/net/daemon/cmwhod"

#endif /* __SYS__MUDWHO */
// --- END [/mnt/home2/grok/lib/include/mudwho.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/hospital.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/hospital.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630088   Available: 13577442
Inodes: Total: 5242880    Free: 4960136
4700 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/hospital.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630088   Available: 13577442
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __STD_HOSPITAL_H
#define __STD_HOSPITAL_H

#define HOSPITAL_ALIGNMENT_INHERIT "/std/hospital/alignment"

#define REGEN_TIME (1 * 60 * 60)
#define DEFAULT_MAX_CACHE 10
/**
 * This controls where the hospital will log to by default if a logging 
 * directory is not set.
 */
#define DEFAULT_LOG_DIRECTORY "/log"
/**
 * This defines the default population for a group of NPCs if a default
 * is not set.
 */ 
#define DEFAULT_POPULATION 3
#define MINIMUM_DEATH_REGEN 3

/**
 * How often we recheck the population to make sure 0's etc have not snuck
 * in.
 */ 
#define POPULATION_UPDATE_TIME 15 * 60

/**
 * This class stores information about a regenerated NPC.
 * @param type the type of NPC that is to be regenerated
 * @param load_position the file name of the room where the NPC will 
 * regenerate.
 */ 
class regenerated_npc {
    string type;
    string load_position;
}

/**
 * This class stores all the information about a zone.
 * @param wealth The wealthiness of the zone (unused)
 * @param busy The business of the zone. ie. how frequently NPCs should be
 * created.
 * @param npc_chance The total chances for an npc in this zone.
 * @param npcs A list of the NPCs that are members of this zone.
 * @param group_chance The total chances for a group in this zone.
 * @param groups A list of the groups of NPCs in this zone.
 * @param zone_chance The total chances for a zone in this zone.
 * @param zones A list of the zones within this zone.
 */
class zone_info {
   int wealth;
   int busy;

   int npc_chance;
   mapping npcs;
   int group_chance;
   mapping groups;
   int zone_chance;
   mapping zones;
}

/**
 * This class stores all the information about unique NPCs.
 * @param next_regen_time When this npc will next regenerate.
 */
class unique_npc {
   int next_regen_time;
}

/**
 * This class stores all the information about a particular NPC.
 *
 * @param path The relative path of the NPC
 * @param unique Is the NPC unique?
 * @param delay The regeneration delay for this NPC
 * @param transient If this NPC is transient.
 * @param nocturnal If this NPC is nocturnal.
 * @param diurnal If this NPC is diurnal.
 * @param seasonal A list of seasons during which this NPC is active.
 * @param max_population How many of these NPCs can exist at a time.
 * @param move_zones The move zones for this NPC
 * @param commands Commands to be executed by the NPC when it is created.
 * @param population A cache of the current population
 * @param no_deaths The number of recorded deaths
 * @param no_created The number of these NPCs we've created
 * @param no_reused How many of these NPCs have been reused (recycled)
 * @param next_update When the population data will next be updated.
 */
class npc_info {
   string path;
   int unique;
   int delay; // used by unique npcs

   int transient;
   int nocturnal;
   int diurnal;

   string* seasonal;
   
   int max_population;
   string* move_zones;
   string* commands;

   // Tracking information
   object* population;
   int no_deaths;
   int no_created;
   int no_reused;
   int next_update;
}

/**
 * This class stores all the information about an NPC group.
 *
 * @param move_zones The move zones for this NPC
 * @param npcs A list of the NPCs within this group.
 * @param npc_commands A list of commands to be executed on each of the group
 * members when the group is created.
 * @param protect Should these group members protect each other.
 * @param defend Should these group members defend each other.
 * @param transient Should these group members be considered transient.
 * @param max_population How many of these NPCs can exist at a time.
 * @param storage A cache of the population of NPCs in this group.
 * @param no_creates The number of these NPCs we've created
 * @param next_update When the population data will next be updated.
 */
class group_info {
   string* move_zones;
   // This is a list of npcs with a name as the key and a quantity as the value.
   mapping npcs;
   mapping npc_commands;
   int protect;
   int defend;
   int transient;
   
   int max_population;

   // Tracking details.
   mixed* storage;
   int no_creates;
   int next_update;
}

// These are old defines from some old hospital which AFAIK isn't actually
// being used anymore. Nevertheless, retained for backwards compatibility.
/*
 * Defines for hospitals on Discworld
 */
#define MONSTER "/obj/monster"

// the max number of named living objects. This is used to keep the regen
// rate under control.
#define MAX_NAMED_LIVING 600

#define MAX_AM_LIVING 450
// Due to the way the hospital works in KLK this is the number of
// hospital NPCs other npcs aren't counted.
#define MAX_DJEL_LIVING 100

#endif // __STD_HOSPITAL_H
// --- END [/mnt/home2/grok/lib/include/hospital.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/fuel_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/fuel_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630087   Available: 13577441
Inodes: Total: 5242880    Free: 4960136
112 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/fuel_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630087   Available: 13577441
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define FUEL_TIME 15 /* time between calls of consume_fuel */
#define FUEL_HANDLER "/obj/handlers/fuel_handler"
// --- END [/mnt/home2/grok/lib/include/fuel_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/network.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/network.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630087   Available: 13577441
Inodes: Total: 5242880    Free: 4960136
2742 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/network.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630087   Available: 13577441
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This header includes all the network defines.
 */
#ifndef __NETWORK_H 
/** @ignore yes */
#define __NETWORK_H 
 
#include <socket_errors.h> 

/**
 * The parameter to the socket_create efun, makes a mud type socket.
 */ 
#define MUD                       0 
/**
 * The parameter to the socket_create efun, makes a stream type socket.
 */ 
#define STREAM                    1 
/**
 * The parameter to the socket_create efun, makes a datagram type socket.
 */ 
#define DATAGRAM                  2 
/**
 * The parameter to the socket_create efun, makes a binary stream type socket.
 */ 
#define STREAM_BINARY             3
/**
 * The parameter to the socket_create efun, makes a binary datagram type socket.
 */ 
#define DATAGRAM_BINARY           4

/**
 * This is the port the mud is on.
 */
#define PORT_MUD (mud_name() == "Discworld") ? 23 : 6677
/**
 * This is the port the ftp server runs on.
 */
#define PORT_FTP (mud_name() == "Discworld") ? 21 : 4444

/**
 * This is the port the http server runs on.
 */
#define PORT_HTTP                 80
/** 
 * This is the port the MUD's internal LPC web server runs on
 */
#define PORT_INTERNAL_HTTP                  5678
/**
 * This is the port the out of band data for the intermud services runs on.
 */
#define PORT_OOB                  8765
/**
 * This is the port the authorisation stuff for the ftp server runs on.
 */
#define PORT_FTPAUTH              2227
#undef  PORT_RCP
#undef  PORT_UDP

/**
 * This is the inherit to use for client based network inheritables.
 */
#define CLIENT                    "/net/inherit/client"
/**
 * This is the inherit to use for server based network inheritables.
 */
#define SERVER                    "/net/inherit/server"
/**
 * This is the path to the intermud 3 daemon for doing intermud requests.
 */
#define INTERMUD_D                "/net/intermud3/intermud"
/**
 * This is the path to the intermud 3 services handler.
 */
#define SERVICES_D                "/net/intermud3/services"
/**
 * This is the path to the intermud 3 out of band services handler.
 */
#define OOB_D                     "/net/intermud3/oob_server"
/**
 * This is the path to the dictionary handler.
 */
#define NETWORK_DICTIONARY_HANDLER "/net/daemon/dictionary"

/**
 * The successful return of a network thing.
 */
#define NETWORK_SUCCESS 0

/**
 * The Discworld version string
 */
#define MUDLIB_VERSION "Discworld 17.0a"

/**
 * Admin Address.
 */
#define ADMIN_ADDRESS (mud_name() == "Discworld") ? "trustees@discworld.imaginary.com" : "none"

/**
 * Allows the real Discworld to show 'open for players' while mirrors
 * automatically show 'Development'
 */
#define STATUS (mud_name() == "Discworld") ? "open for players" : "Development"

#endif /* __NETWORK_H */ 
// --- END [/mnt/home2/grok/lib/include/network.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/command.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/command.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630086   Available: 13577440
Inodes: Total: 5242880    Free: 4960136
804 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/command.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630086   Available: 13577440
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef _COMMAND_H
#define _COMMAND_H

#define CMD_D "/secure/command"
#define DIR_PLAYER_CMDS "/cmds/player"
#define DIR_SECURE_PLAYER_CMDS "/secure/cmds/player"
#define DIR_LIVING_CMDS "/cmds/living"
#define DIR_CREATOR_CMDS "/cmds/creator"
#define DIR_SECURE_CREATOR_CMDS "/secure/cmds/creator"
#define DIR_LORD_CMDS "/cmds/lord"
#define DIR_SECURE_LORD_CMDS "/secure/cmds/lord"
#define DIR_GUILD_CMDS "/cmds/guild-race"
#define DIR_PLAYTESTER_CMDS "/cmds/playtester"
#define DIR_SENIOR_PLAYTESTER_CMDS "/cmds/playtester/senior"
#define DIR_EXEC_PLAYTESTER_CMDS "/cmds/playtester/exec"

class command {
  string verb;
  string file;
  string args;
  string filepart;
}

class command_class {
    mapping patterns;
    string* order;
}

class command_data {
    int weight;
    mixed* calls;
}

#endif
// --- END [/mnt/home2/grok/lib/include/command.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/learning.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/learning.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630085   Available: 13577439
Inodes: Total: 5242880    Free: 4960136
815 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/learning.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630085   Available: 13577439
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define CURRENT_LORD "Wodan"
#define DOM_TITLE "the domain of learning"
#define DOMAIN "learning"

/* Paths */
#define LEARNING "/d/learning/" 
#define HELP LEARNING +"help_topics/"
#define FUNCTIONS LEARNING +"functions/"
#define SAVEPATH LEARNING +"save/"
#define CHARS LEARNING + "chars/"

/* Rooms */
#define ENTRANCE (LEARNING +"main")
#define SEARCH_ROOM (LEARNING +"search_room")
#define FUNCTION_ROOM (LEARNING +"function_room")

/* Objects */
#define SEARCH (LEARNING +"handlers/search")
#define QUIT_HANDLER (LEARNING +"handlers/quit")

/* definitions for tinytown */
#define TTOWN (LEARNING +"TinyTown/")
#define TTOWNBUILDINGS (TTOWN +"buildings/")
#define TTOWNITEMS (TTOWN +"items/")
#define TTOWNCHARS (TTOWN +"chars/")
#define TTOWNROADS (TTOWN +"roads/")
#define TTOWNHOSPITAL (TTOWN +"hospital")

// --- END [/mnt/home2/grok/lib/include/learning.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/money.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/money.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630085   Available: 13577439
Inodes: Total: 5242880    Free: 4960136
2506 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/money.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630085   Available: 13577439
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all the data needed for handling money.  This
 * includes the money handler and the money object itself.
 * @author Pinkfish
 */
#ifndef __SYS__MONEY
/** @ignore yes */
#define __SYS__MONEY
#include <shops/bank.h>

/**
 * The object to use for money.
 */
#define MONEY_OBJECT "/obj/money"
/**
 * The money handler object, used for routines and opetations on money.
 */
#define MONEY_HAND "/obj/handlers/money_handler"
/**
 * The money alias, this is used by the money object to identify
 * itself.  The reason it has spaces in it is so that it is not
 * matched by find_match(), only by present().
 * @example
 * // Find the players money object.
 * money = present(MONEY_ALIAS, player);
 */
#define MONEY_ALIAS "Some Money For Me"

#define NO_MATCH -1
#define NO_MONEY -2
#define NO_LEGAL -3

/**
 * The money recycling room
 */
#define MONEY_VAULT "/room/vault"

/**
 * The index into the array returned by the make_payment functions for
 * the change.
 */
#define MONEY_PAY_CHANGE 1
/**
 * The index into the array returned by the make_payment functions for
 * the return array.  This is the actual value to fiddle with.
 */
#define MONEY_PAY_RETURN 0
/**
 * The index into the array returned by make_payment functions for the
 * the depleted money array.
 */
#define MONEY_PAY_DEPLETED 2

/**
 * The index into the array returned by query_details_for function
 * for the return array.  This is the word printed when the coin is 
 * flipped and it hands in its head.
 */ 
#define MONEY_DETAILS_HEADS 0

/**
 * The index into the array returned by query_details_for function
 * for the return array.  This is the word printed when the coin is 
 * flipped and it hands in its tail.
 */ 
#define MONEY_DETAILS_TAILS 1

/**
 * The index into the array returned by query_details_for function
 * for the return array.   This is what is contained on the reverse
 * of the coin.
 */ 
#define MONEY_DETAILS_REVERSE 2

/**
 * The index into the array returned by query_details_for function
 * for the return array.  This is what is contained on the obverse
 * of the coin
 */ 
#define MONEY_DETAILS_OBVERSE 3

/**
 * The index into the array returned by query_details_for function
 * for the return array.  This is what the coin is made of. 
 */ 
#define MONEY_DETAILS_COMPOSITION 4

/**
 * The index into the array returned by query_details_for function
 * for the return array.  This is what the plural for the coin
 * is.
 */
#define MONEY_DETAILS_PLURAL 5

#endif /* __SYS__MONEY */
// --- END [/mnt/home2/grok/lib/include/money.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/door.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/door.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630084   Available: 13577438
Inodes: Total: 5242880    Free: 4960136
886 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/door.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630084   Available: 13577438
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for all the bits of door setup stuff.
 * @author Pinkfish
 */
#ifndef __SYS__NEW_DOOR
/** @ignore yes */
#define __SYS__NEW_DOOR
/*
 * These are indexes into the arrays in the door_types mapping defined
 * in the room handler.
 */
/** The index into the arrat showing if it is closed. */
#define D_CLOSED 0
/** The index into the arrat showing if it is locked. */
#define D_LOCKED 1
/** The index into the arrat showing what sort of key is needed. */
#define D_KEY 2
/** The index into the arrat showing the difficulty of picking the lock. */
#define D_DIFFICULTY 3
/** The index into the arrat showing if the door is hidden from the long. */
#define D_SECRET 4
/** The index into the arrat showing if the door is transparent. */
#define D_TRANSPARENT 5
/** The index into the arrat giving the name of the door. */
#define D_NAME 6

#endif /* __SYS__NEW_DOOR */
// --- END [/mnt/home2/grok/lib/include/door.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/config.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/config.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630084   Available: 13577438
Inodes: Total: 5242880    Free: 4960136
1104 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/config.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630084   Available: 13577438
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all the basic configuration information for the
 * mudlib.  Controls all the bits which need to be setup for someone to get
 * somewhere.
 * @author Pinkfish
 */
#ifndef __SYS__CONFIG
/** @ignore yes */
#define __SYS__CONFIG

/**
 * A nice define for the configuration setting this place as discworld.
 */
#define __DISCWORLD__

#define __DISTRIBUTION_LIB__

/**
 * A define setting the start location.
 */
#define CONFIG_START_LOCATION "/d/dist/pumpkin/squash/squash5"

/**
 * The start location for newbies.
 */
#define CONFIG_NEWBIE_START_LOCATION "/d/liaison/NEWBIE/foyer"

/**
 * The players default race.
 */
#define CONFIG_DEFAULT_RACE "/std/races/human"

/**
 * The players default race.
 */
#define CONFIG_DEFAULT_GUILD "/std/guilds/standard"

/**
 * The user to use to connect to mysql.
 */
#define CONFIG_DB_USER "ddt"

/**
 * The web address to use for the site.
 */
#define CONFIG_WEB_ADDRESS "http://dead-souls.net/"

/**
 * The web address to use external for the site.
 */
#define CONFIG_EXTERNAL_WEB_ADDRESS "http://dead-souls.net/"

#endif /* __SYS__CONFIG */
// --- END [/mnt/home2/grok/lib/include/config.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/priests_dev.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/priests_dev.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
314 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/priests_dev.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * An include file for development work for priests.
*/


#define EFFECTS "/d/playtesters/effects/faith"
#define SHADOWS "/d/playtesters/shadows/faith"
#define ITEMS "/d/playtesters/items/faith"
#define RITUALS "/d/playtesters/rituals"
#define ROOMS "/d/playtesters/rooms"
#define INHERITS RITUALS "/inherits"
// --- END [/mnt/home2/grok/lib/include/priests_dev.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/state_change.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/state_change.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
555 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/state_change.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * state_change.h - include file for /obj/handlers/state_change.c
 */

#ifndef __STATE_CHANGE_H
#define __STATE_CHANGE_H

class state_change {
    string result;       // Path of result
    float factor;        // Ratio of old amount to new amount
    function *func;      // Array of function pointers for configuring
                         // the result on-the-fly
    int playtester;      // Whether the state change is restricted to
                         // playtesters only.
}

#define STATE_CHANGE     ("/obj/handlers/state_change")

#endif
// --- END [/mnt/home2/grok/lib/include/state_change.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/client.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/client.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
674 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/client.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630083   Available: 13577437
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __CLIENT_H__
#define __CLIENT_H__

class client {
    int Descriptor;
    int Blocking;
    mixed *Buffer;
    int Closed;
}

int eventCreateSocket(string host, int port);
protected void eventAbortCallback(int fd);
protected void eventReadCallback(int fd, mixed val);
protected void eventRead(int fd, mixed val);
protected void eventWriteCallback(int fd);
void eventWrite(int fd, mixed val);
protected void eventClose(class client sock);
protected void eventSocketClose(int fd);
int eventDestruct();
protected void eventSocketError(string str, int x);
function SetRead(function f);
int SetSocketType(int x);
int SetDestructOnClose(int x);

#endif /* __CLIENT_H__ */
// --- END [/mnt/home2/grok/lib/include/client.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/inhume.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/inhume.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630082   Available: 13577436
Inodes: Total: 5242880    Free: 4960136
4400 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/inhume.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630082   Available: 13577436
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__INHUME
#define __SYS__INHUME

// many things in the AM guild use this file directly after
// <morpork.h>, which #defines LOG.
#ifdef LOG
#undef LOG
#endif

#undef DEBUG // Define to start logging skills info to LOGFILE. undefine for normal use.
// #define NOKILL  // For testing purposes -- noone will attack or die if this is defined

#define INHUME "/obj/handlers/secure_handlers/inhume"
#define NO_INHUME_PROP  "cannot inhume"
#define NO_CONTRACT_PROP "cannot place contracts"

// These defines are for the inhume handler...
#define LOGDIR          "/log/secure/assassins/"
#define LOG             ( LOGDIR + "INHUME" )
#define INHUMED         ( LOGDIR + "INHUMED" )
#define RECEIPTS        ( LOGDIR + "INHUME_RECEIPTS" )
#define LOGFILE         ( LOGDIR + "inhume_debug" )
#define PLAY_LOG        ( LOGDIR + "play_inhume_debug" )
#define TM_LOG          ( LOGDIR + "INHUME_TMS" )
#define NPC_LOG         ( LOGDIR + "NPC_CONTRACTS" )

/**
 * This class keeps track of all the contract details.
 * @member status Requested, Validated, Informed, Active, or Special
 * @member bastard The name of the person who requested/paid for it
 * @member value Cost of the contract, in money units (4 units = 1 AM pence)
 * @member time Time progress was last made
 * @member reveal Whether or not the requestor wants their identity revealed
 * @member message Message if any to be passed on to the victim
 * @member name String to be displayed on the receipt as the requestor's name
 * @member place Office where the contract was requested.
 * @member nodeath 1 if no life will be lost when the contract is closed,
 *   0 otherwise. (0 is normal)
 * @member originator The person who originally requested the contract,
 *   if different from the current bastard.
 */

//Size of contract class without location
#define CONTRACT_NO_LOCATION 10 

class contract {
   int status;
   string bastard;
   int value;
   int time;
   int reveal;
   string message;
   string name;
   string place;    //This is for money.
   int nodeath;
   string originator;
   string location; //This is for location!
} /* class contract */

#define EXP_TIME   2419200       // 28 days
#define TAXES      40            // how much they steal in taxes
#define SURCHARGE  10            // service charge for timed-out contracts
#define NOTME_MULT 1.1           // How much extra if you pay for a
                                 // contract someone else requested.
#define MIN_LEVEL  50            // minimum level for a contract
#define PK_MULT    0             // how much extra nonPKs cost
                                 // 0 indicates disallowed
#define COST_MULT  ( 5 * 400 )   // how much per level 400 = 1$AM
#define COST_GUILD ( 6 * 400 )   // Premium rate for contracts on
                                 // guild members.
#define MAXTIMES 4               // how many times can you inhume
                                 // an NPC.
#define NO_DEATH_MULT 0.5        // How much less you pay for a contract
                                 // that doesn't cause the victim to lose
                                 // a life.

/* failure values when validating contracts */
#define LOW          -1
#define NON_KILLER   -2
#define CRE          -3
#define TOO_SOON     -4

/* status values for contracts */
#define REQUESTED 0
#define VALIDATED 1
#define INFORMED 2
#define ACTIVE 3
#define SPECIAL 4

/* type defines for collect classes */
#define INHUME_COLLECT_NONE   0
#define INHUME_COLLECT_REFUND 1
#define INHUME_COLLECT_WAGES  2
#define INHUME_COLLECT_MIXED  3

/* defines for checking whether an assassin can handle PK contracts */
#define INHUME_PK_THRESH_GUILD_LEVEL   175
#define INHUME_PK_THRESH_NUM_CONTRACTS 4
#define INHUME_PK_THRESH_AGE_DAYS      10

/* Rate at which a given player can be inhumed. */
#define REPEAT_RATE ( 60 * 60 * 24 * 7 * 2 ) // 2 weeks

/* Time before an npc will start working on a player contract */
#define NPC_TIME ( 60 * 60 * 24 * 7 * 2 ) // 2 weeks

/* Number of crimes a player has to commit before they become
   inhume-on-sight on Guild grounds */
#define INHUME_ON_SIGHT_THRESH 10

/* How long it takes crime-free to have your crime count drop by one */
#define INHUME_CRIME_EXPIRY_TIME ( 60 * 60 * 24 * 3 )

/* How long you have to wait before another contract can pop up on this NPC */
#define INHUME_NPC_WAIT_TIME ( 60 * 60 * 12 )

#endif /* __SYS__INHUME */
// --- END [/mnt/home2/grok/lib/include/inhume.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/autodoc.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/autodoc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630081   Available: 13577435
Inodes: Total: 5242880    Free: 4960136
2256 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/autodoc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630081   Available: 13577435
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main include file for the autodocumentation system.
 * @author Pinkfish
 */
#ifndef __AUTODOC_H
/** @ignore */
#define __AUTODOC_H

/** The type index into the function definition save type. */
#define AUTO_TYPE 0
/** The args index into the function definition save type. */
#define AUTO_ARGS 1
/** The docs index into the function definition save type. */
#define AUTO_DOCS 2

/** The index for the docs in the class array. */
#define AUTO_CLASS_DOCS 2
/** The index of the members sectio nof the main class array. */
#define AUTO_CLASS_MEMBERS 1
/** The index for the types in the class array. */
#define AUTO_CLASS_TYPE 1
/** The index for the name of the member in the class array. */
#define AUTO_CLASS_NAME 0

/**
 * In the args section of the function definition stuff, this is the
 * type index.
 */
#define AUTO_ARGS_TYPE 0
/**
 * In the args section of the function definition stuff, this is the
 * args index.
 */
#define AUTO_ARGS_NAME 1

/** The name in the index array. */
#define AUTO_INDEX_NAME      0
/** The file name of the index in the index array. */
#define AUTO_INDEX_FILE_NAME 1
/** The args in the index array. */
#define AUTO_INDEX_ARGS      2
/** The summary string in the index array. */
#define AUTO_INDEX_SUMMARY   3

/** The path of the parser to the autodoc stuff. */
#define AUTODOC_FILE "/obj/handlers/autodoc/autodoc_file"
/** The path of the file to make the resulting nroff files. */
#define AUTODOC_NROFF "/obj/handlers/autodoc/autodoc_nroff"
/** The path of the file to make the html files. */
#define AUTODOC_HTML "/obj/handlers/autodoc/autodoc_html"
/** The main autodoc handler object. */
#define AUTODOC_HANDLER "/obj/handlers/autodoc/autodoc_handler"

/** Where to put the nroff documents. */
#define NROFF_DOC_DIR "/doc/autodoc/"
/** The path of the file to put the single function nroff files. */
#define NROFF_DOC_SINGLE "/doc/creator/autodoc/"
/** Where to put the html documents. */
#define HTML_DOC_DIR "/www/external/autodoc/"

/** The path of the master object. */
#define MASTER_OB "/secure/master.c"
/** Where to save the parsed files. */
#define SAVE_DIR "/save/autodoc/"

/** The delay bewteen each time we save the index file.   1 day. */
#define SAVE_INDEX_DELAY (60 * 60 * 24)

#endif
// --- END [/mnt/home2/grok/lib/include/autodoc.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/broadcaster.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/broadcaster.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
484 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/broadcaster.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file to use with the broadcaster.  The broadcaster
 * handles shouts sent to npcs and channels and events.
 * @author Pinkfish
 * @started Sun Oct 11 02:18:25 PDT 1998
 */
#ifndef BROADCAST_H
/** @ignore yes */
#define BROADCAST_H

/**
 * This defines the location of the broadcaster.
 */
#define BROADCASTER "/obj/handlers/broadcaster"

/**
 * This defines the location of the history handler.
 */
#define HIST_HANDLER "/obj/handlers/hist_handler"

#endif
// --- END [/mnt/home2/grok/lib/include/broadcaster.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/image.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/image.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
454 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/image.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * image.h - definitions for handler to load and save 2D images
 */

class IMAGE_INFO {
  mixed image; // Array of image
  int rle;     // Image is run-length encoded along the rows (unimplemented)
  int *size;   // Array size (only 2D implemented right now)
  int *nw_coord; // Coordinate of the room at (0,0) (for calculating indices)
} /* IMAGE_INFO */

// This is just temporary for testing...
#define IMAGE_HANDLER "/d/sur/beta/topography/image"
// --- END [/mnt/home2/grok/lib/include/image.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/parser_error.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/parser_error.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
255 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/parser_error.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

#define ERR_IS_NOT		1
#define ERR_NOT_LIVING		2
#define ERR_NOT_ACCESSIBLE	3
#define ERR_AMBIG		4
#define ERR_ORDINAL		5
#define ERR_ALLOCATED		6
#define ERR_THERE_IS_NO		7
#define ERR_BAD_MULTIPLE	8

#endif
// --- END [/mnt/home2/grok/lib/include/parser_error.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/npc/ai.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/npc/ai.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
317 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/npc/ai.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630080   Available: 13577434
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The general include for the npc inteligence control stuff.
 * @author Pinkfish
 * @started Thu Aug 13 08:18:33 EDT 1998
 */
#ifndef __NPC_AI_H__
/** @ignore yes */
#define __NPC_AI_H__

/**
 * The main inheritable for an npc that uses inteligence.
 */
#define AI_NPC_INHERIT "/std/npc/npc_intelligent"

#endif
// --- END [/mnt/home2/grok/lib/include/npc/ai.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/npc/transport.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/npc/transport.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630079   Available: 13577433
Inodes: Total: 5242880    Free: 4960136
1659 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/npc/transport.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630079   Available: 13577433
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file to deal with transport style npcs.
 * @author Pinkfish
 * @started Mon Nov 15 02:07:32 PST 1999
 */
#ifndef __NPC_TRANSPORT_H
/** @ignore yes */
#define __NPC_TRANSPORT_H

/**
 * This means the transport is not currently moving.
 */
#define RIDE_NOT_MOVING   0
/**
 * This means the transport is currently walking.
 * These values are also used to set the maximum speed of the transport.
 */
#define RIDE_WALK   1
/**
 * This means the transporet is currently trotting.
 */
#define RIDE_TROT   2
/**
 * This means the transport is currently cantering.
 */
#define RIDE_CANTER 3
/**
 * This means the transport is currently galloping.
 */
#define RIDE_GALLOP 4

/**
 * This is the object used to repeat messages onto the
 * rest of the world.
 */
#define TRANSPORT_REPEATER "/std/npc/types/helper/repeater"
/**
 * This is the effect used when someone is riding the transport.
 */
#define TRANSPORT_EFFECT   "/std/effects/attached/riding"
/**
 * This is the effect used to setup ownership of the transport.
 */
#define TRANSPORT_OWNER_EFFECT "/std/effects/attached/owned_transport"

/**
 * This is the property used to control who is allowed to use the
 * owner's horses.
 */
#define TRANSPORT_ALLOW_PROP "transport allow"

/**
 * This is the basic inheritable for a transport.
 */
#define TRANSPORT_INHERIT "/std/npc/types/transport"

/**
 * This is the property used on things to make them able to be used
 * as a tether by a horse.
 */
#define TRANSPORT_TETHER_PROP "tether"

/**
 * This is the property used on things to make them able to have horses
 * tethered to them.
 */
#define TRANSPORT_TETHER_POST_PROP "tether post"

#endif
// --- END [/mnt/home2/grok/lib/include/npc/transport.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/npc/events.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/npc/events.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630079   Available: 13577433
Inodes: Total: 5242880    Free: 4960136
1196 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/npc/events.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630079   Available: 13577433
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all the different sorts of npc events that can
 * be generated.
 * @author Pinkfish
 * @started Tue Aug  4 19:16:53 PDT 1998
 */
#ifndef __NPC_EVENTS_H__
/** @ignore yes */
#define __NPC_EVENTS_H__

/**
 * This is the event for losing hps.
 */
#define EVENT_LOSE_HPS "lose hps"
/**
 * This is the event for gaining hps.
 */
#define EVENT_GAIN_HPS "gain hps"
/**
 * This is the event for reaching a fully healed state.
 */
#define EVENT_FULLY_HEALED "100% hps"
/**
 * This is the event for crossing the 75% hp barrier.
 */
#define EVENT_75PERCENT_HPS "75% hps"
/**
 * This is the event for crossing the 50% hp barrier.
 */
#define EVENT_50PERCENT_HPS "50% hps"
/**
 * This is the event for crossing the 25% hp barrier.
 */
#define EVENT_25PERCENT_HPS "25% hps"
/**
 * This is the event when the npc has moved.
 */
#define EVENT_MOVED "moved"
/**
 * This is the event for when the item is given.
 */
#define EVENT_GIVEN "given"

/**
 * This is the basis for a finished plan event.
 */
#define EVENT_PLAN_FINISHED_TAG "plan finished : "
/**
 * THis is the macro to create a finished plan event
 */
#define EVENT_PLAN_FINISHED(PLAN) (EVENT_PLAN_FINISHED_TAG + PLAN)

#endif
// --- END [/mnt/home2/grok/lib/include/npc/events.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/npc/plan.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/npc/plan.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630078   Available: 13577432
Inodes: Total: 5242880    Free: 4960136
1078 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/npc/plan.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630078   Available: 13577432
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all the needed defines for the plans.  This is part
 * of the npc inteligence system.
 * @author Pinkfish
 * @started Thu Aug 13 07:35:51 EDT 1998
 */
#ifndef __NPC_PLAN_H__
/** @ignore yes */
#define __NPC_PLAN_H__

/**
 * The directory all the default plans are stored in.
 */
#define PLAN_DIR "/std/npc/plans/"

/**
 * This is the file to use as a base class for all plans.  It defines
 * all the default plan behaviour and makes sure you do not declare your
 * control functions with the wrong arguments.
 */
#define PLAN_BASE_INHERIT (PLAN_DIR "base")

/**
 * This should be returned if the plan is not at all sutabile for the
 * specified situation.
 */
#define PLAN_INVALID_SUTABILITY -1

/**
 * This is the lowest sutability used for a plan.
 */
#define PLAN_LOWEST_SUTABILITY 0

/**
 * This is the low sutability for a plan.
 */
#define PLAN_LOW_SUTABILITY 100

/**
 * This is the medium sutability for a plan.
 */
#define PLAN_MEDIUM_SUTABILITY 200

/**
 * This is the high sutability for a plan.
 */
#define PLAN_HIGH_SUTABILTIY 300

#endif
// --- END [/mnt/home2/grok/lib/include/npc/plan.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/npc/goals.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/npc/goals.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630078   Available: 13577432
Inodes: Total: 5242880    Free: 4960136
1821 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/npc/goals.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630078   Available: 13577432
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The helper include file for the goals system.
 * @author Pinkfish
 * @started Thu Jul 30 18:08:47 PDT 1998
 * @see /std/living/goals.c
 * @see /std/npc/goals/base.c
 */
#ifndef __GOALS_H__
/** @ignore yes */
#define __GOALS_H__

/**
 * The lowest priority goal.
 */
#define GOAL_LOWEST_PRIORITY 0
/**
 * A low priority goal.
 */
#define GOAL_LOW_PRIORITY 1000
/**
 * A medium priority goal.
 */
#define GOAL_MEDIUM_PRIORITY 2000
/**
 * A high priority goal.
 */
#define GOAL_HIGH_PRIORITY 3000
/**
 * A very high priority goal.
 */
#define GOAL_VERY_HIGH_PRIORITY 4000

/**
 * The invalid priority for a goal.
 */
#define GOAL_INVALID_PRIORITY -32768
/**
 * The default priority for a goal that does not have a priority set.
 */
#define GOAL_DEFAULT_PRIORITY GOAL_LOWEST_PRIORITY

/**
 * This is the return value for the goal which tells it to skip
 * this goal and continue onto the next.
 */
#define GOAL_CONTINUE_PROCESSING 1

/**
 * The directory all the standard goals will go in.
 */
#define GOALS_DIR "/std/npc/goals/"

/**
 * The basic inherit for all npc goals.
 */
#define GOAL_BASE_INHERIT (GOALS_DIR "base")

/**
 * The class used to keep track of the data passed into a goal.
 */
class goal_control {
   /** The extra plans associated with the goal. */
   mapping extra_plans;
   /** The current plan of the goal. */
   string current_plan;
   /** The override priority of the goal. */
   int priority;
   /** The data is controled by the goal itself. */
   mixed data;
   /** The plan data for each plan. */
   mapping plan_info;
}

/**
 * This is the return value from the event handling routine if the event
 * was not handled.
 */
#define GOAL_EVENT_NOT_HANDLED 0
/**
 * This is the return value from the event handling system if the event
 * was handled.
 */
#define GOAL_EVENT_HANDLED 1

#endif
// --- END [/mnt/home2/grok/lib/include/npc/goals.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/comms.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/comms.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
135 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/comms.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__COMMS
#define __SYS__COMMS

#define COMM_ROOM "/d/guilds/wizards/Ankh-Morpork/old/comm_room"

#endif /* __SYS__COMMS */
// --- END [/mnt/home2/grok/lib/include/comms.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/virtual.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/virtual.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
743 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/virtual.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the header file for use with virtual objects.
 * @author Pinkfish
 */
#ifndef __SYS__VIRTUAL
/** @ignore yes */
#define __SYS__VIRTUAL

/**
 * The path to the server used in making virtual objects.
 */
#define SERVER "/global/virtual/server"
/**
 * The path to the handler for use in making virtual objects.
 */
#define VR_HAND "/global/virtual/vr_hand.c"
/**
 * Ths path to the handler for virtual objects.
 */
#define VIRTUAL_HANDLER "/obj/handlers/virtuals"
/**
 * The path to the cloner used for making nice exciting clones of things.
 */
#define CLONER "/global/cloner"
/**
 * The property used to determine the original path of the virtual object.
 */
#define VIRTUAL_NAME_PROP "virtual name"

#endif /* __SYS__VIRTUAL */
// --- END [/mnt/home2/grok/lib/include/virtual.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/project_management.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/project_management.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
2380 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/project_management.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630077   Available: 13577431
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __project_management_h
#define __project_management_h

#define MINUTE (60) 
#define HOUR (60 * 60)
#define DAY (HOUR * 24)
#define WEEK (DAY * 7)

#define PROJECT_LOCK (5 * MINUTE)
#define TIME_BETWEEN_POSTINGS (7 * DAY)

#define STATUS ({"heap", "development", "playtesting", "play", "limbo"})
#define SIZE ({"very small", "small", "medium", "large", "very large", "huge", "special"})
#define COMPLEXITY ({"low", "medium", "high", "very high", "special"})
#define PROJECT_SAVE "/save/project"
#define TMP_SAVE "/save/project_tmp"
#define PROJECT_LOG "PROJECT_MANAGEMENT"
#define PROJECT_HANDLER "/obj/handlers/project_management"
#define TWIKI_BASE "http://discworld.imaginary.com/twiki/bin/view/"
#define WHATWHAT ("/www/whatwhat")

#define PROJECT "project"
#define TASK "task"
#define NOTE "note"
#define FILE "file"
#define PLAYTESTING "playtesting"
#define CALLBACK "project_callback"

class task {
  string id; 
  string task_name;
  string comments;
  string *assigned_to;
  string added_by;
  string aims;
  int percent_complete;
  int completion_date;
  int date_added;
}

class note {
  string id;
  int date_added;
  string added_by;
  string note;
}

class file {
  string file;
  int access;
  string task;
}


class project {
  string id;
  string name;
  string leader;
  string added_by;
  string description;
  string pt_notes;  
  string what_touched;
  string touched_by;

  int date_added;
  int date_completed;
  int status;
  int percent_complete;
  int estimated_completion;
  int last_touched;
  int last_status_change;  

  string *twiki;
  string *playtesters;
  string *domains;
  string *creators;
  string *sub_projects;  

  class file *files;
  class task *tasks;
  class note *notes;

  int last_rotation;
  int size;
  int complexity;
  int current_rotation;
  string *last_pt_cohort;
  string *all_pts;
  string *guild_specific;

}


class project_tmp {
  string id;
  string name;
  string leader;
  string added_by;
  string description;
  string pt_notes;  
  string *domains;
  string *creators;
  string *sub_projects;  
  class file *files;
  string *twiki;
  string *playtesters;
  string what_touched;
  string touched_by;
  int date_added;
  int date_completed;
  int status;
  int percent_complete;
  int estimated_completion;
  int last_touched;
  int last_status_change;  
  class task *tasks;
  class note *notes;
}

#endif
// --- END [/mnt/home2/grok/lib/include/project_management.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/http.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/http.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630076   Available: 13577430
Inodes: Total: 5242880    Free: 4960136
9993 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/http.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630076   Available: 13577430
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* ====================================================================
 * Copyright (c) 1995-1997 The Apache Group.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * 4. The names "Apache Server" and "Apache Group" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission.
 *
 * 5. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the Apache Group
 *    for use in the Apache HTTP server project (http://www.apache.org/)."
 *
 * THIS SOFTWARE IS PROVIDED BY THE APACHE GROUP ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE APACHE GROUP OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Group and was originally based
 * on public domain software written at the National Center for
 * Supercomputing Applications, University of Illinois, Urbana-Champaign.
 * For more information on the Apache Group and the Apache HTTP server
 * project, please see <http://www.apache.org/>.
 *
 */

/**
 * The main header file for the web system.  This header files is based on
 * one which comes with apache web server software.
 */
#ifndef __HTTP_H
#define __HTTP_H

#include <mime.h>

/**
 * The path to the http daemon.
 */
#define HTTPD "/net/daemon/http"

/**
 * The version of the http protocol that is supported.
 */
#define HTTP_PROTOCOL "HTTP/1.1"
/**
 * The version of the web server.
 */
#define HTTP_VERSION "Discworld/0.10.3"

/**
 * The header request type for compression.
 */
#define HTTP_ACCEPT_ENCODING "accept-encoding"
/**
 * To tell the system we are going to send the content compressed.
 */
#define HTTP_CODING_TYPE "Content-Encoding"

#define REQ_REQUEST 0
#define REQ_HEADERS 1
#define REQ_BODY 2

#define BODY_START 0
#define BODY_READ 1
#define BODY_CHUNK_FOOTER 2
#define BODY_CHUNK_END 3

/**
 * The directory in which the web pages exist.
 */
#define DIR_WWW "/www"

/**
 * The response number for a continue.
 */
#define CONTINUE 100
/**
 * The response number for an ok.
 */
#define HTTP_OK 200
/** The response number for a no content message. */
#define NO_CONTENT 204
/** The response number for a partial content message. */
#define PARTIAL_CONTENT 206
/** The response number for a moved permanently message. */
#define MOVED_PERMANENTLY 301
/** The response number for a moved temporarily message. */
#define MOVED_TEMP 302
/** The response number for a not modified message. */
#define NOT_MODIFIED 304
/** The response number for a bad command message. */
#define BAD_CMD 400
/** The response number for a authorisation required message. */
#define AUTH_REQUIRED 401
/** The response number for a acess denied message. */
#define ACCESS_DENIED 403
/** The response number for a not found message. */
#define NOT_FOUND 404
/** The response number for a not allowed message. */
#define NOT_ALLOWED 405
/** The response number for a time out message. */
#define TIME_OUT 408
/** The response number for a length required message. */
#define LENGTH_REQUIRED 411
/** The response number for a precondition failed message. */
#define PRECONDITION_FAILED 412
/** The response number for an internal error message. */
#define INTERNAL_ERROR 500
/** The response number for a not implemented message. */
#define NOT_IMPLEMENTED 501

nosave private mapping status_lines = ([
   100 : "100 Continue",
   101 : "101 Switching Protocols",
   200 : "200 OK",
   201 : "201 Created",
   202 : "202 Accepted",
   203 : "203 Non-Authoritative Information",
   204 : "204 No Content",
   205 : "205 Reset Content",
   206 : "206 Partial Content",
   300 : "300 Multiple Choices",
   301 : "301 Moved Permanently",
   302 : "302 Moved Temporarily",
   303 : "303 See Other",
   304 : "304 Not Modified",
   305 : "305 Use Proxy",
   400 : "400 Bad Request",
   401 : "401 Authorization Required",
   402 : "402 Payment Required",
   403 : "403 Forbidden",
   404 : "404 File Not Found",
   405 : "405 Method Not Allowed",
   406 : "406 Not Acceptable",
   407 : "407 Proxy Authentication Required",
   408 : "408 Request Time-out",
   409 : "409 Conflict",
   410 : "410 Gone",
   411 : "411 Length Required",
   412 : "412 Precondition Failed",
   413 : "413 Request Entity Too Large",
   414 : "414 Request-URI Too Large",
   415 : "415 Unsupported Media Type",
   500 : "500 Internal Server Error",
   501 : "501 Method Not Implemented",
   502 : "502 Bad Gateway",
   503 : "503 Service Temporarily Unavailable",
   504 : "504 Gateway Time-out",
   505 : "505 HTTP Version Not Supported",
   506 : "506 Variant Also Varies"
]);

/**
 * Where to save the status information.
 */
#define SAVE_FILE "/net/save/http"

#define status_drops_connection(x) (((x) == BAD_CMD)          || \
                                    ((x) == TIME_OUT)         || \
                                    ((x) == INTERNAL_ERROR)   || \
                                    ((x) == LENGTH_REQUIRED))

#undef DEBUG

#ifdef DEBUG
#define TP(STR) if (find_player("ceres")) tell_object(find_player("ceres"), STR)
#else
#define TP(STR)
#endif

#define RES_DIR    0
#define RES_FILE   1
#define RES_NORMAL 2

#define DAYS ({"Sun", "Mon", "Tue", "Wed", "Thu", \
         "Fri", "Sat"})

#define MONTHS ({"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"})

class http_session {
  int fd;                       /* file descriptor */
  int time;                     /* request time */
  string address;               /* socket_address() of remote */
  string name;                  /* resolved() hostname of remote */
}

class http_body {
  int state;                    /* state of the body */
  int remaining;                /* remaining length of received body */
  int read_chunked;             /* reading a chunked body */
  int read_length;              /* length read so far */
  string buff;                  /* the body itself */
  mapping data;                 /* If a post for, the data */
}

class http_request_header {
  int noheaders;                     /* stupid mode (HTTP/0.9) */
  class mime_header headers_in;      /* incoming header */
  class mime_header headers_out;     /* outgoing header */
  class mime_header err_headers_out; /* outgoing error header */
  int header_only;                   /* the "HEAD" operation was requested */
}

class http_body_info {
  string content_type;          /* MIME content type of body */
  int chunked;                  /* chunked transfer mode */
  int clength;                  /* content length of body */
  int byterange;                /* type of byterange */
  string boundary;              /* boundary of range */
  string range;                 /* range string */ 
}

class http_request {
  class http_session sess;           /* connection info */
  string hostname;              /* expected hostname of server */
  int time;                     /* request time */
  string request;               /* the request so far */
  string status_line;           /* custom status of response */
  int status;                   /* status code */
  int proto_num;                /* protocol version (numerical) */
  string method;                /* requested operation */
  string uri;                   /* the uri */
  string args;                  /* arguments to the request */
  string filename;              /* the filename of the request */
  string dir;                   /* the directory of the request */
  string user;                  /* the user name for secure transactions */
  class http_request_header rh; /* header junk */
  string location;              /* the new location of the document */
  int id;                       /* call out id for timeout */
  string the_request;           /* first line of the request */
  int state;                    /* state of the request */
  int persistent;               /* is this connection persistent? */
  string compression;           /* does the client accept compression? */
  int proxyreq;                 /* this is a proxy request */
  int numredirect;              /* amount of internal redirects done */
  int cgi_request;              /* Is this a cgi bin request? */
  class http_body body;         /* incoming body */
  class http_body_info bi;      /* various junk about the body */
  class http_request prev;      /* previous request */
  int delayed;                  /* In a delayed response */
}

#endif /* __HTTP_H */
// --- END [/mnt/home2/grok/lib/include/http.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/crafts.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/crafts.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630073   Available: 13577427
Inodes: Total: 5242880    Free: 4960136
2044 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/crafts.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630073   Available: 13577427
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main crafts include file.  Contains everything you needed to know
 * about crafts and more.
 * @author Pinkfish
 * @started Fri Nov 12 17:53:57 PST 1999
 */
#ifndef __CRAFTS
#define __CRAFTS

/**
 * The value the craft functions return as an error.
 */
#define CRAFT_ERROR 0

/**
 * The file to inherit to make a craft process
 */
#define CRAFT_INHERIT "/obj/crafts/base"

/**
 * The location of the craft handler.
 */
#define CRAFT_HANDLER "/obj/crafts/craft_handler"

/**
 * This is the definition for a required input material.
 */
#define CRAFT_MATERIAL_REQUIRED 1
/**
 * This is the definition for a 'one of' input material.  The material
 * must be one of these 'one of' materials.
 */
#define CRAFT_MATERIAL_ONE_OF 2
/**
 * This is the definition for an optional input material
 */
#define CRAFT_MATERIAL_OPTIONAL 3
/**
 * This is the definition for a denied input material
 */
#define CRAFT_MATERIAL_DENIED 4

/**
 * The mask to get of the actual type of the material classication.
 */
#define CRAFT_MATERIAL_TYPE_MASK 127

/**
 * This means that every material must have this material.
 */
#define CRAFT_MATERIAL_ALL    128

/**
 * Worthless quality.
 */
#define CRAFT_QUALITY_WORTHLESS -4
/**
 * Awful quality.
 */
#define CRAFT_QUALITY_AWFUL -3
/**
 * Bad quality.
 */
#define CRAFT_QUALITY_BAD -2
/**
 * Poor quality.
 */
#define CRAFT_QUALITY_POOR -1
/**
 * Normal quality.
 */
#define CRAFT_QUALITY_NORMAL 0
/**
 * Fine quality.
 */
#define CRAFT_QUALITY_FINE 1
/**
 * Good quality.
 */
#define CRAFT_QUALITY_GOOD 2
/**
 * Excelent quality.
 */
#define CRAFT_QUALITY_EXCELLENT 3
/**
 * Perfect quality.
 */
#define CRAFT_QUALITY_PERFECT 4


/**
 * This is a class to handle the bonus stuff for the process.
 * @element result the result of the 'taskmaster' call
 * @element skill_bonus the actual bonus from this skill
 * @element quality a quality indicator
 * @element bonus the overall bonus over the skills
 */
class crafts_bonus {
   mapping result;
   mapping skill_bonus;
   int quality;
   int bonus;
}

#endif
// --- END [/mnt/home2/grok/lib/include/crafts.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/surface.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/surface.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
171 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/surface.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__SURFACE
#define __SYS__SURFACE

#define SURFACE_MODULE "/std/basic/surface"
#define SURFACE_SHADOW "/std/shadows/misc/surface"

#endif /* __SYS__SURFACE */
// --- END [/mnt/home2/grok/lib/include/surface.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/weather.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/weather.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
909 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/weather.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the weather handler.
 * @author Pinkfish
 */
#ifndef __SYS__WEATHER
/** @ignore yes */
#define __SYS__WEATHER

/**
 * The location of the weather handler.
 */
#define WEATHER "/obj/handlers/weather"
/**
 * The location of the weather handler.
 */
#define WEATHER_HANDLER WEATHER

/**
 * The type of rain if it is not raining at all.
 */
#define WEATHER_NO_RAIN_TYPE 0
/**
 * The type of precipitation if it is raining.
 */
#define WEATHER_RAIN_TYPE 3
/**
 * The type of precipitation if it is sleeting.
 */
#define WEATHER_SLEET_TYPE 2
/**
 * The type of precipitation if it is snowing.
 */
#define WEATHER_SNOW_TYPE 1

/**
 * The standard set of climate types.
 */
#define CLIMATES ({ "Af", "Am", "Aw", "Bw", "Bs", "Cfa", "Cs", "Cfb", \
                    "Dw", "Ds", "Df", "Et", "Ef", "H" })
/**
 * Default climate
 */
#define DEFAULT_CLIMATE "Cfb"

#endif /* __SYS__WEATHER */
// --- END [/mnt/home2/grok/lib/include/weather.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/virtual_spell.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/virtual_spell.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
2226 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/virtual_spell.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630072   Available: 13577426
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define TRICK_HANDLER     load_object( "/obj/spells/trick_handler" )
#define VIRTUAL_SPELL_OB  "/obj/spells/virtual_spell"
#define SET_STONE         "/obj/magic/lg_hag_stone_set"
#define UNSET_STONE       "/obj/magic/lg_hag_stone_unset"
#define VIRTUAL_SPELL_EFF "/std/effects/magic/virtual_spell"

#define SPELL_DIRECT_NON_LIVING 1
#define SPELL_DIRECT_LIVING     2
#define SPELL_UNDIRECTED        3

#define SPELL _spell->name
#define STAGE _spell->stages[ stage_num - 1 ]

#define STAGE_COST  20
#define DIFF_POWER  25
#define STAGE_TIME  10

class spell_stage {
  string skill;      // the skill checked
  int difficulty;    // the difficulty of the check
  string tell_msg;   // the msg the witch sees 
  string say_msg;    // the msg the audience sees
  string *consumed;  // spell component(s) consumed during stage
} 

class spell_info {
  string name;                // the name of the spell
  int target_type;            // what it's directed at
  class spell_stage *stages;  // data for each stage
  string *needed;             // spell component(s) needed (not consumed)
  string tell_final;          // msg to witch when successful
  string say_final;           // msg to room when successful
}

class eff_args {
  object obj;
  class spell_info spell;
  int id;
}

/* --- MySQL Stuff --- */
/* 
The columns of the TRICKS table are as follows:
create table Tricks (
  TrickId smallint unsigned not null auto_increment,
  TrickName char(255) default '',
  Author char(255) default '',
  TimeSet int(12) unsigned default '0',
  Guild char(10) default '',
  TimesCast smallint(5) unsigned default '0',
  Witnesses double default '0.0',
  Canonised tinyint(3) default '0',
  Shared tinyint(1) default '0',
  MostRecentTime int(12) unsigned default '0',
  MostRecentCaster char(255) default '',
  TargetType tinyint unsigned default '0',
  Needed blob,
  FinalTell char(255) default '',
  FinalSay char(255) default '',
  Ritual blob,
  primary key( TrickId )
);
*/

#include <db.h>
#include <config.h>

#define DB            "discworld"
#define TRICKS        "Tricks"
#define USER_ID       CONFIG_DB_USER
#define PASSWORD      ""
#define MAXID         "max( TrickId )"
#define ID_EXISTS     1
#define DATA_EXISTS   2
// --- END [/mnt/home2/grok/lib/include/virtual_spell.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/soul.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/soul.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630071   Available: 13577425
Inodes: Total: 5242880    Free: 4960136
736 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/soul.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630071   Available: 13577425
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS_SOUL_H
#define __SYS_SOUL_H

#define PATTERNS 0
#define SINGLE 1
#define TARGET 2

#define NO_ARGUMENTS 0
#define ARGUMENTS 1

#define SELF     0
#define REST     1
#define TARG     2
#define ARGS     3
#define FORCE    4
#define POSITION 5
/* Reuse the TARG for this... */
#define POSITION_SINGLE 2

/* targeted arg size... */
#define ARG_SIZE 6
/* Untargeted arg size... */
/* We don't need force or position for this :) */
#define SMALL_ARG_SIZE 4

#define SOUL_OBJECT "/obj/handlers/new_soul"
#define SOUL_COMPILER "/obj/handlers/soul_compiler"
#define SOUL_DIR "/soul/"

#define ONLY_ARGUMENT 1
#define NO_ARGUMENT 2
#define ARGUMENT_FIRST 3
#define ARGUMENT_SECOND 4
#define ONLY_TARGET 5

#endif /* __SYS_SOUL_H */
// --- END [/mnt/home2/grok/lib/include/soul.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/pop3.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/pop3.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630071   Available: 13577425
Inodes: Total: 5242880    Free: 4960136
1501 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/pop3.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630071   Available: 13577425
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __POP3_H
#define __POP3_H

#define PORT_POP3 4110

#define POP3_VERSION "0.1"

#define POP_AUTH_USER   0
#define POP_AUTH_PASS   1
#define POP_TRANSACTION 2
#define POP_UPDATE      3

#define LOGIN_OB "/secure/login"
#define FOLDER_H "/obj/handlers/folder_handler"

#define DEBUG
#ifdef DEBUG
#define TP(_x) tell_object(find_player("turrican"), (_x))
#else
#define TP(_x)
#endif

#define CHECK_STATE(_state) if ((_state) != sess->state) \
{ \
    eventWrite(fd, sprintf("-ERR Unknown command in %s state\r\n", \
                           pop_states[sess->state])); \
    break; \
} 

#define CHECK_CMD(_num, _str) if (sizeof(bits) < (_num)+1) \
                       { \
                         eventWrite(fd, _str); \
                         break; \
                       }

class pop_session {
  int fd;                      /* socket descriptor */
  int state;                   /* state of the connection */
  int time;                    /* time of last command */
  string command;              /* current POP3 command */
  string user_name;            /* user name */
  int *deleted;                /* list of deleted messages */
  int num_messages;            /* amount of messages in the folder */
  class mail_header *headers;  /* headers of messages in the folder */
  string *messages;            /* parsed messages */
  int *sizes;                  /* sizes of parsed messages */
  int last;                    /* number of last accessed message */
}

#endif /* __POP3_H */
// --- END [/mnt/home2/grok/lib/include/pop3.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/armour.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/armour.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630070   Available: 13577424
Inodes: Total: 5242880    Free: 4960136
681 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/armour.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630070   Available: 13577424
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for armour stuff.
 * @author Ceres
 */
#ifndef __SYS__ARMOUR
#define __SYS__ARMOUR

/**
 * Defines for armour callbacks.
 * ARM_INNER places the magical protection inside all physical armour but
 * just above the skin.
 * ARM_OUTER places the protection just outside the physical armour
 */
#define ARM_INNER 0
#define ARM_OUTER 1

/**
 * Class used to store callback data.
 * @entry id A unique ID number given to each entry.
 * @entry callback the object & function names for the callback
 * @entry data any additional data the callback function desires.
 */
class armour_callback {
  int id;
  mixed callback;
  mixed data;
}

#endif /* __SYS__ARMOUR */
// --- END [/mnt/home2/grok/lib/include/armour.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/bits_controller.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/bits_controller.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630070   Available: 13577424
Inodes: Total: 5242880    Free: 4960136
413 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/bits_controller.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630070   Available: 13577424
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The file for keeping track of all the stuff for the bits controller.
 */

/**
 * The timeout in seconds.  This is the distance between each level of the
 * decay.
 */          
#define TIME_OUT 30
/**
 * The bits controller path.  The path to the bits controller.  If you are
 * ever referencing the bits controller you should use this function.
 */
#define BITS_CONTROLLER "/obj/handlers/bits_controller"
// --- END [/mnt/home2/grok/lib/include/bits_controller.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/route.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/route.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630069   Available: 13577423
Inodes: Total: 5242880    Free: 4960136
173 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/route.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630069   Available: 13577423
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __ROUTE_H
#define __ROUTE_H
/*
 * The route handler defines, all you need to know is where it is :)
 */

#define ROUTE_HANDLER "/obj/handlers/route_handler"

#endif
// --- END [/mnt/home2/grok/lib/include/route.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/group_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/group_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630069   Available: 13577423
Inodes: Total: 5242880    Free: 4960136
3831 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/group_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630069   Available: 13577423
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the group system.  It is included
 * by at least the handler, the effect and the commands.         
 *
 * @author Tape
 */ 

#ifndef __GROUP_HANDLER_H__
/** @ignore yes */
#define __GROUP_HANDLER_H__

#include <command.h>

/**
 * This points to the location of the group handler.
 */
#define GROUP           "/obj/handlers/group_handler"

/**
 * This points to the location of the master group command file.
 */
#define GROUP_CMD       ( DIR_PLAYER_CMDS "/group" )
// #define GROUP_CMD       "/w/tape/cmds/ngroup"

/**
 * This defines where the master group command looks for
 * sub commands.
 */
#define GROUP_SUB_CMDS_DIR             (DIR_PLAYER_CMDS "/group_cmds/")
/**
 * This is the wildcard used to find the commands in the directory.
 */
#define GROUP_SUB_CMDS_FILE_WILDCARD   "*.c"

/**
 * This points to the group sub-command inheritable.
 */
#define GROUP_SUBCOMMAND_INHERITABLE   "/cmds/player/group_cmds/base_group"

/**
 * This points to the location of the group effect.
 */
#define EFFECT          "/std/effects/other/group"

/**
 * This points to the location of the group shadow.
 */
#define SHADOW_OB       "/std/shadows/other/group"

/** 
 * Invitations automatically time out after this many seconds.
 */
#define INVITE_TIMEOUT        120

/**
 * These words are automatically filtered out when converting
 * a group's short to its name with short_to_name().  They're
 * not case sensitive.
 */
#define INVALID_WORDS         ({ })

/**
 * This is sticked to the beginning of all group messages.  $channel$
 * is replaced by the group's channel name after making it look pretty.<p>
 *
 * The $colour$ tag is replaced with the custom group colour, if any
 * has been set.<p>
 *
 * Note: the $I$ bit must be there somewhere, unless you feel like
 * rewriting the group history function.  Plus it looks nice, so
 * what the hell.  Mind, it should be in the form "$I$+x,+y="
 */
#define GROUP_NOTIFY_PREFIX   "$I$+5,+0=[$colour$$channel$%^RESET%^] "

/**
 * If shared xp gained is below this number, it isn't shared.
 */
#define MIN_EXPERIENCE        0

/**
 * This defines the maximum number of characters you can have
 * in a group name.
 */
#define MAX_GROUP_NAME_SIZE                  30

/**
 * The maximum number of members a party can contain at a time.
 */
#define MAX_PEOPLE_PER_PARTY                 6

/**
 * The maximum number of invitations that can at one time be
 * pending.
 */
#define MAX_INVITATIONS_PER_PARTY_AT_ONCE    5

/**
 * The maximum number of people you can be assisting at a time.
 */
#define MAX_PEOPLE_YOU_CAN_ASSIST            1

/**
 * Set this to 1 if you want base stats (the ones the player
 * rearranged to) to be used for calculating xp share, instead
 * of the player's current stats.
 */
#define USE_BASE_STATS                       1

/**
 * A member's personal rating:<br>
 *   ( collective primary bonuses / number of bonuses *
 *    PRIMARY_BONUS_MULTIPLIER ) + ( bonus in fighting *
 *    FIGHTING_BONUS_MULTIPLIER )
 *<p>
 * A member's xp share: <br>
 *    Total xp from a kill *
 *    a member's personal rating / group's combined
 *    ratings
 */
#define PRIMARY_BONUS_MULTIPLIER     0.80
#define FIGHTING_BONUS_MULTIPLIER    0.20

/**
 * Path to the contemplate effect/command.
 */
#define CONTEMPLATE ( DIR_GUILD_CMDS "/magic/contemplate" )

/**
 * Name of the title type for a group used by set_title().
 */
#define GROUP_TITLE  "group"

/**
 * This defines how many characters of the group channel name is displayed
 * until it's cut off with three periods (...)  E.g. [groupna...] Tape: Bing.
 * It must be larger than 3, or 0 if no periods should be added.
 */
#define GROUP_CHANNEL_MAX_CHARS  15

/**
 * This defines what the custom colour label for the group is
 * called.
 */
#define GROUP_COLOUR_EVENT   "group"

#endif

// --- END [/mnt/home2/grok/lib/include/group_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mail.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mail.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630068   Available: 13577422
Inodes: Total: 5242880    Free: 4960136
2297 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mail.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630068   Available: 13577422
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the mailer.
 * @author Pinkfish
 * @started 1992 sometime
 */
#ifndef __SYS__MAIL
#define __SYS__MAIL

#ifndef __MAIL_H_NO_CLASSES
/**
 * The mail header class.
 * @member number the message number
 * @member status the current status of the message
 * @member subject the subject of the message
 * @member from who the message is from
 */
class mail_header {
  int number;
  string status;
  string subject;
  string from;
}

/**
 * The mail message class.
 * @member to the list of people the message is to
 * @member cc the list of people the message is cced to
 * @member body the actual message text
 * @member subject the subject of the message
 */
class mail_message {
  string *to;
  string *cc;
  string body;
  string from;
  string subject;
}
#endif

/**
 * A define of the days as strings, starting from Sun as 0 to Sat as 6.
 */
#define DAYS ({"Sun", "Mon", "Tue", "Wed", "Thu", \
               "Fri", "Sat"})

/**
 * A define of an array of the months as strings, starting from Jan as 0 and
 * Dec as 11.
 */
#define MONTHS ({"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
     "Jul", "Aug", "Sep", "Oct", "Nov", \
     "Dec"})

/**
 * The path to the mail tracker handler.  Keeps track of who has which
 * mailer.
 */
#define MAIL_TRACK "/obj/handlers/mail_track"
/**
 * The path to the actual mailer object.
 */
#define MAILER "/obj/handlers/mailer"
/**
 * The path to the auto mailer object.
 */
#define AUTO_MAILER "/global/auto_mailer"
/**
 * The path to the smtp mail outgoing handler.
 */
#define OUT_MAIL "/net/daemon/out_mail"
/**
 * The path to the post office frog NPC.
 */
#define POST_FROG "/obj/monster/post_frog"
/**
 * The path to the place where the frogs try to go when they have
 * finished delivering their mail.
 */
#define FROG_HOME "/d/am/buildings/post/mailing"
/**
 * The path to the SMTP object.
 */
#define SMTP "/net/obj/smtp"
/**
 * The path to the location to look for external incoming mail.
 */
#define EXTERNAL_MAIL_PATH "/secure/mail/incoming/"
/**
 * This is the path to the parcel post handler.
 */
#define MAIL_PARCEL_HANDLER "/obj/handlers/parcel"

/**
 * This is the maximum number of messages storable in a single folder.
 */
#define MAX_FOLDER_SIZE 250
#define WARN_FOLDER_SIZE 100

#endif /* __SYS__MAIL */
// --- END [/mnt/home2/grok/lib/include/mail.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/localtime.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/localtime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
304 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/localtime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming

/*
 * Definitions for localtime() efun
 */
#define LT_SEC          0
#define LT_MIN          1
#define LT_HOUR         2
#define LT_MDAY         3
#define LT_MON          4
#define LT_YEAR         5
#define LT_WDAY         6
#define LT_YDAY         7
#define LT_GMTOFF       8
#define LT_ZONE         9
// --- END [/mnt/home2/grok/lib/include/localtime.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/finger.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/finger.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
124 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/finger.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__FINGER
#define __SYS__FINGER

#define CREATE (name != "domos" && name != "shru")

#endif /* __SYS__FINGER */
// --- END [/mnt/home2/grok/lib/include/finger.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/permissions.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/permissions.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
129 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/permissions.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/** 
 *  File Permissions
 *
 */
 
#define READ_MASK 1
#define WRITE_MASK 2
#define GRANT_MASK 4
#define LOCK_MASK 8

 // --- END [/mnt/home2/grok/lib/include/permissions.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/artifacts.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/artifacts.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
286 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/artifacts.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630067   Available: 13577421
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define ARTIFACT_HAND "/obj/handlers/artifact_handler"

#define RING_SKILL "magic.items.worn.ring"
#define STAFF_SKILL "magic.items.held.staff"
#define WAND_SKILL "magic.items.held.wand"

#define RING_OBJECT "/obj/ring"
#define STAFF_OBJECT "/obj/staff"
#define WAND_OBJECT "/obj/wand"
// --- END [/mnt/home2/grok/lib/include/artifacts.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/decay_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/decay_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
121 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/decay_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define DECAY_TIME 15
// time between do_decay calls in the decayer

#define DECAY_HANDLER "/obj/handlers/decay_handler"
// --- END [/mnt/home2/grok/lib/include/decay_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ftmoney.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ftmoney.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
196 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ftmoney.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__FTMONEY
#define __SYS__FTMONEY

#define MONEY_OBJECT "/obj/money"
#define MONEY_HAND "/obj/handlers/money_handler"
#define MONEY_ALIAS "SomeMoneyForMe"

#endif /* __SYS__FTMONEY */
// --- END [/mnt/home2/grok/lib/include/ftmoney.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/socket_errors.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/socket_errors.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
2070 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/socket_errors.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630066   Available: 13577420
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * socket_errors.h -- definitions for efun socket error return codes.
 *    5-92 : Dwayne Fontenot (Jacques@TMI) : original coding.
 *   10-92 : Dave Richards (Cynosure) : less original coding.
 */

#ifndef _SOCKET_ERRORS_H_
#define _SOCKET_ERRORS_H_

#define EESUCCESS	  1	/* Call was successful */
#define EESOCKET	 -1	/* Problem creating socket */
#define EESETSOCKOPT	 -2	/* Problem with setsockopt */
#define	EENONBLOCK	 -3	/* Problem setting non-blocking mode */
#define EENOSOCKS	 -4	/* UNUSED */
#define EEFDRANGE	 -5	/* Descriptor out of range */
#define EEBADF		 -6	/* Descriptor is invalid */
#define EESECURITY	 -7	/* Security violation attempted */
#define	EEISBOUND	 -8	/* Socket is already bound */
#define EEADDRINUSE	 -9	/* Address already in use */
#define EEBIND		-10	/* Problem with bind */
#define EEGETSOCKNAME	-11	/* Problem with getsockname */
#define EEMODENOTSUPP	-12	/* Socket mode not supported */
#define EENOADDR	-13	/* Socket not bound to an address */
#define EEISCONN	-14	/* Socket is already connected */
#define EELISTEN	-15	/* Problem with listen */
#define EENOTLISTN	-16	/* Socket not listening */
#define EEWOULDBLOCK	-17	/* Operation would block */
#define EEINTR		-18	/* Interrupted system call */
#define EEACCEPT	-19	/* Problem with accept */
#define	EEISLISTEN	-20	/* Socket is listening */
#define EEBADADDR	-21	/* Problem with address format */
#define EEALREADY	-22	/* Operation already in progress */
#define EECONNREFUSED	-23	/* Connection refused */
#define EECONNECT	-24	/* Problem with connect */
#define EENOTCONN	-25	/* Socket not connected */
#define EETYPENOTSUPP	-26	/* Object type not supported */
#define	EESENDTO	-27	/* Problem with sendto */
#define	EESEND		-28	/* Problem with send */
#define	EECALLBACK	-29	/* Wait for callback */
#define EESOCKRLSD	-30	/* Socket already released */
#define EESOCKNOTRLSD   -31	/* Socket not released */
#define EEBADDATA       -32	/* sending data with too many nested levels */

#define	ERROR_STRINGS	 33	/* sizeof (error_strings) */

#endif				/* _SOCKET_ERRORS_H_ */
// --- END [/mnt/home2/grok/lib/include/socket_errors.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/spells.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/spells.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630065   Available: 13577419
Inodes: Total: 5242880    Free: 4960136
187 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/spells.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630065   Available: 13577419
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__SPELLS
#define __SYS__SPELLS

#define SP_OBJECT 1
#define SP_FUNC 2
#define SP_PARAM 3
#define S_OBJECT 0
#define S_FUNC 1
#define SP_NO_RNDS 0

#endif /* __SYS__SPELLS */
// --- END [/mnt/home2/grok/lib/include/spells.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/situations.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/situations.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630065   Available: 13577419
Inodes: Total: 5242880    Free: 4960136
1231 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/situations.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630065   Available: 13577419
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This contains the definitions of the situation class
 * and the when defines for situations.
 * The when defines consist of (1>>hour) combined with or
 * where hour is an hour of the day during which a 
 * situation may occur (25 hour clock, AM time).
 * For example, WHEN_WEE_HOURS allows the situation
 * to occur between 12 midnite and 4 am.
 */

class situation { 
  string start_mess;
  string end_mess;
  string extra_look;
  function start_func;
  function end_func;
  int *chat_rate;
  string *chats;
  mixed *add_items;
  mixed *random_words;
}

#define WHEN_WEE_HOURS     ((1<<0) | (1<<1) | (1<<2) | (1<<3))
#define WHEN_EARLY_MORNING ((1<<4) | (1<<5) | (1<<6))
#define WHEN_LATE_MORNING  ((1<<7) | (1<<8) | (1<<9) | (1<<10) | (1<<11))
#define WHEN_AFTERNOON     ((1<<12) | (1<<13) | (1<<14) | (1<<15) | (1<<16))
#define WHEN_EVENING       ((1<<17) | (1<<18) | (1<<19))
#define WHEN_LATENIGHT     ((1<<20) | (1<<21) | (1<<22) | (1<<23))

#define WHEN_MIDDAY        ((1<<11) | (1<<12))
#define WHEN_MORNING       (WHEN_EARLY_MORNING | WHEN_LATE_MORNING)

#define WHEN_NIGHT         (WHEN_LATENIGHT | WHEN_WEE_HOURS)
#define WHEN_DAY           (WHEN_MORNING | WHEN_AFTERNOON)

#define WHEN_ANY_TIME      ((1<<24)-1)
// --- END [/mnt/home2/grok/lib/include/situations.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/mime.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/mime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630064   Available: 13577418
Inodes: Total: 5242880    Free: 4960136
1620 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/mime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630064   Available: 13577418
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __MIME_H
#define __MIME_H

/**
 * The header file for the MIME header parser.
 */

/**
 * The path to the MIME parser.
 */
#define MIME "/obj/handlers/mime"

/**
 * Checks if c is a white-space character.
 * @param c the character to check
 * @return 1 if c is a white-space character, 0 otherwise
 */
#define isspace(c) (((c) == ' ') || ((c) == '\t') || ((c) == '\n') || \
                    ((c) == 12) || ((c) == '\r') || ((c) == 11))

/**
 * Checks if c is a control character.
 * @param c the character to check
 * @return 1 if c is a control character, 0 otherwise
 */
#define iscntrl(c) (((c) == 127) || (((c) >= 0) && ((c) <= 31)))

/**
 * Checks if c is a hexadecimal digit.
 * @param c the character to check
 * @return 1 if c is a hexadecimal digit, 0 otherwise
 */
#define isxdigit(c) ((((c) >= 'A') && ((c) <= 'F')) || \
                     (((c) >= 'a') && ((c) <= 'f')) || \
                     (((c) >= '0') && ((c) <= '9')))

/**
 * Checks if c is an alphanumeric character.
 * @param c the character to check
 * @return 1 if c is a letter or digit, 0 otherwise
 */
#define isalnum(c) ((((c) >= '0') && ((c) <= '9')) || \
                    (((c) >= 'A') && ((c) <= 'Z')) || \
                    (((c) >= 'a') && ((c) <= 'z')))

/**
 * Checks if c is a digit character.
 * @param c the character to check
 * @return 1 if c is a digit, 0 otherwise
 */
#define isdigit(c) (((c) >= '0') && ((c) <= '9'))

class mime_header {
  mapping header_m;             /* keys: header fields, values: values */
  string *header_k;             /* ordered array of header fields */
}

#endif /* __MIME_H */
// --- END [/mnt/home2/grok/lib/include/mime.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/playerinfo.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/playerinfo.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630064   Available: 13577418
Inodes: Total: 5242880    Free: 4960136
1349 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/playerinfo.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630064   Available: 13577418
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the header file for the player information database handler.
 *
 * @author Fiona
 */

#ifndef __PLAYERINFO_H
#define __PLAYERINFO_H

/**
 * Structure containing one database entry. Fields are:
 *    time    - entry's creation timestamp
 *    creator - the name of the creator who added the event
 *    event   - the name of the event
 *    comment - arbitrary comment string
 *    extra   - arbitrary array of arbitrary objects
 * @ignore
 */
class dbentry {
    int     time;
    string  creator;
    string  event;
    string  comment;
    mixed   *extra;
}

/**
 * Structure containing a single player's information. Fields are:
 *    name        - the name of the player (always lowercased)
 *    last_check  - timestamp of the last timeout check
 *    alts        - array containing this player's alt character names
 *    data        - array containing playerinfo entries
 * @ignore
 */
class playerinfo {
    string          name;
    int             last_check;
    string          *alts;
    class dbentry   *data;
    string          main_alt;
    string          *old_alts;
    mapping         access_log;
}

/** This is the handler for all the player information. Lucky it. */
#define PLAYERINFO_HANDLER "/obj/handlers/playerinfo"

#define VERBOSE_PI "verbose playerinfo"

#endif                         // __PLAYERINFO_H
// --- END [/mnt/home2/grok/lib/include/playerinfo.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/disease.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/disease.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
395 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/disease.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define EFFECTS "/std/effects/"
#define SHADOWS "/std/shadows/"
#define BASIC_DISEASE EFFECTS "disease/basic_disease"
#define SIMPLE_DISEASE EFFECTS "disease/simple_disease"
#define BASIC_CURE EFFECTS "healing/basic_cure"
#define SIMPLE_CURE EFFECTS "healing/simple_cure"
#define DISEASE_HANDLER "/obj/handlers/disease"
#define CURE_SCALE ({ 2, 3, 3, 3 })
#define DISEASE_SCALE ({ 2, 3, 3, 3 })
// --- END [/mnt/home2/grok/lib/include/disease.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/effect.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/effect.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
375 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/effect.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__EFFECT
#define __SYS__EFFECT

#define REMOVE_THIS_EFFECT 2000000000
#define REMOVE_THIS_EFFECT_NEXT_HB 2000000001
#define CANCEL_THIS_EE 2000000002

#define EE_REMOVE 1
#define EE_CONTINUOUS 2
#define EE_OLD 4
#define EE_CANCELLED 8
#define EE_ONCE 0

#define BOGUS_OLD_ARG 20495621

class effect {
  string ob_name;
  mixed arg;
}

#endif /* __SYS__EFFECT */
// --- END [/mnt/home2/grok/lib/include/effect.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/nomic_system.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/nomic_system.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
6629 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/nomic_system.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630063   Available: 13577417
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file to deal with the nomic system for the
 * player council.
 * @author Pinkfish
 * @started Fri Jun 23 20:10:40 PDT 2000
 */
#ifndef __NOMIC_SYSTEM__
/** @ignore yes */
#define __NOMIC_SYSTEM__

/**
 * The path to the nomic rule handler.
 */
#define NOMIC_HANDLER "/obj/handlers/player_council"

#ifndef NOMIC_SYSTEM_NO_CLASSES
/**
 * This is the class to handle amendments to the rule
 * @member amender the person doing the amendments
 * @member text the text of the amendment
 * @member date_amended when it was amended
 */
class nomic_amendment {
   string amender;
   string text;
   int date_amended;
}

/**
 * The information on nomic rules.
 * @member id the id of the rule (unique)
 * @member date_create when the rule was created
 * @member creator who created the rule
 * @member text the text of the rule
 * @member amendments the amendments to the rule
 */
class nomic_rule {
   int id;
   int type;
   int date_created;
   string creator;
   string text;
   class nomic_amendment* amendments;
}

/**
 * The information needed for each nomic area.
 * @member new_type_num the next numbers to use in each type area
 * @member rules the rules for the area
 */
class nomic_area {
   int* new_type_num;
   class nomic_rule* rules;
}

/**
 * Comment on this new rule thingy by magistrates.
 * @member text the text of the comment
 * @member commenter the person commenting
 * @member date_commented the date the comment was made
 */
class nomic_comment {
   string text;
   string commenter;
   int date_commented;
}

/**
 * This method sets up a new nomic rule for someone to vote on.
 * @member identifier the id of the rule
 * @member motion_type the type of the new rule
 * @member rule the new rule (or amended rule)
 * @member new_rule_type if the rule typ eis to change types, this is the new
 * type
 * @member comments any comments associated with the rule
 * @member yes_votes the current set of yes votes
 * @member no_votes the current set of no votes
 * @member abstain_votes the current set of abstain votes
 * @member voted the current bunch of people that have voted
 * @member state the state of the current rule
 * @member date_added the date this new rule discussion was added
 * @member date_event the date of the last state change event
 * @member added_by the person who added the rule change
 */
class nomic_motion {
   int identifier;
   int motion_type;
   class nomic_rule rule;
   int new_rule_type;
   class nomic_comment* comments;
   int yes_votes;
   int no_votes;
   int abstain_votes;
   string* voted;
   int state;
   int date_added;
   int date_event;
   string added_by;
}
#endif

#ifdef NOMIC_SYSTEM_CASE_CLASSES

/**
 * This is a note associated with the case.
 * @param id the id of the note
 * @param person the person who made the note
 * @param text the text of the note
 * @param time_created the time the note was created
 */
class nomic_case_note {
   int id;
   string person;
   string text;
   int time_created;
}

/**
 * This is an event associated with the case.
 * @param type the type of the event
 * @param mess the message associated with the event
 * @param event_time the time of the event
 * @param data any extra data associed with the event
 */
class nomic_case_event {
   int type;
   string mess;
   string person;
   int event_time;
   mixed data;
}

/**
 * This is the class for the thing.
 * @param id the id of the case
 * @param opener the person who opened the case
 * @param short the short of the case
 * @param people the people who are involved in the case
 * @param notes the list of ids of the notes
 * @param events the array of events for the case
 * @param time_opened the time the case was opened
 */
class nomic_case {
   int id;
   string opener;
   string short;
   string* people;
   int* notes;
   class nomic_case_event* events;
   int time_opened;
}

#endif

/**
 * This is the default set of types for the nomic system.
 */
#define NOMIC_DEFAULT_TYPE_NUMS ({ 100, 300, 2000 })

/**
 * The immutable rule type.  Effects everyone.
 */
#define NOMIC_TYPE_IMMUTABLE 0
/**
 * The general rule type.  Effects everyone.
 */
#define NOMIC_TYPE_GENERAL   1
/**
 * The citizen rule type.  Only effects citizens.
 */
#define NOMIC_TYPE_CITIZEN   2

/**
 * The error define for nomic functions.
 */
#define NOMIC_ERROR -1

/**
 * This sets up the type of the new rule to be a real new rule.
 */
#define NOMIC_MOTION_TYPE_RULE_ADD     1
/**
 * This changes the text of the rule.  Amends it.
 */
#define NOMIC_MOTION_TYPE_RULE_AMEND   2
/**
 * This moves the rule type from one rule set to another.
 */
#define NOMIC_MOTION_TYPE_RULE_MOVE    3
/**
 * This removes the rule type from one rule set to another.
 */
#define NOMIC_MOTION_TYPE_RULE_REMOVE  3

/**
 * This is the state for when it is being looked at by the council.
 */
#define NOMIC_STATE_COUNCIL_REVIEW 1
/**
 * This is the state for when it is being voted on by the council.
 */
#define NOMIC_STATE_COUNCIL_VOTE   2
/**
 * This is the state for when it is being voted on by the citizens.
 */
#define NOMIC_STATE_CITIZEN_VOTE   3

/**
 * This sets the yes type of the vote.
 */
#define NOMIC_VOTE_YES 1
/**
 * This sets the no type of the vote.
 */
#define NOMIC_VOTE_NO  2
/**
 * This sets the abstain type of the vote.
 */
#define NOMIC_VOTE_ABSTAIN  3

/**
 * This is the event type for a close event on a case.
 */
#define NOMIC_CASE_EVENT_CLOSE  1
/**
 * This is the event type for an open event on a case.
 */
#define NOMIC_CASE_EVENT_APPEAL 2
/**
 * This is the event type for a remove person event.
 */
#define NOMIC_CASE_EVENT_ADD_PERSON 3
/**
 * This is the event type for a add person event.
 */
#define NOMIC_CASE_EVENT_REMOVE_PERSON 4

/**
 * This is the directory to use to get the default rules from.
 */
#define NOMIC_RULE_DEFAULT_DIR "/save/nomic/default/"

/**
 * This is the directory to find all the default nomic punishments from.
 */
#define NOMIC_PUNISHMENT_DIR "/std/room/punishments/"
/**
 * This is the directory to find all the punishment documentation.
 */
#define NOMIC_PUNISHMENT_DOCS_DIR "/doc/punishments/"

/**
 * This is where the system saves it's nomic rules.
 */
#define NOMIC_SYSTEM_SAVE_FILE "/save/nomic/main.o"

/**
 * This is the place where we will save the nomic information about
 * cases.
 */
#define NOMIC_CASE_SAVE "/save/nomic/"

/**
 * This is the amount of time some has to appeal the decision.
 * 2 weeks.
 */
#define NOMIC_CASE_APPEAL_TIME (14 * 60 * 60 * 24)

/**
 * This is the name of the poster used to post messages to the boards.
 */
#define NOMIC_SYSTEM_ADMINISTRATOR_NAME "Administration"

#endif
// --- END [/mnt/home2/grok/lib/include/nomic_system.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/twiki.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/twiki.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
310 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/twiki.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file to get the define for the twiki interface
 * inside the mud.
 * @author Pinkfish
 * @started Wed May 24 17:10:08 PDT 2000
 */
#ifndef __TWIKI_H
/** @ignore yes */
#define __TWIKI_H

/**
 * This is the path of the handler.
 */
#define TWIKI_HANDLER "/obj/handlers/twiki"

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/twiki.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/guild_base.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/guild_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
68 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/guild_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
class teach_skill  {
   string skill;
   int teach;
   int learn;
}
// --- END [/mnt/home2/grok/lib/include/cmds/guild_base.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/teach.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/teach.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
1284 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/teach.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630061   Available: 13577415
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains all the stuff to do with the teaching respondable
 * command.
 * @author Pinkfish
 * @started Sun Aug 16 23:39:28 PDT 1998
 */
#ifndef __CMDS_TEACH_H__
/** @ignore yes */
#define __CMDS_TEACH_H__

/**
 * The class to keep track of everything to do with teaching a skill.
 */
class teaching_skill {
   /**
    * The skill to teach.
    */
   string skill;
   /**
    * The level the skill was at when we started teaching.
    */
   int lvl;
   /**
    * The number of levels of the skill to teach.
    */
   int num;
   /**
    * The amount of xp to spend on teaching the skill.
    */
   int xp;
   /**
    * This is used in the stop command for teaching the skill.
    */
   object teacher;
   /**
    * This is used iun the stop command for teaching the skill.
    */
   object taught;
   /**
    * This is the location we started the teaching in.  Fail if we moved.
    */
   object room;
}

/**
 * This is the type used for teaching skills.
 */
#define TEACH_SKILL_TYPE "teach skill"

/**
 * This is the type used for teaching commands.
 */
#define TEACH_COMMAND_TYPE "teach command"

/**
 * This is the property to use to test to see if the player has
 * automatic teaching turned on or not.
 */
#define TEACH_COMMAND_AUTO_PROPERTY "auto teach"

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/teach.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/options.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/options.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630060   Available: 13577414
Inodes: Total: 5242880    Free: 4960136
1669 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/options.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630060   Available: 13577414
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This contains all the defines for the options command and the options
 * handler.
 * @author Pinkfish
 * @started Thu Jun  8 17:59:30 PDT 2000 
 */
#ifndef __CMDS_OPTIONS_H
/** @ignore yes */
#define __CMDS_OPTIONS_H

/** An integer type. */
#define OPTIONS_TYPE_INTEGER  1
/** A string type. */
#define OPTIONS_TYPE_STRING   2
/** A boolean type. */
#define OPTIONS_TYPE_BOOLEAN  3
/** A brief/verbose type. */
#define OPTIONS_TYPE_BRIEF    4
/** A colour type. */
#define OPTIONS_TYPE_COLOUR   5
/** A dynamic group option.  This will expand out to a bunch more options. */
#define OPTIONS_TYPE_DYNAMIC_GROUP 6
/** A percentage type. */
#define OPTIONS_TYPE_PERCENTAGE 7
/** A terminal type. */
#define OPTIONS_TYPE_TERMINAL   8
/** A normal group. */
#define OPTIONS_TYPE_GROUP 9

/**
 * This is the path to the option handler.
 */
#define OPTION_HANDLER "/obj/handlers/options_handler"

/**
 * The property for determining the include file to exec.
 */
#define OPTION_EXEC_INCLUDE "exec include"

/**
 * The property to use for determining tab stop information.
 */
#define TABSTOP_PROP "more tabstop"

/**
 * The property to use for determining shorthand expansion.
 */
#define SHORTHAND_PROP "expand shorthands"
#define SHORTHAND_OUTPUT_PROP "expand output shorthands"


/** The monitor options */
#define MONITOR_OPTIONS ({ "off", "on", "slow", "snails pace" })

/** Type of option, everyone's option. */
#define OPTIONS_TYPE_ALL 0
/** Type of option, creator only. */
#define OPTIONS_TYPE_CRE_ONLY 1
/** Type of option, lord only. */
#define OPTIONS_TYPE_LORD_ONLY 2
/** Type of option, playtester only. */
#define OPTIONS_TYPE_PLAYTESTER_ONLY 3

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/options.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/bury.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/bury.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
565 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/bury.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Contains information specific for the bury command.
 * @author Pinkfish
 * @started Mon Feb  7 01:12:21 PST 2000
 */
#ifndef __BURY_H
/** @ignore yes */
#define __BURY_H

/**
 * This is the path to the burial effect.
 */
#define BURY_EFFECT "/std/effects/room/burial"

/**
 * This is the amount of time to leave the thing buried before really
 * destroying it. (5 minutes)
 */
#define BURY_TIMEOUT (5 * 60)

/**
 * This is the property that's used to track the environment of the object
 * when it's buried.
 */
#define BURY_PROPERTY "bury location"

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/bury.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/offer.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/offer.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
646 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/offer.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file has all the defines for offer/accept npc handlers.
 * @author Pinkfish
 * @started Tue Aug 18 06:47:13 EDT 1998
 */
#ifndef __OFFER_NPC_H__
/** @ignore yes */
#define __OFFER_NPC_H__

/**
 * The class for offering a sale to another player/npc.
 */
class offer_sale {
   /**
    * The value of the sale.
    */
   int value;
   /**
    * The place in which to handle the money.
    */
   string place;
   /**
    * The objects being sold.
    */
   object *sell_obs;
   /**
    * This is the person who does the selling.
    */
   object seller;
   /**
    * This is the person doing the buying.
    */
   object buyer;
}

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/offer.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/cmds/friends.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/cmds/friends.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
290 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/cmds/friends.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630059   Available: 13577413
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is stuff specific for the friends command.
 * @author Pinkfish
 * @started Thu May 30 15:21:09 PDT 2002
 */
#ifndef __CMDS_FRIENDS_H__
/** @ignore yes */
#define __CMDS_FRIENDS_H__

/** The location of the friends command. */
#define FRIENDS_CMD "/cmds/player/friend_s"

#endif
// --- END [/mnt/home2/grok/lib/include/cmds/friends.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/clothing.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/clothing.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
412 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/clothing.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the clothing include file.  It has all the defines and
 * classes need to make your clothing more fun.
 * @author Pinkfish
 */
#ifndef __CLOTHING_H
/** @ignore yes */
#define __CLOTHING_H
 
/**
 * This points to the clothing handler object.
 */
#define CLOTHING_HANDLER "/obj/handlers/clothing_handler"
 
class clothing_type {
   string *_not_remove;
   string *_hiding;
   int _depth;
}
 
#endif
// --- END [/mnt/home2/grok/lib/include/clothing.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/top_ten_tables.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/top_ten_tables.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
1545 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/top_ten_tables.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The defines for the top ten tables.
 * @author Deutha
 */
#ifndef __TOP_TEN_TABLES_H
/** @ignore yes */
#define __TOP_TEN_TABLES_H

/**
 * The path to the top ten handler.
 */
#define TOP_TEN_HANDLER "/obj/handlers/top_ten_handler"

/**
 * The index of the name of the player in the returned array.
 */
#define TOP_TEN_NAME 0
/**
 * The index of the name of the player's rating in the returned array.
 */
#define TOP_TEN_RATING 1
/**
 * The index of the name of the player's guild level in the returned array.
 */
#define TOP_TEN_LEVEL 2
/**
 * The index of the name of the player's age in the returned array.
 */
#define TOP_TEN_AGE 3

/**
 * The index of the family with the most members.
 */
#define TOP_TEN_LARGEST_FAMILY    0
/**
 * The index of the family with the highest average age.
 */
#define TOP_TEN_OLDEST_FAMILY     1
/**
 * The index of the family with the highest average quest points.
 */
#define TOP_TEN_MOST_QUEST_POINTS 2
/**
 * The index of the guilds mapping for the most of each guild.
 */
#define TOP_TEN_MOST_GUILD        3
/**
 * The index of the family with the most pks.
 */
#define TOP_TEN_MOST_PKS          4
/**
 * The index of the largest single gender family.
 */
#define TOP_TEN_SINGLE_GENDER     5
/**
 * The index of the family that has the oldest logged on players.
 */
#define TOP_TEN_OLDEST_LOGONS     6
/**
 * The index of the family that has the msot relationships per person.
 */
#define TOP_TEN_MOST_RELATIONSHIPS 7

class top_ten_family_guild {
   int num;
   string top_family_name;
}

#endif
// --- END [/mnt/home2/grok/lib/include/top_ten_tables.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/guide_places.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/guide_places.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
2164 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/guide_places.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630058   Available: 13577412
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
// These are the places the guide can go to.  The first element is the
// word the player must say, the second is the file name of the location
// and the third is what the guide describes the place as.

string *guilds = ({
  "fish",
    "/d/am/cockbill/cockbill8", 
      "the Temple of Fish",
  "small gods",
    "/d/guilds/priests/Ankh-Morpork/small-gods/entrance", 
      "the Temple of the Small Gods",
  "warrior", 
    "/d/am/hero/lobby", 
      "the Warriors' Guild",
  "wizard", 
    "/d/am/square/ss13", 
      "the Unseen University",
  "university", 
    "/d/am/square/ss13", 
      "the Unseen University",
  "assassin", 
    "/d/guilds/assassins/Ankh-Morpork/admin/foyer", 
      "the Assassins' Guild",
  "thief",
    "/d/guilds/thieves/Ankh-Morpork/rooms/ground/entrance",
      "the Thieves' Guild",
  "thieves",
    "/d/guilds/thieves/Ankh-Morpork/rooms/ground/entrance",
      "the Thieves' Guild",
  "gennie",
    "/d/guilds/witches/Ankh-Morpork/gennies_cottage",
      "Gennie's place"});

string *services = ({
  "drum",
    "/d/am/am/mendeddrum",
      "the Mended Drum",
  "bank",
    "/d/am/broad_way/bing_bank",
      "the Bank of Bing",
  "post",
    "/d/am/ampost/foyer",
      "the Post Office",
   "sator stall",
     "/d/guilds/merchants/stalls/am/sator",
     "the Sator Square player stall",
   "cockbill stall",
     "/d/guilds/merchants/stalls/am/cockbill",
      "the Cockbill Street player stall",
  "patrician",
    "/d/am/patrician/foyer",
      "the Patrician's Palace"});

string *places = ({
  "sator square",
    "/d/am/square/ss33", 
      "Sator Square",
  "least gate", 
    "/d/am/gates/least", 
      "the Least Gate",
  "brass bridge",
    "/d/am/river/bridge",
      "the Brass Bridge",
  "widdershins gate",
    "/d/am/gates/widdershins",
      "the Widdenshins Gate",
  "cockbill",
    "/d/am/cockbill/cockbill1",
      "Cockbill Street",
  "plaza",
    "/d/am/plaza/plaza_33",
      "the Plaza of Broken Moons",
  "hubward",
    "/d/am/gates/hubwards",
      "the Hubwards Gate",
  "pillory",
    "/d/am/pillory/pillory2",
      "Pillory Place",
  "ninth yard",
    "/d/am/ninth/ninth1",
      "Ninth Yard"});

// --- END [/mnt/home2/grok/lib/include/guide_places.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/data.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/data.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630057   Available: 13577411
Inodes: Total: 5242880    Free: 4960136
730 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/data.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630057   Available: 13577411
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the include file for the data handler. The main bits of the data
 * handler were written by Jeremy.  The lisp like compiler for the data
 * was added by Pinkfish March 10th 2002.
 * @author Pinkfish
 */

#ifndef __DATA_HANDLER_H
/** @ignore yes */
#define __DATA_HANDLER_H

/**
 * This is the path to the data handler. 
*/
#define DATA_HANDLER "/obj/handlers/data"

/**
 * This is the class used for dealing with dice like structures in the
 * the lisp like data structure compiler.
 * @element die the die to roll
 * @element number the number of times to roll it
 * @element modifier the amount to be added or subtracted from the result
 */
class data_dice {
   int die;
   int number;
   int modifier;
}

#endif
// --- END [/mnt/home2/grok/lib/include/data.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/sur.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/sur.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630057   Available: 13577411
Inodes: Total: 5242880    Free: 4960136
2598 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/sur.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630057   Available: 13577411
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* sur.h - Common defines for the Sur domain
 *
 * Rhinehold, 08-Aug-01
 *
 */

#if !defined(__SUR__)
#define __SUR__

#define SUR                    "/d/sur/"

// Cities and towns

#define STO_LAT                SUR "StoLat/"
#define NOWHERE                SUR "Nowhere/"
#define DINKY                  SUR "Dinky/"
#define SHEEPRIDGE             SUR "Sheepridge/"
#define HOLYWOOD               SUR "Holywood/"
#define PEKAN_FORD             SUR "PekanFord/"
#define HILLSHIRE              SUR "Hillshire/"
#define CONSORT                SUR "Consort/"
#define SCROGDEN               SUR "Scrogden/"
#define RHAM_NITZ              SUR "Rham_Nitz/"
#define CHIRM                  SUR "Chirm_dev/"
#define JOWSERS_COVE           SUR "JowsersCove_dev/"
#define PSEUDOPOLIS            SUR "Pseudopolis_dev/"
#define QUIRM                  SUR "Quirm_dev/"
#define SCROTE                 SUR "Scrote_dev/"
#define STO_HELIT              SUR "Sto_Helit/"
#define STO_KERRIG             SUR "StoKerrig_dev/"
#define WEEZENT                SUR "Weezent/"

// Large areas

#define STO_PLAINS             SUR "Sto_Plains/"
#define SKUND_FOREST           SUR "Skund/"
#define CARRACK_MTNS           SUR "Carrack_Mtns/"
#define MORPORK_MTNS           SUR "Morpork_Mtns/"
#define ANKH_RIVER             SUR "Ankh_River/"

// Small areas

#define BEL_SHAMHAROTH         SUR "Bel_Shamharoth/"
#define DRYAD                  SUR "Dryad/"
#define HAUNTED_HOUSE          SUR "HauntedHouse/"

// Misc

#define SUR_ITEMS              SUR "items/"
#define SUR_CHARS              SUR "chars/"
//#define SUR_HOSPITAL           (SUR+"hospital")
#define SUR_HOSPITAL           SUR "hospital/sur_hospital"
#define SUR_ROADS              SUR "roads/"
#define SUR_CURRENCY_DEFAULT   "Ankh-Morpork"
#define SAVE                   "/save/"
#define SUR_SAVE               SAVE "sur/"

// Inherits

#define SUR_INHERIT            SUR "inherit/"
#define SUR_HUMAN              SUR_INHERIT "sur_human"
#define SUR_ANIMAL             SUR_INHERIT "sur_animal"
#define SUR_PEDDLER            SUR_INHERIT "sur_peddler"
#define SUR_INSIDE             SUR_INHERIT "inside_room"
#define SUR_OUTSIDE            SUR_INHERIT "outside_room"
#define SUR_ITEM_SHOP_INSIDE   SUR_INHERIT "item_shop_inside"
#define SUR_ITEM_SHOP_OUTSIDE  SUR_INHERIT "item_shop_outside"
#define SUR_GEN_SHOP_INSIDE    SUR_INHERIT "general_shop_inside"
#define SUR_GEN_SHOP_OUTSIDE   SUR_INHERIT "general_shop_outside"

// Standard room sizes

#define SHORT_ROAD             10000
#define MEDIUM_ROAD            25000
#define LONG_ROAD              50000

#endif
// --- END [/mnt/home2/grok/lib/include/sur.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/merchant.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/merchant.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630056   Available: 13577410
Inodes: Total: 5242880    Free: 4960136
313 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/merchant.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630056   Available: 13577410
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define MERCHANT "/d/guilds/merchants"

#define STALL MERCHANT+"/stalls/"
#define SHOPS MERCHANT+"/shops/"
#define MERCHANT_GUILD MERCHANT+"/guild/"

#define MERCHANT_CHARS MERCHANT+"/chars/"
#define MERCHANT_ITEMS MERCHANT+"/items/"
#define MERCHANT_SAVE MERCHANT+"/save/"
#define MERCHANT_STD MERCHANT+"/std/"

// --- END [/mnt/home2/grok/lib/include/merchant.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/bit.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/bit.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
289 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/bit.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__BIT
#define __SYS__BIT

#define BIT_SIZE 3
#define BIT_NAME 0
#define BIT_ALIAS 1
#define BIT_EXTRA 2
#define EXTRA_PARENT 0
#define EXTRA_WEIGHT 1
#define EXTRA_VALUE 2
#define EXTRA_SUBBIT 3

#define BIT_CONTROLLER "/obj/handlers/bits_controller"

#endif /* __SYS__BIT */
// --- END [/mnt/home2/grok/lib/include/bit.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/nameserver.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/nameserver.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
146 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/nameserver.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__NAMESERVER
#define __SYS__NAMESERVER

#define NAME_D "/net/nameserver"
#define INET_D "/net/inetd"

#endif /* __SYS__NAMESERVER */
// --- END [/mnt/home2/grok/lib/include/nameserver.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/good_fighter.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/good_fighter.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
321 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/good_fighter.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define GOOD_FIGHTER "/std/effects/npc/good_fighter"

//  bits: 000uuudd (uuu = use, dd = defend)
#define USE_UNARMED 16
#define USE_BLUNT 12
#define USE_SHARP 8
#define USE_PIERCE 4
#define USE_BALANCED 0
#define USE_mask 28

#define DEFEND_DODGE 2
#define DEFEND_PARRY 1
#define DEFEND_BALANCED 0
#define DEFEND_mask 3
// --- END [/mnt/home2/grok/lib/include/good_fighter.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/imap4.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/imap4.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
1527 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/imap4.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630055   Available: 13577409
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __IMAP4_H
#define __IMAP4_H

#define PORT_IMAP4 1143

#define IMAP4_VERSION "0.1"

#define IMAP_CONNECTED   0
#define IMAP_AUTHENTICATED   1
#define IMAP_SELECTED 2

#define LOGIN_OB "/secure/login"
#define FOLDER_H "/obj/handlers/folder_handler"

#define DEBUG
#ifdef DEBUG
#define TP(_x) tell_object(find_player("ceres"), (_x))
#else
#define TP(_x)
#endif

#define CHECK_STATE(_state) if ((_state) != sess->state) \
{ \
    eventWrite(fd, sprintf("* BAD Unknown command in %s state\r\n", \
                           imap_states[sess->state])); \
    break; \
} 

#define CHECK_CMD(_num, _str) if (sizeof(bits) < (_num)+2) \
                       { \
                         eventWrite(fd, _str); \
                         break; \
                       }

class imap_session {
  int fd;                      /* socket descriptor */
  int state;                   /* state of the connection */
  int time;                    /* time of last command */
  string user_name;            /* user name */
	string selected;             /* selected folder */
	string command;              /* last command */
  int *deleted;                /* list of deleted messages */
  int num_messages;            /* amount of messages in the folder */
  class mail_header *headers;  /* headers of messages in the folder */
  string *messages;            /* parsed messages */
  int *sizes;                  /* sizes of parsed messages */
  int last;                    /* number of last accessed message */
}

#endif /* __IMAP4_H */
// --- END [/mnt/home2/grok/lib/include/imap4.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/telnet.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/telnet.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630054   Available: 13577408
Inodes: Total: 5242880    Free: 4960136
176 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/telnet.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630054   Available: 13577408
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define DO 253
#define IAC 255
#define SB  250
#define SE  240
#define TELOPT_TTYPE 24
#define TELOPT_NAWS 31
#define TELOPT_MXP 91
#define TELQUAL_IS 0
#define TELQUAL_SEND 1
// --- END [/mnt/home2/grok/lib/include/telnet.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/log.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/log.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630054   Available: 13577408
Inodes: Total: 5242880    Free: 4960136
1245 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/log.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630054   Available: 13577408
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This include file for use with bug, idea and typo report logging.
 */
#ifndef __SYS__LOG
/** @ignore yes */
#define __SYS__LOG


/**
 * This is the file name into which the errors used to saved.  Depreciated.
 * @ignore yes
 */
#define ERROR_LOG "ERROR_REPORTS"
/**
 * This is the file name into which the errors used to saved.  Depreciated.
 * @ignore yes
 */
#define PLAYER_ERROR_LOG "BUGS"
/**
 * Where the errors are logged to.
 */
#define LOG_FILE "/log/ERRORS"
/**
 * Used to keep track of the mailing list to use when you exit the
 * error system.
 */
#define TEMP_MAIL_LIST ("/w/" + this_player()->query_name() + "/TEMP_MAIL_LIST")
/**
 * Used to keep track of the forward list to use when you exit the
 * error system.
 */
#define TEMP_FORWARD_LIST ("/w/" + this_player()->query_name() + "/TEMP_FORWARD_LIST")
/**
 * The smart logger.
 */
#define SMART_LOG "/std/smart_log"

/**
 * Used to keep track of the mail list to use when you exit the
 * error system on the web.
 */
#define WWW_TEMP_MAIL_LIST "/w/" + user + "/TEMP_MAIL_LIST"
/**
 * Used to keep track of the forward list to use when you exit the
 * error system on the web.
 */
#define WWW_TEMP_FORWARD_LIST "/w/" + user + "/TEMP_FORWARD_LIST"

#endif /* __SYS__LOG */
// --- END [/mnt/home2/grok/lib/include/log.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/shop.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
423 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__SHOP
#define __SYS__SHOP

#define PAY_RATES ({ 100, 90, \
                     200, 80, \
                     400, 70, \
                     800, 60, \
                     1600, 50, \
                     3200, 40, \
                     6400, 30, \
                     12800, 20, \
                     10 })
#define MAX_AMOUNT 50000
#define MAX_INVENTORY 50
#define MAX_OBS 8

#endif /* __SYS__SHOP */
// --- END [/mnt/home2/grok/lib/include/shop.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/chime.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/chime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
556 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/chime.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the chime handler.  Spcifies the location of the
 * chime handler and the types used in the fucntion call when chiming.
 * @see /obj/handlers/chime_handler.c
 * @author Pinkfish
 */
#ifndef __CHIME_H
/** @ignore yes */
#define __CHIME_H

/** The chime handler object. */
#define CHIME_HANDLER "/obj/handlers/chime_handler"

/** The type for the hour chime. */
#define CHIME_HOUR 1
/** The type of the half hour chime. */
#define CHIME_HALF_HOUR 2
/** The type for the quarter hour chime. */
#define CHIME_QUARTER_HOUR 4

#endif
// --- END [/mnt/home2/grok/lib/include/chime.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/peopler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/peopler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
4185 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/peopler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630053   Available: 13577407
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the support stuff for the peopler command...
 * The tags are all placed into an array.  The MASKs for RIGHT and CENTER
 * can be applied to the tags to make them centered or right justified
 * respectively.
 * @author Pinkfish
 */

#ifndef __PEOPLE_H
/** @ignore yes */
#define __PEOPLE_H

/** A name field. */
#define NAME 0
/** A Capitalized name field. */
#define C_NAME 1
/** This is used to put spaces into the output. */
#define STRING 2
/** The gender field. */
#define GENDER 3
/** The ip number field. */
#define IP_NUMBER 4
/** The ip name field. */
#define IP_NAME 5
/** The object type field (C, p, etc). */
#define TYPE 6
/** The players age field. */
#define AGE 7
/** The players guild field. */
#define GUILD 8
/** The players race field. */
#define RACE 9
/** The plauyers level field. */
#define LEVEL 10
/** The players terminal type field. */
#define TERMINAL 11
/** The current numbr of rows for the player. */
#define ROWS 12
/** The current number of columns for the player. */
#define COLS 13
/** The current room the player is in. */
#define ROOM 14
/** The players effective user id. */
#define EUID 15
/** The players user id. */
#define UID 16
/** The creator file. */
#define CFILE 17
/** The current directory of the player. */
#define CUR_DIR 18
/** Is the player allowed to be on together with someone from the same IP? */
#define ND_ALLOWED 19

/** The Center mask, center the info. */
#define CENTER 128
/** The right justify mask. */
#define RIGHT 64
/** The mask of change flags. */
#define MASK (RIGHT+CENTER)
/** The list of abbreviations for the types. */
#define ABBREV ({ \
          "n", \
          "N", \
          "",  \
          "G", \
          "#", \
          "I", \
          "T", \
          "A", \
          "g", \
          "R", \
          "L", \
          "t", \
          "r", \
          "c", \
          "O", \
          "E", \
          "U", \
          "F", \
          "/", \
          "a"  \
        })
/** The names of the types, given in the header. */
#define DE_NAMES ({ \
          "Name", \
          "Capitalized Name", \
          "", \
          "Gender", \
          "IP Number", \
          "IP Name", \
          "Type", \
          "Age", \
          "Guild", \
          "Race", \
          "Level", \
          "Terminal type", \
          "Rows", \
          "Cols", \
          "Room", \
          "Euid", \
          "Uid", \
          "Creator file", \
          "Current dir", \
          "Not allowed with" \
        })

/* This is the default people listing thingy. */
/** The default set of of tags for the people command. */
#define P_DEFAULT ({ \
          NAME, 15, \
          TYPE|CENTER, 3, \
          GENDER|CENTER, 6, \
          STRING, " ", \
          GUILD|CENTER, 10, \
          STRING, " ", \
          LEVEL|RIGHT, 4, \
          STRING, " ", \
          AGE, 5, \
          ROOM, 30 \
        })
/** The default set of tags for the quick people command. */
#define QP_DEFAULT ({ \
          AGE|RIGHT, 4, \
          STRING, " ", \
          NAME, 30, \
        })
/** The default set of flage for the term command. */
#define T_DEFAULT ({ \
          NAME, 12, \
          ROWS|CENTER, 5, \
          STRING, " ", \
          COLS|CENTER, 4, \
          STRING, " ", \
          TERMINAL, 30, \
        })
/** The default set of flags for the netstat command. */
#define N_DEFAULT ({ \
          NAME, 12, \
          STRING, " ", \
          IP_NUMBER, 16, \
          STRING, " ", \
          IP_NAME, 30, \
        })
#define SN_DEFAULT ({ \
          IP_NAME, 30, \
          STRING, " ", \
          IP_NUMBER, 16, \
          STRING, " ", \
          NAME, 12, \
        })
/** The default set of flags for the dirs command. */
#define D_DEFAULT ({ \
          NAME, 12, \
          STRING, " ", \
          CUR_DIR, 25, \
          STRING, " ", \
          ROOM, 40, \
        })
/** The default set of flags for the netdups command. */
#define ND_DEFAULT ({ \
          NAME, 12, \
          STRING, " ", \
          IP_NUMBER, 16, \
          STRING, " ", \
          IP_NAME, 20, \
          STRING, " ", \
          ND_ALLOWED, 100, \
        })

#endif
// --- END [/mnt/home2/grok/lib/include/peopler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/clubs.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/clubs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630052   Available: 13577406
Inodes: Total: 5242880    Free: 4960136
14972 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/clubs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630052   Available: 13577406
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The main include file for clubs.  This contains all the defines and things
 * needed to interface to the club handler.
 * @author Pinkfish
 * @started Sat Oct  3 22:30:30 EDT 1998
 */
#ifndef __CLUBS_H
/** @ignore yes */
#define __CLUBS_H

#include <am_time.h>

/**
 * The type to use to create a personal club type.  In a personal club it
 * is run by one specific person, if that person leaves the mud for too
 * long or the dues are not paid then the club will cease to exist.
 * @see /obj/handlers/club_handler->create_club()
 */
#define CLUB_PERSONAL  0
/**
 * The type to use to create a elected club type.  In an elected club all
 * the officals are elected now and then.
 * @see /obj/handlers/club_handler->create_club()
 */
#define CLUB_ELECTED   1
/**
 * The type to use to create a family.  A family is a special type of a
 * club.
 * @see /obj/handlers/club_handler->create_club()
 */
#define CLUB_FAMILY    2

/**
 * String array to give the club type name.
 */
#define CLUB_ARRAY ({"Personal", "Elected", "Family"})

/**
 * The default name for the default account.
 */
#define CLUB_DEFAULT_ACCOUNT_NAME "default"

/**
 * This is the mask to get the type from the type attribute.
 */
#define CLUB_TYPE_MASK (15)
/**
 * This is the mask to get the flags from the type attribute.
 */
#define CLUB_FLAGS_MASK (~CLUB_TYPE_MASK)
/**
 * This is the flag to determine if the club is secret or not.
 */
#define CLUB_SECRET_FLAG 16

/**
 * This amount of money a club will cost to run each dw year.
 */
#define CLUB_COST_PER_YEAR (400 * 50)
/**
 * The amount it costs to startup a club.
 */
#define CLUB_STARTUP_COST (400 * 100)
/**
 * The amount it costs to startup a family.
 */
#define FAMILY_STARTUP_COST (400 * 300)
/**
 * This amount of money a family will cost to run each dw year.
 */
#define FAMILY_COST_PER_YEAR (400 * 300)
/**
 * The amount of money a club costs per member per year.  10 am pence.
 */
#define CLUB_COST_PER_MEMBER_PER_YEAR 100
/**
 * The amount of money a family costs per member per year.  10 am pence.
 */
#define FAMILY_COST_PER_MEMBER_PER_YEAR 200
/**
 * This is the cost of the inisgnia.
 */
#define CLUB_COST_INSIGNIA (400)

/**
 * This is the minimum number of members a club must have before it can
 * become elected.
 */
#define CLUB_MINIMUM_ELECTED_MEMBERS 10
/**
 * This is the maximum number of members a club can have before it
 * must turn into an elected club.
 */
#define CLUB_MAXIMUM_ELECTED_MEMBERS 30

/**
 * The location of the club handler.
 */
#define CLUB_HANDLER "/obj/handlers/club_handler"
/**
 * The location of the club badge.
 */
#define CLUB_BADGE "/obj/misc/club_badge"

/**
 * This is an invalid time for the clubs election to be set to.
 */
#define CLUB_INVALID_TIME 0

/**
 * This defines the club timeout for the clubs.  8 weeks.
 */
#define CLUB_TIMEOUT (8 * 7 * 24 * 60 * 60)
/**
 * This defines the amount of time for each pay period.
 */
#define CLUB_PAY_PERIOD (AM_SECONDS_PER_HALF_YEAR / 4)
/**
 * This defines the amount of time between each election.  About 6 real
 * months and 2 am years.
 */
#define CLUB_ELECTION_PERIOD (AM_SECONDS_PER_HALF_YEAR * 2)
/**
 * This defines the minimum amount of time for an election.
 */
#define CLUB_MINIMUM_ELECTION_PERIOD (AM_SECONDS_PER_HALF_YEAR / 2)
/**
 * This defines the amount of time to call for nominations.
 */
#define CLUB_NOMINATION_TIME (7 * 24 * 60 * 60)
/**
 * This defines the amount of time for the actuall election.
 */
#define CLUB_ELECTION_TIME (7 * 24 * 60 * 60)

/**
 * This defines the type to use for clubs in the add_respond_command
 * section of the club handling.
 * @see /std/living/respond_cmd.c
 */
#define CLUB_RESPOND_TYPE "club"
/**
 * This defines the type to use for families in the add_respond_command
 * section of club handling.
 * @see /std/living/respond_cmd.c
 */
#define CLUB_FAMILY_RESPOND_TYPE "family"

#ifndef __CLUBS_H_NO_CLASSES
/**
 * This defines the class to use for accepting into families.
 * @member family the family name
 * @member relationship the relationship type
 */
class family_response_data {
   string family;
   string relationship;
}

/**
 * This class defines the stuff which shows the relationships between the
 * two people.
 * @member related_to who they are related to
 * @member relationship the relationship between the two people
 */
class relationship_data {
   string related_to;
   string relationship;
}
#endif

/**
 * Transaction type when someone requests some insignias.
 */
#define CLUB_TRANSACTION_INSIGNIA 1
/**
 * Transaction type when someone deposits some money.
 */
#define CLUB_TRANSACTION_DEPOSIT 2
/**
 * Transaction type for when the club has its yearly charges.
 */
#define CLUB_TRANSACTION_UPKEEP 3
/**
 * Transaction type for starting balance of the club.
 */
#define CLUB_TRANSACTION_START_BALANCE 4
/**
 * Transaction type for withdrawing some money from the club.
 */
#define CLUB_TRANSACTION_WITHDRAWL 5
/**
 * Transaction type for transfering money from one account to another.
 */
#define CLUB_TRANSACTION_TRANSFER 6

#ifndef __CLUBS_H_NO_CLASSES
/**
 * This class is used to keep track of financial transactions for
 * each club.
 * @member who who made the transaction
 * @member amount Amount of the transaction
 * @member transaction_type type of the transaction
 * @member date the date at which the transaction occured
 * @member information the information about the transaction
 */
class club_transaction {
   string who;
   int amount;
   int transaction_type;
   int date;
   string information;
}

/**
 * This class is used for the archives in elected clubs.
 * @memver archive_date the date at which the archived element was added
 * @member subject the subject of the archive
 * @member matter the actual matter of the archive
 */
class club_archive {
   int archive_date;
   string subject;
   string matter;
}
#endif

/** 
 * This defines the index of the emote flag in the message array.
 */
#define CLUB_MESSAGE_EMOTE_INDEX 1
/**
 * This defines the index of the message itself in the message array.
 */
#define CLUB_MESSAGE_MESSAGE_INDEX 0

/**
 * This is the maximum length of a club name.
 */
#define CLUB_MAX_NAME_LEN 40
/**
 * The maximum length of a family name, with spaces.
 */
#define MAX_FAMILY_NAME_LEN 15

/**
 * This makes the club control room a club or family room.
 * @see /std/room/club_control.c
 */
#define CLUB_ROOM_CLUB_OR_FAMILY 0
/**
 * This makes the club control room a club only room, only club manipulations can
 * be done.
 * @see /std/room/club_control.c
 */
#define CLUB_ROOM_CLUB_ONLY   1
/**
 * This makes the club control room a family only room, only family manipulations can
 * be done.
 * @see /std/room/club_control.c
 */
#define CLUB_ROOM_FAMILY_ONLY 2

#ifndef __CLUBS_H_NO_CLASSES
/**
 * This class is for a discussion idea associated with a club.
 * @member id the unique id of the discusion idea
 * @member time_added the time the discussion item was added
 * @member discuss_type the type of the item up for discusion
 * @member added_by the name of the member who added the item
 * @member information entered by the person when they added the discussion
 * @member name the name of the person who added the item
 * @member choices the choices and votes for the discussion
 * @member voted who has voted for the item
 * @member optional_data the extra data associated with the idea
 */
class discussion_idea {
   int id;
   int time_added;
   int time_finish;
   int discuss_type;
   string added_by;
   string name;
   string information;
   mapping choices;
   string *voted;
   mixed optional_data;
}
#endif

/**
 * Special flag for the type giving the open or closed status of the
 * discussion idea.
 */
#define CLUB_DISCUSS_OPEN 0x800000
/**
 * Special flag for the type giving the quorum, or no quorum required
 * status of the discussion idea.
 */
#define CLUB_DISCUSS_NO_QUORUM 0x400000
/**
 * Mask to only get the real type of the discussion item.
 */
#define CLUB_DISCUSS_TYPE_MASK 0xff

/**
 * This type of discussion item is used when a position become vacant
 * before an full election is due.  It is a by-election.  The
 * name field contains the position being elected and the choices contains
 * the list of people to choose the election from.
 */
#define CLUB_DISCUSS_ELECTION      1
/**
 * This type is a discussion item to the change the clubs description.  The
 * information field will contain the new description and the choices field
 * should only contain 'yes' and 'no'.
 */
#define CLUB_DISCUSS_DESCRIPTION   2
/**
 * This type is a discussion item for a memo of some kind.  Means that it
 * is about whatever the players wish it to be about and results are mailed
 * to the people involed (or posted on their buliten board if they have one).
 */
#define CLUB_DISCUSS_MEMO          3
/**
 * This type is a no-confidence vote in the current committee, or in a
 * specific comittee member.  The name field contains the position the
 * no-confidence vote is in.
 */
#define CLUB_DISCUSS_NO_CONFIDENCE 4
/**
 * This type of item will be a discussion on adding in a new positon to
 * the committee.  The choices in this case should only contain 'yes' and
 * 'no' and the name field will be the name of the new position.
 */
#define CLUB_DISCUSS_NEW_POSITION 5
/**
 * This type of item will be for changing the name of a position in
 * the committee.  The choices will be yes, no, abstain.  The
 * optional_data field will contain the new name and the name field will contain
 * the old name.
 */
#define CLUB_DISCUSS_POSITION_NAME 6
/**
 * This type of item will be for discussing changing the club to a
 * secret type.
 */
#define CLUB_DISCUSS_SECRET_TYPE 7
/**
 * This type of item will be for discussing removing a member from the
 * club.  The name field contains the person being removed.
 */
#define CLUB_DISCUSS_MEMBER_REMOVE 8
/**
 * This type of item will allow a position to be removed from the club.
 * The name field will contain the position being removed.
 */
#define CLUB_DISCUSS_POSITION_REMOVE 9
/**
 * This type of item will allow someone to be nominated for a position.
 * The choices element will be used to keep track of who has nominated
 * who for what.
 */
#define CLUB_DISCUSS_NOMINATION 10
/**
 * This type of item will do calls onto a specified object to handle
 * all of the data and stuff.  The way this works is that the
 * entire discussion item will be passed onto the function, the function
 * is specified as a two element array in the name field of the discussion
 * item.
 */
#define CLUB_DISCUSS_FUNCTION 11
/**
 * This type of item will add a new account to the club.
 * The name field will contain the name of the new account.
 */
#define CLUB_DISCUSS_CREATE_ACCOUNT 12
/**
 * This type of item will add a new account to the club.
 * The name field will contain the name of the new account.
 */
#define CLUB_DISCUSS_REMOVE_ACCOUNT 13

/**
 * This is the choice which means do it!
 */
#define CLUB_DISCUSS_YES_CHOICE "yes"
/**
 * This is the choice which means no no no!
 */
#define CLUB_DISCUSS_NO_CHOICE "no"
/**
 * This is the choice to abstain from the vote.
 */
#define CLUB_DISCUSS_ABSTAIN_CHOICE "abstain"

/**
 * The message sent to the discussion item functions when the item
 * is initialy added.  If this returns a non-zero value then it is
 * properly verified and the item will be added.
 */
#define CLUB_DISCUSS_MESSAGE_VERIFY            1
/**
 * The message sent to the discussion item functions when the item
 * is completed.  This will send the mail to committee and all that
 * fun stuff.  In the case a CLUB_DISCUSS_FUNCTION if this returns
 * a string then the club_handler will deal with mailing the result
 * onto the committee and posting it and archiving it.
 */
#define CLUB_DISCUSS_MESSAGE_COMPLETE          2
/**
 * The message sent to the discussion item functions when a short
 * description is requested.  This should not have any new lines in
 * it and should be very short summary.
 */
#define CLUB_DISCUSS_MESSAGE_SHORT_DESCRIPTION 3
/**
 * The message sent to the discussion item functions when a long
 * description is requested.  This should be a detailed description
 * of the item, the choices are not neeeded to be included since they'
 * will be displayed automatically.
 */
#define CLUB_DISCUSS_MESSAGE_LONG_DESCRIPTION  4
/**
 * The message sent to the discussion item function when a nomination
 * request is done.  The first argument will contain the person
 * doing the nomination and the second will contain the person being
 * nominated.
 */
#define CLUB_DISCUSS_MESSAGE_NOMINATION        5
/**
 * This message is sent to determine the type of the discussion item.
 * Currently there are only two types, nomination and voting.  The
 * voting type means the 'vote' command is used for the discussion
 * item and the 'nomination' means the nominate type is used.
 * @see CLUB_DISCUSS_MESSAGE_TYPE_VOTE
 * @see CLUB_DISCUSS_MESSAGE_TYPE_NOMINATE
 */
#define CLUB_DISCUSS_MESSAGE_TYPE              6
/**
 * This message is sent when a member is removed from the club.
 * The first argument contrains the member being removed.
 */
#define CLUB_DISCUSS_MESSAGE_REMOVE_MEMBER     7
/**
 * This message is sent when a position in the club is changed name.
 * The first arguement is the position being changed and the
 * second arguement is the position it is changed to.
 */
#define CLUB_DISCUSS_MESSAGE_CHANGE_POSITION   8
/**
 * This message is sent to return the nomination mapping.  It must be
 * in the same format as descriped in /obj/handlers/inherit/club_discuss.c
 * @see /obj/handlers/inherit/club_discuss.c
 */
#define CLUB_DISCUSS_MESSAGE_NOMINATION_QUERY  9
/**
 * This message is sent when the position is removed from the club.
 * The first arguement contains the position being removed.
 */
#define CLUB_DISCUSS_MESSAGE_REMOVE_POSITION   10
/**
 * This message is sent when someone is withdrawing from a position in 
 * a nomination discussion item.
 */
#define CLUB_DISCUSS_MESSAGE_WITHDRAW          11

// Make the type default to votable.
/**
 * This is the return type to use to specify that the discusion item
 * is a voting type.
 */
#define CLUB_DISCUSS_MESSAGE_TYPE_VOTE         0
/**
 * This is the return type to use to specify that the discussion item
 * is a nomination type.
 */
#define CLUB_DISCUSS_MESSAGE_TYPE_NOMINATE     1

/**
 * This is the index of the object in the name field when doing a
 * function discussion type.
 */
#define CLUB_DISCUSS_FUNCTION_OBJECT     0
/**
 * This is the index of the function in the name field when doing a
 * function discussion type.
 */
#define CLUB_DISCUSS_FUNCTION_FUNCTION   1

/**
 * This is the maximum size that a position name can be.
 */
#define CLUB_MAX_POSITION_NAME 30

/**
 * The name given to members that have been remove from positions.
 */
#define CLUB_UNKNOWN_MEMBER "unknown"
/**
 * The name of the club controller, when used as a member.
 */
#define CLUB_CONTROLLER_MEMBER "Club Controller"

#endif
// --- END [/mnt/home2/grok/lib/include/clubs.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/user_parser.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/user_parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630048   Available: 13577402
Inodes: Total: 5242880    Free: 4960136
1198 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/user_parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630048   Available: 13577402
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS_PARSER_H
#define __SYS_PARSER_H

/* Position of things in the commands array */
#define PATTERN_WEIGHT 0
#define PATTERN_STRING 1
#define OLD_PATTERN_STRING 2
#define OBJS 3

/* Type... */
#define WORD_LIST 1
#define STRING 2
#define OPTIONAL 3
#define DIRECT_OBJECT 4
#define INDIRECT_OBJECT 5
#define NUMBER 6
#define LIVING 7
#define SINGLE_WORD 8
#define DISTANT_LIVING 9
#define ANY_LIVING 10
#define ANY_OBJECT 11
#define SHORT_STRING 12
#define FRACTION 13
#define WIZ_PRESENT_TARGET 14
#define WORD_LIST_SPACES 15
#define OPTIONAL_SPACES 16
#define TARGET_PLAYER 17
#define QUOTED_STRING 18

#define PATTERN ({ "","","<string> ","[","<direct> ","<indirect> ", \
                   "<number> ", "","<word> ","","","","<string:short> ", \
                   "<fraction> ", "", "", "[", "", "<string:quoted>" })

/* Defines used when searching the string. */
#define FIND_NONE 0
#define FIND_FIRST 1
#define FIND_LAST 2

/* Environments */
#define ENV_HERE       0
#define ENV_ME         1
#define ENV_HERE_ME    2
#define ENV_DIRECT_OBS 3
#define ENV_ME_HERE    4

#define MASTER "/secure/master"
#define PATTERN_OB "/obj/handlers/pattern_compiler"

#endif /* __SYS_PARSER_H */
// --- END [/mnt/home2/grok/lib/include/user_parser.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/nroff.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/nroff.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630047   Available: 13577401
Inodes: Total: 5242880    Free: 4960136
360 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/nroff.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630047   Available: 13577401
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__NROFF
#define __SYS__NROFF

#define V_CENTER 1
#define V_ALL 2
#define V_PARA 3
#define V_LEFT 4
#define V_TABLE 5
#define V_COLUMN 6
#define V_INDENT 7
#define V_HEADER 8

#define NROFF_HAND "/obj/handlers/nroff"

#define NROFF_DIR "/doc/helpnr/"
#define CNROFF_DIR "/doc/creatornr/"
#define MNROFF_DIR "/doc/mannr/"

#endif /* __SYS__NROFF */
// --- END [/mnt/home2/grok/lib/include/nroff.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/room.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630047   Available: 13577401
Inodes: Total: 5242880    Free: 4960136
2851 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/room.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630047   Available: 13577401
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is the main include file for rooms.  It contains all the defines
 * needed by vairous bits of rooms.
 * @author Pinkfish
 */
#ifndef __SYS__ROOM
/** @ignore yes */
#define __SYS__ROOM

/**
 * This is the room handler objects path.
 */
#define ROOM_HANDLER "/obj/handlers/room_handler"

#define ROOM_DEST       0
#define ROOM_EXIT       1
#define ROOM_OBV        2
#define ROOM_SIZE       3
#define ROOM_FUNC       4
#define ROOM_ENTER      5
#define ROOM_REL        6
#define ROOM_LOOK       7
#define ROOM_LOOK_FUNC  8
#define ROOM_GRADE      9
#define ROOM_MESS      10
#define ROOM_LINK_MESS 11
#define ROOM_NO_MAP    12
#define ROOM_DELTA     13
#define ROOM_NPC_STOP  14
/** This is used for extra messages on a move */
#define ROOM_EXTRA_MOVE_MESS 15

/**
 * This is the path used to the object used for doors.
 */
#define DOOR_OBJECT "/std/room/basic/door"
/**
 * This is the path used to the object used for items.
 */
#define ITEM_OBJECT "/std/room/basic/item"
/**
 * This is the path used to the object used to set up room chats.
 */
#define CHATTER_OBJECT "/std/room/basic/chatter"
/**
 * This is the path used to the object used to set up room situations.
 */
#define SITUATION_CHANGER_OBJECT  "/std/room/basic/situation_changer"
/**
 * This is the path used to the object used to link connected rooms
 * together.
 */
#define LINKER_OBJECT "/std/room/basic/linker"
/**
 * This is the path to the object used by the terain handler.
 */
#define TERRAIN_OBJECT "/std/room/basic/terrain"
/**
 * This is the path used to the object use for walls.
 */
#define WALL_OBJECT "/std/room/basic/wall"

/**
 * This is the path to the void.  Used as an error return in a few
 * function calls.
 */
#define ROOM_VOID "/room/void"

/**
 * This is the 'halflife' of magic in a room, it's used for calculating
 * the enchantment level
 */
#define ENCHANT_HALF 3600
/**
 * This is the property used for the keep room loaded attribute.
 * We use a property to reduce the memory usage.
 */
#define ROOM_KEEP_PROP "room keep"

/**
 * This is the property we use to keep to stop the room being replaced with
 * replace_program().
 */
#define ROOM_NOT_REPLACE_PROGRAM_PROP "replace program"

/**
 * This is used to control how long it must be since a player visited
 * this room in order for it to clean_up() and dest itself.
 */
#define ROOM_IDLE_TIMEOUT 900

/**
 * This is the directory to make all the help files relative to.
 */
#define ROOM_HELP_FILE_DIR "/doc/room/"
/**
 * This is the property used to keep track of the help file.
 */
#define ROOM_HELP_FILE_PROPERTY "help file name"

/**
 * This is index for day items/chats.
 */
#define ROOM_DAY_INDEX 1
/**
 * This is the index for night item/chats.
 */
#define ROOM_NIGHT_INDEX 0
/**
 * THis is the index for default item/chats.
 */
#define ROOM_DEFAULT_INDEX 2

#endif /* __SYS__ROOM */
// --- END [/mnt/home2/grok/lib/include/room.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/colour.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/colour.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630046   Available: 13577400
Inodes: Total: 5242880    Free: 4960136
1604 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/colour.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630046   Available: 13577400
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__COLOUR
#define __SYS__COLOUR

#define COL_RED 0
#define COL_PINK 1
#define COL_ORANGE 2
#define COL_YELLOW 3
#define COL_GREEN 4
#define COL_BLUE 5
#define COL_PURPLE 6
#define COL_WHITE 7
#define COL_GREY 8
#define COL_BROWN 9
#define COL_BLACK 10
#define COL_GOLD 11
#define COL_SILVER 12
#define COL_COPPER 13
#define COL_MULTI 14
#define COLOURS ({ "red", "pink", "orange", "yellow", "green", "blue", "purple", "white", "grey", "brown", "black", "gold", "silver", "copper", "multicoloured" })
#define ANSI_COLOURS ({ "%^RED%^", "%^MAGENTA%^", "%^ORANGE%^", "%^YELLOW%^", "%^GREEN%^", "%^BOLD%^%^BLUE%^", "%^MAGENTA%^", "%^BOLD%^%^WHITE%^", "%^CYAN%^", "%^ORANGE%^", "%^BOLD%^%^BLUE%^"  })

#define REDDISH 0
#define PINKISH 1
#define YELLOWISH 3
#define GREENISH 4
#define BLUISH 5
#define PURPLISH 6
#define PALE 7
#define GREYISH 8
#define BROWNISH 9
#define BLACKISH 10
#define OFF 11
#define MUDDY 12
#define WHITISH 13
#define GOLDEN 14
#define LIGHT 15
#define DARK 16
#define VARIEGATED 17
#define SILVERY 18
#define METALLIC 19
#define MODIFIERS ({ "reddish ", "pinkish ", "orange-", "yellowish ", "greenish ", "bluish ", "purplish ", "pale ", "greyish ", "brownish ", "blackish ", "off-", "muddy ", "whitish ", "golden ", "light ", "dark ", "variegated ", "silvery ", "metallic " })


#define USER_COLOUR_LIST ({"newbie", "shout", "tell", "say", "whisper", \
                            "soul", "emote", "remote", "exits", "inventory", \
                           "weather", "group", "shopchat", "emoteall", \
                           "combat"})
#endif /* __SYS__COLOUR */
// --- END [/mnt/home2/grok/lib/include/colour.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/combat.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/combat.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630045   Available: 13577399
Inodes: Total: 5242880    Free: 4960136
10511 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/combat.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630045   Available: 13577399
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS_COMBAT
#define __SYS_COMBAT

#include <player.h>

class surrender_information {
   object *refusers;
   object *to;
   object *from;
}

/**
 * This class stores all the info about a combat special.
 *
 * @param id A unique ID given to this special
 * @param type The type of special (offensive, defensive, continuous)
 * @param events The list of events this special wants to be notified for
 * @param callback The callback data.
 * @param data Any additional data the special registered.
 */
class combat_special {
  int id;
  int type;
  int events;
  mixed callback;
  mixed data; // this can be used to store anything the special wants to store.
}

/**
 * This holds the combat information for this player/npc.
 */
class combat_information {
  int hbc;
  int mbc;                      // Monitor count
  int in_combat;
  int special_id;
  object *protectors;
  object *defenders;
  mapping attacker_list;
  mapping hunting_list;
  object concentrating;
  object last_opponent;
  object last_weapon;
  string last_action;
  int last_result;
  int action_defecit;
  class combat_special *specials;
}

class tactics {
  string attitude;
  string response;
  string parry;
  string attack;
  int parry_unarmed;
  string mercy;
  string focus_zone;
  string ideal_distance;
}

/**
 * This class stores all the information about a given attack. One of these is
 * created for every attack. It contains attacker and defender information and
 * is passed in to and back from every special attack.
 *
 * @param attacker the attacking object
 * @param attacker_tactics a class for the attackers tactics
 * @param attacker_specials a list of specials registered for the attacker
 * @param attacker_concentrating who the atacker is concentrating on
 * @param attack_weapon the attacking weapon
 * @param attack_action the attackers action
 * @param attack_skill the skill being used for the attack
 * @param attack_data the attack data for the weapon
 * @param attacker_defecit how far into action defecit the attacker is
 * @param attack_cost the action cost for the attack
 * @param attack_modifier the difficulty modifier for the attack
 * @param attacker_last_opponent the last opponent the attacker fought
 * @param attacker_last_weapon the last weapon the attacker used
 * @param attacker_last_action the last combat action by the attacker
 * @param attacker_last_result the result of the last action
 *
 * @param opponent the opponent object (the person who was attacked and who
 *                                      will take any damage)
 * @param defender_specials a list of specials registered for the defender
 * @param defender The defending object (the person who will perform the
 *                                       defense against the attack)
 * @paran distance length units between attacker and the opponent
 * @param person_hit Someone who will jump in the way of the attack
 * @param defender_tactics a class for the defenders tactics
 * @param defender_concentrating who the defender is concentrating on
 * @param defense_weapon the defending weapon
 * @param defense_limb if parrying unarmed which limb are they using
 * @param defense_action the defenders action
 * @param defense_skill the skill being used for the defense
 * @param defender_defecit how far into action defecit the defender is
 * @param defense_cost the action cost for the defense
 * @param defense_modifier the difficulty modifier for the defense
 * @param defender_last_opponent the last person the defender fought
 * @param defender_last_weapon the last weapon the defender used
 * @param defender_last_action the last combat action by the defender
 * @param defender_last_result the result of the last action
 *
 * @param damage how much damage will be done
 * @param armour_stopped how much damage was stopped by armour
 * @param stopped_by which armour stopped the most damage
 * @param target_zone which part of the opponents body is being hit
 * @param result the outcome (OFFAWARD, OFFWIN, DEFAWARD, DEFWIN)
 * @param degree the degree of the outcome (TASKER_CRITICAL,
 *                                          TASKER_EXCEPTIONAL,
 *                                          TASKER_NORMAL,
 *                                          TASKER_MARGINAL)
 *
 * @param attack_messages messages to be shown about the attack
 * @param defense_messages messages to be shown about the defense
 * @param verbose should the messages be considered verbose (ie. only to be
 *        displayed to people with verbose combat turned on).
 * @param repeat should we go through the attack loop again?
 *
 */
class attack {
  object attacker;
  class tactics attacker_tactics;
  class combat_special *attacker_specials;
  object attacker_concentrating;
  object attack_weapon;
  string attack_action;
  string attack_skill;
  mixed *attack_data;
  int attacker_defecit;
  int attack_cost;
  int attack_modifier;
  object attacker_last_opponent;
  object attacker_last_weapon;
  string attacker_last_action;
  int attacker_last_result;

  object opponent;
  class combat_special *defender_specials;
  object person_hit;
  object defender;
  int distance;
  class tactics defender_tactics;
  object defender_concentrating;
  object defense_weapon;
  string defense_limb;
  string defense_action;
  string defense_skill;
  int defender_defecit;
  int defense_cost;
  int defender_cost;
  int protector_cost;
  int defense_modifier;
  object defender_last_opponent;
  object defender_last_weapon;
  string defender_last_action;
  int defender_last_result;

  int damage;
  int armour_stopped;
  mixed stopped_by;
  string target_zone;
  int result;
  int degree;
  object corpse;
  
  string *attack_messages;
  string *defense_messages;
  int verbose;

  int repeat_count;
  int repeat;
}

/**
 * Standard skills for attacks and defenses
 */
#define WEAPON_PARRY "fighting.combat.parry.melee"
#define UNARMED_PARRY "fighting.combat.parry.melee"
#define DODGE "fighting.combat.dodging.melee"
#define ATTACK_SKILL "fighting.combat.melee."
#define MOVE_SKILL "fighting.combat.special.tactics"
#define TACTICAL_SKILL "fighting.combat.special.tactics"
#define SPECIAL_WEAPON "fighting.combat.special.weapon"
#define SPECIAL_UNARMED "fighting.combat.special.unarmed"

/**
 * The speed combat runs at
 */
#undef COMBAT_SPEED
#define COMBAT_SPEED 1

/**
 * Number of actions per heartbeat, actions used for an attack or defense, and
 * number of player actions an action uses.
 */
#define COMBAT_ACTION_TIME (environment() ? environment()->attack_speed() : 15)
#define ACTIONS_PER_HB DEFAULT_TIME
#define ATTACK_COST (COMBAT_ACTION_TIME * 4) / 3
#define DEFENSE_COST (COMBAT_ACTION_TIME * 2) / 3
#define MOVE_COST (COMBAT_ACTION_TIME / 4)

/**
 * How many GPs an attack or defense costs.
 * This compliments the combat actions by gradually wearing down the
 * combatant.
 */
#define ATTACK_GP ([ "insane" : 1, \
                     "offensive" : 0, \
                     "neutral" : 0,\
                     "defensive" : 1, \
                     "wimp" : 2 ])

#define DEFENSE_GP ([ "insane" : 2, \
                     "offensive" : 1, \
                     "neutral" : 0,\
                     "defensive" : 0, \
                     "wimp" : 1 ])

#define DEFENDER_GP ([ "insane" : 4, \
                       "offensive" : 2, \
                       "neutral" : 1,\
                       "defensive" : 2, \
                       "wimp" : 3 ])

/**
 * A balance modifier which sways things towards the attacker or the
 * defender.
 *
 * Using a negative number makes combat a little less dangerous by tipping
 * the balance in favour of the defender, a positive number does the opposite.
 */
//#define BALANCE_MOD (random(random(100)) - 50)
#define BALANCE_MOD (random(random(75)) - 25)

/**
 * Time until we stop hunting someone.
 */
#define HUNTING_TIME 300

/**
 * The initial distance value (in size units)
 */
#define INITIAL_DISTANCE 45

/**
 * The size of a distance "step" (in size units)
 */
#define DISTANCE_STEP 9

/**
 * This is the reach of an object, should be more dynamic than this
 */
#define REACH 18

/**
 * Map size units to distance strings.
 */
#define DISTANCES ([ "ranged" : 45, "long" : 36, "medium" : 27, "close" : 18,\
                     "hand-to-hand" : 9 ])

/**
 * Types of special
 */
#define T_OFFENSIVE 1
#define T_DEFENSIVE 2
#define T_CONTINUOUS 4

/**
 * Events specials can register for
 */
#define E_OPPONENT_SELECTION 1
#define E_DEFENDER_SELECTION 2
#define E_ATTACK_SELECTION 4
#define E_DEFENSE_SELECTION 8
#define E_ATTACK_MODIFIER 16
#define E_DEFENSE_MODIFIER 32
#define E_DAMAGE_CALCULATION 64
#define E_ARMOUR_CALCULATION 128
#define E_WEAPON_DAMAGE 256
#define E_WRITE_MESSAGES 512
#define E_AFTER_ATTACK 1024

/**
 * Return fields for a special
 */
#define R_PASSTHRU 1
#define R_CONTINUE 2
#define R_DONE 4
#define R_ABORT 8
#define R_REMOVE_ME 16

/**
 * Min & Max combat action defecits.
 */
#define MAX_ACTION_DEFECIT 100
#define MIN_ACTION_DEFECIT 0

/**
 * Indices of the attack_messages and defense_messages arrays.
 */
#define M_ATTACKER 0
#define M_OPPONENT 1
#define M_SPECTATORS 2
#define M_DEFENDER 3
#define M_PERSON_HIT 4

/**
 * How far into action defecit someone will go and still try to attack
 */
#define OFFENSIVE_DEFECITS ([ "insane" : (COMBAT_ACTION_TIME * 2), \
                              "offensive" : (COMBAT_ACTION_TIME), \
                              "neutral" : (COMBAT_ACTION_TIME * 2 / 3),\
                              "defensive" : (COMBAT_ACTION_TIME / 2), \
                              "wimp" : (COMBAT_ACTION_TIME / 4) ])

/**
 * How far into action defecit someone will go and still try to defend.
 * Generally speaking people will go farther into defecit in order to
 * defend themselves than they will to attack.
 *
 * The defensive numbers are higher than the offensive ones because
 * people are prone to avoiding pain.
 */
#define DEFENSIVE_DEFECITS (["insane" : (COMBAT_ACTION_TIME / 2), \
                             "offensive" : (COMBAT_ACTION_TIME), \
                             "neutral" : (COMBAT_ACTION_TIME * 3 / 2), \
                             "defensive" : (COMBAT_ACTION_TIME * 2), \
                             "wimp" : (COMBAT_ACTION_TIME * 3) ])

/**
 * How far from ideal distance someone can be before they attempt to
 * change their combat distance.
 */
#define MOVE_DISTANCE ([ "insane" : 36, "offensive" : 27, "neutral" : 9,\
                         "defensive" : 0, "wimp" : 0 ])
#endif
// --- END [/mnt/home2/grok/lib/include/combat.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/guilds.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/guilds.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630043   Available: 13577397
Inodes: Total: 5242880    Free: 4960136
326 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/guilds.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630043   Available: 13577397
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef INCLUDE_GUILDS
#define INCLUDE_GUILDS

#define GUILDS "/d/guilds/"
#define GUILDSAVE "/save/guilds/"

#define PLAYER_GUILDS ({ "assassins", "priests", "thieves", "warriors", "witches", "wizards" })

#define POSITION_OK 0
#define POSITION_FAIL 1
#define POSITION_TOO_MANY 2
#define POSITION_ALREADY_APPOINTED 3

#endif
// --- END [/mnt/home2/grok/lib/include/guilds.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/runtime_config.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/runtime_config.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630042   Available: 13577396
Inodes: Total: 5242880    Free: 4960136
2831 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/runtime_config.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630042   Available: 13577396
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * runtime_config.h
 *
 * Copy this file to your mudlib include dir for use with the
 * get_config() efun.
 *
 * See Config.Example describing most of these settings.  Some are actually
 * in options.h, but the mudlib doesn't have to know...
 *
 * Note for backwards compatibility:
 *
 *    get_config(__MUD_NAME__) == MUD_NAME
 *    get_config(__MUD_PORT__) == __PORT__
 */

#ifndef RUNTIME_CONFIG_H
#define RUNTIME_CONFIG_H

#define BASE_CONFIG_STR        0
#define CFG_STR(x) ((x) + BASE_CONFIG_STR)
/*
 * These config settings return a string
 */

#define __MUD_NAME__                CFG_STR(0)

#define __ADDR_SERVER_IP__          CFG_STR(1)

#define __MUD_LIB_DIR__             CFG_STR(2)
#define __BIN_DIR__                 CFG_STR(3)

#define __LOG_DIR__                 CFG_STR(4)
#define __INCLUDE_DIRS__            CFG_STR(5)
#define __SAVE_BINARIES_DIR__       CFG_STR(6)

#define __MASTER_FILE__             CFG_STR(7)
#define __SIMUL_EFUN_FILE__         CFG_STR(8)
#define __SWAP_FILE__               CFG_STR(9)
#define __DEBUG_LOG_FILE__          CFG_STR(10)

#define __DEFAULT_ERROR_MESSAGE__   CFG_STR(11)
#define __DEFAULT_FAIL_MESSAGE__    CFG_STR(12)
#define __GLOBAL_INCLUDE_FILE__     CFG_STR(13)

#define __MUD_IP__                  CFG_STR(14)

/*
 * These config settings return an int (ie number)
 */

#define BASE_CONFIG_INT (BASE_CONFIG_STR + 15)
#define CFG_INT(x)  ((x) + BASE_CONFIG_INT)

#define __MUD_PORT__                CFG_INT(0)
#define __ADDR_SERVER_PORT__        CFG_INT(1)

#define __TIME_TO_CLEAN_UP__        CFG_INT(2)
#define __TIME_TO_RESET__           CFG_INT(3)
#define __TIME_TO_SWAP__            CFG_INT(4)

#define __COMPILER_STACK_SIZE__     CFG_INT(5)
#define __EVALUATOR_STACK_SIZE__    CFG_INT(6)
#define __INHERIT_CHAIN_SIZE__      CFG_INT(7)
#define __MAX_EVAL_COST__           CFG_INT(8)
#define __MAX_LOCAL_VARIABLES__     CFG_INT(9)
#define __MAX_CALL_DEPTH__          CFG_INT(10)
#define __MAX_ARRAY_SIZE__          CFG_INT(11)
#define __MAX_BUFFER_SIZE__         CFG_INT(12)
#define __MAX_MAPPING_SIZE__        CFG_INT(13)
#define __MAX_STRING_LENGTH__       CFG_INT(14)
#define __MAX_BITFIELD_BITS__       CFG_INT(15)

#define __MAX_BYTE_TRANSFER__       CFG_INT(16)
#define __MAX_READ_FILE_SIZE__      CFG_INT(17)

#define __RESERVED_MEM_SIZE__       CFG_INT(18)

#define __SHARED_STRING_HASH_TABLE_SIZE__ CFG_INT(19)
#define __OBJECT_HASH_TABLE_SIZE__        CFG_INT(20)
#define __LIVING_HASH_TABLE_SIZE__        CFG_INT(21)

#define __FD6_PORT__		    CFG_INT(22)
#define __FD6_KIND__		    CFG_INT(23)

#define RUNTIME_CONFIG_NEXT CFG_INT(24)

/*
 * The following is for internal use (ie driver) only
 */

#define NUM_CONFIG_STRS (BASE_CONFIG_INT - BASE_CONFIG_STR)
#define NUM_CONFIG_INTS (RUNTIME_CONFIG_NEXT - BASE_CONFIG_INT)

#endif				/* RUNTIME_CONFIG_H */
// --- END [/mnt/home2/grok/lib/include/runtime_config.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/race.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/race.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630042   Available: 13577396
Inodes: Total: 5242880    Free: 4960136
124 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/race.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630042   Available: 13577396
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__RACE
#define __SYS__RACE

#define R_OBJECT 0
#define STD_RACE "/std/race/standard"

#endif /* __SYS__RACE */
// --- END [/mnt/home2/grok/lib/include/race.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/server.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/server.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
926 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/server.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SERVER_H__
#define __SERVER_H__

#define STRING 0
#define FILE 1

#define BLOCK_SIZE 65536

class buff {
    int Type;
    int Size;
    int Pos;
    string Filename;
    mixed Value;
}

class server {
    int Descriptor;
    int Blocking;
    int Closing;
    class buff *Buffer;
}

int eventCreateSocket(int port);
protected void eventServerListenCallback(int fd);
protected void eventServerAbortCallback(int fd);
protected void eventServerReadCallback(int fd, mixed val);
protected void eventRead(int fd, mixed val);
protected void eventServerWriteCallback(int fd);
varargs void eventWrite(int fd, mixed val, int close);
protected void eventClose(class server sock);
protected void eventSocketClosed(int fd);
int eventDestruct();
protected void eventNewConnection(int fd);
protected void eventSocketError(string str, int x);
function SetRead(function f);
int SetDestructOnClose(int x);

#endif /* __SERVER_H__ */
// --- END [/mnt/home2/grok/lib/include/server.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/climate.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/climate.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
314 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/climate.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__CLIMATE
#define __SYS__CLIMATE

#define TEMP 0
#define CLOUD 1
#define WINDSP 2
#define RAIN 3

// These values are ORed together for room notifications.
#define NOTIFY_TEMPERATURE 1
#define NOTIFY_CLOUD       2
#define NOTIFY_RAIN        4
#define NOTIFY_DAY         8

#endif /* __SYS__CLIMATE */
// --- END [/mnt/home2/grok/lib/include/climate.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/position.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/position.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
1937 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/position.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630041   Available: 13577395
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __POSITION_H
#define __POSITION_H

/**
 * the swimming position, used in the underwater room.
 * @see /std/uwater.c
 */
#define SWIMMING "swimming"
#define STANDING "standing"
#define SITTING "sitting"
#define KNEELING "kneeling"
#define LYING "lying"
#define MEDITATING "meditating"
#define CROUCHING "crouching"

/**
 * The property which should be set on objects to allow them to
 * be used for positions.
 */
#define CAN_POSITION_PROPERTY "position on"
/**
 * The property to be set on objhects which tells them to work as
 * multiple objects.
 */
#define MULTIPLE_POSITION_PROPERTY "position multiple"
/**
 * The property to be set on rooms to store the default position in.
 */
#define DEFAULT_POSITION_PROPERTY "default position"

#define POSITION_DEFAULT STANDING

/**
 * The path to the object to use when trying to make someone stand up.
 */
#define STANDING_CMD "/cmds/living/stand"

/**
 * The path to the object to use when trying to make someone stand up.
 */
#define LYING_CMD "/cmds/living/lie"

/**
 * The path to the object to use when trying to make someone stand up.
 */
#define SITTING_CMD "/cmds/living/sit"

/* The position array stuff on the player object */
#define POS_ON_OBJECT 0
#define POS_TYPE      1
#define POS_MULTIPLE  2
#define POSITION_ARRAY_SIZE 3

/* Ok, the type thingies, on, at etc... */
#define ON_TYPE "on"
#define AT_TYPE "at"
#define BESIDE_TYPE "beside"

/* This is te stuff for the default position array. */
/**
 * The size of the array if there is only a type.
 */
#define POSITION_ONLY_TYPE_SIZE 1
/**
 * The size of the array with all the stuff in i it.
 */
#define POSITION_MESS_SIZE 3
/**
 * The posiition in the array fopr the position type.
 */
#define POSITION_TYPE_INDEX 0
/**
 * The index fort the position message to tell others.
 */
#define POSITION_ME_MESS_INDEX 1
/**
 * The index whith referese to the message to tell others.
 */
#define POSITION_REST_MESS 2
#endif
// --- END [/mnt/home2/grok/lib/include/position.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ritual_system.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ritual_system.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630040   Available: 13577394
Inodes: Total: 5242880    Free: 4960136
4835 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ritual_system.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630040   Available: 13577394
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Rituals.h
 * A header file for rituals.
 * @author Terano.
 */
#define EFFECTS "/std/effects/faith/"
#define ITEMS "/d/guilds/priests/items/"
#define RITUALS "/obj/rituals"
#define ROOMS "/d/guilds/priests/rooms"
#define INHERITS RITUALS "/inherits"

#define SHADOWS "/std/shadows/faith/"
//Target types!
#define RITUAL_DIRECT_NONE       0
#define RITUAL_DIRECT_ROOM       1 
#define RITUAL_DIRECT_NON_LIVING 2
#define RITUAL_DIRECT_LIVING     4
#define RITUAL_DIRECT_SELF       8
#define RITUAL_DIRECT_MULTIPLE   16
#define RITUAL_DIRECT_EXTERN     32

//Something to show something!
#define RITUAL_CALCULATE_DYNAMIC  0

//Some imbue stuff
#define IMBUE_PERFORMER -1
#define IMBUE_PRIEST     1

//Special Stages
#define SUCCESS -1
#define FAILURE -2
#define STOPPED -3

//Some files!
#define RITUAL EFFECTS"/basic_ritual"
#define SHADOW SHADOWS"/basic_ritual"

//Impediments and benefits
#define RELIGIOUS   "religious"
#define MENTAL      "mental"
#define SPEECH      "speech"
#define VISION      "vision"
#define MOVEMENT    "movement"
#define ENVIRONMENT "environment"
#define MISC        "misc"

//A skill define
#define FAMILY "faith.rituals" + info->family

//Some defines to make filing a breeze!
#define CURING_INHERIT INHERITS "/basic_healing"
#define SHIELD_INHERIT INHERITS "/basic_shield"
#define PASSAGE_INHERIT INHERITS "/basic_passage"
#define ALCOHOL_INHERIT INHERITS "/basic_alcohol"
#define WARD_BASE SHADOWS +"/base_ward"

//Some common data structures.
/**
 * Each ritual has one or more stages.
 * Each stage must have messages for both the player and external parties.
 * Each stage can optionally have a skill check.
 * Each stage can optionally have items which can be consumed.
 * Each stage can be optionally lengthened, this will then be modified by 
 * other factors. [alignment and skill]. This defaults to 1 if not entered.
 */

class stage {
  int key;               //The identifier for this stage. 
  string *messages;      //Messages [internal and external]
  string skill;          //Skill required for this stage. [Optional]
  int level;             //Power level for this stage.
  string *materials;     //Materials required for this stage. [Optional]
  string *consumables;   //Materials consumed for this stage. [Optional]
  int pause;             //Mandatory Pause - Required for complex rituals. [Opt]
  int time_modifier;     //A base modifier used to determine stage length. 
  function success_func; //A function that will be evaluated if successful.
  string prayer;         //The name of a prayer required for this stage.
  int imbue_source;       //The stage is either set on imbuing or set on casting.
                         //Options are IMBUE_PERFORMER or IMBUE_PRIEST
}

/**
 * Data Storage for Rituals
 */
class ritual {
   //Standard variables: Will be the same for every casting.
   string name;                     //Name of the ritual.
   string family;                   //Type of ritual [Defensive, Curing, etc].
   int base_gp_cost;                //Base cost to cast ritual
   int *align;                      //Alignment restriction
   int targets;                     //An int for the purposes of targeting!
   class stage *stages;             //See info on stages below.
   int pk_check;                    //Is this ritual PK checked?
   int teach_base;                  //Base level for teaching
   int learn_base;                  //Base level for learning
   string training_skill;           //Skill used for teaching
   int movement;                    //Is movement required to cast this ritual.
   int speech;                      //Is speech required to cast this ritual.
   int vision;                      //Is vision required to cast this ritual.
   string *materials, *consumables; //Same as for each stage.
   function target_check;           //Can be set, returns 1 if can be targetted
   string resist_skill;             //Skill that resists the effects.
   string help;                     //Path of the help file.
   int offensive;                   //Is this a ritual that initialises combat

   //Dynamic variables: Change for each instance of the ritual.
   object caster;        //The caster
   object imbue;         //The imbue being performed from [optional]
   object *rit_targets;  //Targets of our ritual
   object *resistors;    //Those who successfully made a resist check.
   int current_stage;    //Stage the ritual is currently at.
   int start_time;       //Time ritual commenced.
   int target_count;     //The count of number of targets!
   function valid;       //Function used to validate casting. 
   int degree;           //The degree of success.
   string deity;         //Deity of the caster.
   mapping difficulties; //Things that make the ritual harder. 
   mapping benefits;     //Things that make the ritual easier.
}
// --- END [/mnt/home2/grok/lib/include/ritual_system.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/complaints_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/complaints_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630039   Available: 13577393
Inodes: Total: 5242880    Free: 4960136
432 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/complaints_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630039   Available: 13577393
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming

/**
 * The include file for the complaints handler.  Specifies the location of
 * the complaints handler.
 *
 * @see /obj/handlers/complaints_handler.c
 * @see /std/room/inherit/complaints_room.c
 * @see /std/room/complaints_room.c
 * @author Arienne
 * @started Wed Apr  4 14:11:50 BST 2001
**/

#ifndef __COMPLAINTS_HANDLER_H
#define __COMPLAINTS_HANDLER_H

#define COMPLAINTS_HANDLER "/obj/handlers/complaints_handler"

#endif

// --- END [/mnt/home2/grok/lib/include/complaints_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/tasks.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/tasks.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630038   Available: 13577392
Inodes: Total: 5242880    Free: 4960136
2662 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/tasks.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630038   Available: 13577392
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __TASKS_H
#define __TASKS_H

#define TASKER "/obj/handlers/taskmaster"

// Perform_task result codes
#define BARF      -1
#define FAIL      0
#define SUCCEED   1
#define AWARD     2

// compare_skills result codes
#define OFFAWARD  -2
#define OFFWIN    -1
#define DRAW      0
#define DEFWIN    1
#define DEFAWARD  2

// Perform_task result codes with better names.
#define TASKER_BARF      -1
#define TASKER_FAIL      0
#define TASKER_SUCCEED   1
#define TASKER_AWARD     2

// compare_skills result codes with better names.
#define TASKER_OFFAWARD  -2
#define TASKER_OFFWIN    -1
#define TASKER_DRAW      0
#define TASKER_DEFWIN    1
#define TASKER_DEFAWARD  2

// Degree-of-success values
#define TASKER_MARGINAL     1
#define TASKER_NORMAL       2
#define TASKER_EXCEPTIONAL  3
#define TASKER_CRITICAL     4

// Upper bounds of the d-o-s ranges.
// These are only really used internally...
#define TASKER_MARGINAL_UPPER        10
#define TASKER_NORMAL_UPPER          80
#define TASKER_EXCEPTIONAL_UPPER     95

// How likely you are to get a critical result if you're within
// the critical range.  Also only really used internally.
#define TASKER_CRITICAL_PERCENTAGE   5

// these are used in tweaking the TM rate for different levels of skill
#define BASE 100.0
#define DECAY 300.0
#define MODIFIER 10
#define E_MODIFIER 5

/*
 * these are temporary defines till the new TM stuff is working.
 */
#define COVERT_TM 100, ({0, 5})
#define CONTINUOUS_COVERT_TM 100, ({0, 3})
#define PERCEPTION_TM 50

#define FAITH_TM 75
#define FAITH_TM_HALF 30

#define MAGIC_TM 75
#define MAGIC_TM_HALF 30

#define OTHER_TM 100

// New definitions for different task types
#define TM_FIXED 1      // A fixed skill test
#define TM_FREE 2       // A free skill test in a room or somesuch
#define TM_CONTINUOUS 3 // continuous task
#define TM_COMMAND 4    // a command
#define TM_RITUAL 5     // a ritual
#define TM_SPELL 6      // a spell
#define TM_NONE 7       // just a test, no chance of an increase

/**
 * This is the class you get when using the degree of success code for the
 * taskmaster.
 * @member result This is the same as the return value would normally be
 *   when using the binary version. (SUCCEED/FAIL/AWARD/etc.)
 * @member degree This is the degree of success, based on how well
 *   you succeeded or how badly you failed.
 * @member raw This is included to enable you to tweak damage/duration/
 *   strength/etc transparently and smoothly.  Never use this to determine
 *   degree of success; use the 'degree' member for that.
 */
class tasker_result {
   int result;
   int degree;
   int raw;
} /* class tasker_result */

#endif   // __TASKS_H
// --- END [/mnt/home2/grok/lib/include/tasks.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/socket_err.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/socket_err.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
2070 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/socket_err.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * socket_errors.h -- definitions for efun socket error return codes.
 *    5-92 : Dwayne Fontenot (Jacques@TMI) : original coding.
 *   10-92 : Dave Richards (Cynosure) : less original coding.
 */

#ifndef _SOCKET_ERRORS_H_
#define _SOCKET_ERRORS_H_

#define EESUCCESS	  1	/* Call was successful */
#define EESOCKET	 -1	/* Problem creating socket */
#define EESETSOCKOPT	 -2	/* Problem with setsockopt */
#define	EENONBLOCK	 -3	/* Problem setting non-blocking mode */
#define EENOSOCKS	 -4	/* UNUSED */
#define EEFDRANGE	 -5	/* Descriptor out of range */
#define EEBADF		 -6	/* Descriptor is invalid */
#define EESECURITY	 -7	/* Security violation attempted */
#define	EEISBOUND	 -8	/* Socket is already bound */
#define EEADDRINUSE	 -9	/* Address already in use */
#define EEBIND		-10	/* Problem with bind */
#define EEGETSOCKNAME	-11	/* Problem with getsockname */
#define EEMODENOTSUPP	-12	/* Socket mode not supported */
#define EENOADDR	-13	/* Socket not bound to an address */
#define EEISCONN	-14	/* Socket is already connected */
#define EELISTEN	-15	/* Problem with listen */
#define EENOTLISTN	-16	/* Socket not listening */
#define EEWOULDBLOCK	-17	/* Operation would block */
#define EEINTR		-18	/* Interrupted system call */
#define EEACCEPT	-19	/* Problem with accept */
#define	EEISLISTEN	-20	/* Socket is listening */
#define EEBADADDR	-21	/* Problem with address format */
#define EEALREADY	-22	/* Operation already in progress */
#define EECONNREFUSED	-23	/* Connection refused */
#define EECONNECT	-24	/* Problem with connect */
#define EENOTCONN	-25	/* Socket not connected */
#define EETYPENOTSUPP	-26	/* Object type not supported */
#define	EESENDTO	-27	/* Problem with sendto */
#define	EESEND		-28	/* Problem with send */
#define	EECALLBACK	-29	/* Wait for callback */
#define EESOCKRLSD	-30	/* Socket already released */
#define EESOCKNOTRLSD   -31	/* Socket not released */
#define EEBADDATA       -32	/* sending data with too many nested levels */

#define	ERROR_STRINGS	 33	/* sizeof (error_strings) */

#endif				/* _SOCKET_ERRORS_H_ */
// --- END [/mnt/home2/grok/lib/include/socket_err.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/gag.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/gag.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
26 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/gag.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/obj/misc/"
// --- END [/mnt/home2/grok/lib/include/gag.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/book_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/book_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
2321 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/book_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630037   Available: 13577391
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file defines all the constants needed for the book handler and the
 * printing shop.
 * @author David Bennett
 * @started Sun Feb 22 22:02:08 CST 1998
 * @see /obj/handlers/book_handler.c
 * @see /std/print_shop.c
 */

#ifndef __BOOK_HANDLER_H
/** @ignore yes */
#define __BOOK_HANDLER_H

/**
 * This is the property to set to a non-zero value to make pages in books
 * be counted as ignored.  This should be done for things like fly leafs in
 * printed books and stuff like that.
 * @see /obj/handlers/book_handler.c
 * @see /std/print_shop.c
 */
#define BH_IGNORE_PAGE "generated page"
/**
 * This is the path to the book handler object.
 * @see /obj/handlers/book_handler.c
 */
#define BOOK_HANDLER "/obj/handlers/book_handler"
 

/*
 *
 * ---=== The defines after this point are used by the printing press. ===---
 *
 */

/**
 * This is the property used to set the copyright status of the book.  The
 * value of the property should be the copyright holder of the book.
 * If you wish to setup a book which no one can copy then set this
 * variable to the name of the creator, or a random banished name.
 * @example
 * book->add_property("copyright", "pinkfish");
 * @see /obj/handlers/book_handler.c
 * @see /std/print_shop.c
 */
#define BH_COPYRIGHT "copyright"

/**
 * This is the index into the collection array for the time at which it
 * ready to be picked up.
 * @see /std/print_shop.c
 */
#define COLLECT_TIME 0
/**
 * This is the index into the collection array for the number of copies
 * to print.
 * @see /std/print_shop.c
 */
#define COLLECT_NUM  1
/**
 * This is the index of the string name of the object which was asked to
 * be printed.
 * @see /std/print_shop.c
 */
#define COLLECT_OB_NAME 2
/**
 * This is the index of the language which will be used in the printing of the
 * the book.
 * @see /std/print_shop.c
 */
#define COLLECT_LANGUAGE 3
/**
 * This is the index into the collection array for the number associated with
 * the book.  This the save file number, the data for the book is stored
 * in a different location to the book handler stuff itself to save
 * memory.
 * @see /std/print_shop.c
 */
#define COLLECT_AUTO_LOAD_NUM 4
/**
 * This is the size of the array to allocate for the print shop information.
 * @see /std/print_shop.c
 */
#define COLLECT_ARR_SIZE 5

#endif
// --- END [/mnt/home2/grok/lib/include/book_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/reversi.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/reversi.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630036   Available: 13577390
Inodes: Total: 5242880    Free: 4960136
897 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/reversi.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630036   Available: 13577390
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define MAX_PAGE ((int)this_player()->query_rows()-3)
#define TP_NAME this_player()->query_name()
/* this will be a handler object... */
#define SAVE_FILE "/w/pinkfish/save/reversi"
#define BOARD_THING "/w/pinkfish/board_getter"

/* used by the board getter */
#define REVERSI_OB "/w/pinkfish/reversi_board"
#define BOARD_PATH "/w/pinkfish/save/reversi/"

/* should be two weeks */
#define MIN_TIME (60*60*24*14)

#undef DEBUG
#undef DEBUG2

#define MAX_GAMES 10

#define R_PLAYER1 0
#define R_PLAYER2 1
/* This is a board number.  A offset to the board save file.
 */
#define R_BOARD 2
#define R_MOVE_NO 3
/* last move.  Saved for timeouts. */
#define R_LAST 4
#define R_LASTX 5
#define R_LASTY 6

#define BOARD_COL "%^B_GREEN%^%^WHITE%^"
#define BLACK_COL "%^B_BLACK%^"
#define WHITE_COL "%^B_WHITE%^"
#define END_TILE  "%^B_GREEN%^"
#define RESET     "%^RESET%^"
#define SETUP_COL "%^B_CYAN%^"
// --- END [/mnt/home2/grok/lib/include/reversi.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/db.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/db.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
691 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/db.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* $Id: db.h,v 1.2 2003/02/11 20:10:15 pinkfish Exp $ */

/**
 * The header file for the database package.  Include this if your
 * object is going to make SQL queries to the database.
 */
#ifndef DB_H
#define DB_H

/**
 * Use this macro to properly escape text that you wish to use in an
 * SQL query.
 */
#define db_escape(query) replace_string((query), "'", "''")

/**
 * This is the handler to the database object.
 */
#define DB_HANDLER "/net/daemon/mysql"

/**
 * This should be the value returned if we have success.
 */
#define DB_SUCCESS 0

/**
 * THis is the error value if a socket was unable to be opened for
 * some reason.
 */
#define DB_ERROR_BAD_SOCKET -1

#endif /* DB_H */
// --- END [/mnt/home2/grok/lib/include/db.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/ranged_response.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/ranged_response.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
46 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/ranged_response.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define RUN 1
#define FIGHT 2
#define STAND 3
// --- END [/mnt/home2/grok/lib/include/ranged_response.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/random_names.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/random_names.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
239 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/random_names.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __RANDOM_NAMES_H
#define __RANDOM_NAMES_H

#define RANDOM_NAME_GENERATOR "/obj/handlers/random_names"
#define RANDOM_NAME_SAVE_FILE "/save/random_names/random_names"
#define RANDOM_NAME_DATA_DIR  "/save/random_names/data/"

#endif
// --- END [/mnt/home2/grok/lib/include/random_names.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/all_inc.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/all_inc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
522 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/all_inc.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630035   Available: 13577389
Inodes: Total: 5242880    Free: 4960136
2009-02-17 16:35:25.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __ALL_INC_H
#define __ALL_INC_H

#define NEW_DRIVER

#define DISTRIBUTION_LIB

//optimize and save_types are off because they can crash us

#pragma strict_types
#pragma warnings
#pragma no_save_types
#pragma no_optimize
#pragma show_error_context

#define slice_array(a,b,c) (a[b..c])
#define m_indices(map) (keys(map))
#define m_sizeof(map) (sizeof(map))
#define m_values(map) (values(map))
//#define mapp(x) (mapp(x))

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#endif

#endif
// --- END [/mnt/home2/grok/lib/include/all_inc.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/type.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/type.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630034   Available: 13577388
Inodes: Total: 5242880    Free: 4960136
336 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/type.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630034   Available: 13577388
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* /include/type.h */

#ifndef _TYPE_H
#define _TYPE_H

#define INT             "int"
#define STRING  	"string"
#define ARRAY   	"array"
#define OBJECT  	"object"
#define MAPPING         "mapping"
#define FUNCTION        "function"
#define FLOAT           "float"
#define BUFFER          "buffer"
#define CLASS           "class"
#endif
// --- END [/mnt/home2/grok/lib/include/type.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/login_handler.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/login_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630034   Available: 13577388
Inodes: Total: 5242880    Free: 4960136
1569 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/login_handler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630034   Available: 13577388
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The include file for the login handler.
 * @author Pinkfish
 */
#ifndef __SYS__LOGIN_HANDLER
/** @ignore yes */
#define __SYS__LOGIN_HANDLER

#include <player_handler.h>

/**
 * The path to the login handler.
 */
#define LOGIN_HANDLER "/obj/handlers/login_handler"

/** The name of the login event.  Used in the static/dynamic login calls. */
#define LOGIN "login"
/** The name of the logout event.  Used in the static/dynamic login calls. */
#define LOGOUT "logout"
/** The name of the netdeath event.  Used in the static/dynamic login calls. */
#define NETDEATH "netdeath"
/** The name of the reconnect event.  Used in the static/dynamic login calls. */
#define RECONNECT "reconnect"

/** The maximum number of compressed stream players. */
#define MAX_COMPRESSED_PLAYERS 200
/** The maximum number of uncompressed stream players.  */ 
#define MAX_UNCOMPRESSED_PLAYERS 100
/** The maximum number of players online at Discworld at once. */
#define MAX_PLAYERS (MAX_COMPRESSED_PLAYERS + MAX_UNCOMPRESSED_PLAYERS)

/** Flag to the is_discworld_full method. */
#define WITHOUT_LOGINS_NOT_IN_QUEUE 3
/** Flag to the is_discworld_full method. */
#define WITHOUT_ANY_LOGINS 2
/** Flag to the is_discworld_full method. */
#define WITHOUT_LOGIN_QUEUE 1
/** Flag to the is_discworld_full method. */
#define WITH_LOGIN_QUEUE    0

/** Returned from is_discworld_full if Discworld is full. */ 
#define DISCWORLD_IS_EMPTY 0 
#define COMPRESSED_FULL 1
#define UNCOMPRESSED_FULL 2 
#define DISCWORLD_IS_FULL (COMPRESSED_FULL | TELNET_FULL)

#endif /* __SYS__LOGIN_HANDLER */
// --- END [/mnt/home2/grok/lib/include/login_handler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/term.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/term.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
109 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/term.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__TERM
#define __SYS__TERM

#define TERM_HANDLER "/obj/handlers/term"

#endif /* __SYS__TERM */
// --- END [/mnt/home2/grok/lib/include/term.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/alias.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/alias.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
843 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/alias.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * The defines for all the aliases.
 * @author Pinkfish
 */
#ifndef __SYS__ALIAS
/** @ignore yes */
#define __SYS__ALIAS

/**
 * The mask for the type.
 */
#define ALIAS_MASK 255
/**
 * A new line in the alias stream.
 */
#define NEW_LINE 256
/**
 * This means include all the arguments.
 */
#define ALL_ARGS 512
#define ALL_ARG 1024
#define ARG_THING 2048
#define IFARG_THING 4096
#define ALL_IFARG 8192
#define ONE_ARG 16384
#define TO_ARG 32768
#define FROM_ARG 65536
#define ELSE_THING 131072
#define CURR_LOC (ELSE_THING+256)
#define END_IF (ELSE_THING+512)

/**
 * The alias command object.
 */
#define ALIAS_CMD "/cmds/player/al_ias"
/**
 * The edit alias command object.
 */
#define EDIT_ALIAS_CMD "/cmds/player/ea_lias"
/**
 * The unalias command object.
 */
#define UNALIAS_CMD "/cmds/player/un_alias"

#endif /* __SYS__ALIAS */
// --- END [/mnt/home2/grok/lib/include/alias.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/refresh.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/refresh.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
679 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/refresh.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630033   Available: 13577387
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Definition so we can reach the refresh handler, and some
 * other definitions for the arguments passed to the callback
 * function.
 * @author Ceres
 */
#ifndef __REFRESH_H
/** @ignore yes */
#define __REFRESH_H

/**
 * The path to the refresh handler itself.
 */
#define REFRESH_HANDLER "/obj/handlers/refresh"

/**
 * The flag to the method that tells us that the refresh is a partial
 * one.
 */
#define PARTIAL_REFRESH 0
/**
 * The flag to the method that tells us that the refresh is a total
 * one.
 */
#define TOTAL_REFRESH 1
/**
 * The flag to the method that tells us that the refresh is actually
 * the player being deleted.
 */
#define PLAYER_DELETED 2

#endif
// --- END [/mnt/home2/grok/lib/include/refresh.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/potion_attrs.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/potion_attrs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
1004 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/potion_attrs.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__POTION_ATTRS
#define __SYS__POTION_ATTRS

/* constants for potion attributes */

#define POTION_SPACE_HANDLER "/obj/handlers/potion_space"

/* number of elements in the potion_attribute struct */
#define POTION_ATTRS_SIZE 6

#define POTION_CONSISTENCY 0     /* 0 = waterlike, 50 = honey, 100 = solid */
#define POTION_TRANSPARENCY 1    /* 0 = opaque, 50 = cloudy, 100 = water */
#define POTION_NAMES 2           /* ({ ({ "chunky soup", 100 }) }) */
#define POTION_COLOURS 3         /* ({ ({ "green", 20 }), ({ "yellow", 80 }) }) */
#define POTION_SMELLS 4          /* ({ ({ "fish", 80 }), ({ "onion", 40 }) }) */
#define POTION_FLAVOURS 5        /* ({ ({ "fish", 60 }), ({ "garlic", 30 }), ({ "onion", 20 }) }) */

#define VERY_SMALL_AMOUNT 5
#define SMALL_AMOUNT 10
#define MODERATE_AMOUNT 25

#define OC_VOL 0
#define OC_MVOL 1
#define OC_WVOL 2
#define OC_MAXVOL 3
#define OC_LEAKRATE 4
#define OC_PSQUANT 5
#define OC_MISCATTRS 6
#define OC_PSCOORD 7

#endif /* __SYS__POTION_ATTRS */
// --- END [/mnt/home2/grok/lib/include/potion_attrs.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/library.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/library.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
116 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/library.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SYS__LIBRARY
#define __SYS__LIBRARY

#define LIBRARY "/obj/handlers/library"

#endif /* __SYS__LIBRARY */
// --- END [/mnt/home2/grok/lib/include/library.h] ---
// --- BEGIN [/mnt/home2/grok/lib/include/player_shop.h] ---
// Size:   File: "/mnt/home2/grok/lib/include/player_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
20789 bytes, Last Modified:   File: "/mnt/home2/grok/lib/include/player_shop.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14630032   Available: 13577386
Inodes: Total: 5242880    Free: 4960136
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * Header file for player-run shops.
 * 
 * <p><b>Introduction</b></p>
 * <p>The aim of the player-run shop is to provide an environment where
 * players can interact with each other, and the shop, with no interference
 * from creators. Ideally, once the shop is set up, and with the exception
 * of the implementation of new features or code maintenance, no further
 * input should be required.
 * </p>
 * <p>All administration tasks can be performed by players. These tasks
 * typically include (but are not limited to): adding and removing stock
 * personnel decisions (hiring/firing/disciplinary) deciding what to stock
 * & for how much it is bought/sold increasing/decreasing stock capacity
 * (for a price) setting pay & bonus levels.
 * </p>
 * <p>The only involvement needed by a creator after setup is the initial
 * role of manager until employees have been promoted to take this position. 
 * </p>
 * 
 * <p><b>Appearance</b></p>
 * <p><b><i>Customers</i></b></p>
 * <p>From a customers' point of view, the shop should appear to function
 * similarly to a normal shop, with the obvious addition of players acting
 * as shopkeepers. In the absence of players, there is an npc shopkeeper
 * to serve customers. The npc has two customer interfaces.
 * <ul>
 * <li>It will recognise the standard "buy", "sell", "list",
 * "browse" commands.</li>
 * <li>It will recognise certain patterns of speech to perform
 * the same function.</li>
 * <\ul>
 * The npc will then react to the customer's request, performing the same
 * actions as a player would.
 * </p>
 * <p>A bell is provided on the counter to alert any employees logged
 * onto DW in the event that the npc is not available. Employees that
 * are clocked in are listed in the description of the shop front. It
 * is here that a customer may make a complaint, suggestion, or apply
 * for employment with the shop. Managers are then mailed to inform
 * them of a new application. Confirmations of employment, or
 * cancellations of application are also made here.
 * </p>
 * 
 * <p><b><i>Employees</i></b></p>
 * <p>Once an application has been accepted, confirmed, and subject to
 * any vacancies, the applicant is hired and becomes an employee of the
 * shop. Employees are able to move past the counter into the room beyond.
 * From here, it should be possible to access the office, storeroom and
 * managers' office.
 * </p>
 * <p>Employees are responsible for replenishing stock and serving
 * customers. Each is given a staff handbook and a special badge which
 * acts as a talker, allowing employees to keep in touch on a dedicated 
 * channel. This channel is also used by the shop bell to alert employees
 * to a customer in the shop.
 * </p>
 * <p>Before undertaking any actions in the shop, it is important that the
 * employee clocks on in the office. Also in the office is the shop's chart,
 * listing the lines of stock carried. This chart displays the buying and
 * selling price, as well as the number of items currently in stock.
 * </p>
 * <p>The stock itself is held in the stockroom, in one or more stock
 * cabinets. Each item is allocated a cabinet and the employee can either
 * place items in a specific cabinet, or let the stockroom work out where
 * they should go. Similarly, an employee can specify which cabinet to
 * remove stock from, or let the stockroom determine that. Listing stock
 * is an artform in itself - stock can be listed by item, cabinet, item in
 * cabinet, or all stock.
 * </p>
 * <p>When buying or selling items, the employee will need to handle
 * money. This is kept in the register behind the counter. Along with
 * the stock, all changes made are logged and viewable by supervisors
 * and managers. The logbook behind the counter is for employees to
 * record for themselves what they have done and why.
 * </p>
 * <p>Of course, a big incentive to do this work is to be paid for it.
 * Employees are paid every DW month, direct into their bank account.
 * They also receive a profit-related bonus each month, which they claim
 * from the office. The pay and bonus structure is discussed later, and
 * ties in nicely with EchoGnomics. Along with the pay, they accumulate
 * points towards promotion.
 * </p>
 * <p>Promotion is now not mandatory, and employees can deselect
 * themselves if they wish not to be promoted. Any player with the
 * "no score" property is automatically de- selected. Promotion is the
 * only personnel issue that managers have no control over. It is done
 * automatically to minimise favouritism. Once an employee has achieved
 * sufficient points, and subject to vacancies, they are promoted to 
 * <i>Supervisor<i>.
 * </p>
 * 
 * <p><b><i>Supervisors</i></b></p>
 * <p>Supervisors receive a higher wage packet than employees - 1.5
 * times the value, to be exact. Their duties include those of the
 * employees, with several additions. They are responsible for deciding
 * what items should be bought and sold, and at what price. Along with
 * this, they assign items to cabinets. To assist them, they are able to
 * view the general and chart logs. These logs indicate what is being
 * bought/sold, and what updates have been made to the chart. Again,
 * supervisors accumulate points towards promotion, and will eventually
 * be promoted to <i>Manager</i>.
 * </p> 
 * 
 * <p><b><i>Managers</i></b></p>
 * <p>Managers receive double the wage of employees. Their duties,
 * however, are quite involved. They include setting staffing levels,
 * pay rates, renting new storage space, hiring/firing/disciplinary
 * issues, and setting the shop's policies. This is in addition to
 * the duties performed by supervisors and employees.
 * Delegation would seem to play a part :-) 
 * </p>
 * <p>Managers cannot be promoted, and so have nothing to "work towards".
 * Experience has shown, however, that players in this position gain their
 * enthusiasm from the role itself, along with that pay packet. This view
 * is reinforced by the fact that most managers will prefer to retire than
 * resign.
 * </p>
 * <p>A retired manager has no active role in the shop, other than voting
 * on policy suggestions, and receives no pay. Those employed by Tarnach's
 * have been shown to be happy acting as 'mentors'. 
 * </p>
 * <p>The main advantage of being a retired manager is the lack of
 * commitment needed - a manager must be very active in the shop,
 * otherwise risking demotion. This demotion follows a warning, 
 * recorded on an employee's record. The same procedure applies to
 * supervisors_, within a longer timescale. <i>Employees</i> have even
 * longer, but risk being fired rather than demoted. These firings and
 * demotions are automatic, and are one method of staff turnover to help
 * ensure a fair system to allow new employees and promotions. If an
 * employee has a valid reason to be away, they can notify a manager
 * who can place them on leave. This ensures they are not fired or
 * demoted if they are genuinely on holiday etc.
 * </p>
 * <p>The code also includes a hook to the refresh handler. The office
 * is registered automatically, and appropriate action taken when an 
 * employee refreshes.
 * <ul>
 * <li>If the character is deleted, the employee data is also deleted.</li>
 * <li>If an applicant refreshes, their application is terminated.</li>
 * <li>If a retired manager refreshes, their employment is terminated.</li>
 * <li>If any other employee refreshes totally, their employment is
 * terminated, but if they only partially refresh, they revert to being
 * a "new employee".</li>
 * </ul>
 * </p>
 * 
 * <p><b>Echo-gnomics</b></p>
 * <p>One problem with the original Tarnach's economic strategy is that
 * employees' pay was created from thin air, whilst the profits accrued
 * without depletion. In order to do something with the profits, they
 * were distributed monthly between the employees by means of a bonus
 * payment. This is still less than desirable, however, as pay is still
 * being created from nothing. 
 * </p>
 * <p>The new system departs from this idea, and all shop's expenditure
 * comes from shop's profits. Shop's expenditure consists of:
 * <ul>
 * <li>Buying stock</li>
 * <li>Monthly bonus fund</li>
 * <li>Employee pay</li>
 * <li>Renting store cabinets</li>
 * </ul></p> 
 * <p>These are listed in order of departure from the original concept.
 * Stock purchases have always been funded by shop's profits. The monthly
 * bonus fund, as explained above, was added later. A new departure is
 * that pay also comes from profits. Finally, the cabinet rental was
 * only made possible by the redesign of the stockroom. 
 * </p>
 * <p>Another major departure from the original idea is that the npc
 * shopkeeper now gets paid. After all, the npc does a hell of a lot
 * of work, so why shouldn't it get paid? The npc will be paid in exactly
 * the same way as a normal employee, except that its pay won't go to a
 * bank account but rather 'disappear'. The npc will also claim a bonus
 * each month, in line with a normal employee's bonus rate. This will help
 * reduce the surplus funds, and should also give an incentive to player
 * employees to work harder. Promotion of the npc employee probably isn't
 * such a good idea though ;-) 
 * </p>
 * <p>Originally, the stockroom could contain an (theroetically) infinite
 * amount of stock. This led to large save-files, and a complete loss of
 * stock in the event of a crash (640k stock files don't tolerate crashes
 * very well if they are writing at the time). 
 * </p>
 * <p>To combat this, stock is seperated into one or more stock cabinets,
 * each holding a maximum of 50 items. Each store owns 5 cabinets, but
 * more may be rented depending on the success of the shop. The rental
 * fee is paid from the profit account. 
 * </p>
 * <p>Obviously, all this expenditure needs to be balanced by income.
 * The only standard source of shop's income is stock sales. Other
 * sources can be added on a shop-by-shop basis, such as the automagical
 * pickler in Tarnach's (A-M). This results in a far more challenging
 * role for shop's managers, having to balance income versus expenditure.
 * Role-playing at its most business-like :-) 
 * </p>
 * @see /std/shops/player_shop/office.c
 * @see /std/shops/player_shop/mgr_office.c
 * @see /std/shops/player_shop/counter.c
 * @see /std/shops/player_shop/storeroom.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */

 /**
 * Default maintainer of player shops.
 */
#define CREATOR "calroth"


/**
 * Initial value for some strings
 */
#define UNSET_STR "__RINGO_WOZ_ERE__"

/**
 * Path to player-shop objects
 */
#define PSOBJDIR "/obj/misc/player_shop/"
/**
 * Path to the shop cabinet object
 */
#define CABINET (PSOBJDIR + "shop_cabinet")
/**
 * Path to the shop badge object
 */
#define BADGE (PSOBJDIR + "shop_badge")
/**
 * Path to staff handbook
 */
#define STAFF_BOOK (PSOBJDIR + "staff_book")
/**
 * Path to the manager's handbook
 */
#define MGR_BOOK (PSOBJDIR + "mgr_book")
/**
 * Path to the shopping bag
 */
#define SHOP_BAG (PSOBJDIR + "shopping_bag")
/**
 * Path to the chart
 */
#define SHOP_CHART (PSOBJDIR + "shop_chart")
/**
 * Path to the policy notice
 */
#define SHOP_NOTICE (PSOBJDIR + "shop_notice")

/**
 * True value (1)
 */
#define TRUE 1
/**
 * False value (0)
 */
#define FALSE 0

/**
 * Paid action
 */
#define PAID 1
/**
 * Unpaid action
 */
#define UNPAID 0

/**
 * Employee mapping - points
 */
#define EMP_POINTS 0
/**
 * Employee mapping - bank
 */
#define EMP_BANK 1
/**
 * Employee mapping - this month's pay
 */
#define EMP_PAY 2
/**
 * Employee mapping - inactivity flag
 */
#define EMP_INACTIVE 3
/**
 * Employee mapping - suspended bonus
 */
#define EMP_NOBONUS 4
/**
 * Employee mapping - Skip promotion.
 * This is done either at employee's request, or automatically
 * if the "no score" property is set.<br>
 * Set at -1 for "no score", or TRUE for employee request
 */
#define EMP_NOPROMOTE 5
/**
 * Employee mepping - = employee of month points
 */
#define EMP_EOM 6

/**
 * Employee bit - employee exists.
 */
#define EMPLOYEE 1
/**
 * Employee bit - employee is the npc shopkeeper.
 */
#define NPC 2
/**
 * Employee bit - employee is supervisor.
 */
#define SUPERVISOR 4
/**
 * Employee bit - employee is manager.
 */
#define MANAGER 8
/**
 * Employee bit - player is clocked in.
 */
#define CLOCKED_IN 16

/**
 * Employee mapping
 */
#define EMP_MAP ({EMPLOYEE,0,0,0,1,0,0,})

/**
 * Number of points to become a manager.
 */
#define MANAGER_POINTS 1000
/**
 * Number of points to become a supervisor.
 */
#define SUPER_POINTS 500

/**
 * Banned people mapping - reason
 */
#define BAD_REASON 0
/**
 * Banned people mapping - banner 
 */
#define BAD_BANNER 1
/**
 * Banned people mapping - time of ban
 */
#define BAD_TIME 2

/**
 * Banned people mapping
 */
#define BAD_MAP ({"","",0,})

/**
 * Applications mapping - type of applicant
 */
#define APP_TYPE 0
/**
 * Applications mapping - time of application
 */
#define APP_TIME 1
/**
 * Applications mapping - votes for
 */
#define APP_FOR 2
/**
 * Applications mapping - votes against
 */
#define APP_AGAINST 3
/**
 * Applications mapping - abstentions
 */
#define APP_ABSTAIN 4
/**
 * Applications mapping - application message
 */
#define APP_MESSAGE 5

/**
 * Applicant types - Just applied
 */
#define APPLIED 1
/**
 * Applicant types - Voted in
 */
#define HIRED 2
/**
 * Applicant types - Awaiting a vacancy
 */
#define AWAITING 3

/**
 * Vote for an applicant
 */
#define VFOR      1
/**
 * Vote against an applicant
 */
#define VAGAINST  0
/**
 * Abstain on applicant
 */
#define VABSTAIN -1

/**
 * Applications mapping
 */
#define APP_MAP ({APPLIED,0,({}),({}),({}),"",})

/**
 * Minimum number of cabinets per storeroom
 */
#define MIN_CABINETS 5
/**
 * Maximum number of cabinets per storeroom
 */
#define MAX_CABINETS 20
/**
 * Maximum number of items per cabinet
 */
#define STOCK_PER_CABINET 50
/**
 * Maximum number of items in stock
 */
#define MAX_STOCK (MAX_CABINETS * STOCK_PER_CABINET)
/**
 * Price of cabinets
 */
#define CABINET_COST 400000

/**
 * Log entries - manual entry
 */
#define LOG_ENTRY 1
/**
 * Log entries - items purchased by shop.
 * Items added to stock, cash removed from till
 */
#define PURCHASE 2
/**
 * Log entries - items sold by shop.
 * Items removed from stock, cash added to till
 */
#define SALE 3
/**
 * Log entries - personnel issues (hire, fire, promote, demote,
 * warnings, retire, resign, on leave etc)
 */
#define PERSONNEL 4
/**
 * Log entries - accounts (pay/bonus/profit)
 */
#define ACCOUNTS 5
/** 
 * Log entries - general entries
 */
#define GENERAL 6
/**
 * Log entries - chart changes
 */
#define CHARTLOG 7

/**
 * Chart mapping - maximum stock
 */
#define CHART_MAX 0
/**
 * Chart mapping - average stock
 */
#define CHART_AVE 1
/**
 * Chart mapping - buy price
 */
#define CHART_BUY 2
/**
 * Chart mapping - sell price
 */
#define CHART_SELL 3
/**
 * Chart mapping - stock cabinet(s) used by this item
 */
#define CHART_CAB 4
/**
 * Chart mapping - average daily sales
 */
#define CHART_AVESALE 5
/**
 * Chart mapping - daily sales
 */
#define CHART_SOLD 6
/**
 * Chart mapping - daily purchases
 */
#define CHART_BOUGHT 7

/** 
 * Policy mapping
 */
#define POLICY_TIME 0
/** 
 * Policy mapping
 */
#define POLICY_MGR 1
/** 
 * Policy mapping
 */
#define POLICY_TEXT 2
/** 
 * Policy mapping
 */
#define POLICY_FOR 3
/** 
 * Policy mapping
 */
#define POLICY_AGAINST 4
/**
 * Policy type
 */
#define POLICY_TYPE 5

/** 
 * Policy mapping
 */
#define POLICY_MAP ({0,"","",({}),({}),0,})

/**
 * Path to the player-shop handler
 */
#define PLAYER_SHOP "/obj/handlers/player_shop"
/**
 * Path to the history handler used for chats through the badge
 */
#define HISTORY_HANDLER "/obj/handlers/hist_handler"
/**
 * Path to the bank handler
 */
#define BANK_HANDLER "/obj/handlers/bank_handler"
/**
 * Path to the player handler
 */
#define PLAYER_HANDLER "/obj/handlers/player_handler"

/**
 * List of banks.
 * The list is formatted as ({ ({ "Description", "Name" }) })<br>
 * Any new banks must be added to the end of this list to avoid 
 * upsetting existing employees ;-)
 */
#define BANKS ({ ({ "Bing's First National", "Bing's First", }), \
                 ({ "Lancrastian Farmers' Co-operative", "LFC", }), \
                 ({ "Klatchian Continental", "Klatchian Continental", }), \
              }) 

/**
 * How long to prevent someone ringing the shop bell again (seconds)
 */
#define BELL_TIMEOUT 120

/**
 * Minimum number of employees per shop
 */
#define MIN_EMP 10
/**
 * Maximum number of employees per shop
 */
#define MAX_EMP 40
/**
 * Percentage of employees that can be managers
 */
#define PERCENT_M 10
/**
 * Percentage of employees that can be supervisors
 */
#define PERCENT_S 20

/**
 * Default pay amount
 */
#define START_PAY 20

/** 
 * Maximum number of consecutive days an employee can be on leave
 */
#define MAX_LEAVE 14
/**
 * Length of ban from shop in days
 */
#define BAN_LENGTH 28
/**
 * Length of time (days) before an applicant can re-apply
 */
#define DECLINE_LENGTH 14
/**
 * Time (days) before managers demoted for inactivity
 */
#define MGR_DEMOTE 14
/**
 * Time (days) before managers warned for inactivity
 */
#define MGR_WARN 7
/**
 * Time (days) before supervisors demoted for inactivity
 */
#define SPR_DEMOTE 28
/**
 * Time (days) before supervisors warned for inactivity
 */
#define SPR_WARN 14
/**
 * Time (days) before employees fired for inactivity
 */
#define EMP_FIRE 62
/**
 * Time (days) before employees warned for inactivity
 */
#define EMP_WARN 14


/**
 * Bag maximum storage
 */
#define MAX_BAG_ITEMS 10
/**
 * Bag maximum contents' weight
 */
#define MAX_BAG_WEIGHT 50

/**
 * Length of time (days) to keep shop's logs
 */
#define LOG_DAYS 14

/**
 * Length of time (seconds) for hired applicants to confirm
 * their employment.
 */
#define HIRE_TIMEOUT (86400*14)

/**
 * Length of time (seconds) for a player's history to expire if
 * there has been no update.
 */
#define HIST_TIMEOUT (86400*91)

/**
 * Length of time (seconds) before votes are considered final
 */
#define VOTE_TIMEOUT (86400*14)

/**
 * Shopkeeper's movement & command delay
 */
#define NPC_DELAY (2 + random(3))
/**
 * Shopkeeper's reload delay (seconds)
 */
#define NPC_RELOAD 3600

/**
 * Call-out delay for saving employee & shop data
 */
#define SAVE_DELAY 1
/**
 * Call-out delay for saving personnel data
 */
#define PERS_DELAY 5
/**
 * Call-out delay for clearing variables
 */
#define CLEAR_DELAY 300

/**
 * Prompt shown to player making a complaint
 */
#define COMPLAINT_TEXT "Please fully state your complaint below.  " \
                       "Include as much detail as you can and any " \
                       "evidence/witnesses to support your complaint."

/**
 * Prompt shown to player making a suggestion
 */
#define SUGGEST_TEXT "Please detail your suggestion below."

/**
 * Questions to ask an applicant for a job
 */
#define APP_QUESTIONS ({ "Why do you want to work for "+ \
                     _office->query_shop_name()+ "?", \
                     "What is your (DW) age?", \
                     "What Guild do you belong to?", \
                     "What relevant experience do you have of collecting " \
                      " and/or recognising our stock?", \
                     "How much time (hours/week) do you think you can " \
                     "commit to the shop?  Please also tell us at what " \
                     "time you will usually be on.", \
                     "Do you already know anyone who is an employee " \
                     "here, who could recommend you?  If so, who?", \
                     "Have you previously held a position at this shop?  " \
                     "If so, why did you leave?", \
                     "Do you currently work at any other shop?", \
                     "Have you applied for employment here before?  " \
                     "If so, what was the outcome?", \
                     "Do you have anything else you'd like to tell us in " \
                     "support of your application?  Please expand on above " \
                     "points if necessary.  What you say here will influence " \
                     "whether or not you are hired." \
                })

/**
 * Log unallowed calls
 */
#define LOG_ERROR(A,B) log_file( "/log/PLAYER_SHOP", "%s: %s : %s called by %s\n",\
                       ctime(time()), A, B, previous_object()->query_name() )

#define last_login(N) (PLAYER_HANDLER)->test_last(N)
#define test_cre(N) (PLAYER_HANDLER)->test_creator(N)
#define test_player(N) (PLAYER_HANDLER)->test_user(N)
#define test_prop(N,P) (PLAYER_HANDLER)->test_property(N,P)
// --- END [/mnt/home2/grok/lib/include/player_shop.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/curses/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/curses/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629885   Available: 13577239
Inodes: Total: 5242880    Free: 4960136
210 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/curses/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629885   Available: 13577239
Inodes: Total: 5242880    Free: 4960136
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: path.h,v 1.1 1998/01/06 04:03:23 ceres Exp $
 * $Log: path.h,v $
 * Revision 1.1  1998/01/06 04:03:23  ceres
 * Initial revision
 * 
*/
#define HERE "/std/curses/"
// --- END [/mnt/home2/grok/lib/std/curses/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/shops/player_shop/patterns.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/shops/player_shop/patterns.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629631   Available: 13576985
Inodes: Total: 5242880    Free: 4960136
1454 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/shops/player_shop/patterns.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629631   Available: 13576985
Inodes: Total: 5242880    Free: 4960136
2006-10-07 21:00:02.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* Office chart command */
#define CHART_ADDITEM       "add <string'item'>"
#define CHART_REMITEM       "remove <string'item'>"
#define CHART_MAXITEM       "max <string'item'> <number>"
#define CHART_BUYITEM       "buy <string'item'> <number>"
#define CHART_SELLITEM      "sell <string'item'> <number>"
#define CHART_ASSIGN_ITEM   "assign <string'item'> <number'cabinet number'>"
#define CHART_UNASSIGN_ITEM "unassign <string'item'> <number'cabinet number'>"

/* Offices logs command */
#define LOG_BLANK  ""
#define LOG_NUMBER "<number>"
#define LOG_MGR    "{personnel|accounts|chart}"
#define LOG_CHART  "chart"

/* Mgr Office list command */
#define LIST_BLANK  ""
#define LIST_CHOICE "{employees|applicants|baddies}"

/* Mgr Office set command */
#define SET_EMPS "maximum <number> [employees]"
#define SET_PAY  "pay <number'amount'> <string'type'>"

/* Mgr Office vote command */
#define VOTE_APPLICANT "<word'applicant'> {y|n|a}"
#define VOTE_POLICY    "policy <word'name'> {y|n}"

/* Mgr Office view command */
#define VIEW_EMP "<string'employee'>"
#define VIEW_APP "application [by] <string'applicant'>"

/* Mgr Office policy command */
#define POLICY_SUGGEST "suggest {manager|shop} <word'policy'>"
#define POLICY_REMOVE  "remove <word'policy'>"

/* Stockroom list command */
#define LIST_CABINET      "cabinet <number'cabinet'>"
#define LIST_ITEM         "<string'item'>"
#define LIST_ITEM_CABINET "<string'item'> in cabinet <number'cabinet'>"
// --- END [/mnt/home2/grok/lib/std/shops/player_shop/patterns.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/shops/player_shop/office.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/shops/player_shop/office.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629625   Available: 13576979
Inodes: Total: 5242880    Free: 4960136
9076 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/shops/player_shop/office.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629625   Available: 13576979
Inodes: Total: 5242880    Free: 4960136
2006-10-07 21:00:02.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*
 * Some useful macros
 */
#define clear_applicants() _call_apps_clear = \
                         call_out((: _applicants = 0 :), CLEAR_DELAY)
#define clear_history() _call_hist_clear = \
                         call_out((: _history = 0 :), CLEAR_DELAY)
#define clear_new_policies() _call_newpols_clear = \
                             call_out((: _new_policies = 0 :), CLEAR_DELAY)
#define clear_policies() _call_pols_clear = \
                         call_out((: _policies = 0 :), CLEAR_DELAY)

#define save_applicants() _call_apps = \
                          call_out((: do_save_applicants() :), SAVE_DELAY);
#define save_hist() _call_hist = \
                          call_out((: do_save_hist() :), SAVE_DELAY);
#define save_new_policies() _call_newpols = \
                          call_out((: do_save_new_policies() :), SAVE_DELAY);
#define save_policies() _call_pols = \
                          call_out((: do_save_policies() :), SAVE_DELAY);

/*
 * Prototypes
 * Where a function exists outside of office.c, the relevant .c file is indicated
 */
void     add_applicant(string,string);   //applications.c
private void add_baddie( string, string, string);   //baddies.c
private void add_board_message(string, string);   //admin.c
private void add_chart_cabinet(string, int);   //stock.c
private void add_declined(string);   //applications.c
private void add_employee(string);   //personnel.c
protected void add_manager_exit(string, string);
private void add_policy(string);   //policies.c
void     add_policy_suggest(string, string, string, int);   //policies.c
private void add_vote(string, int);   //applications.c
private void adjust_bonus(string, int);   //admin.c
void     adjust_bought(string, int);   //stock.c
private void adjust_profit(string, int);   //admin.c
void     adjust_sold(string, int);   //stock.c
void     adjust_takings(int);   //admin.c
string   badge_list();   //lists.c
void     calc_bonus();   //admin.c
int      calc_pay();   //admin.c
private string cap_name(string); //admin.c
void check_hire_list();   //applications.c
int      check_manager(string);   //admin.c
void     confirm_cabinet(string, int);   //cabinets.c
private void demote(string, string);   //personnel.c
string   directions_to(string);   //admin.c
private int do_ban(mixed *);   //baddies.c
private int do_bank(mixed);   //emp_cmd.c
int do_cancel();   //applications.c
private int do_chart(mixed *, string);   //stock.c
private int do_check();   //cabinets.c
private int do_claim(string);   //emp_cmd.c
private int do_clock(string);   //emp_cmd.c
int      do_commend(string);  //personnel.c
private int do_confirm();   //applications.c
int      do_demote(string);   //personnel.c
int      do_fire(mixed *);   //personnel.c
int      do_leave(mixed *);   //personnel.c
int      do_list();   //lists.c
int      do_logs(mixed *, string);   //logging.c
private int do_memo();   //memo.c
private int do_office();   //lists.c
private int do_policy_vote(string, string, string);   //policies.c
private int do_promote(string);   //personnel.c
int      do_remove();   //cabinets.c
int      do_rent();   //cabinets.c
private int do_resign();   //personnel.c
int      do_retire();   //personnel.c
private void do_save();   //save.c
private void do_save_applicants(); //save.c
private void do_save_emps();   //save.c
private void do_save_hist();   //save.c
private void do_save_new_policies(); //save.c
private void do_save_policies(); //save.c
int      do_set(mixed *, string);   //admin.c
int      do_suspend(mixed *);   //personnel.c
int      do_transfer(mixed *);   //admin.c
int      do_unban(string);   //baddies.c
int      do_vote(mixed *, string);   //applications.c
int      do_warn(mixed *);  //personnel.c
private void employee_log(string, string);   //logging.c
string   employees_clocked_in();   //lists.c
private void end_memo(string,string);   //memo.c
private void fire_them(string, string, string);  //personnel.c
mapping  get_applicants();
mapping  get_baddies();
string  *get_employees();
string  *get_managers();
mapping  get_new_policies();
mapping  get_policies(int);
string  *get_retired();
string   get_stock_policy();   //policies.c
string  *get_supervisors();
private void hire(string);   // personnel.c
private string list_stuff(string);   //lists.c
private void load_applicants(); //admin.c
private void load_history(); //admin.c
private void load_new_policies(); //admin.c
private void load_policies(); //admin.c
private void mail_hirees();   //applications.c
private void monthly_review();   //review.c
int      num_employees_in();
private void put_on_list(string);   //stock.c
int      query_applicant(string);
int      query_ave(string);   //stock.c
int      query_baddie(string);
int      query_bonus();
int      query_buy(string);   //stock.c
int     *query_cabinet(string);   //cabinets.c
int      query_cabinet_used(int);   //cabinets.c
string   query_channel();
string   query_counter();
void     query_creator(string);
int      query_declined(string);
int      query_employee(string );
mapping  query_employees();
string  *query_list_array();
string   query_list_string();
int      query_manager(string);
int      query_max(string);   //stock.c
int      query_maxemp();
string   query_mgr_office();
int      query_num_cabinets();
int      query_on_list(string);   //stock.c
int      query_pay();
string   query_place();
int      query_policy(string);
int      query_profit();
string   query_proprietor();
int      query_retired(string);
int      query_sell(string);   //stock.c
string   query_shop_front();
string   query_shop_name();
string   query_shopkeeper();
int      query_stock(string);
string   query_storeroom();
int      query_supervisor(string);
private string query_worked(string);   //personnel.c
private void remove_applicant(string);   //applications.c
private void remove_baddie(string);   //baddies.c
private void remove_chart_cabinet(string, int);   //cabinets.c
private void remove_declined(string);   //applications.c
private void remove_employee(string);   //admin.c
private void remove_policy(string);   //policies.c
private void remove_retired(string);   //admin.c
private void reset_employee(string, int);   //admin.c
mixed   *restore_register();   //admin.c
private void review_employees();   //review.c
private void rm_cab();   //cabinets.c
protected void save_emps();
private void save_list();   //save.c
protected void save_me();
void     save_register(mixed *);   //save.c
private void save_times();   //save.c
private void send_memo(string, string, string);   //memo.c
private void set_buy(string, int);   //stock.c
protected void set_channel(string, int);
protected void set_counter(string);
protected void set_creator(string);
protected void set_directions(string, string, string);
private void set_emp_time(string);   //personnel.c
private void set_employee(string, int);   //admin.c
private void set_max(string, int);   //stock.c
protected void set_place(string);
protected void set_proprietor(string);
private void set_sell(string, int);   //stock.c
protected void set_shop_front(string);
protected void set_shop_name(string);
protected void set_shopkeeper(string);
protected void set_stock_policy(string);
protected void set_storeroom(string);
protected void set_very_short(string);
void     shop_log(int, string, string, int);   // logging.c
string   shop_very_short();
void     summon_shopkeeper();   //admin.c
private void take_off_list(string);   //stock.c
private void update_averages();   //stock.c
void     view_record(string,string);   //personnel.c
private void write_memo(string); //memo.c


/*
 * Patterns used within add_commands
 */

/* Office chart command */
#define CHART_ADDITEM       "add <string'item'>"
#define CHART_REMITEM       "remove <string'item'>"
#define CHART_MAXITEM       "max <string'item'> <number>"
#define CHART_BUYITEM       "buy <string'item'> <number>"
#define CHART_SELLITEM      "sell <string'item'> <number>"
#define CHART_ASSIGN_ITEM   "assign <string'item'> <number'cabinet number'>"
#define CHART_UNASSIGN_ITEM "unassign <string'item'> <number'cabinet number'>"

/* Offices logs command */
#define LOG_BLANK  ""
#define LOG_NUMBER "<number>"
#define LOG_MGR    "{personnel|accounts|chart}"
#define LOG_CHART  "chart"

/* Mgr Office list command */
#define LIST_BLANK  ""
#define LIST_CHOICE "{employees|applicants|baddies}"

/* Mgr Office set command */
#define SET_EMPS "maximum <number> [employees]"
#define SET_PAY  "pay <number'amount'> <string'type'>"

/* Mgr Office vote command */
#define VOTE_APPLICANT "<word'applicant'> {y|n|a}"
#define VOTE_POLICY    "policy <word'name'> {y|n}"

/* Mgr Office view command */
#define VIEW_EMP "<string'employee'>"
#define VIEW_APP "application [by] <string'applicant'>"

/* Mgr Office policy command */
#define POLICY_SUGGEST "suggest {manager|shop} <word'policy'>"
#define POLICY_REMOVE  "remove <word'policy'>"

/* Stockroom list command */
#define LIST_CABINET      "cabinet <number'cabinet'>"
#define LIST_ITEM         "<string'item'>"
#define LIST_ITEM_CABINET "<string'item'> in cabinet <number'cabinet'>"
// --- END [/mnt/home2/grok/lib/std/shops/player_shop/office.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/room/controller/topography/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/room/controller/topography/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629295   Available: 13576649
Inodes: Total: 5242880    Free: 4960135
166 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/room/controller/topography/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629295   Available: 13576649
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:02.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: path.h,v 1.1 2000/05/01 03:10:24 jeremy Exp $
 *
 *
 */

#define FIXED_SHADOW "/std/room/basic/topography/fixed_shadow"
// --- END [/mnt/home2/grok/lib/std/room/controller/topography/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/shadows/object/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/shadows/object/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629120   Available: 13576474
Inodes: Total: 5242880    Free: 4960135
90 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/shadows/object/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629120   Available: 13576474
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:01.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/std/shadows/object/"
#undef EFFECTS
#define EFFECTS "/std/effects/object/"
// --- END [/mnt/home2/grok/lib/std/shadows/object/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/shadows/attached/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/shadows/attached/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629072   Available: 13576426
Inodes: Total: 5242880    Free: 4960135
80 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/shadows/attached/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629072   Available: 13576426
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:01.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/std/shadows/attached/"

#define EFFECTS "/std/effects/attached/"
// --- END [/mnt/home2/grok/lib/std/shadows/attached/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/object/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/object/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629052   Available: 13576406
Inodes: Total: 5242880    Free: 4960135
76 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/object/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629052   Available: 13576406
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/std/effects/object/"

#define SHADOWS "/std/shadows/object/"
// --- END [/mnt/home2/grok/lib/std/effects/object/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/disease/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/disease/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629037   Available: 13576391
Inodes: Total: 5242880    Free: 4960135
21 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/disease/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629037   Available: 13576391
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <disease.h>
// --- END [/mnt/home2/grok/lib/std/effects/disease/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/curses/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/curses/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629032   Available: 13576386
Inodes: Total: 5242880    Free: 4960135
187 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/curses/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629032   Available: 13576386
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define NPCS "/obj/monster/"
#define ITEMS "/obj/faith/"
#define SHADOWS "/std/shadows/curses/"
#define EFFECTS "/std/effects/curses/"
#define BASIS "/std/effects/religious/basic_ritual"
// --- END [/mnt/home2/grok/lib/std/effects/curses/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/npc/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/npc/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629014   Available: 13576368
Inodes: Total: 5242880    Free: 4960135
252 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/npc/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14629014   Available: 13576368
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: path.h,v 1.1 1998/01/06 04:17:06 ceres Exp $
 * $Log: path.h,v $
 * Revision 1.1  1998/01/06 04:17:06  ceres
 * Initial revision
 * 
*/
#define PATH "/std/effects/npc/"

#define SHADOWS "/std/shadows/npc/"
// --- END [/mnt/home2/grok/lib/std/effects/npc/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/attached/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/attached/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628998   Available: 13576352
Inodes: Total: 5242880    Free: 4960135
296 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/attached/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628998   Available: 13576352
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: path.h,v 1.1 1998/01/06 04:06:54 ceres Exp $
 * $Log: path.h,v $
 * Revision 1.1  1998/01/06 04:06:54  ceres
 * Initial revision
 * 
*/
#define PATH "/std/effects/attached/"

#define SHADOWS "/std/shadows/attached/"

#define HUMAN "/std/races/human"
// --- END [/mnt/home2/grok/lib/std/effects/attached/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/effects/other/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/effects/other/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628995   Available: 13576349
Inodes: Total: 5242880    Free: 4960135
74 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/effects/other/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628995   Available: 13576349
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/std/effects/other/"

#define SHADOWS "/std/shadows/other/"
// --- END [/mnt/home2/grok/lib/std/effects/other/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/npc/goal_inherit.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/npc/goal_inherit.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628966   Available: 13576320
Inodes: Total: 5242880    Free: 4960135
615 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/npc/goal_inherit.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628966   Available: 13576320
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This file contains defines needed locally for the goal inheritable
 * for the npcs.
 * @author Pinkfish
 * @started Tue Aug  4 19:04:37 PDT 1998
 */
#ifndef __GOAL_INHERIT_H__
#define __GOAL_INHERIT_H__

/**
 * This is the length of the plan array used in the goal inherit
 * file.
 */
#define PLAN_ARRAY_SIZE 2
/**
 * The index to the plan name itself.
 */
#define PLAN_PLAN 0
/**
 * The index to the plan's priority.
 */
//#define PLAN_PRIORITY 1
/**
 * The index to the plan's data.
 */
//#define PLAN_DATA 2

/**
 * The index to the information associated with the plan.
 */
#define PLAN_INFO 1


#endif
// --- END [/mnt/home2/grok/lib/std/npc/goal_inherit.h] ---
// --- BEGIN [/mnt/home2/grok/lib/std/environ/snowball.h] ---
// Size:   File: "/mnt/home2/grok/lib/std/environ/snowball.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628909   Available: 13576263
Inodes: Total: 5242880    Free: 4960135
89 bytes, Last Modified:   File: "/mnt/home2/grok/lib/std/environ/snowball.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628909   Available: 13576263
Inodes: Total: 5242880    Free: 4960135
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define SNOW_THING "The snow ball thing"
#define SNOW_EXTRA "/std/environ/snowball_look"
// --- END [/mnt/home2/grok/lib/std/environ/snowball.h] ---
// --- BEGIN [/mnt/home2/grok/lib/net/obj/smtp.h] ---
// Size:   File: "/mnt/home2/grok/lib/net/obj/smtp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628679   Available: 13576033
Inodes: Total: 5242880    Free: 4960135
270 bytes, Last Modified:   File: "/mnt/home2/grok/lib/net/obj/smtp.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628679   Available: 13576033
Inodes: Total: 5242880    Free: 4960135
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __SMTP_H__
#define __SMTP_H__

#define SMTP_HOST "127.0.0.1"
#define SMTP_PORT 25
#define MUD_IP_NAME "discworld.imaginary.com"

#undef DEBUG

#ifdef DEBUG
#define TP(s) tell_object(find_player("turrican"), s)
#else
#define TP(s)
#endif

#endif /* __SMTP_H__ */
// --- END [/mnt/home2/grok/lib/net/obj/smtp.h] ---
// --- BEGIN [/mnt/home2/grok/lib/net/intermud3/oob_server.h] ---
// Size:   File: "/mnt/home2/grok/lib/net/intermud3/oob_server.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628671   Available: 13576025
Inodes: Total: 5242880    Free: 4960135
271 bytes, Last Modified:   File: "/mnt/home2/grok/lib/net/intermud3/oob_server.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628671   Available: 13576025
Inodes: Total: 5242880    Free: 4960135
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __OOB_SERVER_H
#define __OOB_SERVER_H

#define TIMEOUT 600

class connection {
  string MudName;
  mixed Buffer;
}

void eventTimeout(int fd);
protected void eventSocketClosed(int fd);
protected void eventRead(int fd, mixed *packet);

#endif /* __OOB_SERVER_H */
// --- END [/mnt/home2/grok/lib/net/intermud3/oob_server.h] ---
// --- BEGIN [/mnt/home2/grok/lib/net/intermud3/intermud.h] ---
// Size:   File: "/mnt/home2/grok/lib/net/intermud3/intermud.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628671   Available: 13576025
Inodes: Total: 5242880    Free: 4960135
635 bytes, Last Modified:   File: "/mnt/home2/grok/lib/net/intermud3/intermud.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628671   Available: 13576025
Inodes: Total: 5242880    Free: 4960135
2006-10-07 20:59:53.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#ifndef __INTERMUD_H__
#define __INTERMUD_H__

#define SAVE_INTERMUD "/net/save/intermud"

class list {
    int ID;
    mapping List;
}

protected void create();
protected void Setup();
protected void eventRead(int fd, mixed *packet);
protected void eventRequestMudList();
protected void eventRequestChannelList();
protected void eventSocketClose(int fd);
protected void eventConnectionFailure();
int SetDestructOnClose(int x);
int SetSocketType(int x);
string GetMudName(string mud);
mapping GetMudList();
string *GetMuds();
mapping GetChannelList();
string *GetMatch(string mud);
string GetNameserver();

#endif /* __INTERMUD_H__ */
// --- END [/mnt/home2/grok/lib/net/intermud3/intermud.h] ---
// --- BEGIN [/mnt/home2/grok/lib/obj/examples/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/obj/examples/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628621   Available: 13575975
Inodes: Total: 5242880    Free: 4960135
30 bytes, Last Modified:   File: "/mnt/home2/grok/lib/obj/examples/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14628621   Available: 13575975
Inodes: Total: 5242880    Free: 4960135
2006-10-07 20:59:55.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define ROOM "/obj/examples/"
// --- END [/mnt/home2/grok/lib/obj/examples/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/obj/monster/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/obj/monster/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627912   Available: 13575266
Inodes: Total: 5242880    Free: 4960133
29 bytes, Last Modified:   File: "/mnt/home2/grok/lib/obj/monster/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627912   Available: 13575266
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:54.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/obj/monster/"
// --- END [/mnt/home2/grok/lib/obj/monster/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/npcs/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/npcs/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627765   Available: 13575119
Inodes: Total: 5242880    Free: 4960133
50 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/npcs/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627765   Available: 13575119
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH HELP + "npcs/"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/npcs/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/rooms/terrains/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/terrains/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627761   Available: 13575115
Inodes: Total: 5242880    Free: 4960133
85 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/terrains/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627761   Available: 13575115
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH HELP +"rooms/terrains/"
#define MAIN PATH +"main"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/rooms/terrains/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/rooms/add_item/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/add_item/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627751   Available: 13575105
Inodes: Total: 5242880    Free: 4960133
85 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/add_item/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627751   Available: 13575105
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH HELP +"rooms/add_item/"
#define MAIN PATH +"main"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/rooms/add_item/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/rooms/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627745   Available: 13575099
Inodes: Total: 5242880    Free: 4960133
51 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627745   Available: 13575099
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH HELP + "rooms/"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/rooms/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/rooms/situations/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/situations/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627743   Available: 13575097
Inodes: Total: 5242880    Free: 4960133
79 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/situations/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627743   Available: 13575097
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>

#define SIT "/d/learning/help_topics/rooms/situations/"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/rooms/situations/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/rooms/crowd/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/crowd/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627733   Available: 13575087
Inodes: Total: 5242880    Free: 4960133
76 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/rooms/crowd/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627733   Available: 13575087
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>

#define CROWD "/d/learning/help_topics/rooms/crowd/"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/rooms/crowd/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/help_topics/objects/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/help_topics/objects/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627729   Available: 13575083
Inodes: Total: 5242880    Free: 4960133
53 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/help_topics/objects/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627729   Available: 13575083
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH HELP + "objects/"
// --- END [/mnt/home2/grok/lib/d/learning/help_topics/objects/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/TinyTown/roads/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/TinyTown/roads/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627723   Available: 13575077
Inodes: Total: 5242880    Free: 4960133
48 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/TinyTown/roads/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627723   Available: 13575077
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>

#define PATH TTOWNROADS

// --- END [/mnt/home2/grok/lib/d/learning/TinyTown/roads/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/TinyTown/buildings/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/TinyTown/buildings/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627721   Available: 13575075
Inodes: Total: 5242880    Free: 4960133
52 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/TinyTown/buildings/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627721   Available: 13575075
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>

#define PATH TTOWNBUILDINGS

// --- END [/mnt/home2/grok/lib/d/learning/TinyTown/buildings/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/functions/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/functions/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627719   Available: 13575073
Inodes: Total: 5242880    Free: 4960133
45 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/functions/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627719   Available: 13575073
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH FUNCTIONS
// --- END [/mnt/home2/grok/lib/d/learning/functions/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/examples/npcs/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/examples/npcs/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627711   Available: 13575065
Inodes: Total: 5242880    Free: 4960133
43 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/examples/npcs/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627711   Available: 13575065
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/d/learning/examples/npcs/"
// --- END [/mnt/home2/grok/lib/d/learning/examples/npcs/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/newbie/introduction/examples/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/newbie/introduction/examples/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627697   Available: 13575051
Inodes: Total: 5242880    Free: 4960133
57 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/newbie/introduction/examples/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627697   Available: 13575051
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/d/learning/newbie/introduction/examples/"
// --- END [/mnt/home2/grok/lib/d/learning/newbie/introduction/examples/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627694   Available: 13575048
Inodes: Total: 5242880    Free: 4960133
44 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627694   Available: 13575048
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:47.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define PATH LEARNING
// --- END [/mnt/home2/grok/lib/d/learning/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/learning/chars/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/learning/chars/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627688   Available: 13575042
Inodes: Total: 5242880    Free: 4960133
71 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/learning/chars/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627688   Available: 13575042
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <learning.h>
#define TERRAIN_TUTORIAL HELP +"rooms/terrains/"
// --- END [/mnt/home2/grok/lib/d/learning/chars/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/mtf/mtfincl.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/mtf/mtfincl.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627672   Available: 13575026
Inodes: Total: 5242880    Free: 4960133
642 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/mtf/mtfincl.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627672   Available: 13575026
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define PATH "/w/ceres/mtf-v1.1/"

/*MISCELLANEOUS */

#define VERSION v1.1

/* ERROR CODES */

#define NO_MAP_FILE -1
#define NO_FILE_DIR -2
#define NO_KEY_FILE -3

/* DEFAULT FILES */

#define DEFAULT_KEYS PATH+"key_dft.c"

#define SPECIALS ({ "*", "+", "x", "-", "|", "\\", "/" })

/* DIRECTION STUFF FOR EXITS */

#define EXITS_NS ({ "north", "", "south" })
#define EXITS_WE ({ "west", "", "east" })

#define DIRECTIONS ({ ({ "northwest", "north", "northeast", }), ({ "west", "", "east", }), ({ "southwest", "south", "southeast" }) })
#define LIST ({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest" })
// --- END [/mnt/home2/grok/lib/d/dist/mtf/mtfincl.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/path2.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/path2.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627669   Available: 13575023
Inodes: Total: 5242880    Free: 4960133
483 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/path2.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627669   Available: 13575023
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:44.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* Created at Thu Jun 22 04:14:19 2000 */
#undef CITY
#define CITY "/d/dist/pumpkin/"
#define CITYROOM (CITY "inherit/cityroom")
#define RABBIT CITY + "rabbit/"
#define STABLE CITY + "stable/"
#define PUMPKIN CITY + "pumpkin/"
#define GUMBOOT CITY + "gumboot/"
#define FRUITBAT CITY + "fruitbat/"
#define STABLE CITY + "stable/"
#define CRUMPT CITY + "crumpt/"
#define PLAIN CITY + "plain/"
#define PLAIN CITY + "plain/"
#define SQUASH CITY + "squash/"
#define PLAIN CITY + "plain/"
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/path2.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/crumpt/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/crumpt/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627666   Available: 13575020
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/crumpt/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627666   Available: 13575020
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:44.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/crumpt/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/inherit/hospital.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/inherit/hospital.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627661   Available: 13575015
Inodes: Total: 5242880    Free: 4960133
252 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/inherit/hospital.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627661   Available: 13575015
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is roughly based on Jeremy's Sur hospital.
 */

class npc_info {
    string base;
    function *functions;
}

class npc_group {
    mixed npc;
    function quantity;
    function population;
    function *functions;
    object *storage;
}

// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/inherit/hospital.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/inherit/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/inherit/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627655   Available: 13575009
Inodes: Total: 5242880    Free: 4960133
21 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/inherit/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627655   Available: 13575009
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/inherit/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/gumboot/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/gumboot/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627655   Available: 13575009
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/gumboot/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627655   Available: 13575009
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/gumboot/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/plain/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/plain/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627652   Available: 13575006
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/plain/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627652   Available: 13575006
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/plain/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/desert/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/desert/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627650   Available: 13575004
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/desert/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627650   Available: 13575004
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/desert/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/rabbit/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/rabbit/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627644   Available: 13574998
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/rabbit/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627644   Available: 13574998
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/rabbit/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627636   Available: 13574990
Inodes: Total: 5242880    Free: 4960133
688 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627636   Available: 13574990
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* Created at Thu Jun 22 04:14:19 2000 */
#undef CITY
#define CITY "/d/dist/pumpkin/"
#define CITYROOM (CITY "inherit/cityroom")
#define RABBIT CITY + "rabbit/"
#define STABLE CITY + "stable/"
#define PUMPKIN CITY + "pumpkin/"
#define GUMBOOT CITY + "gumboot/"
#define FRUITBAT CITY + "fruitbat/"
#define STABLE CITY + "stable/"
#define CRUMPT CITY + "crumpt/"
#define PLAIN CITY + "plain/"
#define DESERT CITY + "desert/"
#define SQUASH CITY + "squash/"
#define WOODS CITY + "woods/"
#define HOSPITAL (CITY "hospital")
#define HOSPITAL_INC (CITY "handler/hostpial.h")
#define SAVE CITY + "save/"
#define CHARS (CITY + "chars/")
#define TERRAIN_HANDLER (CITY + "terrain/terrain_handler")
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/woods/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/woods/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627636   Available: 13574990
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/woods/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627636   Available: 13574990
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/woods/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/squash/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/squash/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627626   Available: 13574980
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/squash/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627626   Available: 13574980
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/squash/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/terrain/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/terrain/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627624   Available: 13574978
Inodes: Total: 5242880    Free: 4960133
21 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/terrain/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627624   Available: 13574978
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/terrain/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/pumpkin/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/pumpkin/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627616   Available: 13574970
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/pumpkin/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627616   Available: 13574970
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:44.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/pumpkin/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/chars/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/chars/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627612   Available: 13574966
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/chars/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627612   Available: 13574966
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/chars/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/dist/pumpkin/fruitbat/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/fruitbat/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627611   Available: 13574965
Inodes: Total: 5242880    Free: 4960133
54 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/dist/pumpkin/fruitbat/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627611   Available: 13574965
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include "../path.h"
#undef PATH
#define PATH __DIR__
// --- END [/mnt/home2/grok/lib/d/dist/pumpkin/fruitbat/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/admin/room/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/admin/room/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627604   Available: 13574958
Inodes: Total: 5242880    Free: 4960133
30 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/admin/room/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627604   Available: 13574958
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define ROOM "/d/admin/room/"
// --- END [/mnt/home2/grok/lib/d/admin/room/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/admin/room/we_care/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/admin/room/we_care/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627596   Available: 13574950
Inodes: Total: 5242880    Free: 4960133
64 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/admin/room/we_care/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627596   Available: 13574950
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define CONTROLLER "/d/admin/room/we_care/club_room_controller"
// --- END [/mnt/home2/grok/lib/d/admin/room/we_care/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/admin/obj/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/admin/obj/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627588   Available: 13574942
Inodes: Total: 5242880    Free: 4960133
17 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/admin/obj/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627588   Available: 13574942
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:45.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/* dummy file */
// --- END [/mnt/home2/grok/lib/d/admin/obj/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/d/liaison/NEWBIE/path.h] ---
// Size:   File: "/mnt/home2/grok/lib/d/liaison/NEWBIE/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627553   Available: 13574907
Inodes: Total: 5242880    Free: 4960133
662 bytes, Last Modified:   File: "/mnt/home2/grok/lib/d/liaison/NEWBIE/path.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627553   Available: 13574907
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:46.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: path.h,v 1.2 2000/06/23 19:25:50 pinkfish Exp $
 *
 * $Log: path.h,v $
 * Revision 1.2  2000/06/23 19:25:50  pinkfish
 * Remove bits for the distribution lib.
 *
 * Revision 1.1  2000/03/01 06:06:59  ceres
 * Initial revision
 *
 * Revision 1.2  1998/09/09 12:35:27  aragorn
 * Changed Fighters to Warriors
 *
 * Revision 1.1  1998/01/16 02:19:20  arby
 * Initial revision
 *
*/
#define PATH "/d/liaison/NEWBIE/"
#ifdef __DISTRIBUTION_LIB__
#define GUILDS "None currently"
#else
#define GUILDS "Witches, Wizards, Warriors, Priests, Thieves, and Assassins"
#endif

#define SIGN_WIDTH 67

#define FOYER (PATH+"foyer")
// --- END [/mnt/home2/grok/lib/d/liaison/NEWBIE/path.h] ---
// --- BEGIN [/mnt/home2/grok/lib/global/parser.h] ---
// Size:   File: "/mnt/home2/grok/lib/global/parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627386   Available: 13574740
Inodes: Total: 5242880    Free: 4960133
66 bytes, Last Modified:   File: "/mnt/home2/grok/lib/global/parser.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627386   Available: 13574740
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define TOKENISER "/obj/handlers/tokeniser"
#include "tokenise.h"
// --- END [/mnt/home2/grok/lib/global/parser.h] ---
// --- BEGIN [/mnt/home2/grok/lib/global/virtual/compiler.h] ---
// Size:   File: "/mnt/home2/grok/lib/global/virtual/compiler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627379   Available: 13574733
Inodes: Total: 5242880    Free: 4960133
7021 bytes, Last Modified:   File: "/mnt/home2/grok/lib/global/virtual/compiler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627379   Available: 13574733
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define TMP_FILE "/global/virtual/tmp_file.c"

#define O_FUN ([ "item"  : "add_item",\
                 "name"  : "set_name",\
                 "long"  : "set_long",\
                 "light" : "set_light",\
                 "alias" : "add_alias",\
                 "plural" : "add_plural",\
                 "adjective" : "add_adjective",\
                 "plural adjective" : "add_plural_adjective",\
                 "main_plural" : "set_main_plural",\
                 "main plural" : "set_main_plural",\
                 "weight" : "set_weight",\
                 "length" : "set_length",\
                 "width" : "set_width",\
                 "value" : "set_value",\
                 "value info" : "set_value_info", \
                 "material" : "set_material", \
                 "property" : "add_property",\
                 "clone" : ({ "do_clone", file_name(this_object()) }), \
                 "money" : "adjust_money",\
                 "effect" : "add_effect",\
                 "read mess" : "add_read_mess", \
                 "short" : "set_short" ])

#define R_FUN ([ "exit" : "add_exit",\
                 "modify exit" : "modify_exit",\
                 "reset" : "add_reset_item",\
                 "dark mess" :  "set_dark_mess",\
                 "co ord" : "set_co_ord", \
                 "size" : "set_room_size", \
                 "zone" : "set_zone", \
                 "cloned object" : "add_cloned_object", \
                 "alias" : "add_alias", \
                 "sign" : "add_sign" ])

#define ARM_FUN ([ "setup" : "setup_armour",\
                   "no limbs" : "set_no_limbs", \
                   "condition" : "set_cond", \
                   "enchant" : "set_enchant", \
                   "ac" : "add_ac", \
                   "max condition" : "set_max_cond", \
                   "immune" : "add_immune_to", \
                   "type" : "set_type", \
                   "wear remove" : "set_wear_remove_func", \
                   "wear effect" : "add_wear_effect", \
                   "dex minus" : "set_dex_minus", \
                   "damage chance" : "set_damage_chance" ])

#define CLO_FUN ([ "setup" : "setup_clothing",\
                   "condition" : "set_cond", \
                   "enchant" : "set_enchant", \
                   "max condition" : "set_max_cond", \
                   "immune" : "add_immune_to", \
                   "type" : "set_type", \
                   "wear remove" : "set_wear_remove_func", \
                   "wear effect" : "add_wear_effect", \
                   "dex minus" : "set_dex_minus", \
                   "pocket mess" : "set_pocket_mess", \
                   "pocket" : "add_pocket", \
                   "stuck" : "set_stuck", \
                   "key" : "set_key", \
                   "damage chance" : "set_damage_chance", \
                   "pair" : "set_is_pair" ])

#define CLOTRANS_FUN ([ \
                   "race" : "set_worn_by_race", \
                   "mount modifier" : "set_mount_difficulty_modifier", \
                   "direction modifier" : "set_direction_difficulty_modifier", \
                 ])

#define SCA_FUN ([ "setup" : "setup_scabbard",\
                   "condition" : "set_cond", \
                   "enchant" : "set_enchant", \
                   "max condition" : "set_max_cond", \
                   "immune" : "add_immune_to", \
                   "type" : "set_type", \
                   "wear remove" : "set_wear_remove_func", \
                   "wear effect" : "add_wear_effect", \
                   "dex minus" : "set_dex_minus", \
                   "types" : "set_types", \
                   "damage chance" : "set_damage_chance" ])

#define CONT_FUN ([ \
                    "amount" : "set_amount", \
                    "continuous" : "set_continuous", \
                    "weight unit" : "set_weight_unit", \
                    "medium alias" : "set_medium_alias", \
                    "pile name" : "set_pile_name", \
                    "amount types" : "set_amount_types", \
                    "pile types" : "set_pile_types", \
                  ])

#define FOOD_FUN ([ \
                    "bites gone" : "set_bites_gone", \
                    "weight per bite" : "set_weight_per_bite", \
                    "eat mess" : "set_eat_mess", \
                    "eat effects" : "add_eat_effect", \
                    "piece description" : "set_piece_description", \
                  ])

#define WEP_FUN ([ "setup" : "new_weapon",\
                   "condition" : "set_condition", \
                   "enchant" : "set_enchant", \
                   "attack" : "add_attack", \
                   "max condition" : "set_max_cond", \
                   "immune" : "add_immune", \
                   "no limbs" : "set_no_limbs", \
                   "attack message" : "add_attack_message", \
                   "damage chance" : "set_damage_chance" ])

#define MON_FUN ([ "move after" : "set_move_after", \
                   "move zone" : "add_move_zone", \
                   "race" : "set_race", \
                   "class" : "set_class", \
                   "guild" : "set_guild", \
                   "level" : "set_level", \
                   "attack" : "add_attack", \
                   "attack message" : "add_attack_message", \
                   "ac" : "add_ac", \
                   "skill" : "add_skill_level", \
                   "equip" : "init_equip", \
                   "remove ac" : "remove_ac", \
                   "remove attack" : "remove_attack", \
                   "attack everyone" : "set_attack_everyone", \
                   "random stats" : "set_random_stats", \
                   "money" : "give_money", \
                   "chat" : "add_chat_string", \
                   "chat chance" : "set_chat_chance", \
                   "achat" : "add_achat_string", \
                   "achat chance" : "set_achat_chance", \
                   "talk string" : "add_talk_string", \
                   "join fights" : "set_join_fights", \
                   "alignment" : "set_al", \
                   "follow speed" : "set_follow_speed", \
                   "aggressive" : "set_aggressive", \
                   "str" : "set_str", \
                   "con" : "set_con", \
                   "dex" : "set_dex", \
                   "wis" : "set_wis", \
                   "bonus int" : "set_bonus_int", \
                   "bonus str" : "set_bonus_str", \
                   "bonus con" : "set_bonus_con", \
                   "bonus dex" : "set_bonus_dex", \
                   "bonus wis" : "set_bonus_wis", \
                   "int" : "set_int", \
                   "gender" : "set_gender", \
                   "command" : "add_known_command", \
                   "concentrate" : "set_concentrate", \
                   "protect" : "do_protect", \
                   "follow" : "do_follow", \
                   "throw out" : "set_throw_out", \
                   "basic setup" : "basic_setup" ])
// --- END [/mnt/home2/grok/lib/global/virtual/compiler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/global/virtual/virtual.h] ---
// Size:   File: "/mnt/home2/grok/lib/global/virtual/virtual.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627377   Available: 13574731
Inodes: Total: 5242880    Free: 4960133
97 bytes, Last Modified:   File: "/mnt/home2/grok/lib/global/virtual/virtual.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627377   Available: 13574731
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#include <virtual.h>

#define SERVER "/global/virtual/server"

#define LOAD   1
#define CLONE  2
// --- END [/mnt/home2/grok/lib/global/virtual/virtual.h] ---
// --- BEGIN [/mnt/home2/grok/lib/global/virtual/setup_compiler/VirtualRoom.h] ---
// Size:   File: "/mnt/home2/grok/lib/global/virtual/setup_compiler/VirtualRoom.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627376   Available: 13574730
Inodes: Total: 5242880    Free: 4960133
1719 bytes, Last Modified:   File: "/mnt/home2/grok/lib/global/virtual/setup_compiler/VirtualRoom.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627376   Available: 13574730
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define CLONEFILE "/global/virtual/setup_compiler/Room.c"

mixed add_item(mixed a1, mixed a2)
 { MyRoom->add_item(a1,a2); }

mixed set_name(mixed a1)
 { MyRoom->set_name(a1); }

mixed set_long(mixed a1)
 { MyRoom->set_long(a1); }

mixed set_light(mixed a1)
 { MyRoom->set_light(a1); }

mixed add_property(mixed a1, mixed a2)
 { MyRoom->add_property(a1,a2); }

mixed set_short(mixed a1)
 { MyRoom->set_short(a1); }

mixed add_exit(string a1, string a2, string a3)
{
	if( file_size(a2) > 0 )
		{ MyRoom->add_exit(a1,a2,a3); return; }
	if( file_size(a2+".c") > 0 )
		{ MyRoom->add_exit(a1,a2+".c",a3); return ; }
	if( file_size(a2+".vrc") > 0 )
		{ MyRoom->add_exit(a1,a2+".vrc",a3); return; }
	if( file_size(a2+".r") > 0 )
		{ MyRoom->add_exit(a1,a2+".r",a3); return; }
	write("Error: Bad arg 2 to add_exit in virtual room");
	return;
}

mixed modify_exit(string m1, mixed *m2)
 { MyRoom->modify_exit(m1,m2); }

mixed set_dark_mess(mixed a1)
 { MyRoom->set_dark_mess(a1); }

mixed set_co_ord(mixed a1)
 { MyRoom->set_co_ord(a1); }

mixed set_zone(mixed a1)
 { MyRoom->set_zone(a1); }

/************** Virtual Room Functions Not found in /std/room.c **********/

void add_reset_func( mixed ob, string func )
{
  MyRoom->add_reset_func( ob, func );
}
void add_dest_func( mixed ob, string func )
{
  MyRoom->add_dest_func( ob, func );
}
void add_enter_func( mixed ob, string func )
{
  MyRoom->add_enter_func( ob, func );
}
void add_exit_func( mixed ob, string func )
{
  MyRoom->add_exit_func( ob, func );
}
void add_death_func( mixed ob, string func )
{
  MyRoom->add_death_func( ob, func );
}

void add_clone_on_reset( string fname )
{
  MyRoom->add_clone_on_reset( fname );
}


#include "/w/mithal/UTIL/use_comments.h"

// --- END [/mnt/home2/grok/lib/global/virtual/setup_compiler/VirtualRoom.h] ---
// --- BEGIN [/mnt/home2/grok/lib/global/virtual/setup_compiler/SetupCompiler.h] ---
// Size:   File: "/mnt/home2/grok/lib/global/virtual/setup_compiler/SetupCompiler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627376   Available: 13574730
Inodes: Total: 5242880    Free: 4960133
365 bytes, Last Modified:   File: "/mnt/home2/grok/lib/global/virtual/setup_compiler/SetupCompiler.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14627376   Available: 13574730
Inodes: Total: 5242880    Free: 4960133
2006-10-07 20:59:52.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
#define TMP_FILE "/global/virtual/tmp_file.c"
#define SERVER "/global/virtual/server"
#define PATH  "/global/virtual/setup_compiler/"
#define ROOMFUNCS  "VirtualRoom.h"
#define WEP_FUNCS  "VirtualWeapon.h"
#define OBJ_FUNCS  "VirtualObject.h"
#define ARM_FUNCS  "VirtualArmour.h"
#define MON_FUNCS  "VritualMonster.h"
/* These function must #define CLONEFILE */



// --- END [/mnt/home2/grok/lib/global/virtual/setup_compiler/SetupCompiler.h] ---
// --- BEGIN [/mnt/home2/grok/lib/w/pinkfish/card_base.h] ---
// Size:   File: "/mnt/home2/grok/lib/w/pinkfish/card_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14626702   Available: 13574056
Inodes: Total: 5242880    Free: 4960132
1233 bytes, Last Modified:   File: "/mnt/home2/grok/lib/w/pinkfish/card_base.h"
    ID: 110ccfcf38e7e640 Namelen: 255     Type: ext2/ext3
Block size: 4096       Fundamental block size: 4096
Blocks: Total: 20496486   Free: 14626702   Available: 13574056
Inodes: Total: 5242880    Free: 4960132
2006-10-07 21:00:03.000000000 +0000
// Note: To be updated for FluffOS v2019+ with Forgotten Realms theming
/**
 * This is a base to make up randomised decks of cards.
 * @author Pinkfish
 * @started Thu Dec  7 07:34:10 PST 2000
 */
#ifndef __CARD_BASE_H
/** @ignore yes */
#define __CARD_BASE_H

/** The suit define for hearts. */
#define CARD_SUIT_HEARTS   1
/** The suit define for diamonds. */
#define CARD_SUIT_DIAMONDS 2
/** The suit define for clubs. */
#define CARD_SUIT_CLUBS    3
/** The suit define for spades. */
#define CARD_SUIT_SPADES   4
/** The suit define for jokers. */
#define CARD_SUIT_JOKER    5

/** The number for a jack. */
#define CARD_NUMBER_JACK    11
/** The number for a jack. */
#define CARD_NUMBER_QUEEN   12
/** The number for a jack. */
#define CARD_NUMBER_KING    13

/** When generating a hand this makes a 3x3 card. */
#define CARD_HAND_THREE         1
/** When generating a hand this makes a 3x1 card. */
#define CARD_HAND_SINGLE        2
/** When generating a hand this makes a 2x2 card. */
#define CARD_HAND_TWO           4
/** When generating a hand, this leaves off all the frilly bits. */
#define CARD_HAND_NO_ADORNMENTS 8

/**
 * The playing card class.
 * @element suit the suit of the card
 * @element number the number of the card
 */
class playing_card {
   int suit;
   int number;
}

#endif
// --- END [/mnt/home2/grok/lib/w/pinkfish/card_base.h] ---
