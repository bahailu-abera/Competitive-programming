class Solution {
public:
    bool canWeMake(vector<int>& bloomDay, int m, int k, int day)
    {
        int n = (int)bloomDay.size();
        int current = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
                current++;
            else
                current = 0;

            if (current == k)
                m--, current = 0;

            if (m == 0)
                return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();
        int mx = *max_element(bloomDay.begin(), bloomDay.end());

        int left = 1, right = mx;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canWeMake(bloomDay, m, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left > mx)
            return -1;

        return left;
    }
};
