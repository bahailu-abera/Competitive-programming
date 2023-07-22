class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long result = 0;
        long long prefix_sum = 0;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            prefix_sum += nums[i];
            result = std::max(result, (prefix_sum + i) / (i + 1));
        }

        return result;
    }
};
