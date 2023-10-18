class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int total = std::accumulate(nums.begin(), nums.end(), 0);

        struct HASH{
            size_t operator()(const pair<int,int>&x)const{
                return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
            }
        };

        unordered_map<pair<int,int>,bool,HASH>mp;

        if (total % 2)
            return false;

        function<bool(int, int)> dp = [&](int index, int target)
        {
            if (total - target == target)
                return true;

            if (index >= n || mp[{index, target}])
                return false;

            mp[{index, target}] = true;
            return dp(index + 1, target + nums[index]) || dp(index + 1, target);
        };

        return dp(0, 0);
    }
};
