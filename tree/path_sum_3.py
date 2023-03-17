from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.my_dct = defaultdict(int)
        self.my_dct[0] = 1
        self.count = 0

    def preorder(self, root, target, prefix_sum=0):
        if root:
            prefix_sum += root.val
            if prefix_sum - target in self.my_dct:
                self.count += self.my_dct[prefix_sum - target]

            self.my_dct[prefix_sum] += 1

            self.preorder(root.left, target, prefix_sum)
            self.preorder(root.right, target, prefix_sum)

            self.my_dct[prefix_sum] -= 1



    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.preorder(root, targetSum)

        return self.count
