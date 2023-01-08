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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	stack<int> _stack;
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;

		if (K != 0)
		{
			_stack.push(K);
		}
		else
		{
			_stack.pop();
		}
	}

	int sum = 0;
	while (_stack.empty() == false)
	{
		sum += _stack.top();
		_stack.pop();
	}

	cout << sum;

	return 0;
}
