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

void Them(int*& a, int& n, int vt, int x)
{
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(b + i) = *(a + i);
	}
	delete[] a;
	a = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(b + i);
	}
	delete[] b;
	for (int i = n - 1; i >= vt; i--)
	{
		*(a + i + 1) = *(a + i);
	}
	*(a + vt) = x;
	n++;
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
	int x, vt;
	cout << " Nhap vi tri muon them: " << endl;
	cin >> vt;
	cout << " Nhap phan tu muon them: " << endl;
	cin >> x;
	Them(a, n, vt, x);
	Xuat_mang(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}