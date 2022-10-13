int pivotIndex(int* nums, int numsSize){

    int i;
    int right_sum = 0, left_sum = 0, cur;

    for (i = 0; i < numsSize; i++)
        right_sum += nums[i];

    for (i = 0; i < numsSize; i++)
    {
        cur = nums[i];
        right_sum -= cur;
        if (left_sum == right_sum)
            return (i);
        left_sum += cur;
    }

    return (-1);
}
