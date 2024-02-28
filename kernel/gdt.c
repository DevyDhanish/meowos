#include "gdt.h"
#include "stdint.h"
#include "stdio.h"

GDTENTRY null_en = {
    .limit = 0,
    .base = 0,
    .base2 = 0,
    .access = 0,
    .flag_limit = 0,
    .base3 = 0
};

GDTENTRY code_en = {
    .limit = 0xffff,
    .base = 0,
    .base2 = 0,
    .access = 0b10011010,
    .flag_limit = 0b11001111,
    .base3 = 0,
};

GDTENTRY data_en = {
    .limit = 0xffff,
    .base = 0,
    .base2 = 0,
    .access = 0b10010010,
    .flag_limit = 0b11001111,
    .base3 = 0,
};

GDTENTRY gdt_en[3];
GDTDISCRIPTOR gdt_desc;

void gdt_init()
{
    gdt_en[0] = null_en;
    gdt_en[1] = code_en;
    gdt_en[2] = data_en;

    gdt_desc.size = sizeof(GDTENTRY) * 3 - 1;
    gdt_desc.offset = (uint32)&gdt_en;
    load_gdt(&gdt_desc);
}