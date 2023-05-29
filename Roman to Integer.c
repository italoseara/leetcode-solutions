// https://leetcode.com/problems/roman-to-integer/

int romanCharToInt(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(char *s)
{
    int answer = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int value = romanCharToInt(s[i]);

        if (value < romanCharToInt(s[i + 1]))
            answer -= value;
        else
            answer += value;
    }

    return answer;
}
