#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;
#define INT32_HALF (2147483647 / 2)

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

struct Node
{
	bool operator<(const Node& other) const { return cost < other.cost; }
	bool operator>(const Node& other) const { return cost > other.cost; }

	int	edge;
	int	cost;
};

int N, E;
int v1, v2;
vector<vector<Node>> nodes;

int AStar(int start, int dest, int cost = 0)
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
	vector<int> best(N + 1, INT32_HALF);

	// OpenList
	priority_queue<Node, vector<Node>, greater<Node>> pq;

	// 1) ����(�߰�) �ý��� ����
	// - �̹� �� ���� ��θ� ã�Ҵٸ� ��ŵ
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó�� �ʼ�
	// - openList���� ã�Ƽ� �����Ѵٰų�.
	// - pq���� pop�� ������ �����Ѵٰų�.

	// �ʱⰪ
	int path = -1;
	{
		int g = 0;
		pq.push(Node{ start, cost });
		best[start] = cost;
	}

	while (pq.empty() == false)
	{
		// ���� ���� �ĺ��� ã�´�
		Node node = pq.top();
		pq.pop();

		// ������ ��ǥ�� ���� ��η� ã�Ƽ�\
		// �� ���� ��η� ���ؼ� �̹� �湮(closed)�� ��� ��ŵ
		// [����]
		if (closed[node.edge])
			continue;
		if (best[node.edge] < node.cost)
			continue;

		// �湮
		closed[node.edge] = true;

		// �������� ���������� �ٷ� ����
		if (node.edge == dest)
		{
			if (path == -1)
				path++;
			path += best[dest];
			break;
		}

		for (auto& next : nodes[node.edge])
		{
			int nextPos = next.edge;
			// [����] �̹� �湮�� ���̸� ��ŵ
			if (closed[nextPos])
				continue;

			// ��� ���
			int time = best[node.edge] + next.cost;
			// �ٸ� ��ο��� �� ���� ���� ã������ ��ŵ
			if (best[nextPos] <= time)
				continue;

			// ���� ����
			best[nextPos] = time;
			pq.push(Node{ nextPos,time });
		}
	}

	return path;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> E;
	nodes = vector<vector<Node>>(N + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	int res1, res2;
	int a1 = AStar(1, v1);
	int a2 = AStar(v1, v2);
	int a3 = AStar(v2, N);
	if (a1 == -1 || a2 == -1 || a3 == -1) res1 = -1;
	else res1 = a1 + a2 + a3;

	int b1 = AStar(1, v2);
	int b2 = AStar(v2, v1);
	int b3 = AStar(v1, N);
	if (b1 == -1 || b2 == -1 || b3 == -1) res2 = -1;
	else res2 = b1 + b2 + b3;

	if (res1 == -1 && res2 == -1) cout << -1;
	else cout << min(res1, res2);

	return 0;
}
