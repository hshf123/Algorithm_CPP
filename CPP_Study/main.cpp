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

	int N, M;
	cin >> N >> M;

	unordered_map<int, string> idxToName;
	unordered_map<string, int> nameToIdx;
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		idxToName.insert(make_pair(i, name));
		nameToIdx.insert(make_pair(name, i));
	}

	vector<string> ans(M);
	for (int i = 0; i < M; i++)
	{
		string nameOrNumber;
		cin >> nameOrNumber;

		if (nameOrNumber[0] > '0' && nameOrNumber[0] <= '9')
		{
			int idx = stoi(nameOrNumber) - 1;
			auto findIt = idxToName.find(idx);
			ans[i] = findIt->second;
		}
		else
		{
			auto findIt = nameToIdx.find(nameOrNumber);
			ans[i] = to_string(findIt->second + 1);
		}
	}

	for (string& str : ans)
	{
		cout << str << endl;
	}

	return 0;
}

