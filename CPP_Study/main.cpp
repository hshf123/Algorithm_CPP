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

int A, B;

int main()
{
	Init;

	vector<vector<pair<int, int>>> vec(101, vector<pair<int, int>>(101, make_pair(101, 101)));
	vector<int> seq;
	map<int, int> idxCheck;

	cin >> A;
	for (int i = 0; i < A; i++)
	{
		int n;
		cin >> n;
		vec[n][i + 1].first = i + 1;
	}
	cin >> B;
	for (int i = 0; i < B; i++)
	{
		int n;
		cin >> n;
		vec[n][i + 1].second = i + 1;
	}

	int aMinIdx = 0;
	int bMinIdx = 0;
	vector<int> v;
	for (int num = 100; num >= 1; num--)
	{
		vector<int> AIdxList;
		vector<int> BIdxList;
		for (int idx = 1; idx < 101; idx++)
		{
			if (vec[num][idx].first != 101)
			{
				AIdxList.push_back(vec[num][idx].first);
				vec[num][idx].first = 101;
			}
			if (vec[num][idx].second != 101)
			{
				BIdxList.push_back(vec[num][idx].second);
				vec[num][idx].second = 101;
			}
		}

		if (AIdxList.empty() == false && BIdxList.empty() == false)
		{
			for (int a = 0; a < AIdxList.size(); a++)
			{
				int ANum = AIdxList[a];
				for (int b = 0; b < BIdxList.size(); b++)
				{
					int BNum = BIdxList[b];
					if (ANum > aMinIdx && BNum > bMinIdx)
					{
						aMinIdx = ANum;
						bMinIdx = BNum;
						v.push_back(num);
					}
				}
			}
		}
	}

	cout << v.size() << endl;
	for (const int& n : v)
		cout << n << " ";
	
	return 0;
}