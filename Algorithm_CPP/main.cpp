#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int N, v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cin >> v;

	int count = 0;
	for (int num : vec)
	{
		if (num == v)
			++count;
	}

	cout << count;
}
