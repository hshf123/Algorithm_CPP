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

int main()
{
	Init;

	cin >> str;

	int cnt = 1;
	while (str.empty() == false)
	{
		int startIdx = str.find('(');
		int endIdx = str.find(')');

		if (startIdx == 0)
			cnt = 1;
		else
			cnt = stoi(str.substr(0, startIdx));

		string pattern = str.substr(startIdx + 1, endIdx - startIdx - 1);

		for (int i = 0; i < cnt; i++)
			cout << pattern;

		str = str.substr(endIdx + 1, str.size() - endIdx);
	}

	return 0;
}