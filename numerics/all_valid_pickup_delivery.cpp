int mod = 1e9 + 7;

class Solution {
public:
    int countOrders(int n) {
        if (n == 1)
            return 1;

        long long result = n;

        result %= mod;

        result = (result * (2 * n - 1)) % mod;

        return (result * countOrders(n - 1)) % mod;
    }
};
