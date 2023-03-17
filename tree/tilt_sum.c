/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>

int helper(struct TreeNode* root, int *sum)
{
    int left_sum, right_sum;

    if (!root)
        return (0);

    if (!root->left && !root->right)
        return (root->val);

    left_sum = helper(root->left, sum);
    right_sum = helper(root->right, sum);

    *sum += abs(left_sum - right_sum);

    return (left_sum + right_sum + root->val);
}
int findTilt(struct TreeNode* root){
    int tilt_sum = 0;

    helper(root, &tilt_sum);

    return (tilt_sum);
}
