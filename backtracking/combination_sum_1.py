class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        answer = []

        def backtrack(candidates, candidates_sum, index):
            if candidates_sum == target:
                answer.append(candidates[:])
                return

            if index == len(nums) or candidates_sum > target:
                return

            candidates.append(nums[index])
            backtrack(candidates, candidates_sum + nums[index], index)
            candidates.pop()
            backtrack(candidates, candidates_sum, index + 1)

        backtrack([], 0, 0)
        return answer
