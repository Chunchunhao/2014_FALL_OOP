#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string string_filter(const string& input_string);

int main()
{
	ifstream inf("Alice_story1.txt");
	
	vector<string> words;
	vector<unsigned> occuring_times;

	string tmp_string;

	while (inf >> tmp_string)
	{
		bool found = false;
		for (decltype(words.size()) index = 0; index != words.size() && found == false; ++index)
		{
			if (words[index] == tmp_string)
			{
				++occuring_times[index];
				found = true;
			}
		}

		if (!found)
		{
			words.push_back(string_filter(tmp_string));
			occuring_times.push_back(1);
		}
	}


	string key_input;

	bool found = false;
	while (key_input != "!")
	{
		cout << "Enter the word to be found in Alice_story1.txt (! to quit): ";
		cin >> key_input;
		for (decltype(words.size()) index = 0; index != words.size(); ++index)
		{
			if (words[index] == string_filter(key_input))
			{
				cout << "The word " << key_input << " has appeared " << occuring_times[index] << " times in Alice_story1.txt" << endl;
			}
		}
	}

	return 0;
}

string string_filter(const string& input_string)
{
	string output = input_string;
	auto iter = output.begin();
	while (iter != output.end())
	{
		if (!isalpha(*iter))
		{
			iter = output.erase(iter);
		}
		else if (isupper(*iter))
		{
			*iter = tolower(*iter);
			++iter;
		}
		else
			++iter;
	}

	return output;
}