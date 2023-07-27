/**
Solution 1: recursive based dp solution
 **/
class Solution {
public:
    int dp(int current, int target, vector<int>& memo)
    {
        int least = 1e5;

        if (target <= 1)
            return target;

        if (memo[target] != -1)
            return memo[target];

        for (int i = current; i > 0; i--)
        {
            int left = target - (i * i);

            least = std::min(least, dp(sqrt(left), left, memo) + 1);
        }

        return memo[target] = least;
    }

    int numSquares(int n) {
        int root = sqrt(n);
        vector<int> memo(n + 1, -1);

        return dp(root, n, memo);
    }
};

/**
Solution 2: bottom up dp solution
**/
class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n);
        vector<int> memo(n + 1, 1e5);

        memo[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int root = sqrt(i);

            for (int r = 1; r <= root; r++)
            {
                int left =  i - (r * r);

                memo[i] = std::min(memo[i], memo[left] + 1);
            }
        }

        return memo[n];
    }
};
