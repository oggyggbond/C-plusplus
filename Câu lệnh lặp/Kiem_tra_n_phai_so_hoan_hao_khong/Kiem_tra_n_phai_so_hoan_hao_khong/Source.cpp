#include <iostream>
using namespace std;
int main()
{
	int n,s = 0;
	cout << " Nhap n: ";
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			s = s + i;
		}
	}
	if (s == n)
	{
		cout << n << " la so hoan hao " << endl;
	}
	else
		cout << n << " khong phai so hoan hao " << endl;

	return 0;
}