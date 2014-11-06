#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;
string & filt( string &);

int main() {
  // File reading ?
  string fn1="Alice_story1.txt", fn2="Alice_story2.txt";
  ifstream if1, if2;
  if1.open(fn1); if2.open(fn2);
  if( !if1.is_open() || !if2.is_open() ){
    cerr << "File open faield!" << endl;
    return -1;
  }

  // Read file into memory
  vector<string> f1, f2;
  string pr0cess;
  while( if1 >> pr0cess )
    f1.push_back(filt(pr0cess));
  while( if2 >> pr0cess )
    f2.push_back(filt(pr0cess));

  // Compare two file
  vector<string> ans;
  for( auto &i : f1)
    if( count(f2.begin(), f2.end(), i) != 0 )
      ans.push_back(i);

  // Output the answer
  sort(ans.begin(), ans.end());
  auto rr = unique(ans.begin(), ans.end());
  for( auto i=ans.begin(); i!=rr; i++)
    cout << *i << endl;
}


// Ignore nonalphabet and case insensitive
string & filt( string & a) {
  for( auto i = a.begin() ; i != a.end(); i++) {
    if( isalpha(*i) ) {
      tolower(*i);
    }
    else {
      a.erase(i);
      i--;
    }
  }
  return a;
}
