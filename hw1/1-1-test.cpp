#include <iostream>
#include <string>

using namespace std;

// Assume under int limit

int readInput (string in);

int readInput (string in) {
  int num = 0,
      negBit = (in[0] == '-' ? 1: 0);
  
  if(negBit == 1 && in.size() == 1)
    return -2;

  for(int i = (negBit == 1 ? 1 : 0) ; i < in.size(); i++) 
  { 
    if( in[i] < '0' || in[i] > '9'){
      return -2; // not integer
    }
     else {
      num = num*10 + in[i] - '0';  
      if( num < 0 )
        return num; // overflow
    }
  }
  if( negBit == 1){
    return -1;
  }
  else 
    return num;
}

int main () {
  string inputStr;
  int sum = 0, msg = 0;

  while( cin >> inputStr ){
   
    msg = readInput(inputStr);
    if( -1 == msg ) {
      // end
      break;
    }
    else if ( 0 > msg ) {
      // not an positive integer
    }
    else {
      // an positive integer
      sum += msg;
    }
  }
 
  cout << "Sum is : " << sum << endl;
  return 0;
}
