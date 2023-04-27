class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        queue<TreeNode*> Q;

        Q.push(root);
        while (!Q.empty())
        {
            double total = 0;
            int count = 0;

            int size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                total += node->val;
                count += 1;
                if (node->left != nullptr)
                    Q.push(node->left);


                if (node->right != nullptr)
                    Q.push(node->right);
            }

            average.push_back(total / (double)count);
        }

        return average;
    }
};
