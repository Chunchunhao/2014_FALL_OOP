#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

struct Circle {
  double radius = 0.0;

  Circle() = default;
  Circle(const double &r) : radius(r) { };
  
  double setRadius ( double r) {
    radius = r;
    cout << "Circle radius: " << radius << " area: " << 
  }

}

#endif
