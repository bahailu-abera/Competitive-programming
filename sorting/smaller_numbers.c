/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 101

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *output;
    int count[MAX_SIZE];
    int i;

    *returnSize = numsSize;
    output = malloc(numsSize * sizeof(int));

    for (i = 0; i < MAX_SIZE; i++)
        count[i] = 0;

    for (i = 0; i < numsSize; i++)
        count[nums[i]]++;

    for (i = 1; i < MAX_SIZE; i++)
        count[i] += count[i - 1];

    for (i = 0; i < numsSize; i++)
        if (nums[i] == 0)
            output[i] = 0;
        else
            output[i] = count[nums[i] - 1];

    return (output);
}
