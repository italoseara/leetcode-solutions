// https://leetcode.com/problems/happy-number/

#include <stdbool.h>

bool contains(int *arr, int arrLen, int n)
{
    for (int i = 0; i < arrLen; i++)
        if (arr[i] == n)
            return true;

    return false;
}

int sumPow(int n)
{
    int sum;
    for (sum = 0; n != 0; n /= 10)
        sum += (n % 10) * (n % 10);
    return sum;
}

bool isHappy(int n)
{
    int prev[100];
    int prevLen = 0;
    int sum = n;

    for (int i = 0; i < 20; i++)
    {
        sum = sumPow(sum);

        if (sum == 1)
            return true;

        if (!contains(prev, prevLen, sum))
            prev[prevLen++] = sum;
        else
            return false;
    }

    return false;
}
