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

int N;
vector<vector<int>> table;
int cache[3];

int GetMax()
{
	int floor = 0;
	while (floor != N)
	{
		if (floor == 0)
		{
			cache[0] = table[0][floor];
			cache[1] = table[1][floor];
			cache[2] = table[2][floor];
			floor++;
			continue;
		}

		int temp[3];
		::memcpy(temp, cache, sizeof(cache));
		cache[0] = max(temp[0], temp[1]) + table[0][floor];
		cache[1] = max(max(temp[0], temp[1]), temp[2]) + table[1][floor];
		cache[2] = max(temp[1], temp[2]) + table[2][floor];

		floor++;
	}

	return max(max(cache[0], cache[1]), cache[2]);
}

int GetMin()
{
	int floor = 0;
	while (floor != N)
	{
		if (floor == 0)
		{
			cache[0] = table[0][floor];
			cache[1] = table[1][floor];
			cache[2] = table[2][floor];
			floor++;
			continue;
		}

		int temp[3];
		::memcpy(temp, cache, sizeof(cache));
		cache[0] = min(temp[0], temp[1]) + table[0][floor];
		cache[1] = min(min(temp[0], temp[1]), temp[2]) + table[1][floor];
		cache[2] = min(temp[1], temp[2]) + table[2][floor];

		floor++;
	}
	
	return min(min(cache[0], cache[1]), cache[2]);
}



int main()
{
	Init;

	cin >> N;

	table = vector<vector<int>>(3);

	for (int i = 0; i < N; i++)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		table[0].push_back(n1);
		table[1].push_back(n2);
		table[2].push_back(n3);
	}

	cout << GetMax() << " ";

	cout << GetMin();

	return 0;
}