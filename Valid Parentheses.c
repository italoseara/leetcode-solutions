// https://leetcode.com/problems/valid-parentheses/

#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    int top = -1;
    char stack[len];

    for (int i = 0; i < len; i++) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[++top] = s[i];
        else
        {
            if (top == -1)
                return false;
            if (
                (s[i] == ')' && stack[top] != '(') ||
                (s[i] == '}' && stack[top] != '{') ||
                (s[i] == ']' && stack[top] != '[')
            )
                return false;
            top--;
        }
    }

    return top == -1;
}
