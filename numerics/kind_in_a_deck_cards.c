#include <math.h>

#define SIZE 10000

int gcd(int a, int b)
{
    if (b == 0)
        return (a);

    return gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int hash_table[SIZE] = {0};

    for (int i = 0; i < deckSize; i++)
        hash_table[deck[i]]++;

    int fgcd = -1;
    for (int i = 0; i < deckSize; i++)
    {
        if (fgcd == -1)
            fgcd = hash_table[deck[i]];
        else
            fgcd = gcd(fgcd, hash_table[deck[i]]);

        if (fgcd < 2)
            return (false);
    }

    return (true);
}
