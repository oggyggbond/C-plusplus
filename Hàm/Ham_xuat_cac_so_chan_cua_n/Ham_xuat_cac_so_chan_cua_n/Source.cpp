#include <iostream>
using namespace std;

void Xuat_so_chan(int n)
{
	for (int i = 1; i <= n; i++)
	{
		int x = n % 10;
		if (x % 2 == 0)
			cout << x << endl;
		n = n / 10;
	}
}
int main()
{
	int n;
	do
	{
		cout << " Nhap n > 0: ";
		cin >> n;
		if (n <= 0)
			cout << " Khong hop le! Nhap lai! " << endl;
	} while (n <= 0);
	cout << " Cac so chan trong n la: " << endl;
	Xuat_so_chan(n);

	return 0;
}
