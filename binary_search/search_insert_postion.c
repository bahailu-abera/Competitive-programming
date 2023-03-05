int searchInsert(int* nums, int numsSize, int target){
    int mid, low, high;

    low = 0, high = numsSize - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return (mid);
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (low);
}
