#include <iostream>
#include <cmath>
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

void Xuat_Cac_Phan_Tu_La_So_Nguyen_To(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_nguyen_to(*(a + i)) == true)
		{
			cout << *(a + i) << " ";
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
	Xuat_Cac_Phan_Tu_La_So_Nguyen_To(a, n);
	cout << endl;
	delete[] a;

	return 0;
}