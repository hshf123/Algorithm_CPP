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
	
	int64 N;
	cin >> N;
	vector<int64> T(N + 1, 0);
	vector<int64> ST(N + 1, 0);
	for (int64 i = 1; i < N + 1; i++)
	{
		cin >> ST[i];
		T[i] = ST[i];
	}
	sort(ST.begin(), ST.end());
	int64 K;
	cin >> K;

	int rest = N;
	for (int i = 1; i < N + 1; i++)
	{
		int loop = (ST[i] - ST[i - 1]) * rest;
		if (K < loop)
		{
			int idx = K % rest;
			int cnt = 0;
			for (int j = 1; j < N + 1; j++)
			{
				if (T[j] >= ST[i])
				{
					if(cnt == idx)
					{
						cout << j;
						return 0;
					}
					cnt++;
				}
			}
		}
		else
		{

			K -= loop;
			--rest;
		}
	}
	
	cout << -1;
	return 0;
}