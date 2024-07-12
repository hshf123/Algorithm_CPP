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

struct Problem
{
	int level = 0;
	unordered_set<int> priorityList;
	unordered_set<int> relationList;
	bool solved = false;

	void Relation(const int& n)
	{
		relationList.insert(n);
	}

	void Insert(const int& n)
	{
		priorityList.insert(n);
	}

	void Erase(const int& n)
	{
		priorityList.erase(n);
	}
};

int main()
{
	Init;

	int N, M;
	cin >> N >> M;
	vector<Problem> problemList(N + 1);
	for (int i = 0; i < N; i++)
		problemList[i + 1].level = i + 1;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		problemList[B].Insert(A);
		problemList[A].Relation(B);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (problemList[i].priorityList.empty())
			pq.push(i);
	}

	int solveCount = 0;
	while (pq.empty() == false)
	{
		int level = pq.top();
		pq.pop();

		if (problemList[level].solved)
			continue;

		cout << level << " ";
		problemList[level].solved = true;
		if (++solveCount == N)
			break;

		// 얘가 풀리면 영향있는 문제들
		for (const int& lv : problemList[level].relationList)
		{
			problemList[lv].Erase(level);
			if (problemList[lv].priorityList.empty())
				pq.push(lv);
		}
	}

	return 0;
}