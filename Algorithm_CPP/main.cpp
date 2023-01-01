#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;

	while (true)
	{
		getline(cin, s);
		if (s == "")
			break;

		cout << s << endl;
	}

	return 0;
}