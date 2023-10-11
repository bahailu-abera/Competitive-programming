class Solution {
public:
    int dp(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        int result = 0;

        if (i >= n || j >= m)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (nums1[i] == nums2[j])
            result = std::max(result, dp(nums1, nums2, i + 1, j + 1) + 1);

        result = std::max(result, dp(nums1, nums2, i + 1, j));

        result = std::max(result, dp(nums1, nums2, i, j + 1));

        return memo[i][j] = result;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memo = vector<vector<int>>((int)nums1.size(), vector<int>((int)nums2.size(), -1));
        return dp(nums1, nums2, 0, 0);
    }
private:
    vector<vector<int>> memo;
};
