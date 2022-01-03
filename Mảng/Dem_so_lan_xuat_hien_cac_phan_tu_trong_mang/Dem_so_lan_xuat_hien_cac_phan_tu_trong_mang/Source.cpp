#include <iostream>
using namespace std;
#define max 100
int dem[max];

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
	for (int i = 0; i < max; i++)
	{
		dem[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		dem[a[i]]++;
	}
	for (int i = 0; i < max; i++)
	{
		if (dem[i] > 0)
		{
			cout << " Gia tri " << i << " xuat hien " << dem[i] << " lan " << endl;
		}
	}
}

int main()
{
	int a[max], n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	Dem_so_lan_xuat_hien(a, n);

	return 0;
}