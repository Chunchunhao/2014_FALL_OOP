#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
 
  // Read File
  fstream fp;
  string filename;
  cin >> filename;
  fp.open(filename);
   if( !fp ) {
    cerr << "Open file failed" << endl;
    return -1;
  }

  // Print file
  vector<string> file;
  string str;
  int ln = 1;
  while( getline(fp, str) ){
    cout << "\"Line " << ln << "\": " <<  str << endl;
    file.push_back(str);
    ++ ln;
  }

  fp.close();
  return 0;
}
