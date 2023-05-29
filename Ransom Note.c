// https://leetcode.com/problems/ransom-note/

#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine)
{
    int map[26] = {}; // Count all the characters in the magazine

    for (int i = 0; magazine[i] != '\0'; i++)
    {
        map[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++)
    {
        if (map[ransomNote[i] - 'a'] > 0)
            map[ransomNote[i] - 'a']--;
        else
            return false;
    }

    return true;
}