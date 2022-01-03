#include <iostream>
using namespace std;

int Tinh_Fn(int n)
{
	if (n == 0 || n == 1)
		return 1;
	if (n == 2)
		return 2;
	return Tinh_Fn(n - 1) + Tinh_Fn(n - 2);
}

int main()
{
	int n;
	do 
	{
		cout << " Nhap n: ";
		cin >> n;
		if (n < 0)
		{
			cout << " Nhap n >= 0! " << endl;
		}
	} while (n < 0);
	cout << " Tong Fn = " << Tinh_Fn(n) << endl;

	return 0;
}