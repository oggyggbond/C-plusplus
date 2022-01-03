#include <iostream>
#include <fstream>
using namespace std;

bool Kiem_tra_so_amstrong(int n)
{
	int k = log10((double)n) + 1;
	int s = 0, tmp = n;
	for (int i = 0; n != 0; i++)
	{
		int x = n % 10;
		s = s + (pow(x, k));
		n = n / 10;
	}
	if (s == tmp)
	{
		return true;
	}
	else
		return false;
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
	int a[100], dem = 0;
	for (int i = 0; filein.eof() == false; i++)
	{
		filein >> a[i];
		dem++;
	}
	for (int i = 0; i < dem; i++)
	{
		cout << a[i] << " ";
	}

	ofstream fileout;
	fileout.open("AMSTRONG.TXT", ios_base::out);
	for (int i = 0; i < dem; i++)
	{
		if (Kiem_tra_so_amstrong(a[i]) == true)
		{
			fileout << a[i] << " ";
		}
	}
	filein.close();
	fileout.close();

	return 0;
}