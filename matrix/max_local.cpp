class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int rows = g.size() - 2;
        int cols = g[0].size() - 2;
        vector<vector<int>> maxLocal(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                maxLocal[i][j] = max({g[i][j], g[i][j + 1], g[i][j + 2], g[i + 1][j],
				      g[i + 1][j + 1], g[i + 1][j + 2], g[i + 2][j], g[i + 2][j + 1], g[i + 2][j + 2]});
            }
        }

        return maxLocal;
    }
};
