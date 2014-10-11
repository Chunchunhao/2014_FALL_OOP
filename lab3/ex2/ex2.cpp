#include <iostream>
#include "Maze.h"
using namespace std;
int main() {
  Maze m("maze612.txt");
  printLayout(cout, m);
  m.find();
  cout << endl;
  cout << "--------------------------------------" << endl; 
  cout << "Your escaping path:" << endl << endl; 
  printPath(cout, m.find());
  return 0; 
}
