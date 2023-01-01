#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;

	getline(cin, str);

	vector<string> answer;
	stringstream ss(str);
	string temp;

	int count = 0;
	while (getline(ss, temp, ' '))
		count++;

	if (str[0] == ' ')
		count--;

	cout << count;
}