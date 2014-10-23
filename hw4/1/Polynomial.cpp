#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial( string & in ) {
  in += ' ';
  double nu = 0.0, digi = 1;
  int epo = 0;
  int op = 0;  // 0 means check number, 1 means check exponential, 2 means do nothing
  for( char &c: in ){
    //cout << c << endl;
    if( c == '.'){
      // error check
      if( digi < 0 )
        cout << "Syntax Error: you cant use 0.0.1 as a number " << endl;
      digi = 0.1;

    }
    else if( c == 'x' || c == 'X' ){
      if( op != 0)
        cout << "Syntax Error: put some number before x^..." << endl;

      op = 1;
      epo = 0;
      digi = 1;
    }
    else if( c == '^' ){
      if( op!= 1 && epo != 0 && digi != 1)
        cout << "Syntax Error: x or X should followed by ^" << endl;
    }
    else if( isdigit(c) ){
      if ( op == 1 ){
        epo += ( c - '0' ) * digi;
        digi *= 10;
      }
      else {  // op == 0
        op = 0;
        nu += ( c - '0' ) * digi;
        digi = ( digi > 0 ? digi *= 10 : digi *= 0.1 ) ;
      }
    }
    else {
      if( op == 1 ){
        // I dont handle x^ 2.2
        if( poly.size() <= epo || poly.size() == 0) {
          while( poly.size() < epo ) {
            poly.push_back(0.0);
          }
          poly.push_back(nu);
        }
        else {
          poly[epo] += nu;
        }
        nu = 0;
        epo = 0;
        digi = 1;
        op = 0;
      }
    }
  }

  for( int i = 0 ; i < poly.size(); i++ ) {
    cout << poly[i] << " x^" << i << "\t";
  }
  cout << endl;
}


ostream & Polynomial::print( ostream & os ) {
  for( int i = 0 ; i < poly.size(); i++ ) {
    os << poly[i] << " x^" << i << "\t";
  }
  os << endl;
  return os;
}


Polynomial & Polynomial::combine( Polynomial & tt ) {
  if( tt.poly.size() > this->poly.size() ) {
    while( tt.poly.size() != this->poly.size())
      this->poly.push_back(0.0);
  }
  for( int i = 0 ; i < tt.poly.size() ; i++ ){
    this->poly[i] += tt.poly[i];
  }
  return *this;
}


/*
  Polynomial() = default;
  Polynomial( std:string &);
  Polynomial &combine( Polynomail & );

  std::vector<double> poly;
}



std::ostream &print( const Polynomial &);


#endif

*/
