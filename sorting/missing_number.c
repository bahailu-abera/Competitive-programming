int missingNumber(int* nums, int numsSize){
    int *extended, i;

    extended = malloc((numsSize + 1) * sizeof(int));
    if (extended == NULL)
    {
        printf("Malloc Error\n");
        exit(-1);
    }

    for (i = 0; i <= numsSize; i++)
        extended[i] = -1;

    for (i = 0; i < numsSize; i++)
        extended[nums[i]] = nums[i];

    for (i = 0; i <= numsSize; i++)
        if (extended[i] == -1)
           break;

    free(extended);
    return (i);
}
