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

int Gia_tri_lon_nhat(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}

void Xoa(int a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}

void Xoa_GTLN(int a[], int &n)
{
	int max = Gia_tri_lon_nhat(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
		{
			Xoa(a, n, i);
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
	Xoa_GTLN(a, n);
	cout << endl;
	Xuat_mang(a, n);

	return 0;
}