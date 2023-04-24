class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int m = arr[--n];
        arr[n] = -1;

        for (int i = --n; i >= 0; i--)
        {
            int current = arr[i];
            arr[i] = m;
            if (current > m) m = current;
        }

        return arr;
    }
};
