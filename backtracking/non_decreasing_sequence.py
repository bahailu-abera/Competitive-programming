class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        subsequences = []
        length = len(nums)

        def backtrack(chosen, index):
            if len(chosen) > 1:
                subsequences.append(chosen[:])

            if index == length:
                return
            visited = set()
            for i in range(index, length):
                if nums[i] in visited or chosen and chosen[-1] > nums[i]:
                    continue

                visited.add(nums[i])
                chosen.append(nums[i])
                backtrack(chosen, i + 1)
                chosen.pop()


        backtrack([], 0)

        return subsequences
