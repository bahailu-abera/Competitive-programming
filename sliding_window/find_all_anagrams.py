from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        size = len(p)
        count = Counter(p)
        answer = []

        for i in range(len(s) - size + 1):
            if Counter(s[i:i+size]) == count:
                answer.append(i)

        return (answer)
