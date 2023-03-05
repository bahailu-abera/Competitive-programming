/**
 * Helper function that performs a binary search to find the left or right index of the target element
 * @param nums The input array of integers
 * @param numsSize The size of the input array
 * @param target The target integer
 * @param isLeft A flag indicating whether we're searching for the left or right index
 * @return The left or right index of the target element, or -1 if it's not found
 */
int binarySearch(int* nums, int numsSize, int target, bool isLeft)
{
    int left = 0;
    int right = numsSize - 1;
    int index = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < nums[mid])
        {
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            index = mid;
            if (isLeft)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    return index;
}

/**
 * Finds the left and right indices of the target element in an array of integers
 * @param nums The input array of integers
 * @param numsSize The size of the input array
 * @param target The target integer
 * @param returnSize A pointer to the size of the output array
 * @return An array containing the left and right indices of the target element, or [-1, -1] if it's not found
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* answer;
    int left_index, right_index;

    *returnSize = 2;
    answer = malloc(*returnSize * sizeof(int));
    answer[0] = -1;
    answer[1] = -1;

    if (numsSize == 0)
    {
        return answer;
    }

    left_index = binarySearch(nums, numsSize, target, true);
    if (left_index == -1)
    {
        return answer;
    }

    right_index = binarySearch(nums, numsSize, target, false);

    answer[0] = left_index;
    answer[1] = right_index;

    return answer;
}
