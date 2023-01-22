class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        len_pushed = len(pushed)
        len_popped = len(popped)
        i = j = 0

        for j in range(len_popped):
            if stack and stack[-1] == popped[j]:
                stack.pop()
            else:
                while i < len_pushed and pushed[i] != popped[j]:
                    stack.append(pushed[i])
                    i += 1
                if i < len_pushed and popped[j] == pushed[i]:
                    i += 1
                else:
                    return False

        return True
