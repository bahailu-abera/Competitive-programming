# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorder(self, root):
        if not root: return 0, 0
        if not root.left and not root.right:
            self.valids += 1
            return root.val, 1
        # Calculate the total sum of the left subtree
        left_subtree_sum, left_count = self.postorder(root.left)
        # Calculate the total sum of right subtree
        right_subtree_sum, right_count  = self.postorder(root.right)

        # Calculate the total sum of the current subtree
        total = root.val + left_subtree_sum + right_subtree_sum
        # Calculate the number of nodes in the current subtree
        count = left_count + right_count + 1

        if total // count == root.val:
            self.valids += 1

        return total, count

    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        self.valids = 0
        self.postorder(root)

        return self.valids
