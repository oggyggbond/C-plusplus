#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "\nFile khong ton tai. Xin kiem tra lai";
		system("pause");
		return 0;
	}
	int a[100];
	int n;
	filein >> n;
	for (int i = 0; i < n; i++)
	{
		filein >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	ofstream fileout;
	fileout.open("KETQUA.TXT", ios_base::out);
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			fileout << a[i] << " ";
		}
	}
	filein.close();
	fileout.close();

	return 0;
}