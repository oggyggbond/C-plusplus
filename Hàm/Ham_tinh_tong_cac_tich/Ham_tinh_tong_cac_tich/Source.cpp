#include <iostream>
using namespace std;

int Tinh_tong_cac_tich(int n)
{
	int s = 0, tich = 1;
	for (int i = 1; i <= n; i++)
	{
		tich = tich * i;
		s = s + tich;
	}
	return s;
}

int main()
{
	int n;
	cout << " Nhap n: ";
	cin >> n;
	cout << " Tong la s = " << Tinh_tong_cac_tich(n) << endl;

	return 0;
} 