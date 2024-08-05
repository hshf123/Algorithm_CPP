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

vector<vector<int>> cache;

int Solve(const string& W, const string& S, int wPos, int sPos)
{
	int& ret = cache[wPos][sPos];
	if (ret != -1)
		return ret;

	while (sPos < S.size() && wPos < W.size() && (W[wPos] == '?' || W[wPos] == S[sPos]))
	{
		++wPos;
		++sPos;
	}

	if (wPos == W.size())
		return ret = sPos == S.size() ? 1 : 0;
	if (W[wPos] == '*')
	{
		for (int skip = 0; sPos + skip <= S.size(); ++skip)
		{
			if (Solve(W, S, wPos + 1, sPos + skip) > 0)
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	Init;
	
	int C;
	cin >> C;

	vector<string> ans;
	for (int c = 0; c < C; c++)
	{
		string W;
		cin >> W;

		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string fileName;
			cin >> fileName;

			cache = vector<vector<int>>(W.size() + 1, vector<int>(fileName.size() + 1, -1));

			if (Solve(W, fileName, 0, 0) > 0)
				ans.push_back(fileName);
		}
	}

	sort(ans.begin(), ans.end());
	cout << endl;
	for (const string& str : ans)
		cout << str << endl;
	
	return 0;
}