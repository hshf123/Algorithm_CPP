#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == tolower(str[i]))
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}

	cout << str;

	return 0;
}
