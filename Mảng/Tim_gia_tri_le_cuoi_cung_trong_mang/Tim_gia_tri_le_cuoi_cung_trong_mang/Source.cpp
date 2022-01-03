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

int Gia_tri_le_cuoi_cung(int a[], int n)
{
	for (int i = n - 1; i < n; i--)
	{
		if (a[i] % 2 != 0)
			return a[i];
	}
	return 0;
}

int main()
{
	int a[100], n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	cout << Gia_tri_le_cuoi_cung(a, n) << endl;

	return 0;
}