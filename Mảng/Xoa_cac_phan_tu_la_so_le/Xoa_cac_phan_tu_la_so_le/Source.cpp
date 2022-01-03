#include <iostream>
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

void Xoa(int a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

void Xoa_cac_phan_tu_la_so_le(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			Xoa(a, n,i);
			i--;
		}
	}
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
	Xoa_cac_phan_tu_la_so_le(a, n);
	Xuat_mang(a, n);
	cout << endl;

	return 0;
}