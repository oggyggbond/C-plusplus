#include <iostream>
#include <cmath>
using namespace std;

void Xuat(int* pa, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(pa + i) << " ";
	}
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

void Hoan_vi(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Sap_xep_tang_dan(int* pa, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(pa + i) > * (pa + j))
			{
				Hoan_vi((pa + i), (pa + j));
			}
		}
	}
}
void Xoa(int* pa, int& n, int vt)
{
	for (int i = vt; i < n; i++)
	{
		*(pa + i) = *(pa + i + 1);
	}
	n--;
}

void Xoa_cac_phan_tu_la_so_chinh_phuong(int* pa, int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (sqrt(* (pa + i)) * sqrt(* (pa + i)) == *(pa + i))
		{
			Xoa(pa, n, i);
		}
	}
}

int main()
{
	int a[] = { 2,4,15,6,8,9,10,3,25,12 };
	int n = sizeof(a) / sizeof(a[0]);
	int* pa = &a[0];
	cout << " Cac phan tu trong mang la: ";
	for (int i = 0; i < n; i++)
	{
		cout << *pa << " ";
		pa++;
	}
	cout << "\n\n";

	pa--;
	cout << " Cac phan tu le trong mang la: ";
	for (int i = 0; i < n; i++)
	{
		if (*pa % 2 != 0)
		{
			cout << *pa << " ";
		}
		pa--;	
	}
	cout << "\n\n";

	pa++;
	cout << " Cac phan tu la so doi xung trong mang: ";
	for (int i = 0; i < n; i++)
	{
		int y = 0, tmp = *pa;
		while (tmp > 0)
		{
			int x = tmp % 10;
			 y = y * 10 + x;
			tmp = tmp / 10;
		}
		if (y == *pa)
		{
			cout << y << " ";
		}
		pa++;
	}
	cout << "\n\n";

	pa--;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_nguyen_to(*pa) == true)
		{
			s = s + (*pa);
		}
		pa--;
	}
	cout << " Tong cac so nguyen to trong mang la: " << s;
	cout << "\n\n";
	pa++;
	Sap_xep_tang_dan(pa,n);
	cout << " Sap xep cac phan tu tang dan: ";
	Xuat(pa, n);
	cout << "\n\n";
	
	Xoa_cac_phan_tu_la_so_chinh_phuong(pa, n);
	Xuat(pa,n);
	
	return 0;
}