class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingred, vector<string>& supplies) {
        vector<string> result;
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        unordered_map<string, bool> supply(supplies.size());
        queue<string> Q;


        for (const auto& s : supplies) {
            supply.emplace(s, true);
        }

        for (int i = 0; i < ingred.size(); i++)
        {
            for (auto s : ingred[i])
            {
                graph[s].push_back(recipes[i]);
                if (supply[s] == false) indegree[recipes[i]]++;
            }

            if (indegree[recipes[i]] == 0) Q.push(recipes[i]);
        }

        while (!Q.empty())
        {
            string current = Q.front();
            Q.pop();
            result.push_back(current);

            for (auto s: graph[current])
            {
                if (--indegree[s] == 0)
                    Q.push(s);
            }
        }

        return result;
    }
};
