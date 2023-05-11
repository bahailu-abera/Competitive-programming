what is wrong with the following algorithm

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
// Code here
unordered_set<int> visited;

clojure
Copy
    function<bool(int, int)> dfs = [&](int vertex, int parent)
    {
        visited.insert(vertex);

        for (int e : adj[vertex])
        {
            if (!visited.count(e))
            {
                if (dfs(e, vertex))
                    return true;
            }

            else if (e != parent)
                return true;
        }
        
        return false;
    };
    
    for (int i = 0; i < adj->size(); i++)
    {
        if (!visited.count(i) && dfs(i, -1))
        {
            return true;
        }
    }
    
    return false;
}
};

//{ Driver Code Starts.
int main() {
int tc;
cin >> tc;
while (tc--) {
int V, E;
cin >> V >> E;
vector<int> adj[V];
for (int i = 0; i < E; i++) {
int u, v;
cin >> u >> v;
adj[u].push_back(v);
adj[v].push_back(u);
}
Solution obj;
bool ans = obj.isCycle(V, adj);
if (ans)
cout << "1\n";
else
cout << "0\n";
}
return 0;
}
// } Driver Code Ends
