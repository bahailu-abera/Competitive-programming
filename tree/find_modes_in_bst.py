from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.visited = None
        self.max_count = 0
        self.count = 0
        self.modes = []

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            if not self.modes or self.visited != root.val:
                self.count = 1
            else:
                self.count += 1

            if self.count == self.max_count:
                self.modes.append(root.val)
            elif self.count > self.max_count:
                    self.modes = [root.val]
            self.visited = root.val
            self.max_count = max(self.max_count, self.count)
            self.inorder(root.right)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.inorder(root)
        return self.modes
