#ifndef GDT_H
#define GDT_H

#include "stdint.h"

typedef struct GDT_ENTRY
{
    uint16 limit;
    uint16 base;
    uint8 base2;
    uint8 access;
    uint8 flag_limit;
    uint8 base3;
}__attribute__ ((packed)) GDTENTRY;


typedef struct GDT_DISCRIPTOR
{
    uint16 size;
    uint32 offset;
} __attribute__ ((packed)) GDTDISCRIPTOR;

extern load_gdt(GDTDISCRIPTOR *gdt_desc);

void gdt_init();

#endif