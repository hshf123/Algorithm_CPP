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

/*
����

� �������� 0�� �̻��� ���ڸ� ���� ����� �� ������ �κ� �����̶�� �θ��ϴ�. ���� ��� '4 7 6'�� '4 3 7 6 9'�� �κ� �����Դϴ�.
�ߺ��� ���ڰ� ���� ���� �������� ���ĵǾ� �ִ� �κ� �������� ������ ���� �κ� �����̶�� �θ�����. ���� ��� '3 6 9'�� ���� ������ ���� �κ� �����Դϴ�.
�� ���� ���� ���� A �� B ���� ���� ���� �κ� ������ ���� �� �̵��� ũ�� ������� ��ģ ���� ��ģ ���� �κ� �����̶�� �θ���� �սô�.
�� �� ���� �� ������ ��ģ LIS(JLIS, Joined Longest Increasing Subsequence)�̶�� �θ��ô�. ���� ��� '1 3 4 7 9' �� '1 9 4' �� '3 4 7' �� JLIS�Դϴ�.
'1 9' �� '3 4 7' �� ���� '1 3 4 7 9'�� ���� �� �ֱ� ����������.
A �� B �� �־��� ��, JLIS�� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է�

�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� c ( 1 <= c <= 50 ) �� �־����ϴ�. �� �׽�Ʈ ���̽��� ù �ٿ��� A �� B �� ���� n �� m �� �־����ϴ� (1 <= n,m <= 100).
���� �ٿ��� n ���� ������ A �� ���ҵ���, �� ���� �ٿ��� m ���� ������ B �� ���ҵ��� �־����ϴ�. ��� ���ҵ��� 32��Ʈ ��ȣ �ִ� ������ ������ �� �ֽ��ϴ�.

���� �Է�
3
3 3
1 2 4
3 4 7
3 3
1 2 3
4 5 6
5 3
10 20 30 1 2
10 20 30

���� ���
5
6
5
*/

int n, m, A[100], B[100];
int cache[101][101];

int JLIS(int AIdx, int BIdx)
{
	int& ret = cache[AIdx + 1][BIdx + 1];
	if (ret != -1) return ret;

	ret = 0;
	int64 a = AIdx == -1 ? INT64_MIN : A[AIdx];
	int64 b = BIdx == -1 ? INT64_MIN : B[BIdx];
	int64 maxElem = max(a, b);

	for (int nextA = AIdx + 1; nextA < n; ++nextA)
	{
		if (maxElem < A[nextA])
			ret = max(ret, JLIS(nextA, BIdx) + 1);
	}
	for (int nextB = BIdx + 1; nextB < m; ++nextB)
	{
		if (maxElem < B[nextB])
			ret = max(ret, JLIS(AIdx, nextB) + 1);
	}

	return ret;
}

int main()
{
	Init;
	
	int C;
	cin >> C;

	vector<int> ans;
	for (int c = 0; c < C; c++)
	{
		memset(A, INT64_MIN, 100);
		memset(B, INT64_MIN, 100);
		for (int i = 0; i < 101; i++)
			memset(cache[i], -1, 101);

		cin >> n >> m;

		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		ans.push_back(JLIS(-1, -1));
	}

	for (int i = 0; i < C; i++)
		cout << ans[i] << endl;
	return 0;
}