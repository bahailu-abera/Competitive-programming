class Solution {
public:
    int backtrack(vector<vector<int>>& costs, int index, int a)
    {
        int n = (int)costs.size();

        if (index == n)
        {
            if (a == n / 2)
                return 0;

            return 1e9;
        }

        if (memo[index][a] != -1)
            return memo[index][a];

        return memo[index][a] = min(costs[index][0] + backtrack(costs, index + 1,  a + 1), costs[index][1] + backtrack(costs, index + 1, a));
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = (int)costs.size();

        memo = vector<vector<int>>(n, vector<int>(n + 1, -1));

        return backtrack(costs, 0, 0);
    }
private:
    vector<vector<int>> memo;
};
