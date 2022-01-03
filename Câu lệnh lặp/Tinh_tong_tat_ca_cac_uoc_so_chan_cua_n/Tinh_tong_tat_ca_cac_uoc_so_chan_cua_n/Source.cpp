#include <iostream>
using namespace std;
int main()
{
	int n,s = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && i % 2 == 0)
		{
			s = s + i;
		}
	}
	cout << " Tong cac uoc chan la s = " << s << endl;

	return 0;
} 