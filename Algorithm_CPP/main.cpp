#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> A;

	for (int i = 0; i < N * M; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N * M; i++)
	{
		int a;
		cin >> a;
		A[i] += a;
	}
	int count = 1;
	for (int i = 0; i < N * M; i++)
	{
		cout << A[i] << " ";
		if (count % M == 0)
			cout << "\n";
		++count;
	}
}
