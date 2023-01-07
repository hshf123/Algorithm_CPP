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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, V;
	cin >> A >> B >> V;

	int height = 0;

	int day = (V - A) / (A - B);
	if ((V - A) % (A - B) != 0)
		day++;
	day++;

	cout << day;
}
