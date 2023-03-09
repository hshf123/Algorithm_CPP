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

int main()
{
	Init;

	int N;
	cin >> N;
	vector<bool> vec(N + 1, false);
	vec[0] = true;
	vec[1] = true;

	for (int i = 2; i <= N; i++)
	{
		if (vec[i] == false)
		{
			for (int j = i + i; j <= N; j += i)
			{
				vec[j] = true;
			}
		}
	}

	if (vec[N] == false)
		cout << "소수";
	else
		cout << "소수 아님";
	
	return 0;
}