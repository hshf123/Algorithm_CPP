#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> vec;
	while (true)
	{
		int A, B, C;
		cin >> A >> B >> C;
		
		if (A + B + C == 0)
			break;
		priority_queue<int> pq;
		pq.push(A);
		pq.push(B);
		pq.push(C);

		int csquare = pq.top() * pq.top();
		pq.pop();
		csquare -= (pq.top() * pq.top());
		pq.pop();
		csquare -= (pq.top() * pq.top());

		if (csquare == 0)
			vec.push_back("right");
		else
			vec.push_back("wrong");
	}

	for (string& str : vec)
		cout << str << endl;
}
