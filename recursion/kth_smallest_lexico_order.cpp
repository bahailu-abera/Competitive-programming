#define int long long

class Solution {
public:
    int count(int start, int limit)
    {
        int result = 0;

        int x = 1;

        while (start <= limit)
        {
            result += min(limit - start + 1, x);

            start *= 10, x *= 10;
        }

        return result;
    }

    int recur(int value, int digit, int k, int n)
    {
        if (k <= 0)
            return value;

        int c = count(value * 10 + digit, n);

        if (c < k)
            return recur(value, digit + 1, k - c, n);

        return recur(value * 10 + digit, 0, k - 1, n);
    }

    int findKthNumber(int n, int k) {
        return recur(0, 1, k, n);
    }
};
#undef int
