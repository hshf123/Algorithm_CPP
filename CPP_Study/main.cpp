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

int D(int n)
{
	return 2 * n % 10000;
}

int S(int n)
{
	return n - 1 < 0 ? 9999 : n - 1;
}

int L(int n)
{
	int n4 = n % 10;
	n /= 10;
	int n3 = n % 10;
	n /= 10;
	int n2 = n % 10;
	n /= 10;
	int n1 = n % 10;

	return n2 * 1000 + n3 * 100 + n4 * 10 + n1;
}

int R(int n)
{
	int n4 = n % 10;
	n /= 10;
	int n3 = n % 10;
	n /= 10;
	int n2 = n % 10;
	n /= 10;
	int n1 = n % 10;

	return n4 * 1000 + n1 * 100 + n2 * 10 + n3;
}

vector<bool> discovered;
vector<string> root;

void BFS(int A, int B)
{
	discovered[A] = true;

	queue<int> q;
	q.push(A);

	while (q.empty() == false)
	{
		int now = q.front();
		q.pop();

		if (now == B)
		{
			cout << root[now];
			cout << endl;
			break;
		}

		int d = D(now);
		if (discovered[d] == false)
		{
			q.push(d);
			discovered[d] = true;
			root[d] = root[now] + "D";
		}

		int s = S(now);
		if (discovered[s] == false)
		{
			q.push(s);
			discovered[s] = true;
			root[s] = root[now] + "S";
		}

		int l = L(now);
		if (discovered[l] == false)
		{
			q.push(l);
			discovered[l] = true;
			root[l] = root[now] + "L";
		}

		int r = R(now);
		if (discovered[r] == false)
		{
			q.push(r);
			discovered[r] = true;
			root[r] = root[now] + "R";
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// D : 2*n % 10000
	// S : n - 1 if 0 : 9999
	// L : 1 2 3 4 -> 2 3 4 1
	// R : 1 2 3 4 -> 4 1 2 3

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int A, B;
		cin >> A >> B;

		discovered = vector<bool>(10000, false);
		root = vector<string>(10000);

		BFS(A, B);
	}

	return 0;
}