#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "functions.h"

size_t kstrlen(const char *str)
{
    size_t size = 0;
    while (str[size])
    {
        size++;
    }
    return size;
}

size_t kstrcmp(const char* str1, const char* str2)
{
    while(*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char) *str2;
}

void toStr(size_t v, char* buffer)
{
    if (v == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    size_t digits = 1;
    size_t temp = v;
    while (temp >= 10) {
        temp /= 10;
        digits++;
    }
    buffer[digits] = '\0';
    do
    {
        buffer[--digits] = (v % 10) + '0';
        v /= 10;
    } while(v != 0);
}

// char* kstrcat(char* str1,char* str2)
// {

// }
