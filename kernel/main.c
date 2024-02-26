#include "vga/vga.h"
#include "stdio.h"
#include "stddefs.h"
#include "gdt.h"

void main()
{
    struct VGA_CHLOR bg;
    bg.CHAR = ' ';
    bg.COLOR = BG_WHITE_FG_BLACK;
    clearBuffer();
    fillBuffer(&bg);

    // code from here
    
    gdt_init();

    string msg = "\nEverything is working\n";
    printf(STRING, msg);
}