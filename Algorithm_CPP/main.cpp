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
	// 이미 방문한 곳이면 pass
	if (_visitedOrder[here] != -1)
		return;

	// 몇 번째로 방문한 곳인지를 기입
	cout << here << "는(은) " << _visitedCount + 1 << "번째" << endl;
	_visitedOrder[here] = _visitedCount++;

	auto findIt = _history.find(here);
	if (findIt == _history.end())
	{
		// 연결된 노드들이 없다.
		_finished[here] = true;
		return;
	}

	// 연결된 노드가 있다.
	set<int>& next = findIt->second;
	for (int there : next)
	{
		if (_visitedOrder[there] == -1)
		{
			// 연결된 노드를 아직 방문한 적이 없다
			// 연결된 노드의 부모를 현재 위치로 설정 (추적용)
			_parent[there] = here;
			DFS(there);
			continue;
		}

		// 순방향 간선인 상황 (방문 순번으로 판단)
		if (_visitedOrder[here] < _visitedOrder[there])
			continue;

		// 역방향 간선
		if (_finished[there] == false) 
		{
			// DFS가 아직 끝나지 않은 상황 
			// 만약 _finished[there]이 true라면 교차간선임
			cout << "Cycle Detected!!" << endl;
			cout << here << " -> " << there << endl;

			int now = here;
			while (now != there)
			{
				// 부모를 추적해서 어떻게 사이클이 형성되었는지 출력
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
