#include <string>       
#include <iostream>     
#include <sstream>      
using namespace std;

int main() {
    cout << "Enter an English expression for an integer: ";
    string s;
    getline(cin, s); 
    cout << "Enter an integer: ";
    int num;
    cin >> num;
    ostringstream oss;
    oss << s << ": " << num;
    cout << oss.str() << endl;
    return 0;
}
