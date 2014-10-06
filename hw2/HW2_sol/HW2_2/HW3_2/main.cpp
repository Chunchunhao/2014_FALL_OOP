#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string caesar_cipher(const string& input, const int shift);

char shit_ascii(const char input, const int shift);

int main()
{
	cout << "Please input a message:" << endl;
	string message;
	getline(cin, message);

	cout << "The 'n' position further along the alphabet: " << endl;
	int shift;
	cin >> shift;

	cout << "The encoded message:" << endl;

	cout << caesar_cipher(message, shift) << endl;

	return 0;

}

string caesar_cipher(const string& input, const int shift)
{
	string ret;
	for (const auto& c : input)
	{
		if (isalpha(c))
			ret += shit_ascii(c, shift);
		else
			ret += c;
	}

	return ret;
}

char shit_ascii(const char c, const int shift)
{
	int char_int = (int) c;
	if (isupper(char_int))
	{
		if ((char_int + shift) > (int)'Z')
		{
			return (char) ('A' + shift - 1 - ('Z' - char_int));
		}
		else if ((char_int + shift) < (int)'A')
		{
			return (char) ('Z' + shift + 1 + (char_int - 'A'));
		}
		else
		{
			return (char) (char_int + shift);
		}
	}
	else
	{
		if ((char_int + shift) > (int)'z')
		{
			return (char) ('a' + shift - 1 - ('z' - char_int));
		}
		else if ((char_int + shift) < 'a')
		{
			return (char) ('z' + shift + 1 + (char_int - 'a'));
		}
		else
		{
			return (char) (char_int + shift);
		}
	}
}