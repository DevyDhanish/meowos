#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t x = 0x12bd13ac;

    uint16_t low = x & 0x0000ffff;
    uint16_t hight = (x>>16);

    printf("%x\n", low);
    printf("%x\n", hight);

    return 0;
}