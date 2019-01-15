#include <iostream>
using namespace std;

// Given two strings A and B, return whether or not A can be shifted some number of times to get B.
// For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false

#define STRLEN 10

main()
{
	char A[STRLEN], B[STRLEN], AA[STRLEN*2];
	
	cout << "Enter String A: ";
	cin.getline(A, STRLEN);
	cout << "# of characters read " << cin.gcount() << " String A: " << A << endl;
	// Clear any error that have occured during the above read. 
	if(cin.good() == 0)
	{
		cout << "Error: Fail:" << cin.fail() << " Bad:" << cin.bad() << " EOF:" << cin.eof() << endl;
		cin.clear();
	}

	cout << "Enter String B: ";
	cin.getline(B, STRLEN);
	cout << "# of characters read " << cin.gcount() << " String B: " << B << endl;
	// Clear any error that have occured during the above read. 
	if(cin.good() == 0)
	{
		cout << "Error: Fail:" << cin.fail() << " Bad:" << cin.bad() << " EOF:" << cin.eof() << endl;
		cin.clear();
	}

	// Concatenate A twice with itself and then check if B is a substring of A
	strcpy(AA, A);
	strcat(AA, A);
	cout << "String AA: " << AA << "  " << "String B: " << B << endl;
	if (strstr(AA, B) != NULL)
		cout << A << " can be shifted to form " << B << endl;
	else
		cout << A << " can NOT be shifted to form " << B << endl;
}
