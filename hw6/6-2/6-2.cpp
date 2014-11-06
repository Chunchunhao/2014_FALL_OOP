#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Sales_item.h"

using namespace std;

bool shlvCMP ( const Sales_item &, const Sales_item & );

int main() {
  string fnm="book_records.txt";
  ifstream ifs;
  cout << "Enter the file name with book records: ";
  // cin >> fnm;
  ifs.open(fnm);

  if( !ifs.is_open() ) {
    cerr << "File dosn't exits, bye~" << endl;
    return -1;
  }

  vector<Sales_item> shlv;
  Sales_item in;
  cout << endl;

  string cp;
  while( getline( ifs, cp ) ){
    // note: Sales item read would not handle the endl
    if( cp[0] != '#' && (cp.size()>10) ){
      stringstream ss;
      ss << cp;
      ss >> in;
      shlv.push_back(in);
    }
  }

  cout << "The book records before sorting are: " << endl;
  for( auto &si: shlv)
    cout << si << endl;
  cout << endl;

  sort( shlv.begin(), shlv.end(), shlvCMP);
  cout << "The book records after sorting are: " << endl;
  for( auto &si: shlv)
    cout << si << endl;
  cout << endl;

  for( auto i = shlv.begin(); i!= shlv.end(); i++) {
    for( auto j = i+1; j != shlv.end(); ++j){
      if( i->isbn() == j->isbn()){
        *i += *j;
        j = shlv.erase(j);
        --j;
      }
    }
  }
  cout << "The average prices for each book record are: " << endl;
  for( auto &si: shlv)
    cout << si << endl;
  cout << endl;

  return 0;
}


bool shlvCMP ( const Sales_item & a, const Sales_item & b ) {
  if( a.isbn() == b.isbn() )
    return a.avg_price() < b.avg_price();
  else
    return a.isbn() < b.isbn();
}
