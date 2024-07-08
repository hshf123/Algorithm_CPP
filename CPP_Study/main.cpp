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
아기 돼지 삼형제가 1부터 n까지 번호가 붙어있는 음식을 먹으려고 합니다. 세 돼지 모두 식탐이 강했기 때문에 다음 규칙에 따라 음식을 먹
기로 결정했습니다.

1.	첫째 돼지에게는 1번 음식부터 x번 음식까지, 둘째 돼지에게는 x+1번 음식부터 y번 음식까지, 셋째 돼지에게는 y+1번 음식부터 n번
	음식까지 분배됩니다. (1 <= x < y < n).
2.	모든 음식은 정수형태의 만족도 수치를 가지고 있습니다.
3.	각 돼지의 포만도는 각자가 먹은 음식의 만족도 값의 합으로 나타낼 수 있으며, 음식을 모두 먹은 후 세 돼지의 포만도가 모두 같아야
	합니다.
4.	모든 돼지는 자신의 음식을 남기지 않고 다 먹습니다.
5.	음식 중에는 만족도가 음수인 음식이 존재할 수 있으며, 만족도가 음수인 음식도 남기지 않고 모두 먹습니다.

음식의 만족도가 저장된 배열 foods가 매개변수로 주어질 때, 아기 돼지 삼 형제의 포만도가 같아지게 음식을 나누어 주는 방법의 가짓수를
return 하는 프로그램을 작성하세요.

제한사항.
foods는 음식의 만족도가 1번 음식부터 n번 음식까지 순서대로 들어있는 배열입니다.
foods에 들어있는 만족도는 -100,000이상 100,000 이하의 정수입니다.
foods에 들어있는 음식의 개수는 500,000개 이하입니다.
정답이 2^31 - 1보다 작거나 같은 경우만 입력으로 주어집니다.
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