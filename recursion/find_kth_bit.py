class Solution:
    def helper(self, n, k):
        if n == 1:
            return 0
        mid = (2 ** n) // 2
        if k == mid:
            return 1
        elif k < mid:
            return self.helper(n - 1, k)
        else:
            return 1 - self.helper(n - 1, mid * 2 - k)

    def findKthBit(self, n: int, k: int) -> str:
        return str(self.helper(n, k))
