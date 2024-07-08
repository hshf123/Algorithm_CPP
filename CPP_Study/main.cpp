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
���ڸ� �ٱ��� ������ �Ĵ� ���԰� �ֽ��ϴ�. �� ���Դ� 1������ N������ ���ʷ� ��ȣ�� ���� �ٱ��� N���� �Ϸķ� ������ �����ϴ�.
ö���� �� �Ƶ鿡�� �� ���ڸ� ����մϴ�. ù° �Ƶ鿡�Դ� l�� �ٱ��Ϻ��� m�� �ٱ��ϱ���, ��° �Ƶ鿡�Դ� m+1�� �ٱ��Ϻ��� r�� �ٱ���
������ �ַ��մϴ�. ��, �� �Ƶ��� ���� ���� ���� ���ƾ� �մϴ�.(1 <= l <= m, m+1 <= r <= N) ��, A[i]�� i�� �ٱ��Ͽ� ����ִ� ���� ��
��� ���� ��, A[l] + .. + A[m] = A[m+1]+..+A[r] �� �����ؾ� �մϴ�.
�� �ٱ��� �ȿ� ���� ���� ���� ���ʷ� ���� �迭 cookie�� �־��� ��, ���ǿ� �°� ���ڸ� �� ��� �� ���� �Ƶ鿡�� �� �� �ִ� ���� ���� ��
�� ���� return �ϴ� ���α׷��� �ۼ��� �ּ��� (��, ���ǿ� �°� ���ڸ� ������ �� ���ٸ� 0�� return �մϴ�)

���� ����
cookie�� ���̴� 1 �̻� 2,000 ���� �Դϴ�.
cookie�� ������ ���Ҵ� 1 �̻� 500������ �ڿ��� �Դϴ�.
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