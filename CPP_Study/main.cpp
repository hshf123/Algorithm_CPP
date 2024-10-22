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

vector<vector<int>> sdoku(9, vector<int>(9, 0));
vector<pair<int, int>> vec;

unordered_set<int> GetEnableNumberList(const int& y, const int& x)
{
	unordered_set<int> ret = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++)
		ret.erase(sdoku[y][i]);
	for (int i = 0; i < 9; i++)
		ret.erase(sdoku[i][x]);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ret.erase(sdoku[y - (y % 3) + j][x - (x % 3) + i]);
		}
	}

	return ret;
}
bool Check()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (sdoku[y][x] == 0)
				return false;
		}
	}

	return true;
}

bool DFS(const int& idx)
{
	if (idx == vec.size())
		return true;

	unordered_set<int> s = GetEnableNumberList(vec[idx].first, vec[idx].second);
	for (const int& p : s)
	{
		int& n = sdoku[vec[idx].first][vec[idx].second];
		n = p;
		if (DFS(idx + 1))
			return true;
		n = 0;
	}

	return false;
}

int main()
{
	Init;

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cin >> sdoku[y][x];
			if (sdoku[y][x] == 0)
				vec.push_back({ y,x });
		}
	}

	DFS(0);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << sdoku[y][x] << " ";
		}
		cout << endl;
	}
	
	return 0;
}