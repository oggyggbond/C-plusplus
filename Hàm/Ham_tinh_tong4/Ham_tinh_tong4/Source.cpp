#include <iostream>
using namespace std;

float Tinh_tong(int n)
{
	float s = 0;
	for (int i = 0; i <= n; i++)
	{
		s = s + (1.0 ) / ((2 * i) + 1);
	}
	return s;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	cout << " Tong la s = " << Tinh_tong(n) << endl;

	return 0;
}