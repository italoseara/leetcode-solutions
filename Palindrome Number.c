// https://leetcode.com/problems/palindrome-number/

#include <stdbool.h>

bool isPalindrome(int x)
{
    long y = 0;
    int z = x;

    while (z > 0)
    {
        y *= 10;
        y += z % 10;
        z /= 10;
    }

    return x == y;
}
