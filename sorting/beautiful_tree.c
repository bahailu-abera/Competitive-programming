#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int swaps;

int* readlist(int size)
{
	int *array, i;

	array = malloc(size * sizeof(int));
	if (!array)
	{
		printf("malloc error\n");
		exit(-1);
	}

	for (i = 0; i < size - 1; i++)
		scanf("%d ", &array[i]);
	scanf("%d\n", &array[i]);

	return (array);
}


bool merge(int *array, int low, int mid, int high)
{
	int *left, *right;
	int n1, n2;
	int i, j, k;
	int left_min, right_max;

	if (array[low] - array[high] == 1)
		swaps++;

	else if (array[mid] - array[mid + 1] != -1)
		return (false);


	n1 = mid - low + 1;
	n2 = high - mid;

	left = malloc(n1 * sizeof(int));
	right = malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		left[i] = array[i + low];

	for (j = 0; j < n2; j++)
		right[j] = array[mid + j + 1];

	i = j = 0;
	k = low;
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			array[k] = left[i], i++;
		else
			array[k] = right[j], j++;
		k++;
	}

	while (i < n1)
		array[k] = left[i], k++, i++;

	while (j < n2)
		array[k] = right[j], k++, j++;

	free(left);
	free(right);

	return (true);
}

bool divide(int *arr, int l, int r)
{
	bool status, left, right;
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

		left = divide(arr, l, m);

		if (!left)
			return false;

		right = divide(arr, m + 1, r);

		if (!right)
			return false;

		status = merge(arr, l, m, r);

		if (!status)
			return false;

		return true;
	}

	return true;
}


void solve(int *array, int size)
{
	swaps = 0;

	if (!divide(array, 0, size - 1))
		printf("-1\n");

	else
		printf("%d\n", swaps);
}

int main(void)
{
	int testcase, size;
	int *permutations;

	scanf("%d\n", &testcase);
	while (testcase--)
	{
		scanf("%d\n", &size);
		permutations = readlist(size);

		solve(permutations, size);
		free(permutations);
	}

	return (0);
}
