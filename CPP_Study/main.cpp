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
	int A = -1;	// �տ��� ���� ¦�� �� ã�� �л��� �ε���
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == false)
		{
			A = i;
			break;
		}
	}
	if (A == -1)	// ��� �л��� ¦�� ã��
		return 1;

	int ret = 0;
	for (int B = A + 1; B < vec.size(); B++)
	{
		if (vec[B])						// B�� �̹� ¦�� �־��
			continue;
		if (friendsList[A][B] == false)	// A�� B�� ģ���� �ƴ�
			continue;

		// A�� B�� ¦����
		vec[A] = true;
		vec[B] = true;
		ret += Solution(friendsList, vec);
		// �ٽ� ¦ Ǯ� ���� ����� �� Ž�� �����ϵ���
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
			friends[A][B] = true;	// A�� B�� ģ��
			friends[B][A] = true;
		}
		vector<bool> vec(n, false);

		ansList[c] = Solution(friends, vec);
	}
	
	for (const int& ans : ansList)
		cout << ans << endl;
	
	return 0;
}