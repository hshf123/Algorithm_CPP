//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//struct Tomato
//{
//	int y; int x;
//};
//
//queue<Tomato> q;
//int tomatos[1001][1001];
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int n, m;
//
//bool IsInside(int y, int x)
//{
//	return (y >= 0 && y < m && x >= 0 && x < n);
//}
//
//void Bfs()
//{
//	while (q.empty() == false)
//	{
//		int y = q.front().y;
//		int x = q.front().x;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (IsInside(ny, nx) && tomatos[ny][nx] == 0)
//			{
//				tomatos[ny][nx] = tomatos[y][x]+1;
//				q.push({ ny,nx });
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//
//	for (int y = 0; y < m; y++)
//	{
//		for (int x = 0; x < n; x++)
//		{
//			int t;
//			cin >> t;
//			tomatos[y][x] = t;
//			if (t == 1)
//				q.push({ y,x });
//		}
//	}
//
//	Bfs();
//
//	int result = 0;
//	for (int y = 0; y < m; y++)
//	{
//		for (int x = 0; x < n; x++)
//		{
//			if (tomatos[y][x] == 0)
//			{
//				cout << -1;
//				return 0;
//			}
//			if (result < tomatos[y][x])
//				result = tomatos[y][x];
//		}
//	}
//
//	cout << result-1;
//}