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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
using BYTE = unsigned char;

vector<string> cache[101];

string Add(string num1, string num2)
{
	string res = "";
	
	if (num1.size() < num2.size())
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int num1Iter = num1.size() - 1;
	int num2Iter = num2.size() - 1;
	bool up = false;
	for (int i = num2Iter; i >= 0; --i)
	{
		int n1 = num1[num1Iter] - '0';
		int n2 = num2[num2Iter] - '0';

		int n = n1 + n2;
		if (up)
			n++;
		if (n >= 10)
		{
			up = true;
			n -= 10;
		}
		else
			up = false;

		char c = n + '0';
		res += c;

		num1Iter--;
		num2Iter--;
	}

	for (int i = num1Iter; i >= 0; --i)
	{
		int n = num1[i] - '0';

		if (up)
			n++;

		if (n >= 10)
		{
			up = true;
			n -= 10;
		}
		else
			up = false;

		char c = n + '0';
		res += c;
	}

	if (up)
		res += "1";

	::reverse(res.begin(), res.end());

	return res;
}

string Combination(string n, string m)
{
	if (m == "0" || m == n)
		return "1";

	string& ret = cache[stoi(n)][stoi(m)];
	if (ret != "-1")
		return ret;

	string n_1 = to_string(stoi(n) - 1);
	string m_1 = to_string(stoi(m) - 1);

	return ret = Add(Combination(n_1, m_1), Combination(n_1, m));
}

int main()
{
	Init;

	for (int i = 0; i < 101; i++)
		cache[i] = vector<string>(101, "-1");

	string n, m;
	cin >> n >> m;

	cout << Combination(n, m);

	return 0;
}
