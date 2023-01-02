#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int H, M;
	cin >> H >> M;

	M -= 45;
	if (M < 0)
	{
		M += 60;
		H--;

		if (H < 0)
		{
			H += 24;
		}
	}

	cout << H << " " << M;
}