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
문제

어떤 수열에서 0개 이상의 숫자를 지운 결과를 원 수열의 부분 수열이라고 부릅니다. 예를 들어 '4 7 6'은 '4 3 7 6 9'의 부분 수열입니다.
중복된 숫자가 없고 오름 차순으로 정렬되어 있는 부분 수열들을 가리켜 증가 부분 수열이라고 부르지요. 예를 들어 '3 6 9'는 앞의 수열의 증가 부분 수열입니다.
두 개의 정수 수열 A 와 B 에서 각각 증가 부분 수열을 얻은 뒤 이들을 크기 순서대로 합친 것을 합친 증가 부분 수열이라고 부르기로 합시다.
이 중 가장 긴 수열을 합친 LIS(JLIS, Joined Longest Increasing Subsequence)이라고 부릅시다. 예를 들어 '1 3 4 7 9' 은 '1 9 4' 와 '3 4 7' 의 JLIS입니다.
'1 9' 와 '3 4 7' 을 합쳐 '1 3 4 7 9'를 얻을 수 있기 때문이지요.
A 와 B 가 주어질 때, JLIS의 길이를 계산하는 프로그램을 작성하세요.

입력

입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100).
다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다. 모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.

예제 입력
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

예제 출력
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