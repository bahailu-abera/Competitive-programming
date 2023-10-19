class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = (int)rating.size();
        int result = 0;
        vector<int> greater(n);
        vector<int> smaller(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (rating[i] < rating[j])
                    greater[i]++;
                else
                    smaller[i]++;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[j] > rating[i])
                    result += greater[j];
                else
                    result += smaller[j];
            }
        }

        return result;
    }
};
