// https://leetcode.com/problems/plus-one/

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *result = malloc((digitsSize + 1) * sizeof(int));

    int carry = 1;
    for (int i = digitsSize - 1; i >= -1; i--)
    {
        int num = carry;
        if (i != -1)
            num = digits[i] + carry;

        carry = 0;
        if (num == 10)
        {
            num = 0;
            carry = 1;
        }

        result[i + 1] = num;
    }

    if (result[0] == 0)
    {
        *returnSize = digitsSize;
        return &result[1];
    }
    else
    {
        *returnSize = digitsSize + 1;
        return result;
    }
}