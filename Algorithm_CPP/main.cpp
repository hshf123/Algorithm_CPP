#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	int big, small;
	if (A > B)
	{
		big = A;
		small = B;
	}
	else
	{
		big = B;
		small = A;
	}
	// 최대 공약수
	for (int i = small; i > 0; i--)
	{
		if (big % i == 0 && small % i == 0)
		{
			cout << i << endl;
			break;
		}
	}
	// 최소 공배수
	int si = 1;
	int bi = 1;
	while (true)
	{
		int ss = small * si;
		int bb = big * bi;
		if (ss == bb)
		{
			cout << ss;
			break;
		}
		else if (ss > bb)
			bi++;
		else
			si++;
	}
}
