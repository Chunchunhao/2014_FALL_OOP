#include "Polynomial.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

	cout << "Please enter the first polynomial with a home-made string representation: " << endl;
	string poly_rep;
	getline(cin, poly_rep);
	Polynomial poly1(poly_rep);

	cout << "Please enter the second polynomial with a home-made string representation: " << endl;
	getline(cin, poly_rep);
	Polynomial poly2(poly_rep);
	cout << "The first polynomial after the addition of the second polynomial is: " << endl;
	poly1.combine(poly2).print(cout) << endl; \
		system("pause");
	return 0;
}