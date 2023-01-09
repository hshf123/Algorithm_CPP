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

#include "LockFreeStack.h"
#include <thread>

LockFreeStack<int> _stack;
void Push()
{
	while (true)
	{
		int value = rand() % 100;
		_stack.Push(value);

		this_thread::sleep_for(10ms);
	}
}

void Pop()
{
	while (true)
	{
		int value;
		if (_stack.TryPop(value))
			cout << value << endl;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	thread t1(Push);
	thread t2(Pop);
	thread t3(Pop);
	thread t4(Pop);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}
