class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> rows(r, 0);
        vector<int> cols(c, 0);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                if (matrix[i][j] == 0)
                    rows[i] = 1, cols[j] = 1;
        }

       for (int i = 0; i < r; i++)
       {
           for (int j = 0; j < c; j++)
           {
               if (rows[i] || cols[j])
                    matrix[i][j] = 0;
           }
       }

    }
};
