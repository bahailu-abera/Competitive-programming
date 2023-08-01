#include <stdio.h>
int solve(int n)
{
    int i;

    if (1 == n)
        return (3);

    if (n & 1)
        return (1);

    i = 0;
    while (n >> i)
    {
        if (n & (1 << i))
            break;
        i++;
    }
    i = 1 << i;
    if (0 == (n ^ i))
        i ^= 1;

    return (i);
}


int main(void)
{
    int testcase, x;

    scanf("%d\n", &testcase);
    while (testcase--)
    {
        scanf("%d\n", &x);
        printf("%d\n", solve(x));
    }

    return (0);
}
