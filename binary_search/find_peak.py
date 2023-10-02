class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        low, high = 0, len(arr) - 1

        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] > arr[mid + 1]:
                high = mid - 1
            else:
                low = mid + 1
        return low
