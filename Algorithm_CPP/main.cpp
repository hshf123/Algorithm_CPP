#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//97
	//122

	string S;
	cin >> S;
	vector<int> vec(26, -1);

	for (int i = 0; i < S.length(); i++)
	{
		int n = (int)S[i] - 97;
		if(vec[n] == -1)
			vec[n] = i;
	}

	for (int num : vec)
	{
		cout << num << " ";
	}
}
