#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<int, int> _numToCount;
	vector<vector<int>> _mode(N);
	vector<int> _mid(N, 0);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		auto findIt = _numToCount.find(num);
		if (findIt == _numToCount.end())
		{
			_numToCount.insert(make_pair(num, 1));
			_mode[0].push_back(num);
		}
		else
		{
			// 최소 1번 이상 등장한 숫자
			findIt->second++;
			_mode[findIt->second - 1].push_back(findIt->first);
		}

		_mid[i] = num;
	}


	double sum = 0;
	int max = 0;
	for (auto it = _numToCount.begin(); it != _numToCount.end(); ++it)
	{
		sum += it->first * it->second;

		if (it->second > max)
			max = it->second;
	}

	double avg = 0;
	avg = sum / N;
	avg = floor(avg + 0.5);

	sort(_mid.begin(), _mid.end());
	int mid = _mid[N / 2];

	int mode = 0;
	if (_mode[max - 1].size() > 1)
	{
		sort(_mode[max - 1].begin(), _mode[max - 1].end());
		mode = _mode[max - 1][1];
	}
	else
	{
		mode = _mode[max - 1][0];
	}

	int range = (--_numToCount.end())->first - _numToCount.begin()->first;
	cout << avg << endl;
	cout << mid << endl;
	cout << mode << endl;
	cout << range << endl;
}
