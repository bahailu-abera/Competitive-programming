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
    int result = 0;

    int helper(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        result += abs(left), result += abs(right);

        int total = left + right + root->val - 1;

        return total;
    }

    int distributeCoins(TreeNode* root) {
        helper(root);

        return result;
    }
};
