#define MAX_COUNT 10
int max(int *nums, int size)
{
    int i, max;

    max = nums[0];

    for (i = 0; i < size; i++)
        if (nums[i] > max)
            max = nums[i];
    return (max);
}
void counting_sort(int *nums, int place, int size)
{
    int count[MAX_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, index;
    int *output;

    for (i = 0; i < size; i++)
    {
        count[(nums[i] / place) % 10]++;
    }
    for (i = 1; i < MAX_COUNT; i++)
        count[i] += count[i - 1];
    output = malloc(size * sizeof(int));
    if (!output)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    for (i = size - 1; i > -1; i--)
    {
        index = (nums[i] / place) % 10;
        output[--count[index]] = nums[i];
    }

    for (i = 0; i < size; i++)
        nums[i] = output[i];
    free(output);
} 

void radix_sort(int *nums, int size)
{
    int max_value, place;

    max_value = max(nums, size);

    for (place = 1; max_value / place > 0; place *= 10)
        counting_sort(nums, place, size);
}

int maxOperations(int* nums, int numsSize, int k){
    int i, j, num_op = 0;
    
    radix_sort(nums, numsSize);
    
    i = 0;
    j = numsSize - 1;

    while (i < j)
    {
        if (nums[i] + nums[j] < k)
            i++;
        else if (nums[i] + nums[j] > k)
            j--;
        else
            num_op++, i++, j--;
    }
    return (num_op);
}
