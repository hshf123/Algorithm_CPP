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

string Solution(string::iterator& it)
{
	char head = *it;
	++it;	// 여기서 이터레이터 증가시켜주니까 밑에 Solution 4번 호출될 때는 항상 다음걸 가리키게됨

	// 분할 필요 없이 바로 리턴
	if (head == 'b' || head == 'w')
		return string(1, head);

	// x라는 소리니까 분할, 압축순서대로 문자열 얻고 위와 아래를 뒤집으면 된다!
	string left_up = Solution(it);
	string right_up = Solution(it);
	string left_down = Solution(it);
	string right_down = Solution(it);
	return "x" + left_down + right_down + left_up + right_up;
}

int main()
{
	Init;

	int C;
	cin >> C;
	vector<string> ansList(C);
	for (int c = 0; c < C; c++)
	{
		string str;
		cin >> str;
		string::iterator it = str.begin();
		ansList[c] = Solution(it);
	}
	
	for (const string& ans : ansList)
		cout << ans << endl;
	
	return 0;
}