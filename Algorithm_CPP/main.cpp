#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a;
	int b;
	vector<int> vec;

	cin >> a >> b;

	while (a != 0 && b != 0)
	{
		vec.push_back(a + b);
		cin >> a >> b;
	}

	for(int sum : vec)
	{
		cout << sum << "\n";
	}
}
