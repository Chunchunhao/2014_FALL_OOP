#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> c(1,10);

  for( auto itr = c.begin(); itr != c.end() ; ++itr){
    if( itr % 2)
      cout << *itr << " ";
    else 
      cout << *itr << " ";
  }
  cout << endl;
  return 0;

}
