// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <strings.h>
#include <stdbool.h>

int strStr(char *haystack, char *needle)
{
    int needleLen = strlen(needle);
    int hayLen = strlen(haystack);

    for (int i = 0; i < hayLen - needleLen + 1; i++)
    {
        bool isInside = true;
        for (int j = 0; j < needleLen; j++)
        {
            if (haystack[i + j] != needle[j])
                isInside = false;
        }

        if (isInside)
            return i;
    }

    return -1;
}