class Solution {
public:
    int dp(string& s, int i, int j)
    {
        int result = 0;

        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == s[j])
            result = dp(s, i + 1, j - 1) + 2;

        result = max(result, dp(s, i + 1, j));
        result = max(result, dp(s, i, j - 1));

        return memo[i][j] = result;
    }

    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));

        return dp(s, 0, n - 1);
    }
private:
    vector<vector<int>> memo;
};
