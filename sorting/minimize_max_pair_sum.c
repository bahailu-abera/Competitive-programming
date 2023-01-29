int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minPairSum(int* nums, int numsSize){
    int max;
    int l, r;

    qsort(nums, numsSize, sizeof(int), cmp);
    l = 0, r = numsSize - 1;
    max = nums[l++] + nums[r--];
    while (l < r)
    {
        if (max < nums[l] + nums[r])
            max = nums[l] + nums[r];
        l++, r--;
    }
    return (max);
}
