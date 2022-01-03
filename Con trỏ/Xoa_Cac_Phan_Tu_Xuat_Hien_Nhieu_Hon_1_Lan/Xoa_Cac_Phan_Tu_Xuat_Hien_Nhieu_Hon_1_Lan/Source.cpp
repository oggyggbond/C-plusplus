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

void Xoa(int* a, int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		*(a + i - 1) = *(a + i);
	}
	n--;
}

void Xoa_Cac_Phan_Tu_Xuat_Hien_Nhieu_Hon_1_Lan(int* a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) == *(a + j))
			{
				Xoa(a, n, j);
				j--;
				dem = 1;
			}
		}
		if (dem == 1)
		{
			Xoa(a, n, i);
			i--;
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
	Xoa_Cac_Phan_Tu_Xuat_Hien_Nhieu_Hon_1_Lan(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}