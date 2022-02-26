#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector<int> v;
	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(y - x);
	}

	for (int i = 0; i < T; i++)
	{
		int distance = v[i];
		int dis = (int)sqrt(distance);
		
		if (dis == sqrt(distance)) 
			cout << dis * 2 - 1 << "\n";
		else if (distance - dis * dis <= dis)
			cout << dis * 2 << "\n";
		else
			cout << dis * 2 + 1 << "\n";

	}
}