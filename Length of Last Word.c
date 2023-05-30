// https://leetcode.com/problems/length-of-last-word/

#include <string.h>

int lengthOfLastWord(char *s)
{
    int result = 0;

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (result == 0)
                continue;
            break;
        }

        result++;
    }

    return result;
}