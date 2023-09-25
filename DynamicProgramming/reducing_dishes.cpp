class Solution {
public:
    int backtrack(vector<int>& satisfaction, int index, int coef)
    {
        int n = (int)satisfaction.size();

        if (n == index)
            return 0;

        if (memo[index][coef] != -1)
            return memo[index][coef];

        int take = satisfaction[index] * coef + backtrack(satisfaction, index + 1, coef + 1);
        int not_take = backtrack(satisfaction, index + 1, coef);

        return memo[index][coef] = max(take, not_take);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = (int)satisfaction.size();

        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

        sort(satisfaction.begin(), satisfaction.end());

        return backtrack(satisfaction, 0, 1);
    }
private:
    vector<vector<int>> memo;
};
