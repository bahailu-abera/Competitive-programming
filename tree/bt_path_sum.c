/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool preorder(struct TreeNode* root, int targetSum, int path_sum)
{
    if (root)
    {
        path_sum += root->val;
        if (!root->left && !root->right)
            return path_sum == targetSum;

        return preorder(root->left, targetSum , path_sum) || preorder(root->right, targetSum, path_sum);
    }

    return (false);
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    return preorder(root, targetSum, 0);
}
