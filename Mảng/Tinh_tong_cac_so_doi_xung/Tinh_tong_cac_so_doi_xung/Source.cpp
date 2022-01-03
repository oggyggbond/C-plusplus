#include <iostream>
using namespace std;

void Nhap_mang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu A[" << i << "] = ";
		cin >> A[i];
	}
}
void Xuat_mang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}
bool Kiem_tra_so_dx(int n)
{
	int tmp = n, y = 0, x;
	while (tmp > 0)
	{
		x = tmp % 10;
		y = y * 10 + x;
		tmp = tmp / 10;
	}
	if (y == n)
		return true;
	else
		return false;
}
int Tinh_tong_cac_so_dx(int A[], int n)
{
	int s = 0;
		for (int i = 0; i < n; i++)
		{
			if (Kiem_tra_so_dx(A[i]) == true)
			{
				s = s + A[i];
			}
		}
		return s;
}

int main()
{
	int n, A[100];
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(A, n);
	Xuat_mang(A, n);
	cout << "\n\n";
	cout << " Tong cac so doi xung la: " << Tinh_tong_cac_so_dx(A, n) << endl;

	return 0;
}
