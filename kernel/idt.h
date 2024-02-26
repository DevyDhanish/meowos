#ifndef IDT_H
#define IDT_H

#include "stdint.h"

typedef struct IDT_ENTRY
{
    uint16 offsetlow;
    uint16 segmentselector;
    uint8 reserved;
    uint8 gatedpl;
    uint32 offsethigh;
} IDTENTRY;

typedef struct IDT_DESCRIPTOR
{
    uint16 size;
    uint32 offset;
} IDTDESCRIPTOR;

extern void load_idt(IDTDESCRIPTOR *idtdescriptor);

void idt_init();

#endif