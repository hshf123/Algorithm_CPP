#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

	int N;
	cin >> N;

	vector<int> red(N + 1);
	vector<int> green(N + 1);
	vector<int> blue(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		red[i] = min(green[i - 1], blue[i - 1]) + r;
		green[i] = min(red[i - 1], blue[i - 1]) + g;
		blue[i] = min(green[i - 1], red[i - 1]) + b;
	}

	cout << min(red[N], min(green[N], blue[N]));
	
	return 0;
}
