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

bool RightCheck(const unordered_map<char, int>& um)
{
	for (auto& p : um)
	{
		if (p.second > 0)
			return false;
	}

	return true;
}

int main()
{
	Init;
	
	string str;
	cin >> str;

	string ans;
	cin >> ans;

	unordered_map<char, int> rightCheck;
	for (int i = 0; i < ans.size(); i++)
		rightCheck[ans[i]] += 1;

	int res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (i < ans.size())
		{
			if (rightCheck.find(str[i]) != rightCheck.end())
				rightCheck[str[i]]--;

			continue;
		}

		if (RightCheck(rightCheck))
			res++;

		int popIdx = i - ans.size();
		if (rightCheck.find(str[popIdx]) != rightCheck.end())
			rightCheck[str[popIdx]]++;
		if (rightCheck.find(str[i]) != rightCheck.end())
			rightCheck[str[i]]--;
	}
	
	if (RightCheck(rightCheck))
		res++;

	cout << res;

	return 0;
}