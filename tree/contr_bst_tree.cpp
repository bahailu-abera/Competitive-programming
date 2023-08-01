/**
First Attempt
**/
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
    TreeNode* builder(vector<int>& preorder, int start, int end)
    {
        int n = (int)preorder.size();

        if (start >= end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[start]);

        int right = start;

        for (; right < end; right++)
        {
           if (preorder[right] > preorder[start])
                break;
        }

        start++;

        if (start < end && preorder[start] < preorder[start - 1])
            root->left = builder(preorder, start, right);

        root->right = builder(preorder, right, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

	    return builder(preorder, 0, (int)preorder.size());
    }
};


/**
Updated version
**/
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
    TreeNode* build(vector<int>& preorder, int& current, int bound)
    {
        int n = (int)preorder.size();

        if (current >= n || preorder[current] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[current++]);

        // passing by reference current is at the right positon
        // for the right subtree
        root->left = build(preorder, current, root->val);
        root->right = build(preorder, current, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int current = 0;

        return build(preorder, current, 1e4);
    }
};
