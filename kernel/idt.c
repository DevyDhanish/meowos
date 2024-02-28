#include "idt.h"
#include "stdint.h"
#include "stdio.h"
#include "gdt.h"

extern void *isr_stub_table[];

IDTDESCRIPTOR idt_desc;

static IDTENTRY idt_en[256];

void idt_set_descriptor(uint8 vector, void *isr, uint8 flags)
{
    IDTENTRY *descriptor = &idt_en[vector];
    descriptor->offsetlow = (uint16)isr & 0xffff;
    descriptor->segmentselector = 0x08;
    descriptor->attributes = flags;
    descriptor->offsethigh = ((uint16)isr >> 16) & 0xffff;
    descriptor->reserved = 0;
}

void idt_init()
{
    idt_desc.size = sizeof(IDTENTRY) * 256 - 1;
    idt_desc.offset = (uint16)&idt_en;

    for(uint8 vector = 0; vector < 32; vector++)
    {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8e);
    }

    load_gdt(&idt_desc);
}
