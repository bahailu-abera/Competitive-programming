class Solution {
public:
    vector<int> findPrimes(int start, int n)
    {
        vector<bool> result(n + 1, true);
        result[1] = false; // one is not prime number

        vector<int> primes;

        int limit = sqrt(n);

        for (int i = 2; i <= limit; i++)
        {
            if (result[i])
            {
                int j = pow(i, 2);

                while (j <= n)
                {
                    result[j] = false;
                    j += i;
                }
            }
        }


        for (int i = start; i <= n;  i++)
        {
            if (result[i])
                primes.push_back(i);
        }

        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = findPrimes(left, right);
        int n = (int)primes.size();

        vector<int> closest = {-1, -1};

        if (n < 2)
            return closest;

        closest[0] = primes[0];
        closest[1] = primes[1];

        int diff = closest[1] - closest[0];

        for (int i = 1; i < n - 1; i++)
        {
            if ((primes[i + 1] - primes[i]) < diff)
            {
                closest[0] = primes[i];
                closest[1] = primes[i + 1];

                diff = closest[1] - closest[0];
            }
        }

        return closest;
    }
};
