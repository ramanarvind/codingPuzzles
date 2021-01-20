#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


/*
This problem was asked by Google.

We can determine how "out of order" an array A is by counting the number of 
inversions it has.Two elements A[i] and A[j] form an inversion if A[i] > A[j] 
but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has.Do this faster than 
O(N ^ 2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. 
The array[2, 4, 1, 3, 5] has three inversions : (2, 1), (4, 1), and (4, 3).
The array[5, 4, 3, 2, 1] has ten inversions : every distinct pair forms an inversion.
*/

class Solution {
private:

public:
	vector<int> pi_inversions;

	int numInversions(vector<int>& A, unsigned int ui_stIdx) {
		unsigned int ui_numInversions;

		if (ui_stIdx == 0)
			pi_inversions.assign(A.size(), -1);

		for (unsigned int i = ui_stIdx; i < A.size(); i++) {
			ui_numInversions = 0;
			if (pi_inversions[i] == -1) {
				for (unsigned int j = i + 1; (j < A.size()); j++) {
					if (A[i] > A[j]) {
						ui_numInversions++;
						if (pi_inversions[j] == -1) 
							numInversions(A, j);
					}
				}
				pi_inversions[i] = ui_numInversions;
			}
		}

		if(ui_stIdx == 0) {
			ui_numInversions = 0;
			for (unsigned int i = ui_stIdx; i < A.size(); i++) {
				ui_numInversions += pi_inversions[i];
			}
		}

		return ui_numInversions;
	}
};

int main()
{
	// The sorted array should have 0 inversions
	//vector<int> intVec = { 1, 2, 3, 4, 5 };
	// The array[2, 4, 1, 3, 5] has three inversions : (2, 1), (4, 1), and (4, 3).
	//vector<int> intVec = { 2, 4, 1, 3, 5 };
	// The array[5, 4, 3, 2, 1] has ten inversions : every distinct pair forms an inversion.
	vector<int> intVec = { 5, 4, 3, 2, 1 };
	//vector<int> intVec = { 1, 5, 2, 3, 4 };
	Solution sol;

	cout << "Number of inversions: " << sol.numInversions(intVec, 0) << endl;
}

