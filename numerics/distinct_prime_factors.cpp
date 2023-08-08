class Solution {
public:
    void findPrimeFactor(int n)
    {
        int divider = 2;

        while (divider * divider <= n)
        {
            if (n % divider == 0)
                prime_factors[divider] = 1, n /= divider;

            else
                divider++;
        }

        if (n > 1)
            prime_factors[n] = 1;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        for (int n : nums)
            findPrimeFactor(n);

        return prime_factors.size();
    }
private:
    unordered_map<int, int> prime_factors;
};
