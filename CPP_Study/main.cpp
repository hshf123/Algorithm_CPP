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
#include <cstring>

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

void Insert(Node*& root, int value)
{
	if (root == nullptr)
	{
		root = new Node();
		root->key = value;
		return;
	}

	if (root->key > value)
		Insert(root->left, value);
	else
		Insert(root->right, value);
}

void PrintPostOrder(Node* node)
{
	if (node == nullptr)
		return;

	PrintPostOrder(node->left);
	PrintPostOrder(node->right);
	cout << node->key << endl;
}

int main()
{
	Init;

	Node* root = nullptr;

	int n;
	while (cin >> n)
	{
		Insert(root, n);
	}
	PrintPostOrder(root);

	return 0;
}