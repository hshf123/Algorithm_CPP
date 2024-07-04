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
금 한 돈의 값은 매일 변합니다. 금값이 낮을 때 금을 사고, 높을 때 팔면 이익을 낼 수 있습니다. 다음 규칙에 맞게 금을 사고 팔아 이익을 남기려고 합니다.
1. 금은 여러 번 사고 팔 수 있습니다.
2. 금을 살 때는 한 돈만 살 수 있으며 팔 때도 한 돈만 팔 수 있습니다.
3. 금은 최대 한돈 까지만 가지고 있을 수 있습니다. (즉, 현재 가지고 있는 금을 팔기 전까지는 금을 살 수 없습니다.)
4. 금을 판 날과 다음날에는 금을 사지 않습니다.
5. 이익이 발생하지 않는다면 금을 사고팔지 않아도 됩니다.
i번째 요소가 i번째 일의 금 한 돈의 값인 배열 gold_prices가 매개변수로 주어질 때, 금을 사고팔아 얻을 수 있는 최대 이윤을 출력하는 프로그램을 작성해주세요.
제한사항
1. 배열 gold_prices의 크기 : 100,000 이하의 자연수
2. 금값 (배열의 원소) : 10,000 이하의 자연수
*/

int GoldPrice(const vector<int>& gold_prices)
{
	vector<int> buy(gold_prices.size(), 0);		// n번째 날 살 때 이윤
	vector<int> sell(gold_prices.size(), 0);	// n번째 날 팔 때 이윤

	// 첫날 살 때와 팔 때의 이윤
	buy[0] = -gold_prices[0];
	sell[0] = 0;
	// 둘째 날 
	buy[1] = max(buy[0], -gold_prices[1]);				// 어제 산게 더 나은건지 오늘산게 더 나은건지
	sell[1] = max(sell[0], buy[0] + gold_prices[1]);	// 어제 사서 오늘 파는게 이득임?
	for (int i = 2; i < gold_prices.size(); i++)
	{
		buy[i] = max(buy[i - 1], sell[i - 2] - gold_prices[i]);
		sell[i] = max(sell[i - 1], buy[i - 1] + gold_prices[i]);
	}

	return sell[gold_prices.size() - 1];
}

int main()
{
	Init;

	// 입력 예제1 Ans)4
	vector<int> gold_prices1 = { 2,5,1,3,4 };
	vector<int> gold_prices2 = { 7,2,5,6,1,4,2,8 };

	cout << GoldPrice(gold_prices1) << endl;
	cout << GoldPrice(gold_prices2) << endl;

	return 0;
}