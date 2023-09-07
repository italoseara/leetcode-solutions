// https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, r = 0; i < nums.size() - r; i++)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
                r++;
            }
        }
    }
};