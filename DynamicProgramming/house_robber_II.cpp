class Solution {
public:
    int helper(vector<int> &nums, int start, int end)
    {
        int a = 0, b = 0;

        for (int i = start; i <= end; i++)
        {
            int c = std::max(nums[i] + a, b);
            a = b;
            b = c;
        }

        return b;
    }

	int rob(vector<int>& nums) {
	int n = (int)nums.size();

       return std::max(nums[0], std::max(helper(nums, 0, n-2), helper(nums, 1, n-1)));
    }
};
