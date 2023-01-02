#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int right, left, up, down;

	right = w - x;
	left = x - 0;
	up = h - y;
	down = y - 0;

	cout << min(min(min(right, left), up), down);
}