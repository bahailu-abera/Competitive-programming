void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int tmp, i, j;
    int col = *matrixColSize;

    for (i = 0; i < matrixSize / 2; i++)
    {
        for (j = i; j < matrixSize - i - 1; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j]
        }
    }
}
