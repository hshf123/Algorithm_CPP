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

struct Student
{
	int idx = 0;
	char team;
	int atk = 0;

	bool operator<(const Student& other) const
	{
		return atk < other.atk;
	}
};

int N;
vector<Student> vec;
vector<int> vec2;

int main()
{
	Init;

	cin >> N;
	vec.resize(N);
	vec2.resize(N, 0);
	for (int i = 0; i < N; i++)
	{
		Student s;
		s.idx = i;
		cin >> s.team >> s.atk;
		vec[i] = s;
	}
	sort(vec.begin(), vec.end());

	unordered_map<char, int> m;
	unordered_set<char> s;

	for (int i = 0; i < N; i++)
	{
		int end = i;
		for(int j = i + 1; j < N; j++)
		{
			if (vec[i].atk != vec[j].atk)
				break;
			end = j;
		}

		for (int j = i; j <= end; j++)
		{
			for(const auto& p : m)
			{
				if (p.first != vec[j].team)
					vec2[vec[j].idx] += p.second;
			}
		}

		for (int j = i; j <= end; j++)
		{
			m[vec[j].team] += vec[j].atk;
		}

		i = end;
	}

	for (const int& n : vec2)
	{
		cout << n << endl;
	}
	
	return 0;
}