# -*- coding: utf-8 -*-
"""
Created on Fri May 31 19:15:03 2019

@author: araman
"""

"""
You are given an array of integers, where each element represents the maximum 
number of steps that can be jumped going forward from that element. Write a 
function to return the minimum number of jumps you must take in order to get 
from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the 
optimal solution involves jumping from 6 to 5, and then from 5 to 9.
"""

# Test cases
inputs = [[[6, 2, 4, 0, 5, 1, 1, 4, 2, 9], 2],
          [[2, 2, 4, 0, 3, 1, 1, 4, 2, 9], 4],
          [[1, 2, 4, 0, 3, 1, 1, 4, 2, 9], 5],
          [[1, 2, 4, 0, 3, 1, 1, 1, 2, 9], 6],
          [[1, 2, 4, 0, 3, 1, 3, 1, 2, 9], 4]]

class DC245:
    
    def __init__(self, input):
        self.minJumps = 0
        self.memoizeJumps = [0]*len(input)
    
    def findMinJumps(self, idx, jumps, input):
        # A value of 0 means dead-end. Decrement the number of jumps and return
        if (input[idx] == 0):
            return(-1)

        # If this path is not going to result in minimum number of jumps return
        # after decrementing the number of jumps        
        if (jumps >= self.minJumps):
            return(-1)
        
        # If you can reach the end of the array from here AND we have found a 
        # a new minimum path, update the member variable minJumps. Also 
        # memorize this path
        if (idx + input[idx] >= len(input) - 1):
            jumps += 1
            if jumps < self.minJumps:
                self.minJumps = jumps
                self.memoizeJumps[idx] = 1
                return(jumps)
            
        for i in range(0, min(input[idx],len(input)-idx-1)):
            # if a path to the end of the array from the next jump point is NOT
            # known
            if(self.memoizeJumps[idx+i+1] == 0):
                # If return value is > 0, a path to the end of the array has 
                # been found. Memorize this path
                if (self.findMinJumps(idx+i+1, jumps+1, input) > 0):
                    self.memoizeJumps[idx] = self.minJumps - jumps
            # else if a path to the end of the array from the next jump point 
            # is known
            else:
                # If this path is more optimal, update the member variable 
                # minJumps. Also memorize this path
                if(jumps + self.memoizeJumps[idx+i+1] + 1 < self.minJumps):
                    self.minJumps = jumps + self.memoizeJumps[idx+i+1] + 1
                    self.memoizeJumps[idx] = self.memoizeJumps[idx+i+1] + 1
                
        return(self.minJumps)
                
    def Solution(self, input):
        self.minJumps = len(input)
        jumps = 0
        jumps = self.findMinJumps(0, jumps, input)
        return(jumps)

for input in inputs:        
    dc = DC245(input[0])
    answer = dc.Solution(input[0])
    if(answer == input[1]):
        print("PASS: Input = ", input[0], "Answer = ", input[1])
    else:
        print("FAIL: Input = ", input[0], "Code Gave = ", answer, "Actual Answer = ", input[1])
        