#include <iostream>
using namespace std;
#define endl "\n"

#include <map>
#include <unordered_map>
#include <set>
#include <vector>

vector<vector<int>>			_vec;
map<int, set<int>>			_history;
vector<int>					_visitedOrder;
int							_visitedCount;
vector<bool>				_finished;
vector<int>					_parent;

void DFS(int here)
{
	// �̹� �湮�� ���̸� pass
	if (_visitedOrder[here] != -1)
		return;

	// �� ��°�� �湮�� �������� ����
	cout << here << "��(��) " << _visitedCount + 1 << "��°" << endl;
	_visitedOrder[here] = _visitedCount++;

	auto findIt = _history.find(here);
	if (findIt == _history.end())
	{
		// ����� ������ ����.
		_finished[here] = true;
		return;
	}

	// ����� ��尡 �ִ�.
	set<int>& next = findIt->second;
	for (int there : next)
	{
		if (_visitedOrder[there] == -1)
		{
			// ����� ��带 ���� �湮�� ���� ����
			// ����� ����� �θ� ���� ��ġ�� ���� (������)
			_parent[there] = here;
			DFS(there);
			continue;
		}

		// ������ ������ ��Ȳ (�湮 �������� �Ǵ�)
		if (_visitedOrder[here] < _visitedOrder[there])
			continue;

		// ������ ����
		if (_finished[there] == false) 
		{
			// DFS�� ���� ������ ���� ��Ȳ 
			// ���� _finished[there]�� true��� ����������
			cout << "Cycle Detected!!" << endl;
			cout << here << " -> " << there << endl;

			int now = here;
			while (now != there)
			{
				// �θ� �����ؼ� ��� ����Ŭ�� �����Ǿ����� ���
				cout << _parent[now] << " -> " << now << endl;
				now = _parent[now];
			}
		}
	}
	_finished[here] = true;
}

void Push(int node, int edge)
{
	_vec[node].push_back(edge);
	set<int>& history = _history[node];
	history.insert(edge);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	_visitedOrder = vector<int>(5, -1);
	_visitedCount = 0;
	_finished = vector<bool>(5, false);
	_parent = vector<int>(5, -1);

	_vec.resize(5);
	Push(0, 1);
	Push(0, 2);
	Push(1, 3);
	Push(3, 0);
	Push(4, 2);

	DFS(0);
}
