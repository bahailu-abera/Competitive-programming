typedef int NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    int i;

    for (i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];

    return ((NumArray *)nums);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (!left)
        return (obj[right]);
    return (obj[right] - obj[--left]);
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 * numArrayFree(obj);
*/
