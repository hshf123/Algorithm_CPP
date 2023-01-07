#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string line;
	while (true)
	{
		getline(cin, line);
		if (line == ".")
			break;
		string answer = "yes";
		stack<char> _lefts;
		const char* p = line.c_str();
		for (int i = 0; i < line.length(); i++)
		{
			char c = *(p + i);
			if (c == '(' || c == '[')
				_lefts.push(c);
			else if (c == ']')
			{
				if (_lefts.empty() == false && _lefts.top() == '[')
					_lefts.pop();
				else
				{
					answer = "no";
					break;
				}
			}
			else if (c == ')')
			{
				if (_lefts.empty() == false && _lefts.top() == '(')
					_lefts.pop();
				else
				{
					answer = "no";
					break;
				}
			}
		}

		if (_lefts.empty() == false)
			answer = "no";

		cout << answer << endl;
	}
}
