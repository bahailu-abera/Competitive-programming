class Solution:
    def select(self, arr, i):
        # code here
        smallest = i
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                i = j

        return i

    def selectionSort(self, arr,n):
        #code here
        for i in range(n):
            min_index = self.select(arr, i)
            arr[i], arr[min_index] = arr[min_index], arr[i]

        return arr
