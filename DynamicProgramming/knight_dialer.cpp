const int mod = 1e9 + 7;

class Solution {
public:
    int dp(int row, int col, int n)
    {
        if (row == 3 && (col == 0 || col == 2))
            return 0;

        if (row < 0 || row > 3 || col < 0 || col > 2)
            return 0;

        if (n == 0)
            return 1;

        if (memo[n][row][col] != -1)
            return memo[n][row][col];

        /*Two square horizonatally and one square vertically*/
        int result = dp(row - 1, col + 2, n - 1) % mod;

        result = (result + dp(row - 1, col - 2, n - 1)) % mod;

        result = (result + dp(row + 1, col + 2, n - 1)) % mod;

        result = (result + dp(row + 1, col - 2, n - 1)) % mod;

        /*Two square vertically and one square horizonatlly*/
        result = (result + dp(row - 2, col + 1, n - 1)) % mod;

        result = (result + dp(row - 2, col - 1, n - 1)) % mod;

        result = (result + dp(row + 2, col + 1, n - 1)) % mod;

        result = (result + dp(row + 2, col - 1, n - 1)) % mod;


        return memo[n][row][col] = result;
    }

    int knightDialer(int n) {
        int result = 0;

        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(4, vector<int>(4, -1)));


        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == 3 && (col == 0 || col == 2))
                    continue;

                result = (result + dp(row, col, n - 1)) % mod;
            }
        }

        return result;
    }
private:
    vector<vector<vector<int>>> memo;
};
