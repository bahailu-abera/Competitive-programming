/** #define BITS 32

int singleNumber(int* nums, int numsSize){
    int base_count;
    unsigned mask, one = 1;
    int i, j, single = 0;

    for (i = 0; i < BITS; i++)
    {
        base_count = 0;
        mask = one << i;
        for (j = 0; j < numsSize; j++)
        {
            if (nums[j] & mask)
                base_count++;
        }

        if ((base_count % 3) != 0)
            single |= mask;
    }

    return (single);
}
**/
int singleNumber(int* nums, int numsSize){
    int once, twice;
    int i;

    once = twice = 0;
    for (i = 0; i < numsSize; i++)
    {
       once = (once ^ nums[i]) & ~twice;
       twice = (twice ^ nums[i]) & ~once;
    }

    return (once);
}
