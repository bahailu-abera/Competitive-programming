int maxSum(int** g, int gSize, int* gColSize){
    int max_sum = 0;
    int current;

    for (int i = 0; i < gSize - 2; i++)
    {
        for (int j = 0; j < *gColSize - 2; j++)
        {
            current = g[i][j] + g[i][j + 1] + g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];
            if (current > max_sum)
                max_sum = current;
        }
    }

    return (max_sum);

}
