#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countSwaps' function below.
#
# The function accepts INTEGER_ARRAY a as parameter.
#

def countSwaps(a):
    # Write your code here
    countswaps = 0
    for i in range(len(a)):
        swap = False 
        for j in range(len(a) - 1):
            if a[j] > a[j+1]:
                countswaps += 1
                temp = a[j]
                a[j] = a[j+1]
                a[j+1] = temp
                swap = True
        if not swap:
            break
    print("Array is sorted in" ,countswaps, "swaps.")
    print("First Element:",a[0])
    print("Last Element:",a[-1])
        

if __name__ == '__main__':
    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)
