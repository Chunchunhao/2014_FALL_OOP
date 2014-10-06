#include <iostream>
#include <vector>
#include <string>

std::string reverseLong(std::string input);

using namespace std;

int main()
{
	cout << "Input a long integer: ";

	string input;

	cin >> input;

	if (input.back() == '0')
	{
		cout << "INPUT ERROR !! The last digit can't be zero." << endl;
		return -1;
	}

	auto output = reverseLong(input);

	cout << "The reverse of " << input << " is " << output << endl;

	return 0;
}

string reverseLong(string input)
{
	string output;
	
	for (decltype(input.size()) index = input.size()-1; index != -1; --index)
	{
		output.push_back(input[index]);
	}

	return output;
}