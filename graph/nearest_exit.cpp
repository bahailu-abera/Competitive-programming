class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int min_path = 0;

        queue<pair<int, pair<int, int>>> Q;
        Q.push({0, {entrance[0], entrance[1]}});
        maze[entrance[0]][entrance[1]] = '+'; // mark as walls because we don't need to visit again

        while (!Q.empty())
        {
            int dis = Q.front().first;
            pair<int, int> Index = Q.front().second;
            Q.pop();

            if (dis != 0 && (Index.first == n - 1 || Index.second == m - 1 || Index.first == 0 || Index.second == 0))
                return dis;

            for (auto &d : directions)
            {
                int row = d.first + Index.first;
                int col = d.second + Index.second;

                if (row >= 0 && row < n && col >= 0 && col < m && maze[row][col] == '.')
                    maze[row][col] = '+', Q.push({dis + 1, {row, col}});
            }
        }

        return -1;
    }

private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};
