#include "vga/vga.h"
#include "stdio.h"
#include "stddefs.h"
#include "gdt.h"
#include "idt.h"

void main()
{
    struct VGA_CHLOR bg;
    bg.CHAR = ' ';
    bg.COLOR = BG_WHITE_FG_BLACK;
    clearBuffer();
    fillBuffer(&bg);

    // code from here
    
    gdt_init();
    idt_init();

    float x = 10 / 0;


    string msg = "Kernel is happy :)\n";
    printf(STRING, msg);
}