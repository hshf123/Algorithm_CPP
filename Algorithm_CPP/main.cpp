#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> res;
	int pal;
	cin >> pal;

	while (pal != 0)
	{
		string str = to_string(pal);
		string str_r = str;
		reverse(str_r.begin(), str_r.end());

		if (str == str_r)
			res.push_back("yes");
		else
			res.push_back("no");

		cin >> pal;
	}

	for (string r : res)
	{
		cout << r << "\n";
	}
}