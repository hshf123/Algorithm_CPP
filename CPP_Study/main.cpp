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
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N ,M;
	cin >> N >> M;
	string str;
	cin >> str;
	
	int count = 0;
	int ans = 0;
	for (int i = 1; i < M - 1;)
	{
		if (str[i] == 'O' && str[i + 1] == 'I')
		{
			count++;
			if (count == N)
			{
				if (str[i - (count * 2 - 1)] == 'I')
					ans++;
				count--;
			}
			i += 2;
		}
		else
		{
			count = 0;
			i++;
		}
	}

	cout << ans;

	return 0;
}

