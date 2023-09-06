// https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ranges;

        if (!nums.size())
            return ranges;

        int start = nums[0];
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];

            if (curr - 1 != prev)
            {
                ranges.push_back(get_string(start, prev));
                start = curr;
            }
            prev = curr;
        }
        ranges.push_back(get_string(start, prev));

        return ranges;
    }

    string get_string(int start, int end)
    {
        if (start == end)
            return to_string(start);
        return to_string(start) + "->" + to_string(end);
    }
};