#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vecN;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		vecN.push_back(A);
	}
	sort(vecN.begin(), vecN.end());

	int M;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		int inA;
		cin >> inA;
		cout << binary_search(vecN.begin(), vecN.end(), inA) << "\n";
	}
}