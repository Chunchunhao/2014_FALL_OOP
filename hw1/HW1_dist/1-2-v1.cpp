#include <iostream>
#include <fstream>
#include "Sales_item.h"
#include <vector>

 #ifdef _WIN32 || WIN32 || defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#include <process.h>
// http://msdn.microsoft.com/en-us/library/1kxct8h0.aspx
 #else
#include <unistd.h>
 #endif


using namespace std;

int main () {
  
  // char filename[] = "book_sales";
  string filename;
  cout << "Enter the file name: " ; 
  cin >> filename;
  fstream fp;
  fp.open(filename);
  
  if( !fp) {
    cerr << "Complain: I cannot find the file" << endl;
    #ifdef OS_Windows
    /* Windows code */
    _execlp( "dir", "dir" );
    #else
    /* GNU/Linux code */
    execlp( "ls", "ls", "-l");
    #endif
    return -1;
  }

  Sales_item in;
  vector<Sales_item> itemList;
  while(  fp >> in ) { // if input is not format corret then leave the program
    if( itemList.size() > 0 ){ 
      for( int i=0; i<=itemList.size(); i++) {
        if( i == itemList.size() ) {
          itemList.push_back(in);
          break;
        }
        else {
          if( compareIsbn(in, itemList[i]) ){
            itemList[i] += in;
            break; 
          }
        } // check whether the books in our list
      }
    }
    else {
      itemList.push_back(in);
    }
  }
  
  fp.close();
  
  for( int i=0; i<itemList.size(); i++) {
    cout << itemList[i] << endl;
  }
  
  return EXIT_SUCCESS;

}
