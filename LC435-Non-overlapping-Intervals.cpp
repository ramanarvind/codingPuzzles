#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


/*
https://leetcode.com/problems/non-overlapping-intervals/
435. Non-overlapping Intervals

Given a collection of intervals, find the minimum number of intervals you need 
to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/
bool compareIntervals(vector<int> a, vector<int> b) {
	if (a[0] < b[0])
		return true;
	else
		return false;
}

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int numOverlapsToRemove = 0;
		//int start;
		int end;

		if (intervals.size() < 2)
			return 0;

		sort(intervals.begin(), intervals.end(), compareIntervals);
		//start = intervals[0][0];
		end   = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (end > intervals[i][0]) {
				numOverlapsToRemove++;
				if (end > intervals[i][1]) {
					//start = intervals[i][0];
					end = intervals[i][1];
				}
			}
			else {
				//start = intervals[i][0];
				end   = intervals[i][1];
			}
			//cout << "{" << intervals[i][0] << ", " << intervals[i][1] << "}" << endl;
		}
		return numOverlapsToRemove;
	}
};

int main()
{
	vector<vector<vector<int>>> intVec = {
		// [1,3] can be removed and the rest of intervals are non-overlapping.
		{{1,2},{2,3},{3,4},{1,3}}, {{1}},
		// You need to remove two [1,2] to make the rest of intervals non-overlapping.
		{{1,2},{1,2},{1,2}}, {{2}},
		// You don't need to remove any of the intervals since they're already non-overlapping.
		{{1,2},{2,3}}, {{0}},
		// My own testcase while explaining Satvik 
		{{0,4},{1,2},{3,5},{5,6},{7,8}}, {{1}},
		{{}}, {{0}}
	};
	Solution sol;

	for (unsigned int i = 0; i < intVec.size(); i += 2) {
		unsigned int answer = sol.eraseOverlapIntervals(intVec[i]);
		if (answer == intVec[i + 1][0][0]) {
			cout << "Test case " << i/2 << " : PASSED" << endl;
		}
		else {
			cout << "Test case " << i/2 << " : FAILED" << endl;
			cout << "Number of overlaps to remove: " << answer << " Correct answer: " << intVec[i + 1][0][0] << endl;
		}
	}
}

