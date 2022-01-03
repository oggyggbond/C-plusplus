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

int Tim_UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}

int Tim_UCLN_Cua_Cac_Phan_Tu_Trong_Mang(int* a, int n)
{
	int UCLN = *a;
	for (int i = 1; i < n; i++)
	{
		UCLN = Tim_UCLN(UCLN, *(a + i));
	}
	return UCLN;
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
	cout << " UCLN la: " << Tim_UCLN_Cua_Cac_Phan_Tu_Trong_Mang(a, n) << endl;
	delete[] a;

	return 0;
}