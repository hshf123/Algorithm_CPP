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
	
	queue<string> _queue;
	for (int i = 0; i <= N; i++)
	{
		string command;
		getline(cin, command);
		_queue.push(command);
	}

	stack<int> _stack;
	_queue.pop();
	while (_queue.empty() == false)
	{
		string& str = _queue.front();

		if (str == "pop")
		{
			if (_stack.empty())
				cout << "-1" << endl;
			else
			{
				cout << _stack.top() << endl;
				_stack.pop();
			}
		}
		else if (str == "size")
		{
			cout << _stack.size() << endl;
		}
		else if (str == "empty")
		{
			if (_stack.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "top")
		{
			if (_stack.empty())
				cout << "-1" << endl;
			else
				cout << _stack.top() << endl;
		}
		else
		{
			// push
			int index = str.find(" ");
			string s = str.substr(index, str.size() - 1);
			int n = stoi(s);
			_stack.push(n);
		}

		_queue.pop();
	}
}
