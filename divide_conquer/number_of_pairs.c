int d;

long long merge(int *array, int low, int mid, int high)
{
	int *tmp_array;
	int i, j, k, hi;
	long long pairs = 0;

	tmp_array = malloc((high - low + 1) * sizeof(int));
	if (tmp_array == NULL)
	{
		printf("Malloc error: \n");
		exit(-1);
	}

	for (i = low; i <= high; i++)
	{
		tmp_array[i - low] = array[i];
	}

	i = 0, mid -= low, hi = high - low, j = mid + 1;
	while (i <= mid && j <= hi)
	{
		if (tmp_array[i] <= tmp_array[j] + d)
			pairs += hi - j + 1, i++;

		else
			j++;
	}

	i = 0, j = mid + 1, k = low;
	while (i <= mid && j <= hi)
	{
		if (tmp_array[i] <= tmp_array[j])
			array[k] = tmp_array[i], i++;
		else
			array[k] = tmp_array[j], j++;
		k++;
	}

	while (i <= mid)
		array[k] = tmp_array[i], i++, k++;

	while (j <= hi)
		array[k] = tmp_array[j], j++, k++;

	free(tmp_array);

	return (pairs);
}


long long divide(int *array, int low, int high)
{
	int mid;
	long long left, right, current;

	if (high <= low)
		return (0);;

	mid = (low + high - 1) / 2;
	left = divide(array, low, mid);
	right = divide(array, mid + 1, high);
	current = merge(array, low, mid, high);

	return (left + right + current);
}

long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int diff){
	int i;

	d = diff;
	for (i = 0; i < nums1Size; i++)
		nums1[i] -= nums2[i];

	return (divide(nums1, 0, nums1Size - 1));
}
