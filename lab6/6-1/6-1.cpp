#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Point2D {
  Point2D( double inx, double iny ): x(inx), y(iny) {}
  double x = 0.0;
  double y = 0.0;
};

bool PointCMP ( const Point2D&, const Point2D&);

int main() {
  vector<Point2D> setPoint;
  do {
    // Read input
    string in;
    cout << "Enter a point (x,y) ! to quit :";
    getline(cin, in);
    if( in == "!")
      break;  // end of input

    // Parse
    stringstream ss;
    ss << in;
    double tmpx, tmpy;
    ss >> tmpx >> tmpy;

    // Push back
    setPoint.push_back(Point2D(tmpx, tmpy));
  } while(1);

  // Before
  cout << "The input points are: ";
  for( auto i = setPoint.begin(); i != setPoint.end(); i++)
    cout << "(" << i->x << "," << i->y << ")";
  cout << endl;
  // Sort
  sort(setPoint.begin(), setPoint.end(), PointCMP);

  // After
  cout << "The points after sorting are: ";
  for( auto i = setPoint.begin(); i != setPoint.end(); i++)
    cout << "(" << i->x << "," << i->y << ")";
  cout << endl;

  return 0;
}


bool PointCMP ( const Point2D &aa, const Point2D &bb) {
  if( aa.x == bb.x )
    return aa.y < bb.y;
  else
    return aa.x < bb.x;
}
