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

	deque<int> _deque;
	_commands.pop();
	while (_commands.empty() == false)
	{
		string& str = _commands.front();

		if (str == "pop_front")
		{
			if (_deque.empty())
				cout << "-1" << endl;
			else
			{
				cout << _deque.front() << endl;
				_deque.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (_deque.empty())
				cout << "-1" << endl;
			else
			{
				cout << _deque.back() << endl;
				_deque.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << _deque.size() << endl;
		}
		else if (str == "empty")
		{
			if (_deque.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "front")
		{
			if (_deque.empty())
				cout << "-1" << endl;
			else
				cout << _deque.front() << endl;
		}
		else if (str == "back")
		{
			if (_deque.empty())
				cout << "-1" << endl;
			else
				cout << _deque.back() << endl;
		}
		else
		{
			// push
			int index = str.find(" ");
			string forb = str.substr(0, index);
			string strNum = str.substr(index, str.size() - 1);
			int n = stoi(strNum);

			if (forb == "push_back")
				_deque.push_back(n);
			else
				_deque.push_front(n);
		}

		_commands.pop();
	}
}
