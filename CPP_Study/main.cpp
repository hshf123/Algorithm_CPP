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

map<int, int> ladders;
map<int, int> snakes;
vector<int> dice;
vector<bool> visited;

void BFS(int n)
{
	dice[n] = 0;
	visited[n] = true;
	queue<int> q;
	q.push(n);

	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = now + i;
			if (next <= 100 && visited[next] == false)
			{
				// 다음칸 전진
				// 만약 사다리라면 탄다.
				{
					auto it = ladders.find(next);
					if (it != ladders.end())
					{
						q.push(it->second);
						if (dice[it->second] == -1)
						{
							dice[it->second] = dice[now] + 1;
						}
						else if (dice[it->second] > dice[now] + 1)
						{
							dice[it->second] = dice[now] + 1;
						}
						visited[it->second] = true;

						if (dice[next] == -1)
						{
							dice[next] = dice[now] + 1;
						}
						else if (dice[next] > dice[now] + 1)
						{
							dice[next] = dice[now] + 1;
						}
						visited[next] = true;

						continue;
					}
				}

				{
					auto it = snakes.find(next);
					if (it != snakes.end())
					{
						q.push(it->second);
						if (dice[it->second] == -1)
						{
							dice[it->second] = dice[now] + 1;
						}
						else if (dice[it->second] > dice[now] + 1)
						{
							dice[it->second] = dice[now] + 1;
						}
						visited[it->second] = true;

						if (dice[next] == -1)
						{
							dice[next] = dice[now] + 1;
						}
						else if (dice[next] > dice[now] + 1)
						{
							dice[next] = dice[now] + 1;
						}
						visited[next] = true;

						continue;
					}
				}

				// 사다리나 뱀이 없다면 그냥 다음칸 가자
				q.push(next);
				if (dice[next] == -1)
				{
					dice[next] = dice[now] + 1;
				}
				else if (dice[next] > dice[now] + 1)
				{
					dice[next] = dice[now] + 1;
				}
				visited[next] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	dice = vector<int>(101, -1);
	visited = vector<bool>(101, false);

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		ladders.insert({ x, y });
	}
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		snakes.insert({ x, y });
	}

	BFS(1);

	cout << dice[100];

	return 0;
}
