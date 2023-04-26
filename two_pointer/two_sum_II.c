/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int l, r, *indexs;
    int sum;

    *returnSize = 2;
    indexs = malloc(*returnSize * sizeof(int));
    l = 0, r = numbersSize - 1;

    while (l < r)
    {
        sum = numbers[l] + numbers[r];
        if (sum == target)
            break;
        else if (sum < target)
            l++;
        else
            r--;
    }
    indexs[0] = l + 1, indexs[1] = r + 1;
    return (indexs);
}
