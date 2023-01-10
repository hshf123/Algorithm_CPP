#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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
	ios::sync_with_stdio(false);

	int neverHear, neverSeen;
	cin >> neverHear >> neverSeen;

	unordered_set<string> hashSet;
	for (int i = 0; i < neverHear; i++)
	{
		string name;
		cin >> name;
		hashSet.insert(name);
	}

	set<string> _set;
	for (int i = 0; i < neverSeen; i++)
	{
		string name;
		cin >> name;
		auto findIt = hashSet.find(name);
		if (findIt != hashSet.end())
			_set.insert(name);
	}

	cout << _set.size() << endl;
	for (const string& str : _set)
		cout << str << endl;

	return 0;
}

