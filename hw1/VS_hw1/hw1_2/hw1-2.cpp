#include <iostream>
#include <fstream>
#include <vector>

#include "Sales_item.h"

// OS dep. 
 #ifdef _WIN32 || WIN32 || defined(_WIN32) || defined(WIN32) 
#define OS_Windows
 #else
#include <unistd.h>
 #endif

using namespace std;

int main() {
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;

	// Open File 
	fstream fp;
	fp.open(filename);
	if (!fp) {
		cerr << "Complain: I cannot find the file" << endl;
		#ifdef OS_Windows
			/* Windows code */
			system("dir");
      system("pause");
    #else
			/* GNU/Linux code */
			execlp("ls", "ls", "-l");
		#endif
		return EXIT_FAILURE;
	}
	
	// Read File
	Sales_item in;
	vector<Sales_item> itemList;
	while (fp >> in) { // if input is not format corret then leave the program
		if (itemList.size() > 0){
			for (int i = 0; i <= itemList.size(); i++) {
				if (i == itemList.size()) {
					itemList.push_back(in);
					break;
				} // there's no book in our list
				else {
					if (compareIsbn(in, itemList[i])){
						itemList[i] += in;
						break;
					}
				} // check whether the books in our list
			}
		}
		else {
			itemList.push_back(in);
		} // empty list
	}

	// Error handling 
	if ( !fp.eof() ) {
		cerr << "Incorrect Input !!" << endl;
		fp.close();
    #ifdef OS_Windows
    system("pause");
    #endif
		return EXIT_FAILURE;
	}
	fp.close();

	for (int i = 0; i<itemList.size(); i++) {
		cout << itemList[i] << endl;
	}
  #ifdef OS_Windows
  system("pause");
  #endif
	return EXIT_SUCCESS;
}
