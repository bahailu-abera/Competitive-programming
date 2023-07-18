class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int result = 0;

        vector<unordered_map<int, int>> memo(n);

        function<int(int, int)> backtrack = [&](int total, int index)
        {
            if (index < 0 && 0 == total)
                return 1;

            if (index < 0)
                return 0;

            if (memo[index].count(total))
                return memo[index][total];

            memo[index][total] = backtrack(total + -1 * nums[index], index - 1) + backtrack(total + nums[index], index - 1);

            return memo[index][total];
        };

        return backtrack(target, n - 1);
    }
};
