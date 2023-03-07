/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p && q)
    {
        if (p->val != q->val)
                return (false);
        if (!isSameTree(p->left, q->left))
            return (false);
        return isSameTree(p->right, q->right);
    }
    return (p == q);
}
