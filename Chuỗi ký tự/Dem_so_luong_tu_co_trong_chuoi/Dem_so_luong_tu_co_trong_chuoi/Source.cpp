#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;

int Dem_So_Tu_Trong_Chuoi(char s[])
{
	int dem = 0;
	if (s[0] != ' ')
	{
		dem++;
	}
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			dem++;
		}
	}
	return dem;
}

int main()
{
	char s[30];
	cout << " Nhap chuoi: ";
	gets_s(s);
	cout << s;
	cout << "\n\n";
	cout << " Co " << Dem_So_Tu_Trong_Chuoi(s) << " tu " << endl;

	return 0;
}