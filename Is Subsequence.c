// https://leetcode.com/problems/is-subsequence/

#include <stdbool.h>
#include <strings.h>

bool isSubsequence(char *s, char *t)
{
    if (strlen(s) > strlen(t))
        return false;

    for (int i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (t[j] == '\0')
            return false;

        for (; t[j] != '\0'; j++)
        {
            if (t[j] == s[i])
            {
                j++;
                break;
            }

            if (t[j + 1] == '\0')
                return false;
        }
    }

    return true;
}