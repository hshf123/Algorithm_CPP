#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

int main()
{
	time_t timer;
	timer = time(NULL);

	struct tm* t = localtime(&timer);

	std::cout << t->tm_year + 1900 << "-";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << t->tm_mon + 1 << "-";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << t->tm_mday;
}
