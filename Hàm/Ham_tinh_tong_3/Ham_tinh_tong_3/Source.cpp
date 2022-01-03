#include <iostream>
using namespace std;

int Tinh_tong(int n)
{
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s = s + i * i;
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