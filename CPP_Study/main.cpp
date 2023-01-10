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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int count = N / 5 + N / 25 + N / 125;

	cout << count;

	return 0;
}

