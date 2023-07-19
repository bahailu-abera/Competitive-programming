class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = (int)q.size();
        vector<long long> memo(n + 3, 0);

       for (int i = n - 1; i >= 0; i--)
       {
            long long chose = q[i][0];
            long long skip = memo[i + 1];

            int next = i + q[i][1] + 1;

            if (next < n)
                chose += memo[next];

            memo[i] = std::max(chose, skip);
       }

        return memo[0];
    }
};
