#include <iostream>
using namespace std;

main()
{
	unsigned int uc_in, uc_out;
	cout << "Enter an 8 bit unsigned integer in hex: ";

	cin >> hex >> uc_in;
	cout << "Input :" << hex << uc_in << endl;
	
	uc_out = (uc_in >> 1) & 0x55 | (uc_in << 1) & 0xAA;

	cout << "Swapping odd & even bits of 0x" << hex << uc_in << " yields 0x" << hex << uc_out << endl;
}
