#include <iostream>
#include <List>

using namespace std;

int main () {
  int in;
  cout << "Please input the number, N: ";
  cin >> in;

  // Preprocessing
  list<int> p;
  cout << "Original data: " << endl;
  for( int i=2; i <=in; i++) {
    p.push_back(i);
    cout << p.back() << " ";
  }
  cout << endl;

  // run algo
  auto it = p.begin();
  while( it != p.end() ) {
    auto itin = it;
    int m0d = *it; // piv. as moder
    ++itin; // after piv.
    while( itin != p.end() ) {
      if( *itin % m0d == 0 )
        itin = p.erase(itin);
      else
        ++itin;
    }
    ++it;
    // Print each itr.
    cout << "After erasing with the base \"" << m0d <<"\": " << endl;
    for( auto i = p.begin(); i!= p.end(); i++)
      cout << *i << " ";
    cout << endl;

  }
}
