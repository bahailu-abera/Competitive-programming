class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l: int = 0
        length: int = len(nums)
        r: int = 1
        while r < length:
            if nums[r] != 0 and nums[l] == 0:
                tmp = nums[l]
                nums[l] = nums[r]
                nums[r] = tmp
                l += 1
            elif nums[l] != 0:
                l += 1
            r += 1
