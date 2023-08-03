class Solution {
public:
    void merge(vector<pair<int, int>>& enumerated, int low, int mid, int high)
    {
        int len_left = mid - low + 1;
        int len_right = high - mid;
        vector<pair<int, int>> left(len_left);
        vector<pair<int, int>> right(len_right);

        for (int i = low; i <= mid; i++)
            left[i - low] = enumerated[i];

        for (int i = mid + 1; i <= high; i++)
            right[i - mid - 1] = enumerated[i];

        int i = 0, j = 0,  k = low;
        int prev = 0;

        while (i < len_left && j < len_right)
        {
            if (left[i].second <= right[j].second)
            {
                enumerated[k] = left[i];
                i++;
            }
            else
            {    
                enumerated[k] = right[j];
                while (prev < len_left &&  left[prev].second < right[j].second)
                {

                    prev ++;
                }

                costs[right[j].first].first += prev;
                costs[right[j].first].second += (len_left - i);
                j++;
            }

            k++;
        }

        while (i < len_left)
        {    
            enumerated[k++] = left[i++];
        }

        while (j < len_right)
        {
            enumerated[k] = right[j];
            while (prev < len_left &&  left[prev].second < right[j].second)
            {
                prev ++;
            }

            costs[right[j].first].first += prev;

            k++;
            j++;
        }
    }

    void divide(vector<pair<int, int>>& enumerated, int low, int high)
    {
        if (high > low)
        {
            int mid = low + (high - low) / 2;

            divide(enumerated, low, mid);
            divide(enumerated, mid + 1, high);

            merge(enumerated, low, mid, high);
        }
    }

    int createSortedArray(vector<int>& instructions) {
        int n = (int)instructions.size();
        int mod = 1e9 + 7;
        int totalCost = 0;

        vector<pair<int, int>> enumerated(n);

        for (int i = 0; i < n; i++)
        {
            enumerated[i] = {i, instructions[i]};
        }

        costs = vector(n, make_pair(0, 0));

        divide(enumerated, 0, n - 1);

        for (auto cost : costs)
        {
            totalCost += std::min(cost.first, cost.second);
            totalCost %= mod;
        }

        return totalCost;
    }
private:
    vector<pair<int, int>> costs;
};
