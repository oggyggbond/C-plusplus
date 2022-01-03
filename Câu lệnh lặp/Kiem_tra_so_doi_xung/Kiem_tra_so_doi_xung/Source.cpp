#include <iostream>
using namespace std;

int main()
{
	int n, x, tmp, y = 0;
	do
	{
		cout << " Nhap n: ";
		cin >> n;
		if (n <= 0)
		{
			cout << " n phai lon hon 0! Nhap lai! " << endl;
		}
	} while (n <= 0);

	tmp = n;
	while (tmp > 0)
	{
		x = tmp % 10;
		y = y * 10 + x;
		tmp = tmp / 10;
	}
	if (y == n)
	{
		cout << n << " la so doi xung " << endl;
	}
	else
		cout << n << " khong phai so doi xung " << endl;

	return 0;
}