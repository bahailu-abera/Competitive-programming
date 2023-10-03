class Solution {
public:
    int backtrack(vector<int>& nums, int chosen, int oper)
    {
        int sz = (int)nums.size(), n = sz / 2;
        int result = 0;

        if (oper > n)
            return 0;

        if (memo[chosen][oper] != -1)
            return memo[chosen][oper];

        for (int i = 0; i < sz; i++)
        {
            int mask = (chosen >> i) & 1;

            if (mask)
                continue;

            for (int j = i + 1; j < sz; j++)
            {
                int mask = (chosen >> j) & 1;

                if (mask)
                    continue;

                chosen |= (1 << i);
                chosen |= (1 << j);

                result = max(result, oper * __gcd(nums[i], nums[j]) + backtrack(nums, chosen, oper + 1));

                chosen ^= (1 << i);
                chosen ^= (1 << j);
            }
        }

        return memo[chosen][oper] = result;
    }

    int maxScore(vector<int>& nums) {
        int sz = (int)nums.size(), n = sz / 2;

        memo = vector<vector<int>>(pow(2, sz), vector<int>(n + 1, -1));

        return backtrack(nums, 0, 1);
    }

private:
    vector<vector<int>> memo;
};
