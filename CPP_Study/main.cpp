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

string str;
int N;

int main()
{
	Init;

	cin >> str >> N;

	string pattern = str.substr(0, 3);

	for (int i = 3; i < str.size(); i++)
	{
		int idx = str.find(pattern, i);
		string can = str.substr(0, idx);
		if (can == str.substr(idx, can.size()))
		{
			pattern = can;
			break;
		}
		i = idx;
	}

	int sum = 0;
	for (const char& c : pattern)
		sum += (c - '0');

	sum *= (N / pattern.size());

	for (int i = 0; i < (N % pattern.size()); i++)
		sum += (pattern[i] - '0');

	cout << sum;

	return 0;
}