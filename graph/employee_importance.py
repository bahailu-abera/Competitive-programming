"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
from collections import defaultdict

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        hash_map = defaultdict(int)

        for employee in employees:
            hash_map[employee.id] = employee


        def dfs(id):
            current = hash_map[id]
            total = current.importance

            if not current.subordinates:
                return total

            for subord in current.subordinates:
                total += dfs(subord)

            return total

        return dfs(id)
