# codingPuzzles
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
