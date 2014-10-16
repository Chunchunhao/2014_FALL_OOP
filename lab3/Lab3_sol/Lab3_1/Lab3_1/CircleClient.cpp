#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
	Circle c1;
	print(cout, c1);
	c1.setRadius(1);    // This sets c1 radius to 1
	print(cout, c1);
	Circle c2(2.5);     // This sets c2 radius to 2.5
	print(cout, c2);

	Circle c3, c4; // default constructor, radius is 0.0 

	cout << "Please input radii for c3 and c4: ";

	read(read(cin, c3), c4); // c3 radius is 1.5, c4 radius is 3.5

	print(print(cout, c3), c4);

	return 0;
}
