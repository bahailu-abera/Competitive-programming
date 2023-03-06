from collections import defaultdict

class TopVotedCandidate:

    def get_leading_persons(self, persons):
        leading_persons = defaultdict(int)
        freq = defaultdict(int)
        current_max = -1
        prev_leader = -1

        for i in range(len(persons)):
            freq[persons[i]] += 1
            if freq[persons[i]] >= current_max:
                leading_persons[i] = persons[i]
                prev_leader = persons[i]
            else:
                leading_persons[i] = prev_leader
            current_max = max(current_max, freq[persons[i]])

        return leading_persons

    def __init__(self, persons: List[int], times: List[int]):
        self.times = times
        self.leading_persons = self.get_leading_persons(persons)

    def q(self, t: int) -> int:
        low, high = 0, len(self.times) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if t < self.times[mid]:
                high = mid - 1
            elif t > self.times[mid]:
                low = mid + 1
            else:
                return self.leading_persons[mid]

        return self.leading_persons[high]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
