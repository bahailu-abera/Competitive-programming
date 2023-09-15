class Ds:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.size = [1 for _ in range(n + 1)]

    def is_connected(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)

        if px == py:
            return

        if self.size[px] >= self.size[py]:
            self.parent[py] = px
            self.size[px] += self.size[py]

        else:
            self.parent[px] = py
            self.size[py] += self.size[px]


    def find(self, x):
        if self.parent[x] == x:
            return x

        self.parent[x] = self.find(self.parent[x])

        return self.parent[x]

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        ds = Ds(len(source))

        for swap in allowedSwaps:
            ds.union(swap[0], swap[1])

        groups = defaultdict(list)

        for i in range(len(source)):
            root = ds.find(i)
            groups[root].append(i)

        hamming_distance = 0

        for indices in groups.values():
            freq = defaultdict(int)

            for i in indices:
                freq[source[i]] += 1

            for i in indices:
                if not target[i] in freq:
                    hamming_distance += 1
                else:
                    freq[target[i]] -= 1

                    if freq[target[i]] == 0:
                        del freq[target[i]]


        return hamming_distance

def count_frequency(arr):
    frequency = {}
    for num in arr:
        frequency[num] = frequency.get(num, 0) + 1

    return frequency
