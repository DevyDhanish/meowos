#include "stdint.h"
#include "stdio.h"
#include "vga/vga.h"
#include "vga/vga_colors.h"

void execption_handler(void)
{
    string msg = "Kernel paniced, stoping execution.\n";
    string msg2 = "reboot now\n";

    struct VGA_CHLOR kpanic_color;
    kpanic_color.CHAR = ' ';
    kpanic_color.COLOR = 0x4c; 

    fillBuffer(&kpanic_color);
    printf(STRING, msg);
    printf(STRING, msg2);
    while (1){}
}