class Solution {
public:
    int dp(vector<int>& prices, int idx, int buy)
    {
        int profit = 0;

        if ((idx >= (int)prices.size()))
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        if (buy)
        {
            profit = max(profit, prices[idx] + dp(prices, idx + 2, 0)); // sell now
            profit = max(profit, dp(prices, idx + 1, 1)); // skip this day.
        }
        else
        {
            profit = max(profit, dp(prices, idx + 1, 1) - prices[idx]); // but today;
            profit = max(profit, dp(prices, idx + 1, 0)); // skip today;
        }

        return memo[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();

        memo = vector<vector<int>>(n, vector<int>(2, -1));

        return dp(prices, 0, 0);
    }
private:
    vector<vector<int>> memo;
};
