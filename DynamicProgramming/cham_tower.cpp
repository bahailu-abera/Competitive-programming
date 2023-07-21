class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> memo(query_row + 1,vector<double>(query_row + 1, 0L));

        memo[0][0] = poured;

        for (int i = 1; i <= query_row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j > 0 && memo[i - 1][j - 1] > 1)
                    memo[i][j] = (memo[i - 1][j - 1] - 1) / 2;

                if (j < i && memo[i - 1][j] > 1)
                    memo[i][j] += (memo[i - 1][j] - 1) / 2;
            }
        }

        return std::min(memo[query_row][query_glass], (double)1);
    }
};
