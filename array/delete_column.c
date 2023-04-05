int minDeletionSize(char ** strs, int strsSize){
    int delete = 0, i, j, len;

    len = strlen(strs[0]);
    for (i = 0; i < len; i++)
    {
        for (j = 1; j < strsSize; j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                delete++;
                break;
            }
        }
    }

    return (delete);
}
