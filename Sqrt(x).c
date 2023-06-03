// https://leetcode.com/problems/sqrtx/

int mySqrt(int x)
{
    // Binary Search
    int start = 0;
    int end = x;

    while (1)
    {
        int mid = (start + end) / 2;
        long pow = (long)mid * mid;

        // If there is only one or two elements left
        if (end - start <= 1)
            if ((long)end * end == x)
                return end;
            else
                return start;

        // Cut the elements
        if (pow > x)
            end = mid;
        else if (pow < x)
            start = mid;
        else if (pow == x)
            return mid;
    }
}