from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        Q = deque([root])
        right_sides = [root.val]
        tmp = deque()

        while Q:
            current = Q.popleft()
            if current.left:
                tmp.append(current.left)
            if current.right:
                tmp.append(current.right)
            if not Q:
                if tmp:
                    right_sides.append(tmp[-1].val)
                Q = tmp
                tmp = deque()

        return right_sides
