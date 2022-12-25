class Compare(str):
    def __lt__(x, y):
        return int(x) < int(y)
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        nums = sorted(nums, key=Compare)
        return nums[len(nums) - k]
