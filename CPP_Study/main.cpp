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
#include <cstring>

#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int main()
{
	Init;

	string str, boom;
	cin >> str >> boom;

	deque<char> s;
	const char* p = str.c_str();
	char lastWord = boom[boom.length() - 1];
	int boom_len = boom.length();
	int idx = 0;
	while (idx != str.length())
	{
		s.push_back(*p++);
		
		if (s.back() == lastWord && s.size() >= boom_len)
		{
			string temp;
			for (int i = boom_len - 1; i >= 0; i--)
			{
				char c = s.back();
				if (c == boom[i])
				{
					temp += c;
					s.pop_back();
				}
				else
				{
					for (int tempIdx = temp.length() - 1; tempIdx >= 0; tempIdx--)
					{
						s.push_back(temp[tempIdx]);
					}
					temp = "";
					break;
				}
			}
		}
		idx++;
	}

	if (s.empty())
		cout << "FRULA";
	else
	{
		while (s.empty() == false)
		{
			cout << s.front();
			s.pop_front();
		}
	}

	return 0;
}
