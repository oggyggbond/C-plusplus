#include <iostream>
#define MAX 100
using namespace std;

void Nhap_mang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Nhap phan tu A[" << i << "] = ";
		cin >> A[i];
	}
}

void Xuat_mang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}

int Tim_phan_tu_nho_nhat(int A[], int n)
{
	int min = A[0];
	for (int i = 0; i < n; i++)
	{
		if (min > A[i])
			min = A[i];
	}
	return min;
}

int main()
{
	int n, A[MAX];
	cout << " Nhap so luong phan tu n: ";
	cin >> n;
	Nhap_mang(A, n);
	Xuat_mang(A, n);
	cout << "\n";
	cout << Tim_phan_tu_nho_nhat(A, n);

	return 0;
}