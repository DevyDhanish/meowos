#include "idt.h"
#include "stdint.h"
#include "stdio.h"

IDTENTRY interupt_1 = 
{
    
};

IDTDESCRIPTOR idt_desc;
IDTENTRY idt_en[256];

void idt_init()
{
    
}