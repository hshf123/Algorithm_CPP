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
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

string FizzBuzz = "FizzBuzz";
string Fizz = "Fizz";
string Buzz = "Buzz";

bool IsFizzOrBuzz(const string& str)
{
	if (str == FizzBuzz || str == Fizz || str == Buzz)
		return true;

	return false;
}

int main()
{
	array<int, 3> num = { 0, };
	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;

		if (IsFizzOrBuzz(str) == false)
		{
			if (i == 0)
			{
				num[i] = stoi(str);
				num[i + 1] = num[i] + 1;
				num[i + 2] = num[i] + 2;
			}
			if (i == 1)
			{
				num[i] = stoi(str);
				num[i - 1] = num[i] - 1;
				num[i + 1] = num[i] + 1;
			}
			if (i == 2)
			{
				num[i] = stoi(str);
				num[i - 2] = num[i] - 2;
				num[i - 1] = num[i] - 1;
			}
		}
	}

	int nextNum = num[2] + 1;
	
	int fizz = nextNum % 3;
	int buzz = nextNum % 5;
	if (fizz == 0 && buzz == 0)
		cout << FizzBuzz << endl;
	else if (fizz == 0)
		cout << Fizz << endl;
	else if (buzz == 0)
		cout << Buzz << endl;
	else
		cout << nextNum << endl;
}