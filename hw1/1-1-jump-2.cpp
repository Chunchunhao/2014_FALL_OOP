#include <iostream>
#include <limits>


using namespace std;

int main () {
  int in=0, sum=0;
  const int max_int = numeric_limits<int>::max();

  while(1){

    if( !(cin >> in) ) {
      // detect none stream or overflow
      cin.clear();
      cin.ignore();
    } 
    else {
      if ( in < 0 )
        break;
      else {
        if( sum + in > max_int)
          cout << "Data may overflow !" << endl;
        else
          sum += in;
      }
    }
  }
  cout << "Sum is : " << sum << endl;
  return 0;

}


// Error when input 1c... 
