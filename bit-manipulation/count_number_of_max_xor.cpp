class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = (int)nums.size();
        int num_subsets = pow(2, n);

        int max_xor = 0;
        unordered_map<int, int> freq;

        for (int i = 1; i <= num_subsets; i++)
        {
            int current_xor = 0;

            for (int j = 0; j < n; j++)
            {
                int mask = (i >> j) & 1;

                if (mask)
                    current_xor |= nums[j];
            }

            max_xor = std::max(max_xor, current_xor);

            freq[current_xor]++;
        }

        return freq[max_xor];
    }
};
