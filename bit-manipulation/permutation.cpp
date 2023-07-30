class Solution {
public:
    void backtrack(vector<int> chosen, vector<int>nums, int used)
    {
        if (chosen.size() == nums.size())
        {
            permutations.push_back(chosen);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int mask = (used >> i) & 1;

            if (mask)
                continue;

            chosen.push_back(nums[i]);
            used |= (1 << i);

            backtrack(chosen, nums, used);

            used ^= (1 << i);
            chosen.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(vector<int>(), nums, 0);

        return permutations;
    }

private:
    vector<vector<int>> permutations;
};
