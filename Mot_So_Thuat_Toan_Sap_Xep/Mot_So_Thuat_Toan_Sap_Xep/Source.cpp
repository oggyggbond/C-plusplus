#include <iostream>

using namespace std;

void Nhap_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu a[" << i << "] = ";
		cin >> a[i];
	}
}

void Xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Hoan_Vi(int& x, int& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

void Selection_Sort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		cout << endl;
		Xuat_Mang(a, n);
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Hoan_Vi(a[min], a[i]);
		}
	}
}

void Insertion_Sort(int a[], int n)
{
	int pos, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		cout << endl;
		Xuat_Mang(a, n);
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void Bubble_Sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		cout << endl;
		Xuat_Mang(a, n);
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				Hoan_Vi(a[j], a[j - 1]);
			}
		}
	}
}

void Menu(int a[], int n)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ==================== SAP XEP ====================";
		cout << "\n\t1. Nhap mang";
		cout << "\n\t2. Xuat mang";
		cout << "\n\t3. Selection Sort";
		cout << "\n\t4. Insertion Sort";
		cout << "\n\t5. Bubble Sort";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ====================== END ======================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			cout << "\n\n\t\tNHAP MANG\n";

			Nhap_Mang(a, n);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\tXUAT MANG\n";

			Xuat_Mang(a, n);

			system("pause");
		}
		else if (luachon == 3)
		{
			Selection_Sort(a, n);
			system("pause");
		}
		else if (luachon == 4)
		{
			Insertion_Sort(a, n);
			system("pause");
		}
		else if (luachon == 5)
		{
			Bubble_Sort(a, n);
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int a[100], n;

	cout << "\nNhap so luong phan tu n: ";
	cin >> n;

	Menu(a, n);

	return 0;
}