#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

struct PQNode
{
	bool operator<(const PQNode& other) const { return time < other.time; }
	bool operator>(const PQNode& other) const { return time > other.time; }

	int	pos;
	int	time;
};

int N, M, X;
vector<vector<PQNode>> roads;
int path = 0;

void AStar(int start,int cost, int dest)
{
	// ���� �ű��
	// F = G + H
	// F = ���� ���� (���� ���� ����, ��ο� ���� �޶���)
	// G = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ��� (���� ���� ����, ��ο� ���� �޶���)
	// H = ���������� �󸶳� ������� (���� ���� ����, ����)

	// ClosedList
	// close[y][x] -> (y, x)�� �湮�� �ߴ��� ����
	vector<bool> closed(N + 1, false);

	// best[y][x] -> ���ݱ��� (y, x)�� ���� ���� ���� ��� (���� ���� ����)
	vector<int> best(N + 1, INT32_MAX);

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 1) ����(�߰�) �ý��� ����
	// - �̹� �� ���� ��θ� ã�Ҵٸ� ��ŵ
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó�� �ʼ�
	// - openList���� ã�Ƽ� �����Ѵٰų�.
	// - pq���� pop�� ������ �����Ѵٰų�.

	// �ʱⰪ
	{
		int g = 0;
		pq.push(PQNode{ start, cost });
		best[start] = cost;
	}

	while (pq.empty() == false)
	{
		// ���� ���� �ĺ��� ã�´�
		PQNode node = pq.top();
		pq.pop();

		// ������ ��ǥ�� ���� ��η� ã�Ƽ�\
		// �� ���� ��η� ���ؼ� �̹� �湮(closed)�� ��� ��ŵ
		// [����]
		if (closed[node.pos])
			continue;
		if (best[node.pos] < node.time)
			continue;

		// �湮
		closed[node.pos] = true;

		// �������� ���������� �ٷ� ����
		if (node.pos == dest)
		{
			path += best[dest];
			break;
		}

		for (auto& next : roads[node.pos])
		{
			int nextPos = next.pos;
			// [����] �̹� �湮�� ���̸� ��ŵ
			if (closed[nextPos])
				continue;

			// ��� ���
			int time = best[node.pos] + next.time;
			// �ٸ� ��ο��� �� ���� ���� ã������ ��ŵ
			if (best[nextPos] <= time)
				continue;

			// ���� ����
			best[nextPos] = time;
			pq.push(PQNode{ nextPos,time });
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> X;
	roads = vector<vector<PQNode>>(N + 1);

	for (int i = 1; i <= M; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;

		roads[start].push_back({ end, time });
	}
	
	int _max = 0;
	for (int i = 1; i <= N; i++)
	{
		path = 0;
		AStar(i, 0, X);
		AStar(X, 0, i);
		_max = max(_max, path);
	}

	cout << _max;

	return 0;
}
