class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();

        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[3];

        for (int i = 0; i < n; i++)
        {
            int two_sum_target = target - nums[i];

            int left = 0, right = n - 1;

            while (left < right)
            {
                if (left == i)
                    left++;

                else if (right == i)
                    right--;

                else
                {
                    int current = nums[left] + nums[right];

                    if (current < two_sum_target)
                        left++;

                    else
                        right--;

                    current += nums[i];

                    if (abs(current - target) < abs(result - target))
                        result = current;
                }
            }
        }

        return result;
    }
};
