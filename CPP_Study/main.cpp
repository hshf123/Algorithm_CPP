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
#include <memory.h>
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

struct Node
{
	Node* left;
	int key;
	Node* right;
};

int n;
vector<int> order[2];

Node* FindTree(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
		return nullptr;

	Node* root = new Node();
	int key = order[1][postEnd];
	root->key = key;

	int nextInStart;
	int nextInEnd;
	int nextPostStart;
	int nextPostEnd;

	auto findIt = ::find(order[0].begin(), order[0].end(), key);
	int idx = findIt - order[0].begin();
	nextInStart = inStart;
	nextInEnd = idx - 1;
	nextPostStart = postStart;
	nextPostEnd = postStart + idx - inStart - 1;
	Node* left = FindTree(nextInStart, nextInEnd, nextPostStart, nextPostEnd);

	nextInStart = idx + 1;
	nextInEnd = inEnd;
	nextPostStart = postStart + idx - inStart;
	nextPostEnd = postEnd - 1;
	Node* right = FindTree(nextInStart, nextInEnd, nextPostStart, nextPostEnd);

	root->left = left;
	root->right = right;

	return root;
}

void PrintPreorder(Node* node)
{
	if (node == nullptr)
		return;

	cout << node->key << " ";
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

int main()
{
	Init;

	cin >> n;
	postOrder = vector<int>(n);
	for (int i = 0; i < 2; i++)
	{
		order[i] = vector<int>(n);
		for (int j = 0; j < n; j++)
		{
			cin >> order[i][j];
		}
	}

	Node* root = FindTree(0, n - 1, 0, n - 1);
	PrintPreorder(root);

	return 0;
}
