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

int Tim_GTLN(int* a, int n)
{
	int max = *a;
	for (int i = 1; i < n; i++)
	{
		if (*(a + i) > max)
		{
			max = *(a + i);
		}
	}
	return max;
}

void Xoa(int* a, int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		*(a + i - 1) = *(a + i);
	}
	n--;
}

void Xoa_Cac_GTLN_Trong_Mang(int* a, int& n)
{
	int max = Tim_GTLN(a, n);
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) == max)
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
	Xoa_Cac_GTLN_Trong_Mang(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}