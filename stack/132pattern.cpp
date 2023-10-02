class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = (int)nums.size();
        stack<int> S;

        vector<int> left_min(n);

        left_min[0] = nums[0];

        for (int i = 1; i < n; i++)
            left_min[i] = min(nums[i], left_min[i - 1]);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!S.empty() && nums[S.top()] <= nums[i])
            {
                int index = S.top();
                S.pop();

                if (nums[i] > nums[index] && nums[index] > left_min[i])
                    return true;
            }

            S.push(i);
        }

        return false;
    }
};
