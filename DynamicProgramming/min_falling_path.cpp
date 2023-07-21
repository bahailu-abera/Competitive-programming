class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        vector<int> prev = mat[0];
        prev.push_back(1e9);

        for (int i = 1; i < n; i++)
        {
            vector<int> tmp = prev;
            for (int j = 1; j < n; j++)
            {
                prev[j] = mat[i][j] + std::min(tmp[j - 1], std::min(tmp[j], tmp[j + 1]));
            }

            prev[0] = mat[i][0] + std::min(tmp[0], tmp[1]);
        }

        return *min_element(prev.begin(), prev.end());
    }
};
