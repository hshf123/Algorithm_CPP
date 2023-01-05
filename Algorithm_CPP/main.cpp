#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	map<int, int> _map;

	for (int i = 0; i < N; i++)
	{
		int card;
		cin >> card;

		auto findIt = _map.find(card);
		if (findIt == _map.end())
			_map.insert(make_pair(card, 1));
		else
			findIt->second++;
	}

	int M;
	cin >> M;

	vector<int> vec(M);
	for (int i = 0; i < M; i++)
	{
		int have;
		cin >> have;
		vec[i] = have;
	}

	for (int& n : vec)
	{
		auto findIt = _map.find(n);
		if (findIt == _map.end())
			cout << "0 ";
		else
			cout << findIt->second << " ";
	}
}
