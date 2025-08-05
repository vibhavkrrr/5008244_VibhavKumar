#!/bin/python3
import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    time = ''
    if s[8]=='P'and s[0:2] != '12':
        pehle_do = str(int(s[0:2]) + 12)
        time = pehle_do + s[2:]
    elif s[8] == 'A' and s[0:2] == '12':
        time = "00"  + s[2:]
    else:
        time = s
    time = time[0:8]
    return time
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()