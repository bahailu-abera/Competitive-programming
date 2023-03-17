class Solution:
    def __init__(self):
        self.permutations = []

    def permuteHelper(self, options, chosen):
        if len(options) == 0:
            self.permutations.append(chosen[:])
            return

        for i in range(len(options)):
            chosen.append(options[i])
            self.permuteHelper(options[:i] + options[i+1:], chosen)
            chosen.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.permuteHelper(nums, [])

        return self.permutations
