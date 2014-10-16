#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main () {
 
  fstream fp;

  // string filename;
  // cin >> filename;
  string filename = "Alice_story.txt";
  fp.open(filename);
   if( !fp ) {
    cerr << "Open file failed" << endl;
    return -1;
  }
  vector<string> file;
  string str;

  while( getline(fp, str) ){
    file.push_back(str);
  }

  string query;
  vector<int> storeline;
  int find = 0, total;
  cout << "Enter the word tp be found in Alice_story.txt (! to quit) : ";
  while( cin >> query && query != "!"){
    total = 0;
    storeline = {};
    for( auto line = 0; line < file.size(); line++){
      find = 0;
      for( char c : file[line]){
        
        if( isalpha(c) ){
          //cout << c;
          if( c == query[find] && find < query.size()) {
            ++find;
          } 
          else {
            find = 0;
          }
        }
        else{
          if( find == query.size() ){
            storeline.push_back(line+1);
            ++ total;
          }
          find = 0;
        }
      }
    }
   cout << "The word " << query << " has appeared " << total << " times in " << filename << endl;; 
   for( auto i: storeline){
    cout << "\"Line " << i << "\": " << file[i] << endl;
   }
   cout << "Enter the word to be found in Alice_story.txt (! to quit) : "; 
  }
  fp.close();

}
