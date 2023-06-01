class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = (int)arr.size();
        int r = n - 2;

        while (r >= 0 && arr[r] <= arr[r + 1]) r--;

        if (r < 0)
            return arr;

        int j = r + 1;
        while (j < n && arr[j] < arr[r]) j++;

        j--;
        while (arr[j] == arr[j - 1]) j--;

        swap(arr[r], arr[j]);

        return arr;
    }
};
