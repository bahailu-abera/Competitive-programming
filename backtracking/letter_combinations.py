class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if not digits:
            return []

        letters = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        combinations = []

        def backtrack(chosen, index):
            if index == len(digits):
                combinations.append(chosen)
                return

            for ele in letters[int(digits[index]) - 2]:
                backtrack(chosen + ele, index + 1)

            backtrack("", 0)

        return combinations
