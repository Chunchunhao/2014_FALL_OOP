#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>
#include <string>

struct Polynomial {

  Polynomial() = default;
  Polynomial( std::string & );
  Polynomial &combine( Polynomial & );

  std::vector<double> poly;
  std::ostream &print( std::ostream & );
};



#endif
