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
    }

    return 0;
}

int romanToInt(char *s)
{
    int answer = 0;

    char cache[3] = {};
    int count = 0;

    for (int i = 0;; i++)
    {
        if (count == 0 || cache[0] == s[i])
        {
            cache[count++] = s[i];
        }
        else
        {
            int value = romanCharToInt(cache[0]) * count;
            if (romanCharToInt(s[i]) > value)
                answer -= value;
            else
                answer += value;

            count = 0;
            cache[count++] = s[i];
        }

        if (s[i] == '\0')
            break;
    }

    return answer;
}
