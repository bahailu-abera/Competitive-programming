/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int *sources, *sinks, *ans;

    sources = calloc(n, sizeof(int));
    sinks = calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++)
    {
        if (sinks[edges[i][0]] == 0)
            sources[edges[i][0]] = 1;

        else
            sources[edges[i][0]] = -1;

        sinks[edges[i][1]] = 1;
        sources[edges[i][1]] =  -1;
    }

    *returnSize = 0;
    ans = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (sources[i] > 0)
            ans[(*returnSize)++] = i;
    }

    if (*returnSize == 0)
        free(ans), ans = NULL;

    free(sources);
    free(sinks);

    return (ans);
}
