/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> graph(500);
        vector<bool> visited(500, false);

        function<void(TreeNode*)> buildGraph = [&](TreeNode* current)
        {
            if (current == nullptr)
                return;

            if (current->left != nullptr)
            {
                graph[current->val].push_back(current->left->val);
                graph[current->left->val].push_back(current->val);
            }

            if (current->right != nullptr)
            {
                graph[current->val].push_back(current->right->val);
                graph[current->right->val].push_back(current->val);
            }

            buildGraph(current->left);
            buildGraph(current->right);
        };

        buildGraph(root);

        queue<int> Q;
        Q.push(target->val);
        visited[target->val] = true;

        while (!Q.empty() && k > 0)
        {
            int level = Q.size();
            for (int i = 0; i < level; i++)
            {
                int current = Q.front();
                Q.pop();

                for (int adj : graph[current])
                {
                    if (!visited[adj])
                        Q.push(adj), visited[adj] = true;;
                }
            }
            k--;
        }

        if (k)
            return {};

        vector<int> result;
        while (!Q.empty())
            result.push_back(Q.front()), Q.pop();

        return result;
    }
};
