class Solution:
    def addLast(self, s, c):
        return s * 27 + c

    def pollFirst(self, s, c, p):
        return s - (c * pow(27, p))

    def hash(self, s, n):
        value = 0

        for i in range(n):
            value = self.addLast(value, ord(s[i]) - ord('a') + 1)

        return value

    def strStr(self, s1, s2):
        n, m = len(s1), len(s2)

        if m > n:
            return -1

        p = self.hash(s2, m)
        current = self.hash(s1, m)

        if current == p:
            return 0

        for right in range(m, n):
            current = self.addLast(current, ord(s1[right]) - ord('a') + 1)
            current = self.pollFirst(current, ord(s1[right - m]) - ord('a') + 1, m)

            if p == current:
                return right - m + 1

        return -1
