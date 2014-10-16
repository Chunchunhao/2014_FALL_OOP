#include <iostream>
#include "Maze.h"
using namespace std;

int main()
{
	Maze m("maze612.txt");
	printLayout(cout, m);
	cout << endl;
	cout << "--------------------------------------" << endl;
	cout << "Your escaping path:" << endl << endl;
	printPath(cout, m.find());

	//printLayout(cout, m);
	// You can uncomment above statment for checking path on the maze.

	return 0;
}

