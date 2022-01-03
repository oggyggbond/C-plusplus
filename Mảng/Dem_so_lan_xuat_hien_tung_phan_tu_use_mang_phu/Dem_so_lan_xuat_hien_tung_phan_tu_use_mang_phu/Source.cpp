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

void Dem_so_lan_xuat_hien(int a[], int n)
{
	int b[100], m = 0;
	for (int i = 0; i < n; i++)
	{
		bool KT = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
			{
				KT = false;
				break;
			}
		}
		if (KT == true)
		{
			b[m] = a[i];
			m++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int dem = 0;

		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j])
			{
				dem++;
			}
		}
		cout << " Phan tu " << b[i] << " xuat hien " << dem << " lan " << endl;
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
	Dem_so_lan_xuat_hien(a, n);
	cout << endl;
	
	return 0;
}