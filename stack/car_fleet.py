class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pos_speed = list(map(lambda a, b: (target - a, b), position, speed))
        pos_speed.sort()
        pos_speed = list(map(lambda tpl:( tpl[0] / tpl[1]), pos_speed))
        index = 1
        fleets = 1
        front = pos_speed[0]

        while index < len(pos_speed):
            if front < pos_speed[index]:
                fleets += 1
                front = pos_speed[index]
            index += 1

        return fleets
