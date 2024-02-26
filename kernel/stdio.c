#include "stdio.h"
#include "stdint.h"
#include "utils.h"
#include "stddefs.h"
#include "vga/vga.h"

uint8 printf(enum DATA_TYPES dt, void *data)
{
    switch (dt)
    {
    case STRING:
    {
        string data_to_write = (string) data;
        struct VGA_CHLOR write_chlor;
        write_chlor.COLOR = BG_WHITE_FG_BLACK;
    
        while(*data_to_write != '\0')
        {
            if(*data_to_write == '\n')
            {
                cursorToNewline();
            }
            else
            {
                write_chlor.CHAR = *data_to_write;
                writeToBuffer(&write_chlor);
            }
            data_to_write += 1;
        }
        break;
    }
    case INT:
    {
        char buffer[100];
        int ndata = *(int *)data;
        itos(ndata, &buffer, 100);
        printf(STRING, &buffer);
        break;
    }

    case CHAR:
    {
        char cdata = *(char *)data;
        struct VGA_CHLOR write_chlor;
        write_chlor.COLOR = BG_WHITE_FG_BLACK;
        write_chlor.CHAR = cdata;
        writeToBuffer(&write_chlor);
        break;
    }

    case FLOAT:
    {
        float ori = *((float *)data);

        int bpoint = ori;
        int apoint = ori * 1000 - bpoint * 1000;
        char point = '.';

        if(apoint < 0) { apoint = apoint * -1; }

        printf(INT, &bpoint);
        printf(CHAR, &point);
        printf(INT, &apoint);

        break;
    }
    
    default:
        break;
    }
}