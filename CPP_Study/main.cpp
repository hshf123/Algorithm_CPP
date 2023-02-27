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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N, K;
int _size;
vector<bool> visited;

void Position()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, N });
	visited[N] = true;

	while (q.empty() == false)
	{
		int count = q.top().first;
		int x = q.top().second;
		q.pop();

		if (x == K)
		{
			cout << count;
			return;
		}

		if (x - 1 >= 0 && visited[x - 1] == false)
		{
			q.push({ count + 1, x - 1 });
			visited[x - 1] = true;
		}

		if (x * 2 < _size && visited[x * 2] == false)
		{
			q.push({ count, x * 2 });
			visited[x * 2] = true;
		}

		if (x + 1 < _size && visited[x + 1] == false)
		{
			q.push({ count + 1, x + 1 });
			visited[x + 1] = true;
		}
	}
}

int main()
{
	Init;

	cin >> N >> K;
	_size = 10'0001;
	visited = vector<bool>(_size, false);
	Position();

	return 0;
}
