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
	// 점수 매기기
	// F = G + H
	// F = 최종 점수 (작을 수록 좋음, 경로에 따라 달라짐)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을 수록 좋음, 경로에 따라 달라짐)
	// H = 목적지에서 얼마나 가까운지 (작을 수록 좋음, 고정)

	// ClosedList
	// close[y][x] -> (y, x)에 방문을 했는지 여부
	vector<bool> closed(N + 1, false);

	// best[y][x] -> 지금까지 (y, x)에 대한 가장 좋은 비용 (작을 수록 좋음)
	vector<int> best(N + 1, INT32_MAX);

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 1) 예약(발견) 시스템 구현
	// - 이미 더 좋은 경로를 찾았다면 스킵
	// 2) 뒤늦게 더 좋은 경로가 발견될 수 있음 -> 예외 처리 필수
	// - openList에서 찾아서 제거한다거나.
	// - pq에서 pop한 다음에 무시한다거나.

	// 초기값
	{
		int g = 0;
		pq.push(PQNode{ start, cost });
		best[start] = cost;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서\
		// 더 빠른 경로로 인해서 이미 방문(closed)된 경우 스킵
		// [선택]
		if (closed[node.pos])
			continue;
		if (best[node.pos] < node.time)
			continue;

		// 방문
		closed[node.pos] = true;

		// 목적지에 도착했으면 바로 종료
		if (node.pos == dest)
		{
			path += best[dest];
			break;
		}

		for (auto& next : roads[node.pos])
		{
			int nextPos = next.pos;
			// [선택] 이미 방문한 곳이면 스킵
			if (closed[nextPos])
				continue;

			// 비용 계산
			int time = best[node.pos] + next.time;
			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos] <= time)
				continue;

			// 예약 진행
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
