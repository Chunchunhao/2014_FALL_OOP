#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

struct Fraction
{

	Fraction() = default;
	Fraction(int a) { son= a; }
	Fraction(int a, int b);
	Fraction(std::istream &);

	void setName(std::string );
	void setName(char a ){ name=""; name.push_back(a); }
	Fraction& setName(Fraction *);

	int son = 0;
	int mother = 1;
	std::string name = "anonymous";
};

std::ostream &printFraction(std::ostream &, const Fraction &);



#endif
