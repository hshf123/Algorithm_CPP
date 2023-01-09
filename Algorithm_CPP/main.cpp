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

int number = 0;
int N, r, c;

void DIV(int startx, int starty, int endx, int endy)
{
	int n = endx - startx;
	int divNumber = n / 2; // 2^n-1 * 2^n-1

	if (n == 2)
	{
		int y = r - starty;
		y *= 2;
		int x = c - startx;
		number += (x + y);
		cout << number;
		return;
	}

	if (starty <= r && r < endy - divNumber && startx <= c && c < endx - divNumber)
	{
		DIV(startx, starty, endx - divNumber, endy - divNumber);
	}
	else if (starty <= r && r < endy - divNumber && startx + divNumber <= c && c < endx)
	{
		number += divNumber * divNumber;
		DIV(startx + divNumber, starty, endx, endy - divNumber);
	}
	else if (starty + divNumber <= r && r < endy && startx <= c && c < endx - divNumber)
	{
		number += divNumber * divNumber * 2;
		DIV(startx, starty + divNumber, endx - divNumber, endy);
	}
	else
	{
		number += divNumber * divNumber * 3;
		DIV(startx + divNumber, starty + divNumber, endx, endy);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> r >> c;

	int n = pow(2, N);

	DIV(0, 0, n, n);

	return 0;
}
