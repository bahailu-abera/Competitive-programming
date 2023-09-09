class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> given(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                given[i] = given[i - 1] + 1;
        }

        int total = given[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                given[i] = max(given[i], given[i + 1] + 1);

            total += given[i];
        }

        return total;
    }
};
