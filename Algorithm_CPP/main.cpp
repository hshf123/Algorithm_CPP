#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count[10] = {};
	int A, B, C;
	cin >> A >> B >> C;

	int res = A * B * C;

	string str = to_string(res);
	for (int i = 0; i < str.length(); i++)
	{
		count[(int)str[i] - 48]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << "\n";
	}
}