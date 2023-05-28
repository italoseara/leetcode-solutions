// https://leetcode.com/problems/longest-common-prefix/

#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    int index = 0;
    char *prefix = malloc(200 * sizeof(char));

    while (1)
    {
        for (int i = 0; i < strsSize; i++)
        {
            if (strs[i][index] == '\0' || strs[i][index] != strs[0][index])
            {
                prefix[index] = '\0';
                return prefix;
            }
        }

        prefix[index++] = strs[0][index];
    }

    return NULL;
}
