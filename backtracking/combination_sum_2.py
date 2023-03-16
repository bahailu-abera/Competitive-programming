class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        self.answer = []
        self.prev = -1


        def backtrack(candidates, candidate_sum, index):
            if candidate_sum == target:
                self.answer.append(candidates[:])
                return

            if len(nums) == index or candidate_sum > target:
                return

            for i in range(index, len(nums)):
                if self.prev == nums[i]:
                    continue
                candidates.append(nums[i])
                backtrack(candidates, candidate_sum + nums[i], i + 1)
                candidates.pop()
                self.prev = nums[i]

        nums.sort()
        backtrack([], 0, 0)

        return self.answer
