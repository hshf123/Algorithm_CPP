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
	
	int N;
	cin >> N;


	stack<int> s;

	vector<int> ret(N);
	vector<int> res(N, 0);
	int resIdx = N - 1;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		ret[i] = n;
	}

	s.push(N - 1);

	for(int i = ret.size() - 2; i >= 0; i--)
	{
		while (s.empty() == false && ret[s.top()] < ret[i])
		{
			res[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}

	for (int& n : res)
		cout << n << " ";

	return 0;
}