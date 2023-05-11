#User function Template for python3
from collections import defaultdict, deque

class Solution:
    def findOrder(self,alien_dict, N, K):
        # code here
        indegree = defaultdict(int)
        graph = defaultdict(set)
        order = []

        for word in alien_dict:
            for lett in word:
                indegree[lett] = 0

        prev = alien_dict[0]

        for current in alien_dict[1:]:
            for a, b in zip(prev, current):
                if a != b:
                    if b not in graph[a]:
                        graph[a].add(b)
                        indegree[b] += 1
                    break

            prev = current

        Q = deque()
        for key, value in indegree.items():
            if value == 0:
                Q.append(key)

        while Q:
            current = Q.popleft()
            order.append(current)

            for adj in graph[current]:
                indegree[adj] -= 1

                if (indegree[adj] == 0):
                    Q.append(adj)

        return "".join(order)
