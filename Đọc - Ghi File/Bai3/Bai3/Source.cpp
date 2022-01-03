#include <iostream>
#include <fstream>
using namespace std;

int Tim_UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}

int Tim_BCNN(int a, int b)
{
	return a * b / Tim_UCLN(a, b);
}

int Tim_UCLN_Cac_Phan_Tu(int a[], int n)
{
	int UCLN = a[0];
	for (int i = 1; i < n; i++)
	{
		UCLN = Tim_UCLN(UCLN, a[i]);
	}
	return UCLN;
}

int Tim_BCNN_Cac_Phan_Tu(int a[], int n)
{
	int BCNN = a[0];
	for (int i = 1; i < n; i++)
	{
		BCNN = Tim_BCNN(BCNN, a[i]);
	}
	return BCNN;
}

int main()
{
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai! Xin kiem tra lai";
		system("pause");
		return 0;
	}
	int a[100], n = 0;
	for (int i = 0; filein.eof() == false; i++)
	{
		filein >> a[i];
		char x;
		filein >> x;
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	ofstream fileout;
	fileout.open("UCLN.TXT", ios_base::out);
	int ucln;
	for (int i = 0; i < n; i++)
	{
		ucln = Tim_UCLN_Cac_Phan_Tu(a, n);
	}
	fileout << ucln;

	ofstream file_1_out;
	file_1_out.open("BCNN.TXT", ios_base::out);
	int bcnn;
	for (int i = 0; i < n; i++)
	{
		 bcnn = Tim_BCNN_Cac_Phan_Tu(a, n);
	}
	file_1_out << bcnn;

	filein.close();
	fileout.close();
	file_1_out.close();

	return 0;
}