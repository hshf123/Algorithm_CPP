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
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N;
int64 B;

vector<vector<int>> vec;
unordered_map<int64, vector<vector<int>>> cache;

vector<vector<int>> MatrixSquare(const vector<vector<int>>& input)
{
	vector<vector<int>> ret(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int i = 0; i < N; i++)
			{
				ret[y][x] += input[y][i] * input[i][x];
			}
			ret[y][x] %= 1000;
		}
	}

	return ret;
}

vector<vector<int>> MatrixMultiple(const vector<vector<int>>& input, const vector<vector<int>>& input2)
{
	vector<vector<int>> ret(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int i = 0; i < N; i++)
			{
				ret[y][x] += input[y][i] * input2[i][x];
			}
			ret[y][x] %= 1000;
		}
	}

	return ret;
}

vector<vector<int>> Func(int64 n)
{
	if (n == 1)
	{
		return cache[1];
	}

	if (n == 2)
	{
		return cache[2] = MatrixSquare(cache[1]);
	}
	
	if (cache.find(n) != cache.end())
	{
		return cache[n];
	}

	if (n % 2 == 0)
		return cache[n] = MatrixSquare(Func(n / 2));
	else
	{
		cache[n - 1] = Func(n - 1);
		return cache[n] = MatrixMultiple((cache[n - 1]), cache[1]);
	}
}

int main()
{
	Init;

	cin >> N >> B;
	vec = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> vec[y][x];
			vec[y][x] %= 1000;
		}
	}
	cache[1] = vec;
	Func(B);
	for (vector<int> y : cache[B])
	{
		for (int x : y)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
