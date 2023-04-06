#include <stdio.h>
#include <stdlib.h>

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

void delete(int **m, int size)
{
	for (int i = 0; i < size; i++)
		free(m[i]);
	free(m);
}

void solve(int **matrix, int size)
{
	int sources[100], sinks[100];
	int len_sources = 0, len_sinks = 0;
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			if (matrix[i][j] != 0) /** check if current vertices is source **/
				break;
		if (j == size)
			sinks[len_sinks++] = i + 1;

		for (j = 0; j < size; j++)
			if (matrix[j][i] != 0)
				break;
		if (j == size)
			sources[len_sources++] = i + 1;
	}
	printf("%d", len_sources);
	for (i = 0; i < len_sources; i++)
		printf(" %d", sources[i]);
	printf("\n");

	printf("%d", len_sinks);
	for (i = 0; i < len_sinks; i++)
		printf(" %d", sinks[i]);
	printf("\n");
}

int main(void)
{
	int vertices;
	int **adj_matrix;

	scanf("%d\n", &vertices);

	adj_matrix = malloc(vertices * sizeof(int *));
	for (int i = 0; i < vertices; i++)
		adj_matrix[i] = readlist(vertices);

	solve(adj_matrix, vertices);
	delete(adj_matrix, vertices);

	return (0);
}
