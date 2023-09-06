// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *node = nullptr;

        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            ListNode *temp = node;
            node = new ListNode(p->val, p->next);
            node->next = temp;
        }

        return node;
    }
};