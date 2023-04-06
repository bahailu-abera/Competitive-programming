/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize){
    int left, right;

    for (*returnSize = 0; *returnSize < numsSize - 1; (*returnSize)++)
    {
        if (nums[*returnSize] == nums[(*returnSize) + 1])
            nums[*returnSize] *= 2, nums[(*returnSize) + 1] = 0;
    }

    (*returnSize)++;

    left = 0;
    for (right = 0; right < numsSize; right++)
    {
        if (nums[left] == 0 && nums[right] != 0)
            nums[left] ^= nums[right], nums[right] ^= nums[left], nums[left] ^= nums[right];

        if (nums[left] > 0)
            left++;
    }

   return (nums);
}
