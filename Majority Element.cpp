// https://leetcode.com/problems/majority-element/

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        pair<int, int> maj = {0, 0};

        for (int num : nums)
        {
            counter[num]++;

            if (counter[num] > maj.second)
                maj = {num, counter[num]};
        }

        return maj.first;
    }
};