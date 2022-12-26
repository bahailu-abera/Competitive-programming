#define MAX_SIZE 100
int numIdenticalPairs(int* nums, int numsSize){
    int dict[MAX_SIZE];
    int i, count = 0, freq;

    for (i = 0; i < MAX_SIZE; i++)
        dict[i] = 0;
    
    for (i = 0; i < numsSize; i++)
        dict[nums[i] - 1]++;
    
    for (i = 0; i < MAX_SIZE; i++)
    {
        freq = dict[i];
        count += ((freq - 1) * freq / 2);
    }
    return (count);
}
