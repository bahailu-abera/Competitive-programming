class Solution {
public:
    int backtrack(vector<int>& stones, int index, int sum)
    {
        if (index == (int)stones.size())
        {
            if (sum < 0)
                return INT_MAX;

            return sum;
        }

        if (memo[index][sum + 3000] != -1)
            return memo[index][sum + 3000];

        return memo[index][sum + 3000] = min(backtrack(stones, index + 1, sum + stones[index]), backtrack(stones, index + 1, sum - stones[index]));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int length = 1e4;
        int n = (int)stones.size();

        memo = vector<vector<int>>(n, vector<int>(length, -1));

        return backtrack(stones, 0, 0);
    }
private:
    vector<vector<int>> memo;
};
