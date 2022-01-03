#include<iostream>
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

void Them(int a[], int& n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--) // i = n
	{
		a[i + 1] = a[i]; // a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}

int main()
{
	int a[100], n, x, vt;
	cout << " Nhap so phan tu n: ";
	cin >> n;
	Nhap_mang(a, n);
	cout << endl;
	Xuat_mang(a, n);
	cout << endl;
	cout << " Nhap phan tu muon them: " << endl;
	cin >> x;
	cout << " Nhap vi tri muon them: " << endl;
	cin >> vt;
	Them(a, n, vt, x);
	cout << endl;
	Xuat_mang(a, n);

	return 0;
}