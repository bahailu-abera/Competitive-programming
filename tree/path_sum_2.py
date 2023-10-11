# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.paths = []

    def helper(self, root, path, path_sum=0):
            if root:
                path.append(root.val)
                path_sum += root.val

                self.helper(root.left, path, path_sum)
                self.helper(root.right, path, path_sum)

                if not root.left and not root.right and path_sum == self.target:
                    self.paths.append(path[:])

                path.pop()
                path_sum -= root.val

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.target = targetSum
        self.helper(root, [])

        return self.paths
