#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	float i;

	if (str[0] == 'A')
		i = 4;
	else if (str[0] == 'B')
		i = 3;
	else if (str[0] == 'C')
		i = 2;
	else if (str[0] == 'D')
		i = 1;
	else
	{
		cout << fixed;
		cout.precision(1); 
		cout << 0.0;
		return 0;
	}

	if (str[1] == '+')
		i += 0.3f;
	else if(str[1] == '-')
		i -= 0.3f;
	cout << fixed;
	cout.precision(1);
	cout << i;

	return 0;
}
