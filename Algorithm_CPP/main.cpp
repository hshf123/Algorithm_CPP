#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (a < X)
			vec.push_back(a);
	}

	for (int num : vec)
	{
		cout << num << " ";
	}
}
