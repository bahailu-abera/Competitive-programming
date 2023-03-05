from bisect import bisect_right
from collections import defaultdict
from typing import List

class Solution:
    def get_frequency_of_smallest_character(self, s: str) -> int:
        freq = defaultdict(int)
        smallest = s[0]
        for ch in s:
            freq[ch] += 1
            if ch < smallest:
                smallest = ch
        return freq[smallest]

    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        words.sort(key=self.get_frequency_of_smallest_character)
        word_count = len(words)
        results = []

        for query in queries:
            query_freq = self.get_frequency_of_smallest_character(query)
            index = bisect_right(words, query_freq, key=self.get_frequency_of_smallest_character)
            results.append(word_count - index)

        return results
