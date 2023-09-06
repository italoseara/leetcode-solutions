// https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binary_search(nums, target, 0, nums.size() - 1);
    }

    int binary_search(vector<int> &nums, int target, int start, int end)
    {
        int length = end - start + 1;
        int mid = start + ((length - 1) / 2);

        if (length == 0) return -1;
        if (length == 1) return nums[start] == target ? start : -1;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return binary_search(nums, target, mid + 1, end);
        return binary_search(nums, target, start, mid - 1);
    }
};