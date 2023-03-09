/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *answer;
    int mul = 1, index;

    answer = malloc(numsSize * sizeof(int));
    for (index = 0; index < numsSize; index++)
        answer[index] = mul, mul *= nums[index];

    mul = nums[--index];
    for (--index; index >= 0; index--)
        answer[index] *= mul, mul *= nums[index];
    *returnSize = numsSize;

    return (answer);
}
