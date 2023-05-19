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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

template<class T>
class Vector
{
public:
	void reserve(int capacity)
	{
		if (_capacity > capacity)
			return;

		T* array = new T[capacity];
		for (int i = 0; i < _size; i++)
		{
			array[i] = _array[i];
		}
		_array = array;
		_capacity = capacity;
	}
	void resize(int size)
	{
		reserve(size);
		for (int i = _size; i < size; i++)
		{
			_array[i] = T();
		}
		_size = size;
	}
	void push_back(T data)
	{
		if (_size >= _capacity)
		{
			if (_size == _size * 1.5)
				_capacity++;
			else
				_capacity *= 1.5;

			reserve(_capacity);
		}

		_array[_size++] = data;
	}

public:
	int size() { return _size; }
	int capacity() { return _capacity; }
	T back() { return _array[_size - 1]; }
	T& operator[](int idx) { return *(_array + idx); }

private:
	T* _array;
	int _size = 0;
	int _capacity = 0;
};

int main()
{
	Vector<int> vec;
	cout << "1" << endl;
	vec.push_back(1);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << endl;
	cout << "2" << endl;
	vec.reserve(3);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << endl;
	cout << "3" << endl;
	vec.resize(5);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << endl;
	cout << vec[0] << endl;
	vec[0] = 3;
	cout << vec[0] << endl;


	return 0;
}