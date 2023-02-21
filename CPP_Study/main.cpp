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

int n;
unordered_map<char, pair<char, char>> tree;

void PrintPreorder(char node)
{
	if (node == '.')
		return;
	auto t = tree[node];
	cout << node;
	PrintPreorder(t.first);
	PrintPreorder(t.second);
}

void PrintInorder(char node)
{
	if (node == '.')
		return;
	auto t = tree[node];
	PrintInorder(t.first);
	cout << node;
	PrintInorder(t.second);
}

void PrintPostorder(char node)
{
	if (node == '.')
		return;
	auto t = tree[node];
	PrintPostorder(t.first);
	PrintPostorder(t.second);
	cout << node;
}

int main()
{
	Init;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char key, left, right;
		cin >> key >> left >> right;

		tree[key] = { left, right };
	}

	PrintPreorder('A');
	cout << endl;
	PrintInorder('A');
	cout << endl;
	PrintPostorder('A');
	return 0;
}
