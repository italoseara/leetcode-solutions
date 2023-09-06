// https://leetcode.com/problems/isomorphic-strings/

#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> a_map;
        unordered_map<char, char> b_map;

        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            char b = t[i];

            if (!a_map.count(a) && !b_map.count(b))
            {
                a_map[a] = b;
                b_map[b] = a;
            }
            else if (a_map.count(a) == 1 && b_map.count(b) == 1)
            {
                if (a_map[a] == b && b_map[b] == a)
                    continue;
                return false;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};