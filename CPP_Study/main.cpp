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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int main()
{
	int N, T, P;
	cin >> N;
	vector<int> sizeList;
	sizeList.reserve(6);
	for (int i = 0; i < 6; i++)
	{
		int size;
		cin >> size;
		sizeList.push_back(size);
	}
	cin >> T;
	cin >> P;

	int totalBundle = 0;
	for (const int& size : sizeList)
	{
		totalBundle += size / T + 1;
		if (size % T == 0)
			totalBundle -= 1;
	}

	cout << totalBundle << endl;
	cout << N / P << " " << N % P << endl;
}