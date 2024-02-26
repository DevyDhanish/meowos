#include "utils.h"
#include "stddefs.h"
#include "stdio.h"

char itoc(int number)
{
    if(number < 0) { number = number * -1; }

    switch (number)
    {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        default: return ' ';
    }
}

void stoi(string number_array)
{

}

void itos(int number, string buffer, int buf_len)
{
    char work_buffer[100];
    uint8 flag = (number < 0);

    if(number >= 0 && number <= 9)
    {
        // one digit positive number
        buffer[0] = itoc(number);
        buffer[1] = '\0';

        return;
    }

    if(number < 0 && number >= -9)
    {
        // one digit negative number
        buffer[0] = '-';
        buffer[1] = itoc(number);
        buffer[2] = '\0';

        return;
    }

    int i = 0;
    while (number)
    {
        int ld = number % 10;
        work_buffer[i] = itoc(ld);
        number = number / 10;
        i++;
    }

    int count = i;
    i--;
    int j = 0;

    if(flag){ buffer[j] = '-';j++; }

    for(; j <= count; j++, i--)
    {
        buffer[j] = work_buffer[i];
    }
    
    j++;
    buffer[j] = '\0';
}