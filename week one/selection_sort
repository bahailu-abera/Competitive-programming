class Solution: 
   
    def selectionSort(self, arr,n):
        for i in range(n):
            least = i
            for k in range(i+1,n):
                if arr[k] < arr[least]:
                    least = k
            temp = arr[i]
            arr[i] = arr[least]
            arr[least] = temp
        return arr
