#include	 <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;

	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}

	map<char, int> dic;

	for (int i = 0; i < str.length(); i++)
	{
		auto findIt = dic.find(str[i]);
		if (findIt == dic.end())
			dic.insert(make_pair(str[i], 1));
		else
			findIt->second++;
	}
	
	int max = 0;
	for (auto findIt = dic.begin(); findIt != dic.end(); ++findIt)
	{
		if (findIt->second > max)
			max = findIt->second;
	}
	int count = 0;
	char findChar;
	for (auto findIt = dic.begin(); findIt != dic.end(); ++findIt)
	{
		if (findIt->second == max)
		{
			count++;
			findChar = findIt->first;
		}
	}

	if (count > 1)
		cout << "?";
	else
		cout << findChar;
}