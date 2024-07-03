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

	string str;
	cin >> str;

	vector<vector<bool>> checkPalindrome(str.size(), vector<bool>(str.size(), false));

	for (int start = 0; start < str.size(); start++)
	{
		for (int end = start; end < str.size(); end++)
		{
			checkPalindrome[start][start] = true;
			if (checkPalindrome[start][end])
				continue;

			if (str[start] == str[end] && checkPalindrome[start + 1][end - 1])
			{
				checkPalindrome[start][end] = true;
				continue;
			}
			
			string checkStr = str.substr(start, end - start + 1);
			string front = checkStr.substr(0, checkStr.size() / 2);
			string behind = checkStr.substr(checkStr.size() % 2 == 0 ? checkStr.size() / 2 : checkStr.size() / 2 + 1, checkStr.size() / 2);
			std::reverse(behind.begin(), behind.end());
			if (front == behind)
				checkPalindrome[start][end] = true;
		}
	}

	vector<int> ans(str.size(), INT32_MAX);
	for (int start = 0; start < str.size(); start++)
	{
		for (int end = start; end < str.size(); end++)
		{
			if (checkPalindrome[start][end])
			{
				if (start == 0)
				{
					ans[end] = 1;
					continue;
				}

				ans[end] = min(ans[end], ans[start - 1] + 1);
			}
		}
	}

	cout << ans[str.size() - 1];
	
	return 0;
}