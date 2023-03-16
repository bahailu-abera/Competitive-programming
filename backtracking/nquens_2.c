#include <math.h>
#include <stdlib.h>

bool is_valid(int *board, int current)
{
    int i;

    for (i = 0; i < current; i++)
    {
        if ((board[i] == board[current]) || (current - i == abs(board[current] - board[i])))
            return (false);
    }
    return (true);
}

int place_quens(int *board, int col, int n)
{
    int row, solutions;

    if (col == n)
        return (1);

    solutions = 0;
    for (row = 0; row < n; row++)
    {
        board[col] = row;
        if (is_valid(board, col))
            solutions += place_quens(board, col + 1, n);
    }
    return solutions;
}

int totalNQueens(int n){
    int col, *board;
    int solutions;

    board = malloc(n * sizeof(int));
    for (col = 0; col < n; col++)
        board[col] = -1;

    solutions = place_quens(board, 0, n);
    free(board);

    return (solutions);
}
