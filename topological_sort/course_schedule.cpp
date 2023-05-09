class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        queue<int> Q;
        int visited = 0;

        for (auto & preq: prerequisites)
        {
            graph[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }

        while (!Q.empty())
        {
            int current = Q.front();
            Q.pop();
            visited++;

            for (int adj : graph[current])
            {
                if (--indegree[adj] == 0)
                    Q.push(adj);
            }
        }

        return visited == numCourses;
    }
};
