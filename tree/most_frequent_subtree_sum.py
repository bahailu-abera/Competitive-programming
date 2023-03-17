from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.freq = defaultdict(int)
        self.top_frequent = 0

    def preorder(self, root):
        if not root:
            return 0

        left = self.preorder(root.left)
        right = self.preorder(root.right)
        total = left + right + root.val

        self.freq[total] += 1
        self.top_frequent = max(self.top_frequent , self.freq[total])

        return total

    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        self.preorder(root)

        modes = []

        for value, freq in self.freq.items():
            if freq == self.top_frequent:
                modes.append(value)

        return modes
