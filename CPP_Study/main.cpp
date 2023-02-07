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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int64 a, b, c, k;
int _count = 1;

int64 power(long long b) {
	cout << _count++ << endl;
	if (b == 0) return 1;
	if (b == 1) return a % c;

	k = power(b / 2) % c;
	if (b % 2 == 0) return k * k % c;
	return k * k % c * a % c;
}

int main()
{
	Init;

	cin >> a >> b >> c;
	cout << power(b);

	return 0;
}
