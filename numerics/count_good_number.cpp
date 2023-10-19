const long long mod = 1e9 + 7;

long long mulmod(long long a, long long b)
{
    long long result = 0;

    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % mod;

        a = (a * 2) % mod;

        b /= 2;
    }

    return result;
}

long long expomod(long long a, long long b)
{
    if (a == 0)
        return b == 0;

    long long result = 1;

    while (b > 0)
    {
        if (b & 1)
            result = mulmod(result, a);

        a = mulmod(a, a);

        b /= 2;
    }

    return result;
}



class Solution {
public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = odd + (n & 1);

        long long result = mulmod(expomod(4, odd), expomod(5, even)) % mod;

        return result;
    }
};
