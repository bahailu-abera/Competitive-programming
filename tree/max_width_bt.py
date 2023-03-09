from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        depth = 0
        max_width = 1
        Q = deque([(root, depth)])
        tmp = deque()

        while Q:
            root, depth = Q.popleft()
            if root.left: tmp.append((root.left, depth * 2))
            if root.right: tmp.append((root.right, depth * 2 + 1))

            if not Q:
                if tmp:
                    left_index, right_index = tmp[0][1], tmp[-1][1]
                    max_width = max(max_width, right_index - left_index + 1)
                Q = tmp
                tmp = deque()

        return max_width
