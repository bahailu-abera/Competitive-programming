int findDuplicate(int* nums, int numsSize){
	int duplicate, nums_count, base_count, bits_length;
	int i, j, mask;

	bits_length  = log2(numsSize) + 1;
	duplicate = 0;

	for (i = 0; i < bits_length; i++)
	{
		mask = (1 << i);
		nums_count = base_count = 0;
		for (j = 0; j < numsSize; j++)
		{
			if (nums[j] & mask)
				nums_count += 1;

			if (j & mask)
				base_count += 1;
		}

		if (nums_count > base_count)
			duplicate |= mask;
	}

	return (duplicate);
}
