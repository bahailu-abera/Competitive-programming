class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        tuple<int, int, int> t(0, 0, 1);
        int n = int(grid.size());
        queue<tuple<int, int, int>> Q;

        n -= 1;
        vector<vector<int>> directions  = { {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1},{-1, -1}, {-1, 1}, {1, -1}
        };

        Q.push(t);
        while (!Q.empty())
        {
            tuple<int, int, int> t = Q.front();
            Q.pop();

            if (grid[get<0>(t)][get<1>(t)] == 1)
                continue;

            if (get<0>(t) == n && get<1>(t) == n)
                return get<2>(t);

            grid[get<0>(t)][get<1>(t)] =  1;
            for (auto dir : directions)
            {
                int x = get<0>(t) + dir[0];
                int y = get<1>(t) + dir[1];
                if (x >= 0 && x <= n && y >= 0 && y <= n && grid[x][y] == 0)
                    Q.push({x, y, get<2>(t) + 1});
            }
        }
        return -1;
    }
};
