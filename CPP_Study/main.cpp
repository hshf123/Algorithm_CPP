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


int main()
{
	Init;

	string A;
	string B;
	cin >> A >> B;
	vector<vector<int>> vec(A.size() + 1, vector<int>(B.size() + 1, 0));

	for (int y = 1; y < A.size() + 1; y++)
	{
		for (int x = 1; x < B.size() + 1; x++)
		{
			if (A[y - 1] == B[x - 1])
				vec[y][x] = vec[y - 1][x - 1] + 1;
			else
				vec[y][x] = max(vec[y - 1][x], vec[y][x - 1]);
		}
	}

	cout << vec[A.size()][B.size()];

	return 0;
}