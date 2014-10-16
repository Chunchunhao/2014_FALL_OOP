#include <iostream>
#include "Matrix.h"
using namespace std;

int main(){
    // m1 2x2
    cout << "Enter the contents of matrix m1 with MATLAB syntax" << endl; 
    Matrix m1(cin);
    cout << "The contents of matrix m1 are: " << endl;
    printMatrix(cout, m1);
    cout << endl;
    // m2 inconsistent dimension
    cout << "Enter the contents of matrix m2 with MATLAB syntax" << endl;
    Matrix m2(cin);
    cout << "The contents of matrix m2 are: " << endl;
    printMatrix(cout, m2);
    cout << endl;
    // m3 2x4
    cout << "Enter the contents of matrix m3 with MATLAB syntax" << endl;
    Matrix m3(cin);
    cout << "The contents of matrix m3 are: " << endl;
    printMatrix(cout, m3);
    cout << endl;
    // m4 2x2
    cout << "Enter the contents of matrix m4 with MATLAB syntax" << endl;
    Matrix m4(cin);
    cout << "The contents of matrix m4 are: " << endl;
    printMatrix(cout, m4);
    cout << endl;    
    // Addition
    cout << "The contents of m1 + m3 are: " << endl;
    // printMatrix(cout, addMatrix(m1, m3));
    cout << "The contents of m1 + m4 are: " << endl;
    // printMatrix(cout, addMatrix(m1, m4));
    return 0;
}