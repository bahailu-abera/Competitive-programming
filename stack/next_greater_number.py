class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = [-1 for _ in range(len(nums1))]
        numIndex = {num: i for i, num in enumerate(nums1)}
        stack = []

        for num in nums2:
            if not stack:
                stack.append(num)
            else:
                while stack and num > stack[-1]:
                    val = stack.pop()
                    try:
                        answer[numIndex[val]] = num
                    except:
                        pass
                stack.append(num)

        return (answer)
