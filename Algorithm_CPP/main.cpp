#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string N;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N.length(); ++i)
	{
		sum += (int)N[i] - 48;
	}

	cout << sum;
}