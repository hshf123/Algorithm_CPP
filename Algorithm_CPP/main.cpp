#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		cout << s[0] << s[s.length() - 1] << "\n";
	}
}