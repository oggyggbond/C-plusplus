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

void Them(int a[], int &n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];
	}
	a[vt] = x;
	n++;
}

bool Kiem_tra_mang_doi_xung(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] == a[n - i - 1])
		{
			return true;
			break;
		}
	}
	return false;
}

void Them_it_phan_tu_nhat_de_duoc_mang_doi_xung(int a[], int &n)
{
	int z = n;
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_mang_doi_xung(a, n) == false)
		{
			Them(a, n, z, a[i]);
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
	Them_it_phan_tu_nhat_de_duoc_mang_doi_xung(a, n);
	Xuat_mang(a, n);
	cout << endl;

	return 0;
}