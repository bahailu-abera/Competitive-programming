void rotate(int* nums, int numsSize, int k){
    int newSize = k % numsSize;
    int *tmp = malloc(newSize * sizeof(int));
    int i = 0, j = 0;

    k = newSize;
    if (newSize == 0)
        return;
    for (i = numsSize - k, j = 0; i < numsSize; i++, j++)
        *(tmp + j) = *(nums + i);

    for (i = numsSize - k - 1; i >= 0; i--)
        *(nums + i + k) = *(nums + i);
    for (i = 0; i < newSize; i++)
        *(nums + i) = *(tmp + i);
}
