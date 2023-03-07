import bisect

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        starts = [(i, interval[0]) for i, interval in enumerate(intervals)]
        starts.sort(key=lambda x: x[1])
        results = [-1] * n

        for i, interval in enumerate(intervals):
            idx = bisect.bisect_left(starts, interval[1], key=lambda x: x[1])
            if idx < n:
                results[i] = starts[idx][0]

        return results
