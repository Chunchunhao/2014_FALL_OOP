#include <iostream>
#include <fstream>
#include <String>
#include <algorithm>
#include "trie.h"

using namespace std;

struct winner
{
  int score = 0;
  string winner;
};  // This struct to save the largest number of times;

int main() {
  
  // Open File
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

  // Read File
  Trie* List = new Trie();
  winner win;
  string in;
  while( fp >> in ){
    int score = List->searchWord(in);
    // In my `trie` structure, it will convert all alphabetic to lowercase
    if( score > win.score){
      win.score = score;
      win.winner = in;
    }
  }
  
  // Output Message
  cout << "The most repeated word is \"" << win.winner << "\"." << endl;
  cout << "It has been repeated for " << win.score << " times." << endl;
  fp.close();

  return 0;
}
