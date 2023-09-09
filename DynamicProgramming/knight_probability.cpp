class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));

        function<double(int, int, int)> dp = [&](int r, int c, int k) {
            if (r < 0 || r >= n || c < 0 || c >= n)
                return 0.0;

            if (k == 0)
                return 1.0;

            if (memo[r][c][k] != -1.0)
                return memo[r][c][k];

            double prob = 0;

            for (auto dir : directions)
            {
                prob += dp(dir.first + r, dir.second + c, k - 1);
            }

            return  memo[r][c][k] = prob / 8;
        };

        return dp(row, column, k);
    }
private:
    vector<pair<int, int>> directions = {
        {-1, 2},
        {-1, -2},
        {1, 2},
        {1, -2},
        {-2, 1},
        {-2, -1},
        {2, 1},
        {2, -1},
    };
};
