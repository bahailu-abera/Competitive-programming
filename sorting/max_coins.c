#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (-1 * (*(int *)a - *(int *)b));
}
int maxCoins(int* piles, int pilesSize){
    int l, counter;
    int coins = 0;

    qsort(piles, pilesSize, sizeof(int), cmp);
    l = 1;
    counter = 0;
    while (counter < pilesSize / 3)
    {
        coins += piles[l];
        l += 2;
        counter++;
    }
    return (coins);
}
