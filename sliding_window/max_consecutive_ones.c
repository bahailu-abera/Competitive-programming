int longestOnes(int* nums, int numsSize, int k){
    int s, f;
    int max = 0;
    s = f = 0;

    while (f < numsSize)
    {
        if (k == 0 && nums[f] == 0)
        {
            if (max < f - s)
                max = f - s;
            while (nums[s] != 0)
                s++;
            if (s >= f)
            {
                while (s < numsSize && nums[s] != 1)
                    s++;
                if (s == numsSize)
                    break;
                f = s;
            }
            else
                s++, k++;
        }
        if (nums[f] == 0)
            k--;
        f++;
    }
    (f - s) > (max) && (max = f - s);
    return (max);
}
