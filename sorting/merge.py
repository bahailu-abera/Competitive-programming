class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = []

        for i in range(len(intervals)):
            if (len(res) <= 0):
                res.append(intervals[i])
            else:
                end = res[-1]
                if end[1] >= intervals[i][0]:
                    res.pop()
                    end = [end[0], max(intervals[i][1], end[1])]
                    res.append(end)
                else:
                    res.append(intervals[i])
        return (res)
