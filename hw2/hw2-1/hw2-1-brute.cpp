#include <iostream>
#include <fstream>
#include <vector>
#include <String>
#include <algorithm>

using namespace std;

struct words
{
  int times = 0;
  string word;
};

struct winner
{
  int times = 0;
  int index = 0;
};

int main() {
  string filename;
  fstream fp;
  int i=0;
  do {
    if( (i++) == 0)
      cout << "Please input the file name." << endl;
    else {
      cout << endl << "File was opened incorrectly." << endl << endl;
      cout << "Please input the file name again." << endl;
    }
    cout << "Input Here :" ;
    cin >> filename;
    fp.open(filename);
  } while (!fp);
  cout << endl << "File was opened correctly." << endl << endl;

  vector<words> list;
  winner win;
  string in;
  while( fp >> in ){
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    if( list.size() == 0){
      words fstword ;
      fstword.times = 1;
      fstword.word = in;
      list.push_back(fstword);
    }
    else {
      for( i=0; i<list.size(); i++) {
        if( in == list[i].word) {
          list[i].times++;
          break;
        }
      }
      if( i == list.size() ) {
        words newWord;
        newWord.times = 1;
        newWord.word = in;
        list.push_back(newWord);
      }
      if( list[i].times > win.times ){
        win.times = list[i].times;
        win.index = i;
      }
    }
  }

  cout << "The most repeated word is \"" << list[win.index].word << "\"." << endl;
  cout << "It has been repeated for " << win.times << " times." << endl;
  fp.close();

  return 0;
}
