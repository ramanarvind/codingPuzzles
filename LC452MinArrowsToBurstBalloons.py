# -*- coding: utf-8 -*-
"""
Created on Sat Jun 1 08:59:27 2019

@author: araman
"""
"""
LC452: Minimum Number of Arrows to Burst Balloons
URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
There are a number of spherical balloons spread in two-dimensional space. For 
each balloon, provided input is the start and end coordinates of the horizontal 
diameter. Since it's horizontal, y-coordinates don't matter and hence the 
x-coordinates of start and end of the diameter suffice. Start is always smaller 
than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the 
x-axis. A balloon with xstart and xend bursts by an arrow shot at x 
if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be 
shot. An arrow once shot keeps travelling up infinitely. The problem is to find 
the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] 
and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
"""

class Solution:
    def findMinArrowShots(self, points) -> int:
        if(len(points[0]) == 0):
            return 0
        
        # Sort the line segments on the basis of their start points
        points = sorted(points, key = lambda xcord: xcord[0])
        end    = points[0][1]
        numArrows = 1
        for point in points[1:]:
            pStart = point[0]
            pEnd   = point[1]
            # Identify the intersection. If the line segments intersect, the 
            # previous can continue to shoot down the balloons. If not, 
            # increment the number of arrows by 1 and freshly start identifying 
            # the intersection points 
            if (pStart <= end):
                end   = min(end, pEnd)
            else:
                end   = pEnd
                numArrows += 1
        return(numArrows)

inputs = [[[[10,16], [2,8], [1,6], [7,12]], 2],
          [[[1,15], [20,30], [2,3], [8,22], [2,3], [2,3], [2,3], [4,12]], 3],
          [[[1,20], [2,4], [6,8], [10,12]], 3],
          [[[1,15], [20,30], [3,6], [10,25], [4,5], [12,14], [12,14]], 3],
          [[[1,20], [2,10], [5,8], [16,18], [5,8], [3,4], [7,8], [3,4], [3,4]], 3],
          [[[]], 0]
         ]

LC452 = Solution()
correct = 0
for input in inputs:
    answer = LC452.findMinArrowShots(points=input[0])
    if (answer == input[1]):
        print("PASS: ", "Input = ", input[0], "Answer = ", answer)
        correct += 1
    else:
        print("FAIL: ", "Input = ", input[0], "Answer = ", answer, "Correct Answer = ", input[1])

print("Pass % = ", correct*100/len(inputs))