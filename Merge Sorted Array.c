// https://leetcode.com/problems/merge-sorted-array/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int cpy[nums1Size];

    for (int i = 0; i < m; i++)
        cpy[i] = nums1[i];

    int i = 0, j = 0;
    for (int k = 0; k < m + n; k++)
    {
        if ((j >= n && i < m) || i < m && j < n && cpy[i] < nums2[j])
            nums1[k] = cpy[i++];
        else
            nums1[k] = nums2[j++];
    }
}
