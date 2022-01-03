#include <iostream>
#include <fstream>
#define MAX 100
int a[MAX][MAX], n, u = 1;

using namespace std;

void Doc_file()
{
	ifstream filein;
	filein.open("dothi.txt", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai. Xin kiem tra lai";
		system("pause");
	}
	filein >> n;
	cout << "\nSo dinh do thi: " << n;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		for (int j = 1; j <= n; j++)
		{
			filein >> a[i][j];
			cout << a[i][j] << "\t";
		}
	}
	filein.close();
}

int KiemTra()
{
	int d = 0, u;

	for (int i = 1; i <= n; i++)
	{
		int s = 0;
		for (int j = 1; j <= n; j++)
		{
			s = s + a[i][j];
		}
		if (s % 2)
		{
			d++;
			u = i;
		}
	}
	if (d != 2)
	{
		return false;
	}
	return true;
}

void DD_Euler(int u)
{
	int v, x, top, dCE;
	int stack[MAX], CE[MAX];
	top = 1; stack[top] = u; dCE = 0;
	do
	{
		v = stack[top];
		x = 1;
		while (x <= n && a[v][x] == 0)
			x++;
		if (x > n)
		{
			dCE++;
			CE[dCE] = v;
			top--;
		}
		else
		{
			top++;
			stack[top] = x;
			a[v][x] = 0;
			a[x][v] = 0;
		}
	} while (top != 0);
	cout << "\nCo duong di Euler: ";
	for (x = dCE; x > 0; x--)
		cout << CE[x] << " ";
}

int main()
{
	Doc_file();
	if (KiemTra())
	{
		DD_Euler(u);
	}
	else
	{
		cout << "\nKhong co duong di Euler";
	}

	return 0;
}