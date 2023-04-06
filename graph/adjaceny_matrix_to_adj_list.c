#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d ", array[i]);
	}
}


int main(void)
{
	int vertices, *adjacents, size, edge;

	scanf("%d\n", &vertices);

	for (int i = 0; i < vertices; i++)
	{
		size = 0;
		adjacents = malloc(vertices * sizeof(int));

		for (int j = 0; j < vertices; j++)
		{
			scanf("%d ", &edge);
			if (edge)
				adjacents[size++] = j + 1;
		}
		printf("%d ", size);
		print_array(adjacents, size);
		free(adjacents);
	}

	return (0);
}
