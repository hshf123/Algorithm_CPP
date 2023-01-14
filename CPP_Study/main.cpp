#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// �� ���� �Լ� R(reverse) : ���� ������ , D(delete) : ù ��° ���� ����

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string p; // �Լ�
		cin >> p;
		int n; // �迭 ����
		cin >> n;
		string arr; // �迭
		cin >> arr;
		bool reverse = false; // ������� �ϴ°Ÿ� true
		bool isError = false; // �����ΰ��
		deque<int> array;
		string number = "";
		for (int i = 1; i < arr.length(); i++)
		{
			char c = arr[i];
			if (c == ',' || c == ']')
			{
				if(number != "")
					array.push_back(stoi(number));
				number = "";
				continue;
			}

			number += c;
		}

		for (int i = 0; i < p.length(); i++)
		{
			char c = p[i];
			if (c == 'R')
				reverse = !reverse;
			else
			{
				if (array.empty())
				{
					isError = true;
					break;
				}

				if (reverse)
					array.pop_back();
				else
					array.pop_front();
			}
		}

		if (isError)
			cout << "error" << endl;
		else
		{
			string str;
			str += '[';
			if (reverse)
			{
				while (array.empty() == false)
				{
					int n = array.back();
					array.pop_back();
					str += to_string(n);
					if (array.empty() == false)
						str += ',';
				}
			}
			else
			{
				while (array.empty() == false)
				{
					int n = array.front();
					array.pop_front();
					str += to_string(n);
					if (array.empty() == false)
						str += ',';
				}
			}
			str += ']';
			cout << str << endl;
		}
	}


	return 0;
}

