#include <iostream>
#include <string>
#include "Stock.h"

using namespace std;

int main()
{
	cout << "Enter the first share (name, num_holding, share_price): ";
	string line;
	getline(cin, line);
	Stock s0(line);

	cout << "Enter the second share (name, num_holding, share_price): ";
	getline(cin, line);
	Stock s1(line);
	Stock top = s0.topval(s1);
	cout << top.getName() << " with total value of "
		<< top.getTotalVal() << " is more valuable." << endl;
	return 0;
}