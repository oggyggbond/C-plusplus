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

void Xoa(int a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++) // i = vt; i < n-1;
	{
		a[i - 1] = a[i]; // a[i] = a[i+1];
	}
	n--;
}

int main()
{
	int a[100], n, vt;
	cout << " Nhap so phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	cout << " Nhap vi tri muon xoa: " << endl;
	cin >> vt;
	Xoa(a, n, vt);
	cout << endl;
	Xuat_mang(a, n);

	return 0;
} 