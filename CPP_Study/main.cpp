#pragma region Headers
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
#include <numeric>
#include <sstream>
#include <array>

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
#pragma endregion

vector<int> vec(9, 0);
unordered_map<int, unordered_set<int>> team;

int DFS(int idx)
{
	if (idx == 9)
	{
		vector<int> sum(3, 0);
		for (auto& p : team)
		{
			for (const int& p2 : p.second)
			{
				sum[p.first] += vec[p2];
			}
		}

		sort(sum.begin(), sum.end());
		return sum.back() - sum.front();
	}

	int ret = INT32_MAX;
	for (int i = 0; i < 3; i++)
	{
		if(team[i].size() < 3)
		{
			team[i].insert(idx);
			ret = min(ret, DFS(idx + 1));
			team[i].erase(idx);
		}
	}
	return ret;
}

int main()
{
	Init;
	
	for (int i = 0; i < 9; i++)
		cin >> vec[i];

	cout << DFS(0);

	return 0;
}