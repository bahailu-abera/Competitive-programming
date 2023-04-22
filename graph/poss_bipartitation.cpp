class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if (dislikes.empty()) {
            return true;
        }

        vector<int> colors(n, -1);

        for (const auto& dislike: dislikes)
        {
            if (colors[dislike[0] - 1] == -1)
            {
                colors[dislike[0] - 1] = 0;
                if (!dfs(dislikes, colors, dislike[0])) {
                    return false;
                }
            }

            if (colors[dislike[1] - 1] == -1)
            {
                colors[dislike[1] - 1] = 0;
                if (!dfs(dislikes, colors, dislike[1])) {
                    return (false);
                }
            }
        }

        return true;

    }

    bool dfs(const vector<vector<int>>& dislikes, vector<int>& colors, int current) {
        for (const auto& dislike : dislikes) {
            int neighbor;

            if (dislike[0] == current) {
                neighbor = dislike[1];
            } else if (dislike[1] == current) {
                neighbor = dislike[0];
            } else {
                continue;
            }

            if (colors[neighbor - 1] == colors[current - 1]) {
                return false;
            }

            if (colors[neighbor - 1] == -1) {
                colors[neighbor - 1] = colors[current - 1] ^ 1;
                if (!dfs(dislikes, colors, neighbor)) {
                    return false;
                }
            }
        }

        return true;
    }
};
