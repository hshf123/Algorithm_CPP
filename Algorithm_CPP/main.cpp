#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	int count = 1;
	int inc = 7;
	while (N > inc)
	{
		count++;
		inc += (6 * count);
	}

	cout << count + 1;

	return 0;
}
