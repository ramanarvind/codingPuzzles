# -*- coding: utf-8 -*-
"""
Created on Sat Jun  1 10:38:11 2019

@author: araman
"""

"""
LC887: Super Egg Drop
URL: https://leetcode.com/problems/super-egg-drop/
You are given K eggs, and you have access to a building with N floors from 1 to 
N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it 
again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped 
at a floor higher than F will break, and any egg dropped at or below floor F 
will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from 
any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F 
is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.

Example 2:
Input: K = 2, N = 6
Output: 3

Example 3:
Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000
"""

class Solution:
    def __init__(self, K, N):
        self.memoizeDrops = [[0 for x in range(N)] for y in range(K)] 
        
    def superEggDrop(self, K: int, N: int) -> int:      
        # If the number of eggs is 1, return the number of floors
        if (K == 1):
            return(N)
        
        # If the number of floors is less than equal to 2 return the number of 
        # floors itself
        if (N <= 2):
            return(N)

        # If the minimum number of drops for K eggs and N floor has already 
        # been cmomputed, return that value
        if (self.memoizeDrops[K-1][N-1] != 0):
            return(self.memoizeDrops[K-1][N-1])
                
        minDrops = N
        for i in range(2, N):
            numDropsCaseBreaks = self.superEggDrop(K - 1, i - 1)
            numDropsCaseDidNotBreak = self.superEggDrop(K, N - i)
            drops = 1 + max(numDropsCaseBreaks, numDropsCaseDidNotBreak)
            if (drops < minDrops):
                minDrops = drops
        
        # Memorize the minimum number of drops for K eggs and N floor
        self.memoizeDrops[K-1][N-1] = minDrops
        return(minDrops)
        
inputs = [[[1, 2], 2], 
          [[2, 2], 2],
          [[2, 3], 2],
          [[2, 4], 3],
          [[2, 5], 3],
          [[2, 6], 3],
          [[2, 7], 4],
          [[2, 10], 4],
          [[2, 11], 5],
          [[2, 15], 5],
          [[2, 20], 6],
          [[2, 50], 10],
          [[2, 100], 14],
          [[3, 14], 4],
          [[4, 1000], 13],
          [[4, 2000], 16],
          [[10, 1000], 10],
          ]

correct = 0
for input in inputs:
    K = input[0][0]
    N = input[0][1]
    LC887=Solution(K, N)
    answer = LC887.superEggDrop(input[0][0], input[0][1])
    if (answer == input[1]) or (input[1] == 0):
        print("PASS: ", "Input: K= ",K, " N= ", N, "Answer = ", answer)
        correct += 1
    else:
        print("FAIL: ", "Input: K= ",K, " N= ", N, "Answer = ", answer, "Correct Answer = ", input[1])

print("Pass % = ", correct*100/len(inputs))