#include <iostream>
using namespace std;
#define endl "\n"

#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

mutex m;

bool IsPrime(int number)
{
	if (number <= 1)
		return false;
	if (number == 2 || number == 3)
		return true;

	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int MAX_NUMBER = 100'0000;
	atomic<int> num = 0;
	atomic<int> primeCount = 0;

	vector<thread> threads;
	int coreCount = thread::hardware_concurrency();
	for (int i = 0; i < coreCount; i++)
		threads.push_back(thread([&num, &primeCount]()
			{
				while (num <= MAX_NUMBER)
					if (IsPrime(num++))
						primeCount++;
			}));

	for (int i = 0; i < coreCount; i++)
		threads[i].join();

	cout << primeCount << endl;
}
