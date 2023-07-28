/**
Solution 1: recursive dp
**/
class Solution {
public:
    int dp(vector<int> &nums, int target, vector<int>& memo)
    {
        if (target == 0)
            return 1;

        if (target < 0)
            return (0);

        if (memo[target] != -1)
            return memo[target];

        int answer = 0;

        for (int num : nums)
            answer += dp(nums, target - num, memo);

        return memo[target] = answer;
    }


    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);

        return dp(nums, target, memo);
    }
};

/**
Solution 2: bottom up dp
**/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> memo(target + 1, 0);

        memo[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0)
                    memo[i] += memo[i - num];
            }
        }

        return memo[target];
    }
};
