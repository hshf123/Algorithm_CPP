#include <iostream>
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
#include <cmath>
#include <memory.h>
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

void PostOrder(string& str)
{
	stack<char> s;
	auto it = str.begin();

	while (it != str.end())
	{
		char now = *it;

		if (now == '(')
		{
			s.push(now);
		}
		else if (now == '*' || now == '/')
		{
			while (s.empty() == false && (s.top() == '/' || s.top() == '*'))
			{
				cout << s.top();
				s.pop();
			}
			s.push(now);
		}
		else if (now == '+' || now == '-')
		{
			while (s.empty() == false && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(now);
		}
		else if (now == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			cout << now;
		}

		++it;
	}

	while (s.empty() == false)
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	Init;

	string str = "A+(B*C)-(D/E)";
	//cin >> str;

	PostOrder(str);

	return 0;
}
