// https://leetcode.com/problems/word-pattern/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool wordPattern(char *pattern, char *s)
{
    int sLen = strlen(s);
    int patternLen = strlen(pattern);

    // A map to store the pattern coresponding words
    char *map[26] = {};

    // Loop through the string
    int j = 0;
    for (int i = 0, k = 0;; i++)
    {
        // The worst case is there is only one word in the string
        char word[sLen + 1];

        // If the word ended
        if (s[i] == ' ' || s[i] == '\0')
        {
            word[k++] = '\0'; // Add the \0 to end the string

            // If the pattern ended but there is still words, returns false
            if (j > patternLen - 1)
                return false;
            
            // If there is no word assigned to the pattern letter
            if (map[pattern[j] - 'a'] == NULL)
            {
                // Check if there is another key with this word
                for (int l = 0; l < 26; l++)
                    if (l != pattern[j] - 'a' && map[l] != NULL && strcmp(map[l], word) == 0)
                        return false;

                // If there isn't any, alloc memory for the word in the map and copy the word to it
                map[pattern[j] - 'a'] = malloc(k * sizeof(char));
                strcpy(map[pattern[j] - 'a'], word);
            }

            // If the word in the map is not the same, the pattern doesn't match
            else if (strcmp(map[pattern[j] - 'a'], word) != 0)
                return false;

            // Reset the word pointer to the begining
            j++;
            k = 0;
        }

        // Exit the loop because the string ended
        if (s[i] == '\0')
            break;

        // Updated word
        if (s[i] != ' ')
            word[k++] = s[i];
    }

    // If still there is pattern left, and the string ended, return false
    if (j < patternLen)
        return false;

    return true;
}
