#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

Matrix::Matrix(std::istream &is) {
	string inputL;

	getline(is, inputL);

	int nameDown = 0;
	double digiNow = 1;
	double inputD = 0.0;
	int hNow = 0;
	int hasDouble = 0;
	int size = 1;
	int lastH = 0;
	int Warm = 0;
	for (char c : inputL){
		if (c == ';')
			size += 1;
	}
	mat.resize(size);
	for (char c : inputL){
		if (c == '[')
			nameDown = 1;

		if (nameDown == 0){
			name.push_back(c);
		}
		else {
			if (c == '.'){
				digiNow = 0.1;
			}
			else if (isdigit(c)){
				hasDouble = 1;
				int tmpInt = c - '0';
				double tmpDouble = tmpInt * digiNow;
				inputD += tmpDouble;
				if (digiNow >= 0)	// Increment
					digiNow *= 10;
				else
					digiNow *= 0.1;
			}
			else {
				if (hasDouble == 1){
					// push new number
					mat[hNow].push_back(inputD);
					++w;
				}
				else {
					// do nothing
				}
				inputD = 0.0;
				digiNow = 1.0;
				hasDouble = 0;
				if (c == ';' || c == ']') {
					++h;
					if (hNow != 0){
						if (lastH != mat[hNow].size())
							Warm = 1;
					}
					lastH = mat[hNow].size();
					++hNow;
				}
			}
		}

	}
	if (Warm == 1){
		bad = 1;
	}
}


std::ostream &printMatrix(std::ostream &os, const Matrix &M){
	for (auto itro = M.mat.begin(); itro != M.mat.end(); ++itro){
		for (auto itri = itro->begin(); itri != itro->end(); ++itri){
			os << *itri << "\t";
		}
		os << endl;
	}
	if (M.bad == 1)
		cout << "WARNING: dimensions are not consistent!!!" << endl;

	os << endl;

	return os;

}

/*
Matrix& addMatrix( Matrix&, Matrix&);
*/