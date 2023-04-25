class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lower = 0;
        int t = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < target) lower++;
            else if (nums[i] == target) t++;

        vector<int> ans(t);
        for (int i = 0; i < t; i++)
            ans[i] = lower + i;

        return ans;
    }
};
