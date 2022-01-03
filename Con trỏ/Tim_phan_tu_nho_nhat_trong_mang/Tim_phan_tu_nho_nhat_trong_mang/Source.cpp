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

int Tim_phan_tu_nho_nhat(int* a, int n)
{
	int min = *(a);
	for (int i = 0; i < n; i++)
	{
		if (*(a + i) < min)
		{
			min = *(a + i);
		}
	}
	return min;
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
	cout << " Phan tu nho nhat trong mang la: " << Tim_phan_tu_nho_nhat(a, n) << endl;

	delete[] a;

	return 0;
}