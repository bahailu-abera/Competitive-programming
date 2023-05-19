class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, pair<int, int>>> Q;

        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (mat[i][j] == 0) Q.push({0, {i, j}}), visited[i][j] = true;;

        while (!Q.empty())
        {
            int distance = Q.front().first + 1;
            pair<int, int> Index = Q.front().second;

            Q.pop();
            for (auto& d : directions)
            {
                int row = Index.first + d.first;
                int col = Index.second + d.second;

                if (row >= 0 && row < n && col >= 0 && col < m && !visited[row][col])
                {
                    mat[row][col] = distance;
                    Q.push({distance, {row, col}});
                    visited[row][col] = true;
                }
            }
        }

        return mat;
    }

private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
};
