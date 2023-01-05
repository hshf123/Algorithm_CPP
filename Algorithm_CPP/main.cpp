#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	multimap<int, string> mm;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		
		mm.insert(make_pair(age, name));
	}

	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}
