#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <list>



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	queue<int> _queue;
	for (int i = 1; i <= N; i++)
		_queue.push(i);

	cout << "<";
	int i = 1;
	while (_queue.empty() == false)
	{
		if (i % K == 0)
		{
			cout << _queue.front();
			_queue.pop();
			if (_queue.empty() == false)
				cout << ", ";
		}
		else
		{
			_queue.push(_queue.front());
			_queue.pop();
		}
		i++;
	}
	cout << ">";

	return 0;
}
