class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        queue<pair<int, int>> Q;
        int bridges = 0;

        function<bool(int, int)> inbound = [&](int r, int c)
        {
            if (r < n && c < n && r >= 0 && c >= 0)
                return true;

            return false;
        };

        function<void(int, int)> dfs = [&](int row, int col)
        {
            grid[row][col] = 2; // set the current cell as visited;
            Q.push({row, col}); // add the cell to the current island

            for (auto d : directions)
            {
                int new_row = row + d.first;
                int new_col = col + d.second;

                if (inbound(new_row, new_col) && grid[new_row][new_col] == 1)
                    dfs(new_row, new_col);
            }
        };

        int flag = true;
        for (int i = 0; i < n && flag; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                dfs(i, j);
                flag = false;
                break;
            }

        while (!Q.empty())
        {
            int level = Q.size();

            for (int i = 0; i < level; i++)
            {
                pair<int, int> Index = Q.front();
                Q.pop();

                for (auto& d : directions)
                {
                    int new_row = Index.first + d.first;
                    int new_col = Index.second + d.second;

                    if (inbound(new_row, new_col) && grid[new_row][new_col] != 2)
                    {
                        if (grid[new_row][new_col] == 1)
                            return bridges;

                        grid[new_row][new_col] = 2;
                        Q.push({new_row, new_col});
                    }
                }
            }

            bridges++;
        }

        return -1;
    }

private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
};
