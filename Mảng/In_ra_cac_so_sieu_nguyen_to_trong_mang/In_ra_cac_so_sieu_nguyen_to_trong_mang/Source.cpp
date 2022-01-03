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

bool Kiem_tra_so_sieu_nguyen_to(int n)
{
	if (n < 2)
		return false;
	else
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return false;
			else
				while (n != 0)
				{
					int x = n / 10;
					for (int j = 2; j <= sqrt(x); j++)
					{
						if (x % j == 0)
							return false;
						else
							return true;
					}
				}
		}
}

void Xuat_cac_so_sieu_nguyen_to_trong_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_tra_so_sieu_nguyen_to(a[i]) == true)
		{
			cout << a[i] << endl;
		}
	}
}

int main()
{
	int n, a[100];
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << "\n";
	Xuat_mang(a, n);
	cout << "\n\n";
	Xuat_cac_so_sieu_nguyen_to_trong_mang(a, n);
	cout << "\n";
	return 0;
}