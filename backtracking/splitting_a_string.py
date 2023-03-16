class Solution:
    def is_valid(self, s, current, right):
        if right == len(s):
            return True
        for i in range(right, len(s)):
            next_num = int(s[right:i+1])
            if current - next_num == 1 and self.is_valid(s, next_num, i+1):
                return True
            if current - next_num < 1:
                break
        return False

    def splitString(self, s: str, l: int = 1) -> bool:
        for i in range(len(s) - 1):
            current = int(s[:i + 1])
            if self.is_valid(s, current, i + 1):
                return True
        return False
