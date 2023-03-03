#define min(a, b) ((a) != 0 && (a) < (b) ? (a): (b))

int minSubArrayLen(int target, int* nums, int numsSize){
    int r, l;
    int minl, sum;

    l = sum = minl = 0;

    for (r = 0; r < numsSize; r++)
    {
        while (sum - nums[l] >= target)
            sum -= nums[l], l++;
        (sum >= target) && (minl = min(minl, r - l));
        sum += nums[r];
    }

    while (sum - nums[l] >= target)
        sum -= nums[l], l++;
    (sum >= target) && (minl = min(minl, r - l));

    return (minl);;
}
