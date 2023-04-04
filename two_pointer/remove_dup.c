int removeDuplicates(int* nums, int numsSize){
    int l, r;

    l = 0, r = 1;
    while (r < numsSize)
    {
        if (nums[r] != nums[l])
        {
            l++;
            nums[l] = nums[r];
        }
        r++;
    }

    return (l + 1);
}
