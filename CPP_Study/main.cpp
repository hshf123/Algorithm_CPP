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
#include <cstring>

#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N;

char board[3072][6144];

void Draw(int y, int x)
{
	board[y][x] = '*';
	board[y + 1][x - 1] = '*';
	board[y + 1][x + 1] = '*';
	for (int i = x - 2; i <= x + 2; i++)
		board[y + 2][i] = '*';
}

void CheckTriangle(int height, int y, int x)
{
	if (height == 3)
	{
		Draw(y, x);
		return;
	}

	CheckTriangle(height / 2, y, x);
	CheckTriangle(height / 2, y + height / 2, x - height / 2);
	CheckTriangle(height / 2, y + height / 2, x + height / 2);
}

int main()
{
	Init;

	cin >> N;
	::memset(board, ' ', sizeof(board));
	CheckTriangle(N, 0, N - 1);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < 2 * N; x++)
		{
			cout << board[y][x];
		}
		cout << endl;
	}

	return 0;
}
