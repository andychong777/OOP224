/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (Part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor 
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
using namespace std;

namespace sdds
{
    // Copies the source character string into the destination
    void strCpy(char *des, const char *src)
    {
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char *des, const char *src, int len)
    {
        int i = 0;

        while (i < len && *src != '\0')
        {
            *des = *src;
            ++des;
            ++src;
            ++i;
        }
        while (i < len)
        {
            *des = '\0';
            ++des;
            ++i;
        }
    }

    // Compares two C-strings
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char *s1, const char *s2)
    {
        int result = 0;

        while (*s1 && *s2 && result == 0)
        {
            if (*s1 > *s2)
            {
                result = 1;
            }
            else if (*s1 < *s2)
            {
                result = -1;
            }

            s1++;
            s2++;
        }

        if (result == 0)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char *s1, const char *s2, int len)
    {
        int i, result = 0;

        for (i = 0; i < len && !result; i++)
        {
            if (s1[i] > s2[i])
            {
                result = 1;
            }
            else if (s1[i] < s2[i])
            {
                result = -1;
            }
        }

        return result;
    }

    // returns the lenght of the C-string in characters
    int strLen(const char *s)
    {
        int len = 0;

        while (*s != '\0')
        {
            len++;
            s++;
        }

        return len;
    }

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char *strStr(const char *str1, const char *str2)
    {

        if (*str2 == '\0')
        {
            return str1; // Empty str2, reuturn str1
        }

        while (*str1 != '\0')
        {
            const char *p1 = str1;
            const char *p2 = str2;

            while (*p1 == *p2 && *p1 != '\0')
            {
                ++p1;
                ++p2;
            }

            if (*p2 == '\0')
            {
                return str1;
            }
            ++str1;
        }
        return nullptr;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char *des, const char *src)
    {
        while (*des != '\0')
        {
            ++des; // Move to the end of des
        }

        while (*src != '\0')
        {
            *des = *src;
            ++des;
            ++src;
        }
        *des = '\0';
    }
}