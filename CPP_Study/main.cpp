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

/*
선행 스킬이란 어떤 스킬을 배우기 전에 먼저 배워야 하는 스킬을 뜻합니다.
예를들어 선행 스킬 순서가 (스파크 -> 라이트닝볼트 -> 썬더) 일 때,
썬더를 배우려면 먼저 라이트닝 볼트를 배워야하고, 라이트닝 볼트를 배우려면 먼저 스파크를 배워야 합니다.

위 순서에 없는 다른 스킬(힐링 등)은 순서에 상관없이 배울 수 있습니다. 따라서 (스파크 -> 힐링 -> 라이트닝볼트 -> 썬더)와
같은 스킬트리는 가능하지만, (썬더 -> 스파크)나 (라이트닝볼트 -> 스파크 -> 힐링 -> 썬더) 와 같은 스킬트리는 불가능합니다.

선행 스킬 순서 skill과 유저들이 만든 스킬트리를 담은 배열 skill_trees가 매개변수로 주어질 때, 가능한 스킬트리 개수를 return하는 프로그램을 작성해주세요.

--------------------------------
			제한조건
--------------------------------
스킬은 알파벳 대문자로 표기하며, 모든 문자열은 알파벳 대문자로만 이루어져 있습니다.
스킬 순서와 스킬트리는 문자열로 표기합니다. - 예를들어 (C -> B -> D)라면 "CBD"로 표기합니다.
선행 스킬 순서 skill의 길이는 1이상 26이하이며, 스킬은 중복해 주어지지 않습니다.
skill_trees는 길이 1이상 20이하인 배열입니다.
skill_trees의 원소는 스킬을 나타내는 문자열입니다.
skill_trees의 원소는 길이가 2이상 26이하인 문자열이며, 스킬이 중복해 주어지지 않습니다.
*/


int main()
{
	Init;

	// 입력 예제 Ans)2
	string skill = "CBD";
	string skill_trees[] = { "BACDE", "CBADF", "AECB", "BDA" };

	unordered_set<char> skillus;
	vector<char> skillVec;
	for (char c : skill)
	{
		skillus.insert(c);
		skillVec.push_back(c);
	}

	int ans = 0;
	for (string& str : skill_trees)
	{
		string sk = "";
		for (char& c : str)
		{
			auto findIt = skillus.find(c);
			if (findIt != skillus.end())
				sk += c;
		}
		if (sk.empty() || skill == sk || (sk.size() != skill.size() && skill.substr(0, sk.size()) == sk))
			ans++;
	}

	cout << ans;

	return 0;
}