#include <iostream>
using namespace std;

int Tinh_tong(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return Tinh_tong(n - 1) + n;
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << Tinh_tong(n);

	return 0;
}