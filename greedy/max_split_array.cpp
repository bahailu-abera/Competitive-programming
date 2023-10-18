/**
Dp Solution O(N)
**/

// class Solution {
// public:
//     int dp(vector<int>& nums, int prev, int flag, int i)
//     {
//         if (i >= (int)nums.size())
//         {
//             if (prev != 0)
//                 return -1e6;

//             return 1;
//         }

//         if (memo[flag][i] != -1)
//             return memo[flag][i];

//         int result = 0;

//         if (flag)
//         {
//             result = dp(nums, nums[i], nums[i] == 0,  i + 1) + 1;
//         }

//         result = max(result, dp(nums, prev & nums[i], (prev & nums[i]) == 0, i + 1));

//         return memo[flag][i] = result;
//     }

//     int maxSubarrays(vector<int>& nums) {
//         int n = (int)nums.size();
//         memo = vector<vector<int>>(2, vector<int>(n, -1));
//         int res = nums[0];

//         for (int i = 1; i < n; i++)
//             res &= nums[i];

//         if (res > 0)
//             return 1;

//         return dp(nums, nums[0], nums[0] == 0, 1);
//     }
// private:
//     vector<vector<int>> memo;
// };


/**
Greedy solution.
**/

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = (int)nums.size();
        int result = 0;
        int res = nums[0];

        for (int i = 1; i < n; i++)
            res &= nums[i];

        if (res > 0)
            return 1;

        res = nums[0];

        nums.push_back(nums[n - 1]);

        for (int i = 0; i < n; i++)
        {
            res &= nums[i];

            if (res == 0)
                result++, res = nums[i + 1];
        }

        return result;
    }
};
