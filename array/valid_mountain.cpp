class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i;

        if (n < 3)
            return (false);

        for (i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                return false;

            if (arr[i] < arr[i - 1])
            {
                if (i == 1)
                    return false;
                break;
            }
        }

        if (i == n)
            return (false);

        for (; i < n - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                return (false);
        }

        return (true);
    }
};
