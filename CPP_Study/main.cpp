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
과자를 바구니 단위로 파는 가게가 있습니다. 이 가게는 1번부터 N번까지 차례로 번호가 붙은 바구니 N개가 일렬로 나열해 놨습니다.
철수는 두 아들에게 줄 과자를 사려합니다. 첫째 아들에게는 l번 바구니부터 m번 바구니까지, 둘째 아들에게는 m+1번 바구니부터 r번 바구니
까지를 주려합니다. 단, 두 아들이 받을 과자 수는 같아야 합니다.(1 <= l <= m, m+1 <= r <= N) 즉, A[i]를 i번 바구니에 들어있는 과자 수
라고 했을 때, A[l] + .. + A[m] = A[m+1]+..+A[r] 를 만족해야 합니다.
각 바구니 안에 들은 과자 수가 차례로 들은 배열 cookie가 주어질 때, 조건에 맞게 과자를 살 경우 한 명의 아들에게 줄 수 있는 가장 많은 과
자 수를 return 하는 프로그램을 작성해 주세요 (단, 조건에 맞게 과자를 구매할 수 없다면 0을 return 합니다)

제한 사항
cookie의 길이는 1 이상 2,000 이하 입니다.
cookie의 각각의 원소는 1 이상 500이하인 자연수 입니다.
*/

int Solution(const vector<int>& cookie)
{
	int ans = 0;

	if (cookie.size() == 1)
		return 0;

	for (int m = 0; m < cookie.size() - 1; m++)
	{
		int leftStart = m;
		int leftEnd = m;
		int leftSum = cookie[m];

		int rightStart = m + 1;
		int rightEnd = rightStart;
		int rightSum = cookie[m + 1];

		while (true)
		{
			if (rightEnd >= cookie.size() || leftStart < 0)
				break;

			if (leftSum == rightSum)
			{
				ans = max(ans, leftSum);
				rightEnd += 1;
				leftStart -= 1;
				continue;
			}

			if (leftSum < rightSum)
			{
				--leftStart;
				if (leftStart >= 0)
					leftSum += cookie[leftStart];
			}
			else
			{
				++rightEnd;
				if (rightEnd < cookie.size())
					rightSum += cookie[rightSum];
			}
		}
	}

	return ans;
}

int main()
{
	Init;

	vector<int> cookie1 = { 1,1,2,3 };	// ANS) 3
	vector<int> cookie2 = { 1,2,4,5 };	// ANS) 0

	cout << Solution(cookie1);
	cout << endl;
	cout << Solution(cookie2);

	return 0;
}