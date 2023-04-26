class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int to_sort = arr.size();
        vector<int> ans;

        for (int i = to_sort; i > 0; i--)
        {
            auto iter = find(arr.begin(), arr.end(), i);
            int index = iter - arr.begin();

            if (index != i - 1)
            {
                if (index != 0)
                {
                    ans.push_back(index + 1);
                    reverse(arr.begin(), next(iter, 1));
                }
                ans.push_back(i);
                reverse(arr.begin(), next(arr.begin(), i));
            }
        }

        return ans;
    }
};
