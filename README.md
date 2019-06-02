# codingPuzzles

## LC887: Super Egg Drop
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

###Example 1:
Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.

###Example 2:
Input: K = 2, N = 6
Output: 3

###Example 3:
Input: K = 3, N = 14
Output: 4
 
###Note:
1 <= K <= 100
1 <= N <= 10000

## LC980: Unique Paths III
https://leetcode.com/problems/unique-paths-iii/
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

## DC245: Minimum Number Of Jumps From Start To End Of An Array
You are given an array of integers, where each element represents the maximum 
number of steps that can be jumped going forward from that element. Write a 
function to return the minimum number of jumps you must take in order to get 
from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the 
optimal solution involves jumping from 6 to 5, and then from 5 to 9.

## LC452: Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Solution: LC452MinArrowsToBurstBalloons.py
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

## LC 975: Odd Even Jump
https://leetcode.com/problems/odd-even-jump/
Solution: LC975-OddEvenJump.cpp

You are given an integer array A.  From some starting index, you can make a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.

You may from index i jump forward to index j (with i < j) in the following way:

* During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
* During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
(It may be the case that for some index i, there are no legal jumps.)

A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once.)

Return the number of good starting indexes.

## LC 976: Largest Perimeter Triangle
https://leetcode.com/problems/largest-perimeter-triangle/submissions/
Solution: LC976-LargestPerimeterTriangle.cpp 

Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.
If it is impossible to form any triangle of non-zero area, return 0.

*Example 1:*
Input: [2,1,2]
Output: 5

*Example 2:*
Input: [1,2,1]
Output: 0

*Example 3:*
Input: [3,2,3,4]
Output: 10

*Example 4:*
Input: [3,6,2,3]
Output: 8
