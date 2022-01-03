#include <iostream>
#include <cmath>
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

bool Kiem_tra_so_nguyen_to(int n)
{
	if (n < 2)
		return false;
	else
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return false;
		}
	return true;
}

void Hoan_vi(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void Sap_xep_so_nguyen_to_tang_dan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_nguyen_to(a[i]) == true)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (Kiem_tra_so_nguyen_to(a[j]) == true && a[i] > a[j])
					Hoan_vi(a[i], a[j]);
			}
		}
	}
}

int main()
{
	int a[100], n;
	cout << " Nhap phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	Sap_xep_so_nguyen_to_tang_dan(a, n);
	cout << endl;
	Xuat_mang(a, n);

	return 0;
}