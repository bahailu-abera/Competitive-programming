class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = [[]]

        def backtrack(chosen, index):
            if len(nums) == index:
                return

            for i in range(index, len(nums)):
                chosen.append(nums[i])
                subsets.append(chosen[:])
                backtrack(chosen, i + 1)
                chosen.pop()

        backtrack([], 0)

        return subsets
