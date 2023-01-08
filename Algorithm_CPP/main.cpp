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
	string str;
	cin >> str;
	const char* p = str.c_str();
	int64 sum = 0;
	int64 r = 1;
	for (int i = 0; i < N; i++)
	{
		char c = *(p + i);
		short number = c - 'a' + 1;
		sum = (sum + number * r) % 1234567891;
		r = (r * 31) % 1234567891;
	}

	cout << sum;

	return 0;
}
