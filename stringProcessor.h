#ifndef STRING_PROCESSOR
#define STRING_PROCESSOR
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include "sort.h"
#define STRING_MAX 512ull

const int32_t get_str(const char const* msg, char* str, const int32_t limit)
{
    printf("%s", msg);
    fgets(str, limit, stdin);
    return 1;
}

const size_t strlenn(const char* str)
{
    size_t len = 0;
    while (str && str[len] != '\0')
    {
        len++;
    }
    return len;
}

void strcopy(char* fStr, const char* sStr, size_t until)
{
    size_t i = 0;
    for (i = 0; i < until && sStr[i] != '\0'; i++)
    {
        fStr[i] = sStr[i];
    }
    fStr[i] = '\0';
}

int32_t strcmpp(const char* fStr, const char* sStr)
{
    while (*fStr && (*fStr == *sStr))
    {
        fStr++;
        sStr++;
    }
    return *(const unsigned char*)fStr - *(const unsigned char*)sStr;
}

char* strcatt(char* fStr, const char* sStr)
{
    char* ptr = fStr + strlenn(fStr);
    while (*sStr != '\0')
    {
        *ptr++ = *sStr++;
    }
    *ptr = '\0';
    return fStr;
}

bool is_string_valid(char* str)
{
    bool isThereString = false;
    bool isThereColon = false;
    const size_t size = strlenn(str);
    for (size_t i = 0; i < size; i++)
    {
        if ((str[i] == ':' || str[i] == ';' || str[i] == ',') && i == 0ull)
        {
            return false;
        }
        if (str[i] == ':')
        {
            isThereColon = true;
        }
        else if (isThereColon)
        {
            if (str[i] == ',')
            {
                if (!isalpha(str[i - 1ull]) && str[i - 1ull] != ' ')
                {
                    return false;
                }
                else
                {
                    isThereString = true;
                }
            }
            if (str[i] == ';')
            {
                if (!isThereString || (!isalpha(str[i - 1ull]) && str[i - 1ull] != ' '))
                {
                    return false;
                }
                else
                {
                    isThereColon = false;
                }
            }
            if (str[i] == ':')
            {
                return false;
            }
        }
        else
        {
            isThereString = false;
        }
    }
    return true;
}

char* process_string(char* str); 

#endif