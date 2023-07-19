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
};
