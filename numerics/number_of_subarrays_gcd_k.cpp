class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int gcd = nums[i];
            for (int j = i; j >= 0; j--)
            {
                gcd = __gcd(gcd, nums[j]);
                count  += (k == gcd);
            }
        }

        return count;
    }
};
