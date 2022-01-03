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

void Xuat_Cac_Phan_Tu_La_So_Chan(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) % 2 == 0)
		{
			cout << *(a + i) << " ";
		}
	}
}

void Hoan_vi(int& x, int& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

void Sap_Xep_Cac_Phan_Tu_Giam_Dan(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) < *(a + j))
			{
				Hoan_vi(*(a + i), *(a + j));
			}
		}
	}
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
	Xuat_Cac_Phan_Tu_La_So_Chan(a, n);
	cout << "\n\n";
	Sap_Xep_Cac_Phan_Tu_Giam_Dan(a, n);
	Xuat_mang(a, n);
	cout << endl;
	delete[] a;

	return 0;
}