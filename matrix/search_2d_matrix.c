bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0, right = matrixSize - 1;
    int mid, row;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (matrix[mid][matrixColSize[0] - 1] == target)
            return (true);

        else if (target < matrix[mid][matrixColSize[0] - 1])
            right = mid - 1;

        else
            left = mid + 1;
    }

    if (left < 0 || left >= matrixSize)
        return (false);

    row = left;
    left = 0, right = matrixColSize[left] - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (matrix[row][mid] == target)
            return (true);

        else if (target < matrix[row][mid])
            right = mid - 1;

        else
            left = mid + 1;
    }

    return (false);
}
