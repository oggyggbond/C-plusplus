#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;
int dem[100];

void Dem_so_lan_xuat_hien(char s[])
{
	for (int i = 0; i < 100; i++)
	{
		dem[i] = 0;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		dem[s[i]]++;
	}
	for (int i = 0; i < 100; i++)
	{
		if (dem[i] > 0)
		{
			cout << " Ky tu " << (char) i << " xuat hien " << dem[i] << " lan " << endl;
		}
	}
}

int main()
{
	char s[30];
	cout << " Nhap chuoi: ";
	gets_s(s);
	cout << s;
	cout << "\n\n";
	Dem_so_lan_xuat_hien(s);

	return 0;
}