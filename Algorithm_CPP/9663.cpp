//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N;
//vector<int> pos;
//vector<bool> flag_a;
//vector<bool> flag_b;
//vector<bool> flag_c;
//int c = 0;
//
//void Set(int i)
//{
//	for (int j = 0; j < N; j++)
//	{
//		if ((flag_a[j] == false) && (flag_b[i + j] == false) && (flag_c[i - j + 7] == false))
//		{
//			pos[i] = j;
//			if (i == N - 1)
//			{
//				c++;
//			}
//			else
//			{
//				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = true;
//				Set(i + 1);
//				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = false;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> N;
//	pos.assign(N, 0);
//	flag_a.assign(N, false);
//	flag_b.assign(N * 2 - 1, false);
//	flag_c.assign(N * 2 - 1, false);
//	Set(0);
//	cout << c;
//}