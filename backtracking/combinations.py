class Solution:
    def helper(self, combinations, chosen, options, k):
        if len(chosen) == k:
            combinations.append(chosen.copy())
            return

        for i in range(len(options)):
            chosen.append(options[i])
            self.helper(combinations, chosen, options[i+1:], k)
            chosen.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        combinations = []
        self.helper(combinations, [], list(range(1, n + 1)), k)
        return combinations
