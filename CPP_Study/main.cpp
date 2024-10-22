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

int N;
char c;

int main()
{
	Init;

	cin >> N >> c;

	vector<string> vec;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str.find(toupper(c)) == string::npos && str.find(tolower(c)) == string::npos)
			continue;
		string ans;
		unordered_set<char> us;
		for (char& s : str)
		{
			s = toupper(s);
			if (us.insert(s).second)
				ans += s;
		}
		vec.push_back(ans);
	}

	for (const string& s : vec)
		cout << s << endl;
	
	return 0;
}