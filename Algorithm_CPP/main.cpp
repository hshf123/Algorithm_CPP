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

	int now = 100;

	string channel;
	cin >> channel;
	int len = channel.length();
	int N = stoi(channel);

	int M;
	cin >> M;
	vector<bool> bd(10, false);
	for (int i = 0; i < M; i++)
	{
		int m;
		cin >> m;

		bd[m] = true;
	}

	int onlyButton = abs(100 - N);

	// 1) 근사치를 찾는다.
	int count = INT32_MAX;
	for (int i = 0; i < 99'9999; i++)
	{
		bool available = true;
		string str = to_string(i);
		for (int j = 0; j < str.length(); j++)
		{
			int n = (int)(str[j] - '0');
			if (bd[n] == true)
			{
				available = false;
				break;
			}
		}

		if (available == true)
		{
			int c = 0;
			c += abs(N - i);
			c += str.length();
			if (count > c)
				count = c;
		}
	}
	if (onlyButton < count)
		cout << onlyButton;
	else
		cout << count;

	return 0;
}
