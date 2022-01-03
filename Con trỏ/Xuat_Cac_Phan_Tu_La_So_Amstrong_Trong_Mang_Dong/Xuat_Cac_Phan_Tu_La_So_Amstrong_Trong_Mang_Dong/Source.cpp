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

bool Kiem_Tra_So_Amstrong(int n)
{
	int k = log10((double)n) + 1;
	int s = 0, tmp = n;
	for (int i = 1; n != 0; i++)
	{
		int x = n % 10;
		s = s + pow(x, k);
		n = n / 10;
	}
	if (s == tmp)
	{
		return true;
	}
	else
		return false;
}

void Xuat_Cac_So_Amstrong(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Kiem_Tra_So_Amstrong(*(a + i)) == true)
		{
			cout << *(a + i) << " ";
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
	Xuat_Cac_So_Amstrong(a, n);
	cout << "\n\n";
	delete[] a;

	return 0;
}