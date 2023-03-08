from queue import Queue
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        answer = []
        depth = 0
        if root is None:
            return []
        q = Queue()
        q.put((root, depth))

        while not q.empty():
            root, depth = q.get()
            if len(answer) == depth:
                answer.append([root.val])
            else:
                answer[depth].append(root.val)
            if root.left:
                q.put((root.left, depth + 1))
            if root.right:
                q.put((root.right, depth + 1))

        return answer
