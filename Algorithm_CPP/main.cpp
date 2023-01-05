#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> vec(N);
	for (int i = 0; i < N; i++)
	{
		string ps;
		cin >> ps;

		int lc = 0;
		int rc = 0;

		const char* p = ps.c_str();
		for (int c = 0; c < ps.length(); c++)
		{
			if (*p == '(')
				lc++;
			else
				rc++;

			if (lc < rc)
				break;

			p++;
		}
		if (rc == lc)
			vec[i] = "YES";
		else
			vec[i] = "NO";
	}

	for (string& str : vec)
		cout << str << endl;
}
