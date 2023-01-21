/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int dict_size = 26, i;
    int dict[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *partition, p, j, k, prev = 0;
    char c;

    i = 0;
    while ((c = *(s + i)) != '\0')
    {
        dict[c - 'a'] = ++i;
    }
    partition = malloc(dict_size * sizeof(int));

    j = k = 0;
    while (*(s + j))
    {
        p = dict[*(s + j) - 'a'];
        i = j + 1;
        while (i < p)
        {
            c = *(s + i);
            if (dict[c - 'a'] > p)
                break;
            i++;
        }
        if (i == p)
        {
            partition[k++] = p - prev;
            prev += partition[k - 1];
            j = i;
        }
        else
            j = i;
    }

    *returnSize = k;
    return partition;
}
