/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
	int i, j, current;
	int *duplicates;

	duplicates = malloc(numsSize * sizeof(int));
	if (duplicates == NULL)
	{
		printf("Malloc Error\n");
		exit(-1);
	}

	for (i = 0; i < numsSize;)
	{
		current = nums[i];
		if (current == i + 1 || current > numsSize || current == nums[current - 1])
			i++;

		else
			nums[i] ^= nums[current - 1], nums[current - 1] ^= nums[i], nums[i] ^= nums[current - 1];
	}

	for (i = j = 0; i < numsSize; i++)
	{
		current = nums[i];
		if (current != i + 1 && current == nums[current - 1])
			duplicates[j++] = current;
	}

	duplicates = realloc(duplicates, j * sizeof(int));
	*returnSize = j;

	return (duplicates);
}
