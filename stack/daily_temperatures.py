class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0 for _ in range(len(temperatures))]
        stack = []

        for index, temp in enumerate(temperatures):
            if not stack:
                stack.append(index)
            else:
                while stack:
                    topIndex = stack[-1]
                    topValue = temperatures[topIndex]
                    if topValue < temp:
                        answer[topIndex] = index - topIndex
                        stack.pop()
                    else:
                        break
                stack.append(index)
        return answer
