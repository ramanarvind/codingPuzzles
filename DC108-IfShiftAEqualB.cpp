#include <iostream>
using namespace std;

// Given two strings A and B, return whether or not A can be shifted some number of times to get B.
// For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false

#define STRLEN 10

main()
{
	char A[STRLEN], B[STRLEN], AA[STRLEN*2];
	cout << "Enter String A: ";
	cin >> A;
	cout << "Enter String B: ";
	cin >> B;

	cout << "String A: " << A << "  " << "String B: " << B << endl;
	strcpy(AA, A);
	strcat(AA, A);
	cout << "String AA: " << AA << "  " << "String B: " << B << endl;
	if (strstr(AA, B) != NULL)
		cout << A << " can be shifted to form " << B << endl;
	else
		cout << A << " can NOT be shifted to form " << B << endl;
}
