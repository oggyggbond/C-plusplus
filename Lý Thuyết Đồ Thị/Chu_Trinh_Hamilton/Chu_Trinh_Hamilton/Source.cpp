#include <iostream>
#include <fstream>
#define MAX 100
int a[MAX][MAX], n, c[MAX], b[MAX], i, d;

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
	for (int i = 1; i <= n; i++)
	{
		c[i] = 0;
	}
}

void Result()
{
	cout << "\n";
	for (int i = n; i >= 0; i--)
	{
		cout << b[i] << " ";
	}
	d++;
}

void Hamilton(int b[], int c[], int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (a[b[i - 1]][j] == 1 && c[j] == 0)
		{
			b[i] = j;
			c[j] = 1;
			if (i < n)
			{
				Hamilton(b, c, i + 1);

			}
			else if (b[i] == b[0])
			{
				Result();
			}
			c[j] = 0;
		}
	}
}

int main()
{
	b[0] = 1;
    i = 1, d = 0;
	Doc_file();
	Hamilton(b, c, i);
	if (d == 0)
	{
		cout << "\nKhong co chu trinh Hamilton";
	}

	return 0;
}