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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int LCS(string& str1, string& str2)
{
	int str1Len = str1.length();
	int str2Len = str2.length();
	vector<vector<int>> lcs(str1Len + 1, vector<int>(str2Len + 1, 0));

	for (int i = 1; i < str1Len + 1; i++)
	{
		for (int j = 1; j < str2Len + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}

	return lcs[str1Len][str2Len];
}

int main()
{
	Init;

	string str1, str2;
	cin >> str1 >> str2;
	cout << LCS(str1, str2);
	return 0;
}
