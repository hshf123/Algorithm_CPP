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

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> ret(a.size() + b.size() + 1);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			ret[i + j] += a[i] * b[j];
		}
	}

	for (int i = 0; i < ret.size() -1 ; i++)
	{
		ret[i + 1] += (ret[i] / 10);
		ret[i] %= 10;
	}
	return ret;
}

void addTo(vector<int>& a, const vector<int>& b, int k)
{
	if (a.size() > b.size() + k)
		a.resize(b.size() + k + 1);
	for (int i = k; i < b.size() + k -1; i++)
	{
		a[i] += b[i - k];
		a[i + 1] = a[i] / 10;
	}
}

void subFrom(vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a[i] -= b[i];
		if (a[i] < 0)
		{
			--a[i + 1];
			a[i] += 10;
		}
	}
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size();
	int bn = b.size();
	if (an < bn)
		return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min((int)b.size(), half));
	vector<int> b1(b.begin() + min((int)b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, an);

	return ret;
}

int main()
{
	Init;
	vector<int> a;
	for (int i = 0; i < 50; i++)
	{
		a.push_back(1);
	}
	vector<int> b;
	for (int i = 0; i < 50; i++)
	{
		b.push_back(2);
	}
	vector<int> c = karatsuba(a, b);
	reverse(c.begin(), c.end());
	for (int n : c)
		cout << n;
	
	return 0;
}