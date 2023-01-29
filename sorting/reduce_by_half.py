class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        dct = {}

        for num in arr:
            try:
                dct[num] += 1
            except KeyError:
                dct[num] = 1
        lst = sorted([(v, k) for k, v in dct.items()], reverse=True)
        mins = 0
        count = 0
        for ( v, k) in lst:
            count += v
            mins += 1
            if count >= len(arr) // 2:
                break
        return (mins)
