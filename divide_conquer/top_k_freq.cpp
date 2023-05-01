class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        vector<int>modes(k);

        for (int n : nums) hash[n]++;

        int length = int(hash.size());
        vector<pair<int, int>> freqArray(length);
        int i = 0;
        for (auto it = hash.begin(); it != hash.end(); ++it)
        {
            freqArray[i++] = make_pair(it->first, it->second);
        }

        quick_select(freqArray, 0, length - 1, length - k);

        i = 0;
        while (i < k)
            modes[i++] = freqArray[length - i - 1].first;

        return (modes);
    }

private:
    void quick_select(vector<pair<int, int>>&array, int low, int high, int k)
    {
        if (low == high)
            return;

        int pivotIndex = partition(array, low, high);
        if (pivotIndex == k)
            return;

        else if (pivotIndex > k)
            quick_select(array, low, pivotIndex - 1, k);

        else
            quick_select(array, pivotIndex + 1, high, k);
    }

    void iter_swap(vector<pair<int, int>> &array, int i, int j)
    {
        pair<int, int> tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    int partition(vector<pair<int, int>> &array, int low, int high)
    {
        pair<int, int> pivot = array[high];
        int i = low;

        for (int j = low; j < high; j++)
        {
            if (array[j].second <= pivot.second)
            {
                if (i != j)
                    iter_swap(array, i, j);
                i++;
            }
        }

        iter_swap(array, i, high);

        return i;
    }
};
