class Solution:
    #Heapify function to maintain heap property.
    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    def parent(self, i):
        return (i - 1) // 2

    def heapify(self,arr, n, i):
        l = self.left(i)
        r = self.right(i)
        largest= i

        if l < n and arr[l] >= arr[largest]:
            largest = l

        if r < n and arr[r] >= arr[largest]:
            largest = r

        arr[i], arr[largest] = arr[largest], arr[i]
        if largest > i and largest < n:
            self.heapify(arr, n, largest)

    #Function to build a Heap from array.
    def buildHeap(self,arr,n):
        j = n // 2
        for i in range(j, -1, -1):
            self.heapify(arr, n, i)

    #Function to sort an array using Heap Sort.
    def HeapSort(self, arr, n):
        #code here
        self.buildHeap(arr, n)

        for i in range(n - 1, -1, -1):
            arr[i], arr[0] = arr[0], arr[i]
            self.heapify(arr, i, 0)
