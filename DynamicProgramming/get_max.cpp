class Solution {
public:
    int getMaximumGenerated(int n) {
       vector<int> nums(n + 1);

        if (n < 2)
            return n;

	nums[0] = 0;
       nums[1] = 1;

       for (int i = 2; i <= n; i++)
       {
           if (i % 2 == 0)
                nums[i] = nums[i / 2];

            else
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
       }

       return *max_element(nums.begin(), nums.end());
    }
};
