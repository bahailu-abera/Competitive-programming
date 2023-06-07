class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = (int)triangle.size();
        vector<int> prev(rows, 1e5);

        prev[0] = triangle[0][0];
        for (int i = 1; i < rows; i++)
        {
            int cols = (int)triangle[i].size();

            for (int j = cols - 1; j > 0; j--)
                prev[j] = triangle[i][j] + std::min(prev[j - 1], prev[j]);

            prev[0] += triangle[i][0];
        }

        return *min_element(prev.begin(), prev.end());
    }
};
