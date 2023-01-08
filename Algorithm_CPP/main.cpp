#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

vector<vector<bool>> vec;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;
int xdir[] = { 0, 1, 0, -1 };
int ydir[] = { -1, 0, 1, 0 };
int earthworm = 0;
int T;
int M, N, K;

void DFS(int x, int y)
{
	visited[y][x] = true;

	if (vec[y][x] == true)
	{
		for (int i = 0; i < 4; i++)
		{
			int dx = xdir[i] + x;
			int dy = ydir[i] + y;

			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			{
				if (vec[dy][dx] == true && visited[dy][dx] == false)
				{
					parent[dy][dx] = make_pair(y, x);
					DFS(dx, dy);
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	
	for (int testcase = 0; testcase < T; testcase++)
	{
		vec.clear();
		visited.clear();
		earthworm = 0;

		cin >> M >> N >> K;

		vec = vector<vector<bool>>(N, vector<bool>(M, false));
		visited = vector<vector<bool>>(N, vector<bool>(M, false));
		parent = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M, make_pair(-1, -1)));

		for (int pos = 0; pos < K; pos++)
		{
			int x, y;
			cin >> x >> y;
			vec[y][x] = true;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				DFS(x, y);
			}
		}

		

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (vec[y][x] == true)
				{
					int ty = parent[y][x].first;
					int tx = parent[y][x].second;
					if (ty == -1 && tx == -1)
					{
						earthworm++;
					}

				}
			}
		}
		cout << earthworm << endl;
	}

	return 0;
}
