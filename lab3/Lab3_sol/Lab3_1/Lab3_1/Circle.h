#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

struct Circle
{

	Circle() = default;

	Circle(double r){ radius = r; }

	void setRadius(double r){ radius = r; }

	double getArea() const { return PI*radius*radius; }

	double radius = 0.0;

	const double PI = 3.14159;

};

std::ostream &print(std::ostream &os, const Circle &c);

std::istream &read(std::istream &is, Circle &c);

#endif // CIRCLE_H
