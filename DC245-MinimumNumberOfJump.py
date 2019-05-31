# -*- coding: utf-8 -*-
"""
Created on Fri May 31 19:15:03 2019

@author: araman
"""

input = [6, 2, 4, 0, 5, 1, 1, 4, 2, 9]

class DC245:
    
    def __init__(self, input):
        self.minJumps = 0
    
    def findMinJumps(self, idx, jumps, input):
        # A value of 0 means dead-end. Decrement the number of jumps and return
        if (input[idx] == 0):
            return(jumps-1)

        # If this path is not going to result in minimum number of jumps return
        # after decrementing the number of jumps        
        if (jumps >= self.minJumps):
            return(jumps-1)
        
        if (idx + input[idx] >= len(input) - 1):
            jumps += 1
            if jumps < self.minJumps:
                print("idx =", idx, "Min jumps = ", jumps)
                self.minJumps = jumps
                return(jumps)
            
        for i in range(0, min(input[idx],len(input)-idx-1)):
            print("idx =", idx, "jumps = ", jumps)
            self.findMinJumps(idx+i+1, jumps+1, input)
        return(self.minJumps)
                
    def Solution(self, input):
        self.minJumps = len(input)
        jumps = 0
        jumps = self.findMinJumps(0, jumps, input)
        return(jumps)
        
dc = DC245(input)
print(dc.Solution(input))