#include <iostream>
#include <string>
#include "encypt.h"

using namespace std;

int main() 
{
  string in;
  unsigned int key;

  cout << "Please input a message: " << endl;
  getline( cin, in);
  
  cout << "The \'n\' position futhur along the alphabet: " << endl;
  cin >> key;

  cout << "The encoded message: " << endl;
  cout << caesar_cipher(in, key) << endl;

  return 0;
}
