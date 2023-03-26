class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        def backtrack(chosen, index):
            if len(chosen) > 2 and chosen[-1] != chosen[-2] + chosen[-3]:
                return False

            if index == len(num):
                return len(chosen) > 2 and chosen[-1] == chosen[-2] + chosen[-3] 

            for i in range(index, len(num)):
                if num[index] == '0' and i - index > 0:
                    continue

                chosen.append(int(num[index:i + 1]))
                flag = backtrack(chosen, i + 1)
                if flag:
                    return True

                chosen.pop()

                return False

        return len(num) > 2 and backtrack([], 0)
