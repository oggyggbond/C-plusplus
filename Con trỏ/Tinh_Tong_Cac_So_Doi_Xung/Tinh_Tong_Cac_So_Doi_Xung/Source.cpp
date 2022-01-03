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

bool Kiem_tra_so_doi_xung(int n)
{
	int  tmp = n, y = 0;
	while (tmp != 0)
	{
		int x = tmp % 10;
		y = y * 10 + x;
		tmp = tmp / 10;
	}
	if (y == n)
	{
		return true;
	}
	else
		return false;
}

int Tinh_tong_cac_so_doi_xung(int* a, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_doi_xung(*(a + i)) == true)
		{
			s = s + *(a + i);
		}
	}
	return s;
}

int main()
{
	int* a;
	int n;
	cout << " Nhap so phan tu n: ";
	cin >> n;
	a = new int[n];
	Nhap_mang(a, n);
	cout << "\n\n";
	Xuat_mang(a, n);
	cout << "\n\n";
	cout << " Tong cac so doi xung la: " << Tinh_tong_cac_so_doi_xung(a, n) << endl;
	delete[] a;

	return 0;
}