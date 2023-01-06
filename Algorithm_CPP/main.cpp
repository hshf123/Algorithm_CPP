#include <iostream>
//using namespace std;
#define endl "\n"
using int64 = long long;

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <list>

//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	LeafC* leafC = new LeafC();
//	leafC->number = 100;
//	leafC->number2 = 100;
//	delete leafC;
//	leafC->number = 200;
//}

#include <windows.h>
using int64 = long long;
const __int16 PAGE_SIZE = 0x1000; // 4096

class LeafCParent
{
public:
	int parentNumber = 20;
};

class LeafC : public LeafCParent
{
public:
	int number = 10;
};

void* Alloc(int size)
{
	const int64 pageCount = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	void* ptr = ::VirtualAlloc(NULL, pageCount * PAGE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	ptr = static_cast<__int8*>(ptr) + (pageCount * PAGE_SIZE - size);
	return static_cast<void*>(ptr);
}

template<typename Type, typename... Args>
Type* x_new(Args&&... args)
{
	Type* memory = static_cast<Type*>(Alloc(sizeof(Type)));
	new(memory)Type(std::forward<Args>(args)...);
	return memory;
}

int main()
{
	LeafC* leafC = x_new<LeafC>();
}