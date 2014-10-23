#include <iostream>
#include "IntegerVector.h"
using namespace std;

int main()
{
	IntegerVector a(3);
	IntegerVector b(5);
	IntegerVector c(2, 6);
	print(cout, c.intersection(b).intersection(a));
}
