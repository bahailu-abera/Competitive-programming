class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = (int)dungeon.size();
        int n = m > 0 ? (int)dungeon[0].size() : 0;

        vector<vector<int>> memo(m, vector<int>(n));

        memo[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        for (int row = m - 2; row >= 0; row--)
        {
            memo[row][n - 1] = max(1, memo[row + 1][n - 1] - dungeon[row][n - 1]);
        }

        for (int col = n - 2; col >= 0; col--)
        {
            memo[m - 1][col] = max(1, memo[m - 1][col + 1] - dungeon[m - 1][col]);
        }

        for (int row = m - 2; row >= 0; row--)
        {
            for (int col = n - 2; col >= 0; col--)
            {
                memo[row][col] = max(1, min(memo[row + 1][col], memo[row][col + 1]) - dungeon[row][col]);
            }
        }

        return memo[0][0];
    }
};
