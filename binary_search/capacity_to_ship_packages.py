class Solution:
    def days(self, capacity, weights):
        day = 1
        total = 0
        for weight in weights:
            if total + weight > capacity:
                total = 0
                day += 1
            total += weight

        return day

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        max_capacity = sum(weights)
        min_capacity = max(weights)

        while min_capacity <= max_capacity:
            mid_capacity = min_capacity + (max_capacity - min_capacity) // 2
            day_taken = self.days(mid_capacity, weights)
            if day_taken <= days:
                max_capacity = mid_capacity - 1
            else:
                min_capacity = mid_capacity + 1

        return min_capacity
