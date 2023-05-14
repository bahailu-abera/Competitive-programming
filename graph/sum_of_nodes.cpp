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
    int sumEvenGrandparent(TreeNode* root, int parent=-1, int grandparent=-1) {
       if (!root)
            return 0;

        int sum = 0;

        if ((grandparent != -1) && (grandparent % 2 == 0))
            sum += root->val;

        sum += sumEvenGrandparent(root->left, root->val, parent);
        sum += sumEvenGrandparent(root->right, root->val, parent);

        return sum;
    }
};
