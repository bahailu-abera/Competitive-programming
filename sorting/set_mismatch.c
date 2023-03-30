/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define RETURN_SIZE 2

int* findErrorNums(int* nums, int numsSize, int* returnSize){
	int loss, dup;
	int *answer;
	int i, current, j;

	loss = dup = 0;
	for (i = j = 0; i < numsSize; j++)
	{
		current = nums[i];
		if (current > numsSize || current == i + 1)
			i++;

		else if (current == nums[current - 1])
			dup = current, i++;

		else
			nums[i] ^= nums[current - 1], nums[current - 1] ^= nums[i], nums[i] ^= nums[current - 1];
	}

	for (i = 0; i < numsSize; i++)
		loss ^= i + 1,  loss ^= nums[i];

	answer = malloc(sizeof(int) * RETURN_SIZE);
	answer[0] = dup, answer[1] = loss ^ dup;
	*returnSize = RETURN_SIZE;

	return (answer);
}
