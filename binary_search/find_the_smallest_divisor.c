/**
 * Finds the maximum value in an integer array
 * @param array The input array
 * @param size The size of the array
 * @return The maximum value in the array
 */
int findMax(int *array, int size)
{
    int max_num = array[size - 1];
    while (size--)
    {
        if (array[size] > max_num)
        {
            max_num = array[size];
        }
    }
    return (max_num);
}

/**
 * Finds the smallest divisor of an array of integers such that the sum of the
 * division results is less than or equal to a given threshold
 * @param nums The input array of integers
 * @param numsSize The size of the input array
 * @param threshold The maximum sum of division results allowed
 * @return The smallest divisor that satisfies the given condition
 */
int smallestDivisor(int* nums, int numsSize, int threshold)
{
    int low = 1;
    int high = findMax(nums, numsSize);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int total_sum = 0;

        for (int i = 0; i < numsSize; i++)
        {
            total_sum += (nums[i] + mid - 1) / mid;
        }

        if (total_sum <= threshold)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (low);
}
