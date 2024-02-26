#include "vga.h"
#include "../stdint.h"
#include "vga_colors.h"

struct VGA_CHLOR *VGA_CHAR_BUFFER = (struct VGA_CHLOR *)0xb8000;
uint32  VGA_INDEX = 0;

void inc_vga_index()
{
    VGA_INDEX += 1;
}

void dec_vga_index()
{
    VGA_INDEX -= 1;
}

void clearBuffer()
{
    struct VGA_CHLOR clear_chlor;
    clear_chlor.CHAR = ' ';
    clear_chlor.COLOR = DEFAULT_BGFG_COLOR;

    VGA_INDEX = 0;

    for(VGA_INDEX; VGA_INDEX < VGA_BUFFER_SIZE; inc_vga_index())
    {
        VGA_CHAR_BUFFER[VGA_INDEX] = clear_chlor;
    }

    VGA_INDEX = 0;
}

void fillBuffer(struct VGA_CHLOR *fill_chlor)
{
    for(VGA_INDEX; VGA_INDEX < VGA_BUFFER_SIZE; inc_vga_index())
    {
        VGA_CHAR_BUFFER[VGA_INDEX] = *fill_chlor;
    }

    VGA_INDEX = 0;
}

uint8 writeToBuffer(struct VGA_CHLOR *write_chlor)
{
    if(VGA_INDEX > VGA_BUFFER_SIZE)
    {
        return 1;
    }

    VGA_CHAR_BUFFER[VGA_INDEX] = *write_chlor;

    inc_vga_index();

    return 0;
}

void cursorToNewline()
{
    VGA_INDEX = (VGA_INDEX / VGA_WIDTH + 1) * VGA_WIDTH;
}