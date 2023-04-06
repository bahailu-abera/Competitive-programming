#include <stdio.h>
#include <stdlib.h>


void delete(int **m, int size)
{
    for (int i = 0; i < size; i++)
        free(m[i]);

    free(m);
}

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

long long scores(int **m, int row, int col, int x, int y)
{
    int cx, cy;
    long long sum = 0;

    for (cx = x, cy = y; cx >= 0 && cy >= 0; cx--, cy--)
    {
        sum += m[cx][cy];
    }

    for (cx = x + 1, cy = y + 1; cx < row && cy < col; cx++, cy++)
    {
        sum += m[cx][cy];
    }

    for (cx = x - 1, cy = y + 1; cx >= 0 && cy < col; cx--, cy++)
    {
        sum += m[cx][cy];
    }

    for (cx = x + 1, cy = y - 1; cx < row && cy >= 0; cx++, cy--)
    {
        sum += m[cx][cy];
    }

    return (sum);
}

void solve(int **matrix, int row_size, int col_size)
{
    long long max = 0;
    long long current;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if ((current = scores(matrix, row_size, col_size, i, j)) > max)
                max = current;
        }
    }

    printf("%lld\n", max);
}


int main(void)
{
    int **matrix;
    int row, col, testcase;

    scanf("%d\n", &testcase);
    while (testcase--)
    {
        scanf("%d %d\n", &row, &col);
        matrix = malloc(row * sizeof(int *));
        for (int i = 0; i < row; i++)
        {
            matrix[i] = readlist(col);
        }
        solve(matrix, row, col);
        delete(matrix, row);
    }

    return (0);
}
