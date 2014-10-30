#include <iostream>
#include <list>
#include <string>
#include <cctype>
using namespace std;

int main() {
  list<char> nu;
  string in;
  cout << "Enter an integer (! ot quit): ";
  cin >> in;
  while( in != "!" ) {
    int neg=0;
    unsigned len=0;
    for( char &c : in ) {
      if( c == '-' && neg == 0 ){
        neg = 1; // - 
      }
      else if( c == '0' && neg!=2 ){
        // ignore; 0000123
      }
      else if( isdigit(c) ) {
        neg = neg == 1 ? 1: 2; // to lock
        nu.push_back(c);
        len++;
      }
      else {
        cout << "Invalid Input !" << endl;
        continue;
      }
    }
    auto it = nu.begin();
    if( neg == 1 )
      cout << '-';

    while( it != nu.end() ) {
      cout << *it;
      ++it;
      if( --len%3 == 0 && it != nu.end()) {
        cout << ',';
      }
    }
    nu.clear();
    cout << endl << "Enter an integer (! ot quit): ";
    cin >> in;
  }
}
