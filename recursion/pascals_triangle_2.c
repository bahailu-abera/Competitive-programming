/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *rows, *upper_row;
    int i;

    rows = malloc(sizeof(int) * (rowIndex + 1));
    rows[0] = 1;

    if (rowIndex == 0)
    {
        *returnSize = 1;
        return (rows);
    }

    upper_row = getRow(rowIndex - 1, returnSize);
    for (i = 1; i < rowIndex; i++)
        rows[i] = upper_row[i - 1] + upper_row[i];
    rows[i] = upper_row[i - 1];
    *returnSize = rowIndex + 1;
    free(upper_row);
    return (rows);
}
