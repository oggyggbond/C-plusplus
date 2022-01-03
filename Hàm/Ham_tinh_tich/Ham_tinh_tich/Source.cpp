#include <iostream>
using namespace std;

int Tinh_tich(int n)
{
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		s = s * i;
	}

	return s;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	cout << " Tich la s= " << Tinh_tich(n) << endl;

	return 0;
}