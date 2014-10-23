#include <iostream>
#include "IntegerVector.h"
using namespace std;

int main()
{
	IntegerVector a;
	IntegerVector b(5);
	print(cout, b);
	IntegerVector c(2, 5);
	print(cout, c);
}
