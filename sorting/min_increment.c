#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int minIncrementForUnique(int* nums, int numsSize){
    int moves = 0;
    int i;

    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            nums[i]++, moves++;
        else if (nums[i] < nums[i - 1])
            moves += ((nums[i - 1] + 1) - nums[i]), nums[i] = nums[i - 1] + 1;
    }
    return (moves);
}
