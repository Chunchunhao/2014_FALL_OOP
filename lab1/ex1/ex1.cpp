#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> list;
  string in;
  int sum = 0;
  cout << "Enter a few strings and terminate with ! : " ;
  
  while( cin >> in && in != "!") {
    list.push_back(in);
  }

  for( string &s: list){
    cout << s << " size is:" << s.size() << endl;
  }
  cout << "The merge string is: ";
  for( string &s: list){
    cout << s;
    sum += s.size();
  }
  cout << " and its size is: " << sum;


  return 0;
}
