// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> letters;

        for (int i = 0; i < s.size(); i++)
        {
            letters[s[i]]++;
            letters[t[i]]--;
        }

        for (pair<char, int> p : letters)
            if (p.second != 0)
                return false;

        return true;
    }
};