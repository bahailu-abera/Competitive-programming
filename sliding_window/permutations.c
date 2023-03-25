#include <stdio.h>
#include <stdlib.h>

#define SIZE 26
void copy(int *arr1, int *arr2, int size)
{
    int i;

    for (i = 0; i < size; i++)
        *(arr1 + i) = *(arr2 + i);
}

bool is_valid(int *arr1, int *arr2, int size)
{
    int i;

    for (i = 0; i < size; i++)
        if (arr1[i] != arr2[i])
            return (false);

    return (true);
}

bool checkInclusion(char * s1, char * s2){
    int *freq, *tmp;
    int i, left, right, index ;

    freq = malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++)
        freq[i] = 0;

    tmp = malloc(SIZE * sizeof(int));
    copy(tmp, freq, SIZE);

    while (*s1)
        freq[*s1 - 'a']++, s1++;

    for (left = right = 0; *(s2 + right) != '\0'; right++)
    {
        index = *(s2 + right) - 'a';
        tmp[index]++;

        while (tmp[index] > freq[index])
        {
            tmp[*(s2 + left) - 'a']--;
            left++;
        }

        if (is_valid(tmp, freq, SIZE))
            return (true);
    }

    free(tmp);
    free(freq);

    return (false);
}
