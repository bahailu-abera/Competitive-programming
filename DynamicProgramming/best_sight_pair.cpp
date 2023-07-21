class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = (int)values.size();
        int max_score = 0;
        int prev = values[0];

        for (int j = 1; j < n; j++)
        {
            max_score = std::max(max_score, prev + values[j] - j);
            prev = std::max(prev, values[j] + j);
        }

        return max_score;
    }
};
