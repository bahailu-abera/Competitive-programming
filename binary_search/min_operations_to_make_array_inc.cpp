class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> unique;
        unordered_set<int> visited;
        int result = n;


        for (int n : nums)
        {
            if (!visited.count(n))
                unique.push_back(n);

            visited.insert(n);
        }

        sort(unique.begin(), unique.end());

        for (int i = 0; i < (int)unique.size(); i++)
        {
            int num = unique[i];

            auto right = upper_bound(unique.begin() + i, unique.end(), num + n - 1);

            int count = distance(unique.begin() + i, right);

            result = min(result, n - count);
        }

        return result;
    }
};
