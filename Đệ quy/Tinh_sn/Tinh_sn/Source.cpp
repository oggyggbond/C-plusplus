#include <iostream>
using namespace std;

float Tinh_Sn(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return Tinh_Sn(n - 1) + 1.0 / (2 * n + 1);
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << Tinh_Sn(n);

	return 0;
}