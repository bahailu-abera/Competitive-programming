/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int hash[100][26];
    char **output;
    char *s;

    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < 26; j++)
            hash[i][j] = 0; /** Set the count of all characters to zero **/
    }

    for (int i = 0; i < wordsSize; i++)
    {
        for (s = words[i]; *s; s++)
            hash[i][*s - 'a']++;
    }

    output = malloc(100 * sizeof(char *));
    *returnSize = 0;
    for (int i = 0; i < 26; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < wordsSize; j++)
        {
            if (hash[j][i] < min)
                min = hash[j][i];
        }

        while (min--)
        {
            output[*returnSize] = malloc(2 * sizeof(char));
            output[*returnSize][0] = i + 'a';
            output[*returnSize][1] = '\0';
            (*returnSize)++;
        }
    }

    if (*returnSize == 0)
    {
        free(output), output = NULL;
    }

    return (output);
}
