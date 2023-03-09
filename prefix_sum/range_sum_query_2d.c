typedef int **NumMatrix;
int rows, cols;

NumMatrix numMatrixCreate(int **matrix, int matrixSize, int *matrixColSize) {
    rows = matrixSize;
    cols = *matrixColSize;

    NumMatrix prefix_sum = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        prefix_sum[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            prefix_sum[i][j] = matrix[i][j];
            if (j > 0) prefix_sum[i][j] += prefix_sum[i][j-1];
            if (i > 0) prefix_sum[i][j] += prefix_sum[i-1][j];
            if (i > 0 && j > 0) prefix_sum[i][j] -= prefix_sum[i-1][j-1];
        }
    }

    return prefix_sum;
}

int numMatrixSumRegion(NumMatrix obj, int row1, int col1, int row2, int col2) {
    int sub_matrix_sum = obj[row2][col2];
    if (row1 > 0) sub_matrix_sum -= obj[row1 - 1][col2];
    if (col1 > 0) sub_matrix_sum -= obj[row2][col1 - 1];
    if (row1 > 0 && col1 > 0) sub_matrix_sum += obj[row1 - 1][col1 - 1];
    return sub_matrix_sum;
}

void numMatrixFree(NumMatrix obj) {
    for (int i = 0; i < rows; i++) {
        free(obj[i]);
    }
    free(obj);
}
