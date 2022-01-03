#include <iostream>
#include <cmath>
using namespace std;

void Nhap_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap so phan tu a[" << i << "] = ";
		cin >> a[i];
	}
}
void Xuat_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
bool Kiem_tra_so_Amstrong(int n)
{
	int k = log10((double)n) + 1;
	int s = 0, tmp = n;
	for (int i = 0; n != 0; i++)
	{
		int x = n % 10;
		s = s + pow(x, k);
		n = n / 10;
	}
	if (tmp == s)
		return true;
	else
		return false;
}
void Xuat_cac_phan_tu_la_so_Amstrong(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_Amstrong(a[i]) == true)
			cout << a[i] << " ";
	}	
}

int main()
{
	int a[100], n;
	cout << " Nhap n: ";
	cin >> n;
	Nhap_mang(a, n);
	Xuat_mang(a, n);
	cout << " \n\n ";
	Xuat_cac_phan_tu_la_so_Amstrong(a, n);

	return 0;
}