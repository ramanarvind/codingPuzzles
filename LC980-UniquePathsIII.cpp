// codingPuzzles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define START 1
#define INVALID -1

class Solution {
private:
	char stepped[20][20];
	vector <vector <int>> steps = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	int  magicNum, numVisitedCells;

	/*
	# Find the starting location in the grid
	# Fine the number of invalid cells that should not be stepped upon
	*/
	int findGridProps(vector<vector<int>>& grid, vector <int> &coordinates) {
		int row, col, gridRows, gridCols;
		int numMinus1s = 0;

		gridRows = grid.size();
		gridCols = grid[0].size();

		for (row = 0; (row < gridRows); row++) {
			for (col = 0; col < gridCols; col++) {
				// Identify the start cell
				if (grid[row][col] == START) {
					if (coordinates[0] == -1) {
						coordinates[0] = row;
						coordinates[1] = col;
					}
					else {
						cout << "Found 2 start cells.. Aborting" << endl;
						return -1;
					}
				}
				// Calculate the number of -1s in the grid. 
				if (grid[row][col] == INVALID) {
					numMinus1s++;
				}
			}
		}
		magicNum = (gridRows* gridCols) - numMinus1s;
		return 0;
	}

	// Find the number of paths from start to end
	int numPathsToEnd(vector<vector<int>>& grid, int row, int col) {
		int numPaths = 0, retVal;
		int nextRow, nextCol;

		// Did we hit a cell that we should not step on?
		if (grid[row][col] == -1)
			return 0;
		// Have we already visited this cell?
		else if (stepped[row][col] == 1)
			return 0;

		// Have we reached the end?
		if (grid[row][col] == 2) {
			// Have we visited all zero cells?
			if (numVisitedCells == (magicNum - 1))
				return 1;
			else
				return 0;
		}

		stepped[row][col] = 1;
		numVisitedCells++;

		// Go left, right, top, down
		for (std::vector< vector <int>>::iterator it = steps.begin(); it != steps.end(); it++) {
			nextRow = row + it[0][0];
			nextCol = col + it[0][1];
			if ((nextCol >= 0) && (nextCol < grid[0].size()) && (nextRow >= 0) && (nextRow < grid.size())) {
				retVal = numPathsToEnd(grid, nextRow, nextCol);
				numPaths += retVal;
			}
		}

		stepped[row][col] = 0;
		numVisitedCells--;

		// If other than the starting cell, return failure to reach the end cell, 
		// else return the search has ended. Return the number of paths found
		return numPaths;
	}

public:
	int uniquePathsIII(vector<vector<int>>& grid)
	{
		vector <int> coordinates;
		int numPaths = 0;

		coordinates.assign(2, -1);
		if (findGridProps(grid, coordinates)) {
			return numPaths;
		}

		cout << "Start at " << coordinates[0] << "x" << coordinates[1] << endl;
		numPaths = numPathsToEnd(grid, coordinates[0], coordinates[1]);

		return numPaths;
	}

};


/*
https://leetcode.com/problems/unique-paths-iii/
On a 2 - dimensional grid, there are 4 types of squares :

1 represents the starting square.There is exactly one starting square.
2 represents the ending square.There is exactly one ending square.
0 represents empty squares we can walk over.
- 1 represents obstacles that we cannot walk over.

Return the number of 4 - directional walks from the starting square to the 
ending square, that walk over every non - obstacle square exactly once.



Example 1:
Input: [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 2, -1]]
	Output : 2
	Explanation : We have the following two paths :
	1. (0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (1, 2), (1, 1), (1, 0), (2, 0), (2, 1), (2, 2)
	2. (0, 0), (1, 0), (2, 0), (2, 1), (1, 1), (0, 1), (0, 2), (0, 3), (1, 3), (1, 2), (2, 2)

Example 2 :
Input : [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 2]]
	Output : 4
	Explanation : We have the following four paths :
	1. (0, 0), (0, 1), (0, 2), (0, 3), (1, 3), (1, 2), (1, 1), (1, 0), (2, 0), (2, 1), (2, 2), (2, 3)
	2. (0, 0), (0, 1), (1, 1), (1, 0), (2, 0), (2, 1), (2, 2), (1, 2), (0, 2), (0, 3), (1, 3), (2, 3)
	3. (0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (1, 2), (1, 1), (0, 1), (0, 2), (0, 3), (1, 3), (2, 3)
	4. (0, 0), (1, 0), (2, 0), (2, 1), (1, 1), (0, 1), (0, 2), (0, 3), (1, 3), (1, 2), (2, 2), (2, 3)
		  
Example 3 :
Input : [[0, 1], [2, 0]]
	Output : 0
	Explanation :
		   There is no path that walks over every empty square exactly once.
		   Note that the starting and ending square can be anywhere in the grid.


Note :
1 <= grid.length * grid[0].length <= 20
*/
int main()
{
	vector <vector <int>> example1 = {	{1, 0, 0, 0}, 
										{0, 0, 0, 0}, 
										{0, 0, 2, -1} };
	vector <vector <int>> example2 = {	{1, 0, 0, 0 },
										{0, 0, 0, 0 },
										{0, 0, 0, 2 } };

	vector <vector <int>> example3 = {	{ 0, 1 },
										{ 2, 0 } };

	Solution sol;

	cout << "Number of paths = " << sol.uniquePathsIII(example1) << endl;

    return 0;
}

