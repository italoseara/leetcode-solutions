// https://leetcode.com/problems/remove-element/

int removeElement(int *nums, int numsSize, int val)
{
    int k = numsSize;

    for (int i = 0; i < k; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < k - 1; j++)
                nums[j] = nums[j + 1];
            k--;
            i--;
        }
    }

    return k;
}
