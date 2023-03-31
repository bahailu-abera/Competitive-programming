#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define max_size 128

int main(void)
{
    char *a, *b;

    a = malloc(sizeof(char) * max_size);
    b = malloc(sizeof(char) * max_size);

    scanf("%s", a);
    scanf("%s", b);

    if (strcmp(a, b) == 0)
        printf("%s\n", a);
    else
        printf("1\n");

    free(a);
    free(b);

    return (0);
}
