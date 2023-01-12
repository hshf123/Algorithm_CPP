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

	int N;
	cin >> N;

	vector<int> vec;
	vector<int> vec2(N);
	set<int> _set;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		vec2[i] = x;
		vec.push_back(vec2[i]);
		_set.insert(x);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < N; i++) 
	{
		int idx = lower_bound(vec.begin(), vec.end(), vec2[i]) - vec.begin();
		cout << idx << " ";
	}

	return 0;
}

