// codingPuzzles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define MAX_VEC_SIZE 20000

class Solution {
private:
	vector <vector <int> > i_memoize2DVec;
	int isGoodStart(vector <int> A, unsigned int ui_start, unsigned int ui_end, unsigned int ui_isOddJump);

public:
	Solution(): i_memoize2DVec(2, vector <int>(20000, 0)) {
	}

	int oddEvenJumps(vector<int>& A); 
};

int Solution::isGoodStart(vector <int> A, unsigned int ui_start, unsigned int ui_end, unsigned int ui_isOddJump)
{
	unsigned int ui_i;
	unsigned int ui_minMaxIdx = 0;
	int i_minMaxVal;

	i_minMaxVal = ui_isOddJump ? 0x7FFFFFFF : 0x80000000;
	for (ui_i = ui_start + 1; ui_i < ui_end; ui_i++) {
		
		if (1 == ui_isOddJump) {
			if ((A[ui_start] <= A[ui_i]) && (A[ui_i] < i_minMaxVal)) {
				i_minMaxVal = A[ui_i];
				ui_minMaxIdx = ui_i;
			}
		}
		else {
			if ((A[ui_start] >= A[ui_i]) && (A[ui_i] > i_minMaxVal)) {
				i_minMaxVal = A[ui_i];
				ui_minMaxIdx = ui_i;
			}
		}
	}

	// If we couldn't make a jump return -1
	if (0 == ui_minMaxIdx)
		return -1;

	if (ui_minMaxIdx == (ui_end - 1)) // And ui_minMaxIdx != 0 is assumed
		return 1;

	// Else continue the search for a good start
	int i_retVal;

	ui_isOddJump ^= 0x1;
	if (i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] != 0) {
		cout << "Memoization helped!!!" << endl;
		return(i_memoize2DVec[ui_isOddJump][ui_minMaxIdx]);
	}

	i_retVal = isGoodStart(A, ui_minMaxIdx, A.size(), ui_isOddJump);
	if ((i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] != 0) && (i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] != i_retVal)) {
		cout << "i_memoize2DVec[" << ui_isOddJump << "][" << ui_minMaxIdx << "] = " << i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] << endl;
		cout << "Will be overwritten by " << i_retVal << endl;
	}

	i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] = i_retVal;
	cout << "i_memoize2DVec[" << ui_isOddJump << "][" << ui_minMaxIdx << "] = " << i_memoize2DVec[ui_isOddJump][ui_minMaxIdx] << endl;
	return(i_memoize2DVec[ui_isOddJump][ui_minMaxIdx]);
}

int Solution::oddEvenJumps(vector<int>& A)
{
	unsigned int ui_isOddJump = 1;
	unsigned int ui_idx;
	unsigned int ui_numPaths;

	ui_numPaths = 0;
	for (ui_idx = 0; ui_idx < A.size() - 1; ui_idx++)
	{
		if (1 == isGoodStart(A, ui_idx, A.size(), ui_isOddJump)) {
			i_memoize2DVec[ui_isOddJump][ui_idx] = 1;
			cout << "Path to end exists from index " << ui_idx << endl;
			ui_numPaths++;
		}
		else {
			i_memoize2DVec[ui_isOddJump][ui_idx] = -1;
			cout << "No path from index " << ui_idx << endl;
		}
		cout << "i_memoize2DVec[" << ui_isOddJump << "][" << ui_idx << "] = " << i_memoize2DVec[ui_isOddJump][ui_idx] << endl;
	}
	ui_numPaths++;
	return(ui_numPaths);
}

int main()
{
	vector <int> A = { 10, 13, 12, 14, 15 };
	Solution sol;
	cout << "Number of paths = " << sol.oddEvenJumps(A) << endl;

    return 0;
}

