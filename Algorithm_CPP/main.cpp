#include <iostream>
using namespace std;
#define endl "\n"

#include <vector>
#include <algorithm>

int arr[1001] = {};

int main()
{
	int N;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int max = vec.back();

	for (int i = 2; i <= max; i++)
		arr[i] = i;

	for (int i = 2; i * i <= max; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= max; j += i)
			arr[j] = 0;
	}

	int count = 0;
	for (int& prime : vec)
	{
		if (arr[prime] != 0)
			count++;
	}

	cout << count;
}
