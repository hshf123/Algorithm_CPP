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
#include <numeric>
#include <sstream>

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

template<class T, class Container = deque<T>>
class Queue
{
public:
	void push(T data)
	{
		container.push_back(data);
	}
	T front()
	{
		return container.front();
	}

	bool empty()
	{
		return container.empty();
	}
	void pop()
	{
		container.pop_front();
	}


private:
	Container container;
};

int main()
{
	Queue<int> q;
	for (int i = 0; i < 100; i++)
	{
		q.push(i + 1);
	}

	while (q.empty() == false)
	{
		cout << q.front() << endl;
		q.pop();
	}


	return 0;
}