#define sz(n) (int)n.size()

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = sz(cost);
	vector<int> memo(n + 2, -1);

        function<int(int)> dp = [&](int n)
        {
            if (n < 2)
                return cost[n];

            if (memo[n] != -1)
                return memo[n];
            memo[n] = std::min(cost[n] + dp(n - 2), cost[n] + dp(n - 1));

            return memo[n];
        };

        cost.push_back(0);
        return dp(sz(cost) - 1);
    }
};
