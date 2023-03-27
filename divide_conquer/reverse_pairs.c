#include <math.h>

int merge(int *array, int low, int middle, int high)
{
	int *tmp_array, i, j, k, mid, hi;
	int pairs = 0;

	tmp_array = malloc(sizeof(int) * (high - low + 1));
	if (tmp_array == NULL)
	{
		printf("insufficient memory\n");
		exit(1);
	}
	for (i = low; i <= high; i++)
		*(tmp_array + i - low) = array[i];

	i = 0, mid = middle - low, hi = high - low, j = mid + 1, k = low;

	while (i <= mid && j <= hi)
	{
		if (tmp_array[i] > 2LL * tmp_array[j])
		{
			pairs += mid - i + 1;
			j++;
		}
		else
			i++;
	}

	i = 0, j = mid + 1;
	while (i <= mid && j <= hi)
	{
		if (tmp_array[i] < tmp_array[j])
			array[k++] = tmp_array[i++];
		else
			array[k++] = tmp_array[j++];
	}

	while (i <= mid)
		array[k++] = tmp_array[i++];

	while (j <= hi)
		array[k++] = tmp_array[j++];

	free(tmp_array);
	return pairs;
}

int divide(int *array, int low, int high)
{
	int middle;
	int left, right, current;

	if (high <= low)
		return (0);

	middle = (low + high - 1) / 2;
	left = divide(array, low, middle);
	right = divide(array, middle + 1, high);
	current = merge(array, low, middle, high);

	return (left + right + current);
}


int reversePairs(int* nums, int numsSize){
	return divide(nums, 0, numsSize - 1);
}
