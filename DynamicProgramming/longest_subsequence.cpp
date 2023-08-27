class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int longest = 0;

        for (int n : arr)
        {
            mp[n] = mp[n - difference] + 1;

            longest = std::max(longest, mp[n]);
        }

        return longest;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = (int)nums.size();
        int longest  = 0;

        int min_value = *min_element(nums.begin(), nums.end());
        int max_value = *max_element(nums.begin(), nums.end());

        int diff = abs(max_value - min_value);

        for (int d = -diff; d <= diff; d++)
            longest = std::max(longest, longestSubsequence(nums, d));

        return longest;
    }
};
