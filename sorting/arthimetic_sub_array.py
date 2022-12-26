class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        for i in range(len(l)):
            lst = sorted(nums[l[i]:r[i] + 1])
            d = lst[1] - lst[0]
            j = 2
            while j < len(lst):
                if lst[j] - lst[j - 1] != d:
                    res.append(False)
                    break
                j += 1
            if j == len(lst):
                res.append(True)
        return (res)
