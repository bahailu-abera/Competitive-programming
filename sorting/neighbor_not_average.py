class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums = sorted(nums)
        i = 1
        length = len(nums)

        while i < length - 1:
            tmp = nums[i]
            nums[i] = nums[i + 1]
            nums[i + 1] = tmp
            i += 2
        return (nums)
