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
�Ʊ� ���� �������� 1���� n���� ��ȣ�� �پ��ִ� ������ �������� �մϴ�. �� ���� ��� ��Ž�� ���߱� ������ ���� ��Ģ�� ���� ������ ��
��� �����߽��ϴ�.

1.	ù° �������Դ� 1�� ���ĺ��� x�� ���ı���, ��° �������Դ� x+1�� ���ĺ��� y�� ���ı���, ��° �������Դ� y+1�� ���ĺ��� n��
	���ı��� �й�˴ϴ�. (1 <= x < y < n).
2.	��� ������ ���������� ������ ��ġ�� ������ �ֽ��ϴ�.
3.	�� ������ �������� ���ڰ� ���� ������ ������ ���� ������ ��Ÿ�� �� ������, ������ ��� ���� �� �� ������ �������� ��� ���ƾ�
	�մϴ�.
4.	��� ������ �ڽ��� ������ ������ �ʰ� �� �Խ��ϴ�.
5.	���� �߿��� �������� ������ ������ ������ �� ������, �������� ������ ���ĵ� ������ �ʰ� ��� �Խ��ϴ�.

������ �������� ����� �迭 foods�� �Ű������� �־��� ��, �Ʊ� ���� �� ������ �������� �������� ������ ������ �ִ� ����� ��������
return �ϴ� ���α׷��� �ۼ��ϼ���.

���ѻ���.
foods�� ������ �������� 1�� ���ĺ��� n�� ���ı��� ������� ����ִ� �迭�Դϴ�.
foods�� ����ִ� �������� -100,000�̻� 100,000 ������ �����Դϴ�.
foods�� ����ִ� ������ ������ 500,000�� �����Դϴ�.
������ 2^31 - 1���� �۰ų� ���� ��츸 �Է����� �־����ϴ�.
*/

int Solution(const vector<int> foods)
{
	if (foods.size() < 3)
		return 0;

	int ans = 0;

	int firstPigSum = 0;
	for (int x = 0; x < foods.size() - 2; x++)
	{
		firstPigSum += foods[x];
		int secondPigSum = 0;
		for (int secondPigStart = x + 1; secondPigStart < foods.size() - 1; secondPigStart++)
		{
			secondPigSum += foods[secondPigStart];
			if (firstPigSum == secondPigSum)
			{
				int thirdPigSum = 0;
				for (int thirdPigStart = secondPigStart + 1; thirdPigStart < foods.size(); thirdPigStart++)
				{
					thirdPigSum += foods[thirdPigStart];
				}
				if (firstPigSum == thirdPigSum)
				{
					ans++;
				}
			}
			if (firstPigSum < secondPigSum)
				break;
		}
	}

	return ans;
}

int main()
{
	Init;

	vector<int> foods1 = { 1,2,3,0,3 }; // ans)2
	vector<int> foods2 = { 4,1 };		// ans)0

	cout << Solution(foods1);
	cout << endl;
	cout << Solution(foods2);

	return 0;
}