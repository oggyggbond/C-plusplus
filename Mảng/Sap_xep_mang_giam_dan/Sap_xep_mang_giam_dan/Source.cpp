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

void Hoan_vi(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void Sap_xep_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
				Hoan_vi(a[i], a[j]);
		}
	}
}

int main()
{
	int a[100], n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	Sap_xep_mang(a, n);
	cout << " Mang sau khi sap xep la: " << endl;
	Xuat_mang(a, n);

	return 0;
}