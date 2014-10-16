#include <iostream>
#include "Matrix.h"
using namespace std;

int main(){
    // m1 
    cout << "Enter the contents of matrix m1 with MATLAB syntax" << endl; 
    Matrix m1(cin);
    

    cout << "The contents of matrix m1 are: " << endl;
    printMatrix(cout, m1);
    
    cout << endl;
    // m2 
    cout << "Enter the contents of matrix m2 with MATLAB syntax" << endl;
    Matrix m2(cin);
    cout << "The contents of matrix m2 are: " << endl;
    printMatrix(cout, m2);
    cout << endl;
    // m3 
    cout << "Enter the contents of matrix m3 with MATLAB syntax" << endl;
    Matrix m3(cin);
    cout << "The contents of matrix m3 are: " << endl;
    printMatrix(cout, m3);
    cout << endl;
    
    return 0;
}