class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();
       int n = rows * cols;

       int left = 0, right = cols, bottom = rows, top = 0;
       vector<int> spiral;
       spiral.reserve(n);

       while (left < right && top < bottom)
       {
           /* get all the elements at the top row */
           for (int i = left; i < right; i++)
                spiral.push_back(matrix[top][i]);
            top += 1; /* move down our top pointer */

            /* get all the elements at the right column */
            for (int i = top; i < bottom; i++)
                spiral.push_back(matrix[i][right - 1]);
            right -= 1; /* move our right pointer to the left */

            if (!(left < right && top < bottom))
                break;

            /* get all the elements at the bottom */
            for (int i = right - 1; i >= left; i--)
                spiral.push_back(matrix[bottom - 1][i]);
            bottom -= 1; /* move the bottom pointer up */

            /* get all the elements at the left column */
            for (int i = bottom - 1; i >= top; i--)
                spiral.push_back(matrix[i][left]);
            left += 1; /* move our left pointer to the right */
       }

       return spiral;
    }
};
