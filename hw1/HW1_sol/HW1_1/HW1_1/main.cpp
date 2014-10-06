#include <iostream>

using namespace std;

#include "Sales_item.h"
#include <fstream>
#include <string>
#include <cstdlib>  // for system command


// opens in binding it to the given file
ifstream& open_file(ifstream& in, const string& file)
{
	in.close();     // close in case it was already open
	in.clear();     // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given
	return in; // condition state is good if open succeeded
}

int main()
{
	ifstream in_file;
	string file_name;
	cout << "Enter the file name: ";
	cin >> file_name;
	if (!open_file(in_file, file_name))
	{
		cerr << "Complain: I cannot find the file" << endl << endl;
		cerr << system("dir") << endl; //only for windows OS
		return -1;
	}

	cout << "Contents of " << file_name << ":\n";

	Sales_item item, total_items;

	in_file >> total_items;

	while (in_file >> item)
	{
		if (compareIsbn(total_items, item))
		{
			total_items += item;
		}
		else
		{
			cout << total_items << " " << endl;

			total_items = item;
		}
	}

	cout << total_items << " " << endl;

	return 0;
}
