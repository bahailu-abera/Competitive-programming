#include <math.h>

int kthGrammar(int n, int k){
    int mid, size;

    if (n == 1)
        return (0);
    size = pow(2, n - 1);
    if (k <=  size / 2)
        return kthGrammar(n - 1, k);

    return (1 - kthGrammar(n - 1, k - size / 2));
}
