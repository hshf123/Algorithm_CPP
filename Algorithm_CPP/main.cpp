#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	string a_str = to_string(A);
	string b_str = to_string(B);

	reverse(a_str.begin(), a_str.end());
	reverse(b_str.begin(), b_str.end());

	A = stoi(a_str);
	B = stoi(b_str);

	if (A >= B)
		cout << A;
	else
		cout << B;
}