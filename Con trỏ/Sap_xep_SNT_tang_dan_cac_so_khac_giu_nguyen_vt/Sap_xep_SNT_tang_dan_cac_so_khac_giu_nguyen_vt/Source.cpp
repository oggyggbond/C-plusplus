#include <iostream>
#include <cmath>
using namespace std;

void Nhap_mang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap so phan tu thu " << i << " : ";
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

void Hoan_vi(int& x, int& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

bool Kiem_tra_so_nguyen_to(int n)
{
	if (n < 2)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void Sap_xep_SNT_tang_dan(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_nguyen_to(*(a + i)) == true)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((Kiem_tra_so_nguyen_to(*(a + j)) == true) && (*(a + i) > *(a + j)))
				{
					Hoan_vi(*(a + i), *(a + j));
				}
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
	Sap_xep_SNT_tang_dan(a, n);
	cout << " Sap xep tang dan cac phan tu la so nguyen to, cac phan tu khac giu nguyen vt: " << "\n\n";
	Xuat_mang(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}