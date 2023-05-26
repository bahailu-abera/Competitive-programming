class Solution {
public:
    int tribonacci(int n) {
        vector<int> memo(n + 1, -1);

        function<int(int)> dp = [&](int current)
        {
            if (current < 2)
                return current;

            if (current == 2)
                return 1;

            if (memo[current] != -1)
                return memo[current];

            memo[current] = dp(current - 1) + dp(current - 2) + dp(current - 3);

            return memo[current];
        };

        return dp(n);
    }
};
