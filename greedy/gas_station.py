class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        index = 0
        start = 0
        length = len(gas)
        tank = 0

        while index < length:
            tank += gas[index]
            if tank < cost[index]:
                start = index + 1
                tank = 0
            else:
                tank -= cost[index]
            index += 1

        if start >= length:
            return -1
        index = 0

        while index < start:
            tank += gas[index]
            if tank < cost[index]:
                return -1
            tank -= cost[index]
            index += 1
        return start
