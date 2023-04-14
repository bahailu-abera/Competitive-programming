int dfs(int **grid, int r, int c, int rows, int cols)
{
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
        return (0);

    grid[r][c] = 0;
    int area = 1; // if grid[r][c] is one we have at least area of one
    int directions[4][2] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0},
    };

    for (int i = 0; i < 4; i++)
        area += dfs(grid, r + directions[i][0], c + directions[i][1], rows, cols);

    return (area);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int area = 0;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == 1)
            {
                int current = dfs(grid, i, j, gridSize, *gridColSize);
                if (current > area)
                    area = current;
            }
        }
    }

    return (area);
}
