#include <iostream>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f1; // 0/1
    f1.setName("f1");
    cout << "======" << endl;
    printFraction(cout, f1);
    Fraction f2(3); //3/1
    f2.setName('f');
    Fraction f3(-2, 4); //-2/4
    cout << "======" << endl;
    printFraction(printFraction(cout, f2), f3);
    cout << "======" << endl;
    Fraction f4(cin); // prompt for input
    cout << "======" << endl;
    printFraction(cout, f4);
    cout << "======" << endl;
    printFraction(cout, f4.setName(&f2));
    return 0;
}
