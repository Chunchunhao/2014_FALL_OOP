#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout << "Enter a sequence of numbers to be summed: ";

	vector<int> numbers;
	
	int tmp_number;
	int sum = 0;
	
	while (cin >> tmp_number && tmp_number > 0)
	{
		sum += tmp_number;
	}

	cout << "Sum is: " << sum << endl;
	return 0;
}