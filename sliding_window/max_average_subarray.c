double findMaxAverage(int* nums, int numsSize, int k){
    int sum, i;
    double average;
    double current_avg;

    sum = 0;
    for (i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    average = (double)sum / k;
    for (i = k; i < numsSize; i++)
    {
        sum -= nums[i - k];
        sum += nums[i];
        current_avg = (double)sum / k;
        if (current_avg > average)
            average = current_avg;
    }
    return (average);
}
