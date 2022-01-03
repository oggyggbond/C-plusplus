#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

void Dem_so_lan_xuat_hien(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		bool KT = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				KT = false;
				break;
			}
		}
		if (KT == true)
		{
			int dem = 0;
			for (int k = 0; k < strlen(s); k++)
			{
				if (s[i] == s[k])
				{
					dem++;
				}
			}
			cout << " Ky tu " << s[i] << " xuat hien " << dem << " lan " << endl;
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