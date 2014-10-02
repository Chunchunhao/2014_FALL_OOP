#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string reverseNumber(const string& passin); 

int main() {
  string in;
  bool neg = false;
  
  // Input 
  cout << "Input a long integer : ";
  cin >> in;
  
  if( in[in.size()-1] == '0' ){
    cout << "INPUT ERROR!!The last digit can't be zero." << endl;
    return -1; // Error check, 
  }
  else {
    // Input Error and neg Check,
    for( auto i=0; i < in.size(); i++)  {
      if(i == 0 && in[i] == '-'){
        neg = true;
        continue;
      } // in[0] is ='1'
      else if( !isdigit(in[i]) ){
        cout << "INPUT ERROR!!Please input an integer." << endl;
        return -1;
      } // in[i] is not digit
    }
    
    // Process and output
    cout << "The reverse of " << in << " is " ;
    if( neg)
      cout << "-"; 
    cout << reverseNumber( in) << endl;

    return 0;
  }
}


string reverseNumber(const string& passin ) {
  string re;
  for( int i = passin.size() -1 ; i > 0; i --){
    re+=passin[i];
  }
  if( passin[0] != '-')
    re+=passin[0];
  return re;
}
