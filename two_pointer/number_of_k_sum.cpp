class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> hash;
        int operations = 0;

        for (auto n : nums)
        {
            if (hash[k - n] != 0)
            {
                operations += 1, hash[k - n] -= 1;
            }
            else
                hash[n] += 1;
        }

        return (operations);
    }
};
