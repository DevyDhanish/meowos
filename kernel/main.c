#include "vga/vga.h"
#include "stdio.h"
#include "stddefs.h"

void main()
{
    struct VGA_CHLOR bg;
    bg.CHAR = ' ';
    bg.COLOR = BG_WHITE_FG_BLACK;

    clearBuffer();

    fillBuffer(&bg);

    string info = "welcome to meow operating system";
    printf(STRING, info);
}