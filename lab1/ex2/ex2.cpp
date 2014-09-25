#include <iostream>
#include <fstream>
#include <vector>
#include <String>

using namespace std;

int main() {
  string filename, line;
  fstream fp;
  int i = 0;
  do {
    if( (i++) == 0)
      cout << "Please input the file name." << endl;
    else
      cout << "Please input the file name again." << endl;
    cout << "Input Here :" ;
    cin >> filename;
    fp.open(filename);
  } while (!fp);
  
  int lineNum = 0;
  while(getline(fp, line)){
    int punc=0, space=0;
    for(char &c: line){
      if( c == ' ')
        space++;
      else if( (c > 'z' || c < 'a') &&
                (c > 'Z' || c < 'A') &&
                (c > '9' || c < '0'))
        punc++;
    }

    lineNum ++;
    cout << "Line " << lineNum << endl;
    cout << "\tPunctuation: " << punc << endl;
    cout << "\tSpaces: " << space << endl;
  
  }

  fp.close();

  return 0;
}
