#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	cout << (A + B) * (A - B);
}