#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int roads = 0;
	int n, edge;

	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &edge);
			roads += edge;
		}
	}

	printf("%d\n", roads / 2);

	return (0);
}
