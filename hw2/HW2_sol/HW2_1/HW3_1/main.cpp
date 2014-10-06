#include <iostream>
#include <fstream>

#include <vector>
#include <string>

#include <iterator>

#include <cctype>

#include <algorithm>

using namespace std;

void openFile(ifstream& inf);

void stringToLower(string& inputString);

int main()
{

	/// Input file handle
	ifstream inf;
	openFile(inf);
	/// Input file handle


	vector< string > wordChain;
	vector< unsigned > wordIndecies;

	string currentWord;

	inf >> currentWord;

	stringToLower(currentWord);
	wordChain.push_back(currentWord);
	wordIndecies.push_back(1);

	while (inf >> currentWord)
	{
		stringToLower(currentWord);

		if (!currentWord.empty())
		{

			bool duplicated = false;
			for (unsigned index = 0; index != wordChain.size() && duplicated == false; ++index)
			{
				if (currentWord == wordChain[index])
				{
					++wordIndecies[index];
					duplicated = true;
				}
			}

			if (duplicated == false)
			{
				wordChain.push_back(currentWord);
				wordIndecies.push_back(1);
			}

		}

	}

	unsigned maxIndex = 0;
	unsigned maxElement = 0;

	unsigned cnt = 0;

	auto iter = wordIndecies.begin();
	auto most_repeated_time = iter;
	*most_repeated_time = 0;

	auto sIter = wordChain.begin();
	auto most_repeated = sIter;

	for (iter = iter; iter != wordIndecies.end(); ++iter)
	{
		if (*iter > *most_repeated_time)
		{
			most_repeated = sIter;
			most_repeated_time = iter;
		}
		++sIter;
	}
	cout << "The most repeated word is \"" << *most_repeated << "\"." << endl;
	cout << "It has been repeated for " << *most_repeated_time << " times." << endl << endl;



	return 0;
}

void openFile(ifstream& inf)
{
	string filename;

	cout << "Please input the file name." << endl;

	cout << "input here: ";

	cin >> filename;

	inf.open(filename.c_str());

	while (!inf.is_open())
	{
		inf.clear();
		cout << endl;
		cout << "The file does not exist!" << endl;
		cout << "Please input the file name again." << endl;
		cout << "input here: ";
		cin >> filename;

		inf.open(filename.c_str());
	}

	if (inf.good())
	{
		cout << endl << "File was opened correctly." << endl << endl;
	}
}

void stringToLower(string& inputString)
{
	auto sIter = inputString.begin();

	while(sIter != inputString.end())
	{
		if (isalpha(*sIter))
		{
			if (isupper(*sIter))
			{
				*sIter = tolower(*sIter);
			}
			++sIter;
		}
		else
		{
			sIter = inputString.erase(sIter);
		}
	}



}
