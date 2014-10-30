#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

Fraction::Fraction(int a, int b) {
	if (b == 0){
		cout << "分母不可以是零，我把它設為一了" << endl;
		son = a;
		mother = 1;
	}
	else {
		son = a;
		mother = b;
	}
}

Fraction::Fraction(istream &io){
	string a;
	cout << "Enter the name for Fraction: ";
	io >> a;
	name = a;
	cout << "Enter the values fot numerator and denomuinator: ";
	int c, d;
	io >> c >> d;
	if (d == 0){
		cout << "分母不可以是零，我把它設為一了" << endl;
		son = c;
		mother = 0;
	}
	else {
		son = c;
		mother = d;
	}
}

void Fraction::setName(string a){
	name = a;
}


Fraction& Fraction::setName(Fraction * f){
	name = f->name;
	return *this;
}

std::ostream &printFraction(std::ostream &os, const Fraction &f){
	os << "Fraction " << f.name << ": " << f.son << "/" << f.mother << endl;
	return os;
}