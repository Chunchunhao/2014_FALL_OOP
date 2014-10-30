#include <List>
#include <iostream>

using namespace std;

int main() {
  int m, n;
  cout << "Enter the people <N> and passes <M> in Josephus problem: " ;
  cin >> n >> m;

  // Let the player sit
  list<int> ply;
  for( int i=1; i<= n; i++)
    ply.push_back(i);

  int mr = m; // magic rod
  auto itr = ply.begin();
  while( ply.size() != 1 && !ply.empty() ) {
    // idiot loop
    if( mr == 0){
      mr = m;
      itr = ply.erase(itr);
      if( itr == ply.end() )
        itr = ply.begin();
    }
    else {
      ++itr;
      if( itr == ply.end() )
        itr = ply.begin();
      --mr;
    }
  }
  cout << "The player " << ply.back() << " wins!" << endl;
}
