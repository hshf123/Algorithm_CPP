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

int Solution(const vector<vector<bool>>& friendsList, vector<bool> vec)
{
	int A = -1;	// 앞에서 부터 짝을 못 찾은 학생의 인덱스
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == false)
		{
			A = i;
			break;
		}
	}
	if (A == -1)	// 모든 학생이 짝을 찾음
		return 1;

	int ret = 0;
	for (int B = A + 1; B < vec.size(); B++)
	{
		if (vec[B])						// B는 이미 짝이 있어요
			continue;
		if (friendsList[A][B] == false)	// A와 B는 친구가 아님
			continue;

		// A와 B를 짝으로
		vec[A] = true;
		vec[B] = true;
		ret += Solution(friendsList, vec);
		// 다시 짝 풀어서 다음 경우의 수 탐색 가능하도록
		vec[A] = false;
		vec[B] = false;
	}

	return ret;
}

int main()
{
	Init;

	int C;
	cin >> C;
	vector<int> ansList(C);
	for (int c = 0; c < C; c++)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<bool>> friends(n, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			int A, B;
			cin >> A >> B;
			friends[A][B] = true;	// A와 B는 친구
			friends[B][A] = true;
		}
		vector<bool> vec(n, false);

		ansList[c] = Solution(friends, vec);
	}
	
	for (const int& ans : ansList)
		cout << ans << endl;
	
	return 0;
}