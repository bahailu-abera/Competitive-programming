class Solution {
public:
    vector<vector<int>> paths;
    void findPath(vector<vector<int>> graph, int current, vector<int>path)
    {
        path.push_back(current);
        if (current == graph.size() - 1)
        {
            paths.push_back(path);
            return ;
        }

        for (auto edge : graph[current])
            findPath(graph, edge, path);

    }

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        findPath(graph, 0, vector<int>());

        return paths;
    }
};
