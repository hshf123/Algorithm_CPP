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
���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.
������� ���� ��ų ������ (����ũ -> ����Ʈ�׺�Ʈ -> ���) �� ��,
����� ������ ���� ����Ʈ�� ��Ʈ�� ������ϰ�, ����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.

�� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�. ���� (����ũ -> ���� -> ����Ʈ�׺�Ʈ -> ���)��
���� ��ųƮ���� ����������, (��� -> ����ũ)�� (����Ʈ�׺�Ʈ -> ����ũ -> ���� -> ���) �� ���� ��ųƮ���� �Ұ����մϴ�.

���� ��ų ���� skill�� �������� ���� ��ųƮ���� ���� �迭 skill_trees�� �Ű������� �־��� ��, ������ ��ųƮ�� ������ return�ϴ� ���α׷��� �ۼ����ּ���.

--------------------------------
			��������
--------------------------------
��ų�� ���ĺ� �빮�ڷ� ǥ���ϸ�, ��� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
��ų ������ ��ųƮ���� ���ڿ��� ǥ���մϴ�. - ������� (C -> B -> D)��� "CBD"�� ǥ���մϴ�.
���� ��ų ���� skill�� ���̴� 1�̻� 26�����̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
skill_trees�� ���� 1�̻� 20������ �迭�Դϴ�.
skill_trees�� ���Ҵ� ��ų�� ��Ÿ���� ���ڿ��Դϴ�.
skill_trees�� ���Ҵ� ���̰� 2�̻� 26������ ���ڿ��̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
*/


int main()
{
	Init;

	// �Է� ���� Ans)2
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