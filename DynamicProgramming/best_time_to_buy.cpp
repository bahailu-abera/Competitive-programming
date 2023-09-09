class Solution {
public:
    int dp(vector<int>& prices, int idx, int buy)
    {
        int profit = 0;

        if (idx == (int)prices.size())
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        if (buy)
        {
            profit = max(profit, prices[idx] + dp(prices, idx + 1, 0) - fee);
            profit = max(profit, dp(prices, idx + 1, 1));
        }
        else
        {
            profit = max(profit, dp(prices, idx + 1, 1) - prices[idx]);
            profit = max(profit, dp(prices, idx + 1, 0));
        }

        return memo[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int f) {
        int n = (int)prices.size();
        fee = f;

        memo = vector<vector<int>>(n, vector<int>(2, -1));

        return dp(prices, 0, 0);
    }
private:
    vector<vector<int>> memo;
    int fee;
};
