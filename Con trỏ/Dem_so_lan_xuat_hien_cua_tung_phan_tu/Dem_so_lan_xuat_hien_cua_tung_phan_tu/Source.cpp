#include <iostream>
using namespace std;

void Nhap_mang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu thu " << i << " : ";
		cin >> *(a + i);
	}
}

void Xuat_mang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}

void Dem_so_lan_xuat_hien(int* a, int n)
{
	int* b;
	b = new int[n];
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		bool KT = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (*(a + i) == *(a + j))
			{
				KT = false;
				break;
			}
		}
		if (KT == true)
		{
			*(b + m) = *(a + i);
			m++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (*(b + i) == *(a + j))
			{
				dem++;
			}
		}
		cout << " Phan tu " << *(b + i) << " xuat hien " << dem << " lan " << endl;
	}
	delete[] b;
}

int main()
{
	int* a;
	int n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	a = new int[n];
	Nhap_mang(a, n);
	cout << "\n\n";
	Xuat_mang(a, n);
	cout << "\n\n";
	Dem_so_lan_xuat_hien(a, n);
	delete[] a;

	return 0;
}