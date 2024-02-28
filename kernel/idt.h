#ifndef IDT_H
#define IDT_H

#include "stdint.h"

typedef struct IDT_ENTRY
{
    uint16 offsetlow;
    uint16 segmentselector;
    uint8 reserved;
    uint8 attributes;
    uint16 offsethigh;
} __attribute__((packed)) IDTENTRY;

typedef struct IDT_DESCRIPTOR
{
    uint16 size;
    uint32 offset;
} __attribute__((packed)) IDTDESCRIPTOR;

extern void load_idt(IDTDESCRIPTOR *idtdescriptor);
void idt_set_descriptor(uint8 vector, void *isr, uint8 flags);
void idt_init();

#endif