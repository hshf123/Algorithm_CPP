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
#include <cmath>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int all = 0b1111'1111'1111'1111'1111;
	int now = 0;

	// add remove check toggle all empty
	int M;
	cin >> M;
	string s;
	getline(cin, s);
	for (int i = 0; i < M; i++)
	{
		getline(cin, s);
		int idx = s.find(' ');
		int n;
		if (idx != -1)
			n = stoi(s.substr(idx, s.length()));
		s = s.substr(0, idx);

		if (s == "add")
		{
			n = pow(2, n - 1);
			now |= n;
		}
		else if (s == "remove")
		{
			n = pow(2, n - 1);
			n = ~(all & n);
			now &= n;
		}
		else if (s == "check")
		{
			n = pow(2, n - 1);
			if ((now & n) > 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (s == "toggle")
		{
			n = pow(2, n - 1);
			int toggle = now | n;
			if (toggle == now)
			{
				n = ~(all & n);
				now &= n;
			}
			else
			{
				now |= n;
			}
		}
		else if (s == "all")
		{
			now |= all;
		}
		else if (s == "empty")
		{
			now &= 0;
		}
	}

	return 0;
}

