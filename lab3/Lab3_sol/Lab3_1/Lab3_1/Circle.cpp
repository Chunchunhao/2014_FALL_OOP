#include "Circle.h"
#include <iostream>
using namespace std;

ostream &print(ostream &os, const Circle &c)
{
	os << "Circle radius: " << c.radius << " area: "
		<< c.getArea() << endl;
	return os;
}

istream &read(istream &is, Circle &c)
{
	double radius;

	is >> radius;

	c.setRadius(radius);

	return is;
}
