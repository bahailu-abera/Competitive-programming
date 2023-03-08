# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode], max_value = inf, min_value =  -inf) -> bool:
        if root:
            if root.val >= max_value or root.val <= min_value:
                return False
            if not self.isValidBST(root.left, min(max_value, root.val), min_value):
                return False
            return self.isValidBST(root.right, max_value, max(min_value, root.val))

        return True
