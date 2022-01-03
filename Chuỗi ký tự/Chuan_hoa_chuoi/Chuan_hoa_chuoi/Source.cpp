#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

void Xoa(char s[], int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[strlen(s) - 1] = '\0';
}

void Xoa_Khoang_Trang_O_Dau(char s[])
{
	while (true)
	{
		if (s[0] == ' ')
		{
			Xoa(s, 0);
		}
		else
			break;
	}
}

void Xoa_Khoang_Trang_O_Cuoi(char s[])
{
	while (true)
	{
		if (s[strlen(s) - 1] == ' ')
		{
			Xoa(s, strlen(s) - 1);
		}
		else
			break;
	}
}

void Xoa_Khoang_Trang_O_Giua(char s[])
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			Xoa(s, i);
			i--;
		}
	}
}

void In_Hoa_Ky_Tu_Dau_Moi_Tu(char s[])
{
	strlwr(s);
	if (s[0] != ' ')
	{
		if (s[0] >= 97 && s[0] <= 122)
		{
			s[0] = s[0] - 32;
		}
	}
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] != ' ')
		{
			if (s[i + 1] >= 97 && s[i + 1] <= 122)
			{
				s[i + 1] = s[i + 1] - 32;
			}
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
	Xoa_Khoang_Trang_O_Dau(s);
	Xoa_Khoang_Trang_O_Cuoi(s);
	Xoa_Khoang_Trang_O_Giua(s);
	In_Hoa_Ky_Tu_Dau_Moi_Tu(s);
	cout << s << endl;

	return 0;
}