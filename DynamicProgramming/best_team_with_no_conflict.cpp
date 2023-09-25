class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int highest = 0;
        int n = (int)scores.size();

        vector<int> index;

        for (int i = 0; i < n; i++)
            index.push_back(i);

        auto compare = [&](int i, int j)
        {
            if (ages[i] == ages[j])
                return scores[i] < scores[j];

            return ages[i] < ages[j];
        };

        sort(index.begin(), index.end(), compare);

        vector<int> memo(n);

        for (int i = 0; i < n; i++)
        {
            memo[i] = scores[index[i]];

            for (int j = 0; j < i; j++)
            {
                if (scores[index[j]] <= scores[index[i]])
                    memo[i] = max(memo[i], memo[j] + scores[index[i]]);
            }

            highest = max(highest, memo[i]);
        }

        return highest;
    }
};
