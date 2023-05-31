class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 1e9);

        memo[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            int res = 1e9;
            for (int c : coins)
            {
                if (i - c >= 0)
                    res = std::min(res, memo[i - c]);
            }

            memo[i] = res + 1;
        }

        return memo[amount] < 1e9 ? memo[amount]: -1;
    }
};
