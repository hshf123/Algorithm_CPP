#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int floor, room;
	int T;
	cin >> T;
	vector<int> vec(T);
	for (int i = 0; i < T; i++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		floor = N % H == 0 ? H : N % H;
		room = (N + H - 1) / H;
		vec[i] = floor * 100 + room;
	}

	for (int& n : vec)
		cout << n << endl;
}
