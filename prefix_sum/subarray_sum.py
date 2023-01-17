class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sumdct = {0:1}
        pre_sum = 0
        count = 0

        for num in nums:
            pre_sum += num
            if pre_sum - k in sumdct:
                count += sumdct[pre_sum - k]
            try:
                sumdct[pre_sum] += 1
            except KeyError:
                sumdct[pre_sum] = 1
        return count
