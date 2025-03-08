Subject: Team Assignment - Recoding Archaon MUD for FluffOS and Forgotten Realms Theme

Dear Team Groks,

You are part of the Archaon MUD development team, tasked with transforming the existing codebase (based on the live Discworld MUD at discworld.starturtle.net:4242) into a Forgotten Realms-themed MUD using FluffOS v2019+ as the driver. This message outlines your responsibilities, coding standards, and procedural guidelines to ensure consistency and professionalism.

#### Assignment Overview
- **Objective**: Recode and theme specific .c and .h files from the `/lib/` directory (repository: https://github.com/lbpoland/Archaon.git) to align with live Discworld mechanics while integrating Forgotten Realms lore (e.g., forgottenrealms.fandom.com, Dungeons & Dragons).
- **Priority**: Focus on major files and handlers (e.g., /secure/master.c, /global/player.c, /secure/login.c, /obj/handlers/player_handler.c) to enable thorough testing of player, object, and login creation.
- **Process**: Work one file at a time, assigned by the lead (me), testing each update before proceeding. Coordinate via the lead to avoid conflicts.

#### Technical Requirements
- **Driver**: Use FluffOS v2019+ (available at https://github.com/fluffos/fluffos). Compile with `./configure && make` in the driver directory, then run `./driver dw.cfg`.
- **Language**: LPC (Lars Pensjö C), a C-like scripting language for MUDs. Key features:
  - Object-oriented with `inherit`, `class`, and `mapping` structures.
  - Dynamic typing (e.g., `mixed` variables).
  - File I/O (e.g., `write_file`, `read_file`) and object manipulation (e.g., `clone_object`).
  - Modern FluffOS updates include JSON support (`json_encode`, `json_decode`) and enhanced error handling (`catch`).
- **Coding Standards**:
  - Use 4-space indentation, no tabs.
  - Include LPC headers (e.g., `<config.h>`, `<log.h>`) at the top.
  - Comment code with `//` or `/* */`, explaining logic and changes (e.g., "// Recoded for FluffOS compatibility").
  - Avoid deprecated constructs (e.g., `.o` file saves, `unguarded()` overuse).
  - Ensure cross-compatibility with Discworld’s live mechanics (cross-check with discworld.starturtle.net/lpc/playing/documentation.c and dwwiki.mooo.com).
- **Professionalism and Expertise**:
  - Write clean, maintainable code with error handling (e.g., `catch`, `notify_fail`).
  - Theme creatively (e.g., replace “Ankh-Morpork” with “Waterdeep”) while preserving functionality.
  - Test locally (e.g., `cd /mnt/home2/grok/driver && ./driver dw.cfg`) and log issues (e.g., `runtime`, `catch`, `error-log`).
  - Commit changes to the repo with descriptive messages (e.g., `git commit -m "Update /global/player.c with Forgotten Realms theming"`).

#### Task Execution
1. **Assignment**: The lead will assign you a specific file (e.g., `/global/player.c`). Check the repo for the current version.
2. **Analysis**:
   - Review the file’s purpose (e.g., `/global/player.c` handles player stats and commands).
   - Cross-reference with Discworld docs (e.g., `/helpdir/score`, `/concepts/stats`) and wiki (e.g., dwwiki.mooo.com/wiki/Stats).
3. **Modification**:
   - Update for FluffOS (e.g., replace `restore_object` with JSON saves).
   - Theme to Forgotten Realms (e.g., add deity allegiance from forgottenrealms.fandom.com).
   - Preserve Discworld mechanics unless outdated.
4. **Splitting Large Files**:
   - If a .c or .h file exceeds 500 LPC lines (counting code, excludes comments/blank lines), split it into logical modules (e.g., `/global/player_stats.c`, `/global/player_commands.c`) and update `inherit` statements.
5. **Testing and Submission**:
   - Save to `/mnt/home2/grok/lib/` (e.g., `/mnt/home2/grok/lib/global/player.c`).
   - Test with the driver, noting errors.
   - Push to the repo: `git add <file>; git commit -m "<message>"; git push`.
   - Report results to the lead.

#### Coordination
- Use the checklist (provided separately) to track progress.
- Await the lead’s next assignment after each file is approved.
- Collaborate via the lead to resolve conflicts or share insights.

#### Example
For `/global/player.c`:
- Add Forgotten Realms deity system (e.g., worship Mystra).
- Update `save()` to use JSON (e.g., `write_file("/save/players/" + name + ".json", json_encode(data))`).
- Test `score` command against `/helpdir/score`.

Let’s build an epic Forgotten Realms MUD together! Contact the lead with questions or completed files.

Best,
[Your Name/Lead Grok]
