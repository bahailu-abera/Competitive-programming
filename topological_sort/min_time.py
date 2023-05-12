from typing import List
from collections import deque, defaultdict


from typing import List


class Solution:
    def minimumTime(self, n : int,m : int, edges : List[List[int]]) -> int:
        # code here
        indegree = [0 for _ in range(n + 1)]
        graph = defaultdict(list)
        times = [0 for _ in range(n)]

        for edge in edges:
            graph[edge[0]].append(edge[1])
            indegree[edge[1]] += 1

        Q = deque()
        for i in range(1, n + 1):
            if indegree[i] == 0:
                Q.append((i, 1))

        while Q:
            current, t = Q.popleft()
            times [current - 1] = str(t)

            for adj in graph[current]:
                indegree[adj] -= 1
                if (indegree[adj] == 0):
                    Q.append((adj, t + 1))

        return " ".join(times)
