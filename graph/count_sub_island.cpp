class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	    ios_base::sync_with_stdio(false); // for fast input and output
        cin.tie(NULL);

        int n = grid1.size();
        int m = grid1[0].size();
        int island = 0;

        function<bool(int, int)> dfs = [&](int r, int c)
        {
            bool flag = true;
            if (grid1[r][c] == 0)
            {
                return false;
            }

            grid1[r][c] = grid2[r][c] = 0;
            for (auto d : directions)
            {
                int new_r = r + d.first;
                int new_c = c + d.second;
                if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m && grid2[new_r][new_c])
                    if (!dfs(new_r, new_c))
                        flag = false;
            }

            return flag;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] && dfs(i, j))
                    island++;

            }
        }

        return island;
    }
private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};
