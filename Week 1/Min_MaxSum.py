#!/bin/python3
import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    lst = list(arr)
    max_sum = sum(lst) - min(lst)
    min_sum = sum(lst) - max(lst)
    
    print(min_sum , max_sum)
    

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)