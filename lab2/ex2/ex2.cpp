#include <iostream>
#include <fstream>
#include <String>
#include <algorithm>
#include "trie.h"

using namespace std;

int main() {
  
  // Open File
  fstream fp;
  fp.open("Alice_story1.txt");
  if(!fp) {
    cerr << "File was opened incorrectly!" << endl;
    return -1;
  }
  
  // Read File
  Trie* List = new Trie();
  string data;
  while( fp >> data ){
    List->searchWord(data);
  }
  fp.close();

  // Process input and output
  string in;
  while( 
    cout << "Enter the word to be found in Alice_story1.txt (! to quit): "
    && cin >> in
    && in != "!"){
    cout << "The word " << in << " has appeared " << List->findWord(in) << " times in Alice_story1.txt\n" << endl;
  }

  return 0;
}
