#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string s = "Some numerical values are 23 5 7";
	cout << s << endl;
	istringstream input_istring(s);
	string dump;
	int val1, val2, val3;
	input_istring >> dump >> dump >> dump >> dump
		>> val1 >> val2 >> val3;
	cout << "The sum is: " << val1 + val2 + val3 << endl;
	return 0;
}
