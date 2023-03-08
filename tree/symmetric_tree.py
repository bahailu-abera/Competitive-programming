# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, left, right):
        if left and right:
            is_left_symmetry = self.traverse(left.left, right.right)
            if left.val != right.val:
                return False
            is_right_symmetry = self.traverse(left.right, right.left)
            return is_left_symmetry and is_right_symmetry

        return left is right


    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        return self.traverse(root.left, root.right)
