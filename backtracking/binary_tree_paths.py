# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorder(self, root, path=""):
        if root:
            path += str(root.val)

            if root.left or root.right:
                path += "->"

            self.preorder(root.left, path)
            self.preorder(root.right, path)

            if not root.left and not root.right:
                self.result.append(path)

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.result = []

        self.preorder(root)

        return self.result
