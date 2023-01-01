#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<bool> vec(30, false);
	for (int i = 0; i < 28; i++)
	{
		int n;
		cin >> n;
		vec[n - 1] = true;
	}

	int count = 1;
	for (bool n : vec)
	{
		if (n == false)
			cout << count << "\n";
		++count;
	}
}
