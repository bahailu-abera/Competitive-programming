/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int i, j;
    int *disappeared;

    disappeared = malloc(numsSize * sizeof(int));
    if (disappeared == NULL)
    {
        printf("Malloc Error\n");
        exit(-1);
    }

    for (i = 0; i < numsSize; )
    {
        j = nums[i];
        if (j > numsSize || i == j - 1 || j == nums[j - 1])
            i++;

        else
            nums[i] ^= nums[j - 1], nums[j - 1] ^= nums[i], nums[i] ^= nums[j - 1];
    }

    j = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
            disappeared[j++] = i + 1;
    }
    disappeared = realloc(disappeared, j * sizeof(int));
    *returnSize = j;
    return (disappeared);
}
