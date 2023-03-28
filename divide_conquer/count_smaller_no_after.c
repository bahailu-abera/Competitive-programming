typedef struct tuble
{
    int data;
    int index;
} tuble_t;

int *count;

void merge(tuble_t *array, int low, int mid, int high)
{
    int i, j, k;
    int hi;
    tuble_t *tmp;

    tmp = malloc((high - low + 1) * sizeof(tuble_t));
    if (tmp == NULL)
    {
        printf("Malloc Error\n");
        exit(-1);
    }

    for (i = low; i <= high; i++)
    {
        tmp[i - low].data = array[i].data, tmp[i - low].index = array[i].index;
    }

    mid -= low, hi = high - low;
    i = 0, j = mid + 1, k = low;
    while (i <= mid && j <= hi)
    {
        if (tmp[i].data <= tmp[j].data)
        {
            array[k].data = tmp[i].data, array[k].index = tmp[i].index;
            count[tmp[i].index] += (j - mid - 1);
            i++;
        }
        else
        {
            array[k].data = tmp[j].data, array[k].index = tmp[j].index;
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        array[k].data = tmp[i].data, array[k].index = tmp[i].index;
        count[tmp[i].index] += (j - mid - 1);
        i++, k++;
    }

    while (j <= hi)
    {
        array[k].data = tmp[j].data, array[k].index = tmp[j].index;
        j++, k++;
    }

    free(tmp);
}

void divide(tuble_t *array, int low, int high)
{
    if (high <= low)
        return;

    int mid = (low + high - 1) / 2;
    divide(array, low, mid);
    divide(array, mid + 1, high);
    merge(array, low, mid, high);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
    tuble_t *array;
    int i;

    array = malloc(numsSize * sizeof(tuble_t));
    if (array == NULL)
    {
        printf("Malloc Error:\n");
        exit(-1);
    }

    for (i = 0; i < numsSize; i++)
    {
        array[i].data = nums[i], array[i].index = i;
    }

    *returnSize = numsSize;
    count = malloc(numsSize * sizeof(int));
    if (count == NULL)
    {
        printf("Malloc error\n");
        exit(-1);
    }

    for (i = 0; i < numsSize; i++)
        count[i] = 0;

    divide(array, 0, numsSize - 1);
    free(array);

    return (count);
}
