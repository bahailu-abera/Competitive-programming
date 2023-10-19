class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int count = 0;
        vector<vector<int>> prefers(n, vector<int>(n));
        vector<bool> unhappy(n, false);

        for (int i = 0; i < n; i++)
        {
            int p = n;
            for (int pref: preferences[i])
            {
                prefers[i][pref] = p--;
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (i == j)
                    continue;

                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];

                if (prefers[x][u] > prefers[x][y] && prefers[u][x] > prefers[u][v])
                    unhappy[x] = true;

                if (prefers[x][v] > prefers[x][y] && prefers[v][x] > prefers[v][u])
                    unhappy[x] = true;

                if (prefers[y][u] > prefers[y][x] && prefers[u][y] > prefers[u][v])
                    unhappy[y] = true;

                if (prefers[y][v] > prefers[y][x] && prefers[v][y] > prefers[v][u])
                    unhappy[y] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (unhappy[i])
                count++;
        }

        return count;
    }
};
