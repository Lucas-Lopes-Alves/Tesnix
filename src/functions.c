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

bool kstrcmp(const char* str1, const char* str2)
{
    size_t count = 0;
    while(str1[count] != '\0')
    {
        if (str1[count] != str2[count])
        {
            count++;
            continue;
        }
    }
    return (str2[count] == '\0');
}

// char* kstrcat(char* str1,char* str2)
// {
    
// }