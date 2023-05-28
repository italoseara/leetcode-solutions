// https://leetcode.com/problems/valid-palindrome/

#include <stdbool.h>
#include <ctype.h>
#include <strings.h>

bool isPalindrome(char *s)
{
    int len = strlen(s);
    int i = 0, j = len - 1;

    while (i + 1 <= j)
    {
        while (i < len && !isalnum(s[i]))
            i++;
        while (j >= 0 && !isalnum(s[j]))
            j--;

        if (i >= len || j < 0)
            break;

        if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }

    return true;
}