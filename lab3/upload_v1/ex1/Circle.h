#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

struct Circle {
friend std::istream &read(std::istream&, const Circle& );
friend std::ostream &print(std::ostream&, const Circle& );
public:
  Circle() : radius(0.0) { setArea();}
  Circle(const double &r) : radius(r) { setArea();}
  Circle &setRadius(const double&);
  double getRadius () const {return radius;}
  double getArea () const {return area;}
private:
  void setArea();
  void printStatus();
  double radius = 0.0;
  double area = 0.0;
};

void Circle::setArea() {
  this->area = 3.14159 * this->radius * this->radius;
}

Circle &Circle::setRadius (const double &r) {
  this->radius = r;
  this->setArea();
  return *this;
}

std::ostream &print(std::ostream &os, const Circle::Circle &cc){
   os << "Circle radius: " << cc.getRadius() << " area: " << cc.getArea() << std::endl;

  return os;
}

std::istream &read(std::istream &is, Circle::Circle &cc) {
  double rr;
  if( is >> rr ){
    cc.setRadius( rr);
    return is;
  }
  else{
    std::cout << "ERROR" << std::endl;
    return is;
  }
}

#endif
