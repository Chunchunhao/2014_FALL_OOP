#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool orderr(int a, int b) {return a > b;}
bool reverr(int a, int b) {return a < b;}

int main() {

  int arr[] = {-2, 19, 80, -47, 80, 80, -2};

  cout << "(a) The elements are: ";
  vector<int> cp(7);
  copy( arr, arr+7, cp.begin());
  for(vector<int>::iterator i = cp.begin(); i != cp.end(); i++)
    cout << *i << " ";
  cout << endl;

  cout << "(b1) The elements sorted in an increasing order are:" << endl;
  sort( cp.begin(), cp.end(), reverr);
  for(vector<int>::iterator i = cp.begin(); i != cp.end(); i++)
    cout << *i << " ";
  cout << endl;

  cout << "(b2) The elements sorted in an decreasing order are:" << endl;
  // Maybe I should just print in revers order ?
  sort( cp.begin(), cp.end(), orderr);
  for(vector<int>::iterator i = cp.begin(); i != cp.end(); i++)
    cout << *i << " ";
  cout << endl;

  cout << "The unique elements are: " << endl;
  vector<int> ui;
  unique_copy(cp.begin(), cp.end(), back_inserter(ui));
  for( auto i = ui.begin(); i!= ui.end(); i++)
    cout << *i << " ";
  cout << endl;

  return 0;
}
