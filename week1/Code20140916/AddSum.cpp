#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int num;
	cout << "Enter the number to be summed: ";
	while (cin >> num) {
		sum += num;
		cout << "Enter the number to be summed (non-integer to quit): ";
	}
	cout << "Sum is: " << sum << endl;
	return 0;
}
