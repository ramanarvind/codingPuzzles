// codingPuzzles.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
private:
	vector <string> numStr;

public:
	string largestNum(vector <int> &numList)
	{
		int iStrSize, jStrSize, i, j, k, l;
		string largestStr;

		for (std::vector<int>::iterator it = numList.begin(); it != numList.end(); it++) {
			char itoaNum[10];
			_itoa_s(it[0], itoaNum, 10);
			numStr.push_back(itoaNum);
		}

		std::sort(numStr.begin(), numStr.end());

		for (i = 0; i < numStr.size()-1; i++) {
			j = i + 1;
			iStrSize = numStr[i].size();
			jStrSize = numStr[j].size();

			for(k = i, l = j; (iStrSize < jStrSize);) {
				if (numStr[l].substr(0, iStrSize).compare(numStr[k]) == 0) {
					if (numStr[l][0] > numStr[l][iStrSize])
						iter_swap(numStr.begin()+k, numStr.begin()+l);
				}
				k++;
				l++;
				if (k < numStr.size() - 1) {
					iStrSize = numStr[k].size();
					jStrSize = numStr[l].size();
				}
				else
					break;
			}
		}

		for (i = numStr.size() - 1; i >= 0; i--) 
			largestStr.append(numStr[i]);

		return largestStr;
	}
};


/*
This problem was asked by Twitter.

Given a list of numbers, create an algorithm that arranges them in order to 
form the largest possible integer. For example, given [10, 7, 76, 415], you 
should return 77641510*/
int main()
{
	//vector <int> example1 = { 10, 7, 76, 74, 77, 78, 79, 8, 415 }; 
	vector <int> example1 = { 798, 79, 794, 78, 764, 77, 7, 76, 75 };
	Solution sol;
	
	sol.largestNum(example1);
	
    return 0;
}

