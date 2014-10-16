#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// members are public by default
struct PersonInfo {
	string name;
	vector<string> phones;
};

ifstream& open_file(ifstream& in, const string& file)
{
	in.close();     // close in case it was already open
	in.clear();     // clear any existing errors
	// if the open fails, the stream will be in an invalid state
	in.open(file.c_str()); // open the file we were given
	return in; // condition state is good if open succeeded
}

void printRecords(ostream &os, const vector<PersonInfo>& people)
{
	for (const auto &entry : people) {    // for each entry in people
		os << entry.name << " has " << entry.phones.size()
			<< " phones and the numbers are: ";
		for (const auto &nums : entry.phones) {  // for each number
			os << nums << " ";
		}
		os << endl;
	}
}

int main()
{
	ifstream fin;
	string file_name;
	cout << "Enter the file name: ";
	cin >> file_name;
	if (!open_file(fin, file_name)) {
		cerr << "Complain: I cannot find the file" << endl << endl;
		cerr << system("dir") << endl; //only for windows OS
		return -1;
	}

	string line, word;
	vector<PersonInfo> people;

	// read the input a line at a time until end-of-file (or other error)
	while (getline(fin, line)) {
		PersonInfo info;            // object to hold this record's data
		istringstream record(line); // bind record to line we just read
		record >> info.name;        // read the name
		while (record >> word)      // read the phone numbers
			info.phones.push_back(word);  // and store them
		people.push_back(info); // append this record to people
	}

	printRecords(cout, people);
	return 0;
}
