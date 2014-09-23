#include <iostream>
#include <string>
#include "hw1Read.h"

using namespace std;

int main() {
	string inputStr;
	int sum = 0, msg = 0;
	cout << "Enter a squence of number to be summed: ";

	while (cin >> inputStr){

		msg = readInput(inputStr);
		if (-1 == msg) {
			// end
			break;
		}
		else if (0 > msg) {
			// not an positive integer
		}
		else {
			// an positive integer
			sum += msg;
		}
	}
	if (cin.fail())
	{
		cerr << "Failed Input !!" << endl;
		return 1;
	}
	cout << "Sum is : " << sum << endl;

#ifdef _WIN32 || WIN32 || defined(_WIN32) || defined(WIN32)
	system("pause");
#endif

	return 0;
}
