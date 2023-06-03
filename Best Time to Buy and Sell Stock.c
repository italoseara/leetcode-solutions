// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(int *prices, int pricesSize)
{
    int result = 0;
    int min = prices[0];

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min)
            min = prices[i];
        else if (prices[i] - min > result)
            result = prices[i] - min;
    }

    return result;
}
