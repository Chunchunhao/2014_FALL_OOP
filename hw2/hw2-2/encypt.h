#include <iostream>
#include <string>

std::string caesar_cipher( const std::string& input, const int shift);

// This function shif `n`
std::string caesar_cipher( const std::string& input, const unsigned int shift) {
  std::string mod = input;  // Copy the input string to prevent incoreect modify happened
  for( char &c: mod) {
    if( c >= 'A' && c <= 'Z') {
      c += shift;
      while( c > 'Z')
        c -= 26;
    }
    else if( c >= 'a' && c<= 'z') {
      c += shift;
      while( c > 'z')
        c -= 26;
    }
  }
  return mod;

}



