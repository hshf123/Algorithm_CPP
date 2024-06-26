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

struct Jewel
{
	int kg = 0;
	int cost = 0;
};

int main()
{
	Init;

	map<int, priority_queue<int>> jewelMap;

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewelMap[M].push(V);
	}

	queue<Jewel> jewelVec;
	for (auto p : jewelMap)
	{
		while (p.second.empty() == false)
		{
			jewelVec.push({ p.first, p.second.top() });
			p.second.pop();
		}
	}
	jewelMap.clear();

	vector<int> pqBag;
	for (int i = 0; i < K; i++)
	{
		int C;
		cin >> C;
		pqBag.push_back(C);
	}
	::sort(pqBag.begin(), pqBag.end());

	int64 ans = 0;
	priority_queue<int> jewCosts;
	for (const int& bag : pqBag)
	{
		int bestCost = 0;
		while (jewelVec.empty() == false)
		{
			Jewel jew = jewelVec.front();
			// 담을게 없음
			if (jew.kg > bag)
				break;

			// 가방에 담을 수 있는거면 일단 다 때려 늫
			if (jew.kg <= bag)
				jewCosts.push(jew.cost);
			jewelVec.pop();
		}

		if (jewCosts.empty() == false)
		{
			ans += jewCosts.top();
			jewCosts.pop();
		}
	}
	
	cout << ans;
	return 0;
}