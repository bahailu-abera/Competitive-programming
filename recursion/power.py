class Solution:
    def pow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n & 1 == 0:
            p = self.pow(x, n // 2)
            return p * p
        return x * self.pow(x, n - 1)

    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return (1 / self.pow(x, -n))
        return (self.pow(x, n))
