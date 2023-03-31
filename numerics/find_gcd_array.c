int gcd(int a, int b)
{
    if (b == 0)
        return (a);

    return gcd(b, a % b);
}

int findGCD(int* nums, int numsSize){
    int min, max,  i;

    min = max = nums[0];
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > max)
            max = nums[i];

        else if (nums[i] < min)
            min = nums[i];
    }

    return gcd(min, max);
}
