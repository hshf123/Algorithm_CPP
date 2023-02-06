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
	// 점수 매기기
	// F = G + H
	// F = 최종 점수 (작을 수록 좋음, 경로에 따라 달라짐)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을 수록 좋음, 경로에 따라 달라짐)
	// H = 목적지에서 얼마나 가까운지 (작을 수록 좋음, 고정)

	// ClosedList
	// close[y][x] -> (y, x)에 방문을 했는지 여부
	vector<bool> closed(N + 1, false);

	// best[y][x] -> 지금까지 (y, x)에 대한 가장 좋은 비용 (작을 수록 좋음)
	vector<int> best(N + 1, INT32_HALF);

	// OpenList
	priority_queue<Node, vector<Node>, greater<Node>> pq;

	// 1) 예약(발견) 시스템 구현
	// - 이미 더 좋은 경로를 찾았다면 스킵
	// 2) 뒤늦게 더 좋은 경로가 발견될 수 있음 -> 예외 처리 필수
	// - openList에서 찾아서 제거한다거나.
	// - pq에서 pop한 다음에 무시한다거나.

	// 초기값
	int path = -1;
	{
		int g = 0;
		pq.push(Node{ start, cost });
		best[start] = cost;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		Node node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서\
		// 더 빠른 경로로 인해서 이미 방문(closed)된 경우 스킵
		// [선택]
		if (closed[node.edge])
			continue;
		if (best[node.edge] < node.cost)
			continue;

		// 방문
		closed[node.edge] = true;

		// 목적지에 도착했으면 바로 종료
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
			// [선택] 이미 방문한 곳이면 스킵
			if (closed[nextPos])
				continue;

			// 비용 계산
			int time = best[node.edge] + next.cost;
			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos] <= time)
				continue;

			// 예약 진행
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
