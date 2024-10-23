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

int n1, n2, n3;

int main()
{
	Init;
	cin >> n1 >> n2 >> n3;
	string A;
	string B;
	cin >> A >> B;
	vector<vector<int>> vec(A.size() + 1, vector<int>(B.size() + 1, 0));

	for (int i = 1; i < A.size() + 1; i++)
		vec[i][0] = i * n2;
	for (int i = 1; i < B.size() + 1; i++)
		vec[0][i] = i * n2;

	for (int y = 1; y < A.size() + 1; y++)
	{
		for (int x = 1; x < B.size() + 1; x++)
		{
			int& val = vec[y][x];
			if (A[y - 1] == B[x - 1])
				val = vec[y - 1][x - 1] + n1;
			else
			{
				val = vec[y - 1][x] + n2;
				val = max(val, vec[y][x - 1] + n2);
				val = max(val, vec[y - 1][x - 1] + (n2 * 2));
				val = max(val, vec[y - 1][x - 1] + n3);
			}
		}
	}

	cout << vec[A.size()][B.size()];

	return 0;
}