#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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



int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> siteToPass;

	for (int i = 0; i < N; i++)
	{
		string site;
		string password;
		cin >> site >> password;
		siteToPass.insert({ site, password });
	}

	vector<string> ans(M);
	for (int i = 0; i < M; i++)
	{
		string site;
		cin >> site;

		auto it = siteToPass.find(site);
		ans[i] = it->second;
	}

	for (string& str : ans)
	{
		cout << str << endl;
	}

	return 0;
}
