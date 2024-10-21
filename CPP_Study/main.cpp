#pragma region Headers
#include <iostream>
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
#include <cstring>
#include <numeric>
#include <sstream>
#include <array>

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
#pragma endregion



int main()
{
	Init;
	
	string str;
	cin >> str;

	int64 sum = 0;

	string num;

	for (int i = 0; i < str.size(); i++)
	{
		char& c = str[i];
		if (isdigit(c))
		{
			num += c;
		}
		else
		{
			if (num.empty())
				continue;

			sum += atoi(num.c_str());
			num.clear();
		}
	}

	if (num.empty() == false)
	{
		sum += atoi(num.c_str());
	}
	cout << sum;
	
	return 0;
}