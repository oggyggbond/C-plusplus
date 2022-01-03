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

void Phan_tu_xuat_hien_nhieu_nhat(int a[], int n)
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
	int c[100], l = 0;
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
		c[l] = dem;
		l++;
	}
	int max = c[0];
	for (int i = 1; i < l; i++)
	{
		if (max < c[i])
		{
			max = c[i];
		}
	}
	for (int i = 0; i < l; i++)
	{
		if (max == c[i])
		{
			cout << b[i] << " ";
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
	cout << " Phan tu xuat hien nhieu nhat la: " << endl;
	Phan_tu_xuat_hien_nhieu_nhat(a, n);
	
	return 0;
}
