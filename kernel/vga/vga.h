#ifndef VGA_H
#define VGA_H

#include "../stdint.h"
#include "vga_colors.h"

#define VGA_HEIGHT 25
#define VGA_WIDTH  80
#define VGA_BUFFER_SIZE VGA_HEIGHT * VGA_WIDTH

#define DEFAULT_BGFG_COLOR BG_WHITE_FG_BLACK

struct VGA_CHLOR
{
    char CHAR;
    uint8 COLOR;
};

void clearBuffer();
void fillBuffer(struct VGA_CHLOR *);
uint8 writeToBuffer(struct VGA_CHLOR *);
void cursorToNewline();

#endif 