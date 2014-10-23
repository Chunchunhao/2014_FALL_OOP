#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

struct Matrix {

	Matrix() = default;
	Matrix(std::istream &);

	std::string getName(const Matrix & M) { return M.name;}

	int w = 0;
	int h = 0;
	int bad = 0;
	bool val = true;
	std::string name = "";
	std::vector < std::vector < double > > mat = {{}};

};


std::ostream &printMatrix(std::ostream &, const Matrix &);



#endif