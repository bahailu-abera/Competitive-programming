from collections import defaultdict

class Solution:
    def f(self, s):
        freq = defaultdict(int)
        smallest = s[0]
        for ch in s:
            freq[ch] += 1
            if ch < smallest:
                smallest = ch
        return freq[smallest]

    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        words = sorted(words, key=self.f)
        words_len = len(words)
        answer = []

        for query in queries:
            low, high = 0, words_len - 1
            mid = words_len
            query_freq = self.f(query)
            while low <= high:
                mid = low + (high - low) // 2
                if query_freq >= self.f(words[mid]):
                    low = mid + 1
                else:
                    high = mid - 1
            answer.append(words_len - low)
        return answer
