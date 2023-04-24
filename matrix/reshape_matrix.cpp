class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();

        if (rows * cols != r * c)
            return mat;

        vector<vector<int>> reshaped(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int index = i * c + j;
                int row = index / cols;
                int col = index % cols;
                reshaped[i][j] = mat[row][col];
            }
        }

        return reshaped;
    }
};
