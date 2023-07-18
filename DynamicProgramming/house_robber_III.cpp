/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (memo.count(root))
            return memo[root];

        int left = rob(root->left);
        int right = rob(root->right);

        int current = root->val;

        if (root->left != nullptr)
        {
            current += rob(root->left->left);
            current += rob(root->left->right);
        }

        if (root->right != nullptr)
        {
            current += rob(root->right->left);
            current += rob(root->right->right);
        }

        memo[root] = std::max(current, left + right);

        return memo[root];
    }
};
