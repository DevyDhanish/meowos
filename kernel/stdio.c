#include "stdio.h"
#include "stdint.h"
#include "stddefs.h"
#include "vga/vga.h"

uint8 printf(enum DATA_TYPES dt, void *data)
{
    switch (dt)
    {
    case STRING:

        string data_to_write = (string) data;
        struct VGA_CHLOR write_chlor;
        write_chlor.COLOR = BG_WHITE_FG_BLACK;
    
        while(*data_to_write != '\0')
        {
            write_chlor.CHAR = *data_to_write;
            writeToBuffer(&write_chlor);
            data_to_write += 1;
        }

        break;
    
    default:
        break;
    }
}