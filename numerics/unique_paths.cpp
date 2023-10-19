class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int r = m - 1, d = n - 1;
        int steps = r + d;
        int k = min(r, d);

        for (int i = 0; i < k; i++) {
            result *= steps;
            result /= i + 1;
            steps--;
        }

        return result;
    }
};
