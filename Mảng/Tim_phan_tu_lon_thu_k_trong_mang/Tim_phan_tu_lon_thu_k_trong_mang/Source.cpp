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

int Phan_tu_lon_thu_k(int a[], int n, int k)
{
	int tmp = 0, vt = -1;
	if (k <= n && k > 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] < a[j])
				{
					Hoan_vi(a[i], a[j]);
				}
			}
			if (a[i] < a[tmp])
			{
				k--; 
				tmp = i;
			}
			if (k == 1)
			{
				vt = i;
				break;
			}
		}
	}
	return a[vt];
}

int main()
{
	int a[100], n,k;
	cout << " Nhap so phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	cout << " Nhap phan tu lon thu: " << endl;
	cin >> k;
	cout << " Phan tu lon thu " << k << " la: " << endl;
	cout << Phan_tu_lon_thu_k(a, n,k);

	return 0;
}