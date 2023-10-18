class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.size(); // length of word1
        int m = (int)word2.size(); // length of word2

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= m; i++)
            memo[n][i] = m - i; // operations required to convert empty string to a string of length `m - i`

        for (int i = 0; i <= n; i++)
            memo[i][m] = n - i; // operations required to convert a string of length `n - i` to empty string

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                    memo[i][j] = memo[i + 1][j + 1];

                else
                    memo[i][j] = std::min(memo[i + 1][j + 1], std::min(memo[i + 1][j], memo[i][j + 1])) + 1;
            }
        }

        return memo[0][0];
    }
};
