#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	vector<int> origin = vec;
	sort(vec.begin(), vec.end());
	
	int curr = 0;
	int i = 0;
	stack<int> stack;
	vector<string> ans;

	while (curr != N)
	{
		if (stack.empty() == false)
		{
			int top = stack.top();
			if (origin[curr] <= top)
			{
				stack.pop();
				ans.push_back("-");
				curr++;
				continue;
			}
		}

		if (i >= N)
		{
			ans.clear();
			ans.push_back("NO");
			break;
		}
		
		if (origin[curr] != vec[i])
		{
			ans.push_back("+");
			stack.push(vec[i]);
		}
		else
		{
			stack.push(vec[i]);
			ans.push_back("+");
			stack.pop();
			ans.push_back("-");
			curr++;
		}
		i++;
	}

	for (string str : ans)
	{
		cout << str << "\n";
	}
}