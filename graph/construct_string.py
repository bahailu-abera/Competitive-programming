# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        string = str()

        def dfs(current):
            nonlocal string
            if not current:
                return

            string += str(current.val)

            if not current.left and not current.right:
                return

            string += '('
            dfs(current.left)
            string += ')'

            if current.right:
                string += '('
                dfs(current.right)
                string += ')'

        dfs(root)

        return string
