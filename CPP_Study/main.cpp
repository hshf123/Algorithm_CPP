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


	unordered_map<char, int> m;

	for (int i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
		m[str[i]]++;
	}
	
	unordered_set<char> s;
	string ans;
	for (int i = 0; i < str.size(); i++)
	{
		char& c = str[i];
		m[c]--;
		if (s.find(c) != s.end())
			continue;
		while (ans.empty() == false && ans.back() > c && m[ans.back()] > 0)
		{
			s.erase(ans.back());
			ans.pop_back();
		}
		if (s.insert(c).second)
			ans += c;
	}

	cout << ans;

	return 0;
}