#include <iostream>
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
void In_phan_tu_chan_ke_nhau(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && (a[i + 1] % 2 == 0 || a[i-1] % 2 == 0))
			cout << a[i] << " ";
	}
}

int main()
{
	int a[100], n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	In_phan_tu_chan_ke_nhau(a, n);

	return 0;
}