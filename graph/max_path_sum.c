 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a, b) ((a) > (b) ? (a) : (b))

int preorder(struct TreeNode* root, int *max_sum)
{
    int left, right, current, total;

    if (!root)
        return (0);

    left = preorder(root->left, max_sum);
    right = preorder(root->right, max_sum);

    total = left + right + root->val;
    current = max(total, root->val);
    current = max(current, root->val + max(left, right));
    *max_sum = max(*max_sum, current);

    return max(root->val, root->val + max(left, right));
}

int maxPathSum(struct TreeNode* root){
    int max_sum = INT_MIN;

    preorder(root, &max_sum);

    return (max_sum);
}
