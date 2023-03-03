#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main()
{
    int test, math, prog;
 
    scanf("%d\n", &test);
    while (test--)
    {
        scanf("%d %d\n", &math, &prog);
        printf("%d\n", min(min(math, prog), (math + prog) / 4));
    }

    return (0);
}
