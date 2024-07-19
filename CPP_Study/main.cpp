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

int Solution(vector<int>& vec, int s, int e)
{
	// ���� ����
	if (s == e)
		return vec[s];	// ������ġ�� ����

	int ret = 0;
	int mid = (s + e) / 2;
	// 1�� ���ʿ� ���� �ִ�
	ret = max(ret, Solution(vec, s, mid));
	// 2�� �����ʿ� ���� �ִ�
	ret = max(ret, Solution(vec, mid + 1, e));

	// 3�� �����ִ�
	// ������ Ȯ������ ���� Ȯ������ ���Ұ���
	int left = mid - 1;
	int right = mid + 1;
	int area = vec[mid];				// ����
	int height = vec[mid];
	int width = 2;
	// ���۰� �� �� �ȿ��� ��ƾ���
	while (s <= left && right <= e)
	{
		if (vec[left] > vec[right])
		{
			// ���ʰ��� �� ũ��!
			height = min(height, vec[left]);
			area = height * width++;
			left--;
		}
		else
		{
			// �����ʰ��� �� ũ��!
			height = min(height, vec[right]);
			area = height * width++;
			right++;
		}

		ret = max(ret, area);
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
		int N;
		cin >> N;
		vector<int> vec(N);
		for (int i = 0; i < N; i++)
			cin >> vec[i];
		ansList[c] = Solution(vec, 0, N - 1);
	}
	
	for (const int& ans : ansList)
		cout << ans << endl;
	
	return 0;
}