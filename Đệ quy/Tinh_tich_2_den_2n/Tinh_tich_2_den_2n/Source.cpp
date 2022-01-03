#include <iostream>
using namespace std;

int Tinh_tich(int n)
{
	if (n == 1)
	{
		return 2;
	}
	return Tinh_tich(n-1)*(2*n);
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << Tinh_tich(n);

	return 0;
}