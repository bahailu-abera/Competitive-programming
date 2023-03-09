/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int i;

    *returnSize = numsSize;
    for (i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];

    return (nums);
}
