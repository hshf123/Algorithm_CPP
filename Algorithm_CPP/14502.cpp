#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
	int y;
	int x;
	int data;
};

vector<vector<Vertex>> v;
int N, M;

int dir_y[] = { 1,0,-1,0 };
int dir_x[] = { 0,1,0,-1 };

bool CanGo(int y, int x, int ny, int nx)
{
	if (ny > 0 && nx > 0 && ny < N && nx < M)
	{
		return true;
	}
	return false;
}

void Virus(Vertex start)
{
	queue<Vertex> q;
	q.push(start);

	while (q.empty() == false)
	{
		Vertex here = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (CanGo(here.y, here.x, here.y + dir_y[i], here.x + dir_x[i]) && v[here.y + dir_y[i]][here.x + dir_x[i]].data == 0)
			{
				v[here.y + dir_y[i]][here.x + dir_x[i]].data = 2;
				q.push(v[here.y + dir_y[i]][here.x + dir_x[i]]);
			}
		}
	}
	int a = 0;
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int wvz;
			cin >> wvz;
			Vertex vertex = { y,x,wvz };
			v[y].push_back(vertex);
		}
	}
}