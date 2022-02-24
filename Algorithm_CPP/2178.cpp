//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct Maze
//{
//	int y;
//	int x;
//};
//
//queue<Maze> q;
//int maze[101][101];
//int n, m;
//
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//
//bool CanGo(int ly, int lx, int y, int x)
//{
//	return (x >= 0 && y >= 0 && y < n&& x < m&& ly != y && lx != x);
//}
//
//void Bfs()
//{
//	while (q.empty() == false)
//	{
//		int x = q.front().x;
//		int y = q.front().y;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (maze[ny][nx] != 0 && CanGo(y, x, nx, ny))
//				maze[ny][nx] += maze[y][x];
//		}
//
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> m;
//
//	for (int y = 0; y < n; y++)
//	{
//		string num;
//		cin >> num;
//		for (int x = 0; x < m; x++)
//		{
//			int number = stoi(num.substr(x, 1));
//			maze[y][x] = number;
//			if (num == 1)
//				q.push({ y,x });
//		}
//	}
//
//	Bfs();
//}