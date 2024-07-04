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
�� �� ���� ���� ���� ���մϴ�. �ݰ��� ���� �� ���� ���, ���� �� �ȸ� ������ �� �� �ֽ��ϴ�. ���� ��Ģ�� �°� ���� ��� �Ⱦ� ������ ������� �մϴ�.
1. ���� ���� �� ��� �� �� �ֽ��ϴ�.
2. ���� �� ���� �� ���� �� �� ������ �� ���� �� ���� �� �� �ֽ��ϴ�.
3. ���� �ִ� �ѵ� ������ ������ ���� �� �ֽ��ϴ�. (��, ���� ������ �ִ� ���� �ȱ� �������� ���� �� �� �����ϴ�.)
4. ���� �� ���� ���������� ���� ���� �ʽ��ϴ�.
5. ������ �߻����� �ʴ´ٸ� ���� ������� �ʾƵ� �˴ϴ�.
i��° ��Ұ� i��° ���� �� �� ���� ���� �迭 gold_prices�� �Ű������� �־��� ��, ���� ����Ⱦ� ���� �� �ִ� �ִ� ������ ����ϴ� ���α׷��� �ۼ����ּ���.
���ѻ���
1. �迭 gold_prices�� ũ�� : 100,000 ������ �ڿ���
2. �ݰ� (�迭�� ����) : 10,000 ������ �ڿ���
*/

int GoldPrice(const vector<int>& gold_prices)
{
	vector<int> buy(gold_prices.size(), 0);		// n��° �� �� �� ����
	vector<int> sell(gold_prices.size(), 0);	// n��° �� �� �� ����

	// ù�� �� ���� �� ���� ����
	buy[0] = -gold_prices[0];
	sell[0] = 0;
	// ��° �� 
	buy[1] = max(buy[0], -gold_prices[1]);				// ���� ��� �� �������� ���û�� �� ��������
	sell[1] = max(sell[0], buy[0] + gold_prices[1]);	// ���� �缭 ���� �Ĵ°� �̵���?
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

	// �Է� ����1 Ans)4
	vector<int> gold_prices1 = { 2,5,1,3,4 };
	vector<int> gold_prices2 = { 7,2,5,6,1,4,2,8 };

	cout << GoldPrice(gold_prices1) << endl;
	cout << GoldPrice(gold_prices2) << endl;

	return 0;
}