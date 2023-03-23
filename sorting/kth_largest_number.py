class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums) - k
        def partition(low, high):

            # choose the rightmost element as pivot
            pivot = nums[high]

            # pointer for greater element
            i = low - 1

            # traverse through all elements
            # compare each element with pivot
            for j in range(low, high):
                if nums[j] <= pivot:
                    # if element smaller than pivot is found
                    # swap it with the greater element pointed by i
                    i = i + 1

                    # swapping element at i with element at j
                    (nums[i], nums[j]) = (nums[j], nums[i])

            # swap the pivot element with the greater element specified by i
            (nums[i + 1], nums[high]) = (nums[high], nums[i + 1])

            # return the position from where partition is done
            return i + 1

        right = len(nums) - 1
        left = 0
        pivot = partition(left, right)

        while pivot != k:
            if pivot < k:
                left = pivot + 1
            else:
                right = pivot - 1

            pivot = partition(left, right)

        return nums[pivot]
