#include "../io.h"

int help_init() {
    kprints("COMMANDS:\n");
    kprints("[GENERAL]\n");
    kprints("help           prints this message\n");
    kprints("echo           prints {} to the display\n");
    kprints("wipe           cleans screen\n");
    kprints("exit           exit kernel shell\n");
    kprints("[RANDOM]\n");
    kprints("fortune        digital fortune cookie\n")
    kprints("[SYSTEM INFO]\n");
    kprints("version        get kernel version\n");
    kprints("neofetch       show info about your system\n");
    kprints("[THEMES]\n");
    kprints("theme-blue     changes the theme to white on blue\n");
    kprints("theme-cyan     changes the theme to white on cyan\n");
    kprints("theme-gray     changes the theme to gray on black\n");
    kprints("theme-default  changes the theme back to default\n");
    kprints("[SYSTEM]\n");
    kprints("memstat        get allocated memory usage\n");
    kprints("memtest        allocate memory for test\n");
    kprints("random         get random number between 0-100\n");
    kprints("panic          invoke debug kernel panic\n");  
    kprints("[FILE_SYSTEM]\n");
    kprints("ls             list all files\n");
    kprints("mk             create new file\n");
    kprints("rm             delete file\n");
    kprints("in             read file content\n");
}
