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

void Xoa(int*& a, int &n, int vt)
{
	for (int i = vt + 1; i < n; i++)
	{
		*(a + i - 1) = *(a + i);
	}
	n--;
	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(b + i) = *(a + i);
	}
	delete[] a;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(b + i);
	}
	delete[] b;
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
	int vt;
	cout << " Nhap vi tri muon xoa: " << endl;
	cin >> vt;
	Xoa(a, n, vt);
	Xuat_mang(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}