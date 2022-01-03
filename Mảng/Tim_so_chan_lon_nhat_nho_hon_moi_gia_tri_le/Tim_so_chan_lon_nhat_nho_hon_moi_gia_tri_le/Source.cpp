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

int Tim_so_chan_nho_hon_so_le(int a[], int n)
{
	int minle = 10000, maxchan = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0 && minle > a[i])
		{
			minle = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && minle > a[i] && maxchan < a[i])
		{
			maxchan = a[i];
		}
	}
	return maxchan;
}

int main()
{
	int a[100], n;
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	Xuat_mang(a, n);
	cout << "\n\n";
	cout << Tim_so_chan_nho_hon_so_le(a, n) << endl;

	return 0;
}
