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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

struct Craft
{
	vector<int> prevCraft; // ������ �Ϸ�Ǿ�� �ϴ� �͵�
	int time; // �� �ǹ��� ���µ� �ɸ��� �ð�
};
int T, N, K;
vector<Craft> vec;
vector<int> cache;

int MinTime(int craft)
{
	Craft& c = vec[craft];
	vector<int>& prevCraft = c.prevCraft;
	// ���� ���
	if (prevCraft.size() == 0)
		return c.time;

	// ĳ�� Ȯ��
	int& ret = cache[craft];
	if (ret != -1)
		return ret;

	for (int& n : prevCraft)
		ret = max(c.time + MinTime(n), ret);
	return ret;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		vec = vector<Craft>(N);
		cache = vector<int>(N, -1);

		for (int j = 0; j < N; j++)
		{
			int D;
			cin >> D;

			vec[j] = { vector<int>(), D};
		}

		for (int j = 0; j < K; j++)
		{
			int X, Y;
			cin >> X >> Y;

			vec[Y - 1].prevCraft.push_back(X - 1);
		}

		int W;
		cin >> W;

		cout << MinTime(W - 1) << endl;
	}

	return 0;
}