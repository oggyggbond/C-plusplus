#include <iostream>
#include <fstream>
using namespace std;

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
	int a[100], n;
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
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	fileout << max << endl;

	filein.close();
	fileout.close();

	return 0;
}