#include <iostream>
using namespace std;

void Nhap_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu a[" << i << "] = ";
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

int Tim_UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}

int Tim_UCLN_cac_phan_tu_trong_mang(int a[], int n)
{
	int UCLN = a[0];
	for (int i = 1; i < n; i++)
	{
		UCLN = Tim_UCLN(UCLN, a[i]);
	}
	return UCLN;
}

int main()
{
	int a[100], n;
	cout << " Nhap so phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	cout << " UCLN cac phan tu trong mang la: " << Tim_UCLN_cac_phan_tu_trong_mang(a, n) << endl;

	return 0;
}