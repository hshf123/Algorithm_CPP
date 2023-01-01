#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a;
	int b;
	vector<int> vec;

	bool end = (cin >> a >> b).eof();

	while (!end)
	{
		vec.push_back(a + b);
		end = (cin >> a >> b).eof();
	}

	for (int sum : vec)
	{
		cout << sum << "\n";
	}
}
