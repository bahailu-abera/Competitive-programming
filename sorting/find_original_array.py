class Solution:
    @staticmethod
    def counting_sort(lst):
        max = lst[0]
        for i in range(1, len(lst)):
            if lst[i] > max:
                max = lst[i]
        count = [0 for _ in range(max + 1)]
        for num in lst:
            count[num] += 1
        for i in range(1, len(count)):
            count[i] += count[i - 1]
        output = [0 for _ in range(len(lst))]
        for i in range(len(output) - 1, -1, -1):
            count[lst[i]] -= 1
            output[count[lst[i]]] = lst[i]
        return output



    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed = self.counting_sort(changed)
        my_dict = dict()
        lst = []

        for num in changed:
            if num == 1:
                value = -1
            else:
                value = my_dict.get(num / 2, -1)
            if value == -1:
                my_dict[num] = my_dict.get(num, -1) + 1
            else:
                lst.append(num // 2)
                if value == 0:
                    del my_dict[num / 2]
                else:
                    my_dict[num / 2] -= 1
        if len(my_dict):
            return []
        return lst

            
