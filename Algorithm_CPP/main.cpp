#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <stack>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	queue<string> _commands;
	for (int i = 0; i <= N; i++)
	{
		string command;
		getline(cin, command);
		_commands.push(command);
	}

	queue<int> _queue;
	_commands.pop();
	while (_commands.empty() == false)
	{
		string& str = _commands.front();

		if (str == "pop")
		{
			if (_queue.empty())
				cout << "-1" << endl;
			else
			{
				cout << _queue.front() << endl;
				_queue.pop();
			}
		}
		else if (str == "size")
		{
			cout << _queue.size() << endl;
		}
		else if (str == "empty")
		{
			if (_queue.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "front")
		{
			if (_queue.empty())
				cout << "-1" << endl;
			else
				cout << _queue.front() << endl;
		}
		else if (str == "back")
		{
			if (_queue.empty())
				cout << "-1" << endl;
			else
				cout << _queue.back() << endl;
		}
		else
		{
			// push
			int index = str.find(" ");
			string s = str.substr(index, str.size() - 1);
			int n = stoi(s);
			_queue.push(n);
		}

		_commands.pop();
	}
}
