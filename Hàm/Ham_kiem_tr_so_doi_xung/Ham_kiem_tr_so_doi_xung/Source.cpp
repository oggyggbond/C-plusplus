#include <iostream>
using namespace std;

bool Kiem_tra_so_dx(int n)
{
	int tmp = n, y = 0, x;
	while (tmp > 0)
	{
		x = tmp % 10;
		y = y * 10 + x;
		tmp = tmp / 10;
	}
	if (y == n)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	if (Kiem_tra_so_dx(n) == true)
	{
		cout << n << " la so doi xung " << endl;
	}
	else
		cout << n << " khong phai so doi xung " << endl;

	return 0;
}