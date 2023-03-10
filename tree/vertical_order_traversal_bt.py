# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraverse(self, root, x=0, y=0):
        if  root:
            self.vertical[(x)].append((y, root.val))
            self.verticalTraverse(root.left, x-1, y+1)
            self.verticalTraverse(root.right, x+1, y+1)

    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.vertical = defaultdict(lambda: [])
        self.verticalTraverse(root)

        verticalOrder = []
        for key in sorted(self.vertical.keys()):
            temp = sorted(self.vertical[key])
            verticalOrder.append([val for _, val in temp])
        return verticalOrder
