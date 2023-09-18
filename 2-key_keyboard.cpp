class Solution {
public:
    int backtrack(int written, int copied, int n)
    {
        int result = 1e9;

        if (written == n)
            return 0;

        if (written > n)
            return 1e9;

        if (memo[written][copied] != -1)
            return memo[written][copied];

        if (written > copied)
            result = min(result, backtrack(written, written, n));

        if (copied > 0)
            result = min(result, backtrack(written + copied, copied, n));

        return memo[written][copied] = result + 1;
    }

    int minSteps(int n) {
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return backtrack(1, 0, n);
    }

private:
    vector<vector<int>> memo;
};
