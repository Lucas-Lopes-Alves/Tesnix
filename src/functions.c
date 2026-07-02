#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "functions.h"
#include "terminal.h"

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

// char* kstrcat(char* str1,char* str2)
// {
    
// }