#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	bool hasMinus = false;
	bool isFirstNumber = false;
	int minNum;
	int lastIdx = 0;
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || i == str.length())
		{
			int num = stoi(str.substr(lastIdx, i));
			lastIdx = i + 1;

			if (isFirstNumber == false)
			{
				minNum = num;
				isFirstNumber = true;
			}
			else
			{
				if (hasMinus == false)
					minNum += num;
				else
					minNum -= num;
			}

			if (str[i] == '-')
				hasMinus = true;
		}
	}

	cout << minNum;

	return 0;
}

