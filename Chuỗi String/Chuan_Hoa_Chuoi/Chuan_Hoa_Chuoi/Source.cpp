#include <iostream>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

void Xoa_Khoang_Trang_O_Dau(string &s)
{
	while (s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}
}

void Xoa_Khoang_Trang_O_Cuoi(string &s)
{
	while (s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + (s.length() - 1));
	}
}

void Xoa_Khoang_Trang_Giua_Cac_Tu(string &s)
{
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
}

void In_Hoa_Ky_Tu_Dau_Moi_Tu(string &s)
{
	strlwr((char*)s.c_str());
	if (s[0] != ' ')
	{
		if (s[0] >= 97 && s[0] <= 122)
		{
			s[0] = s[0] - 32;
		}
	}
	for (int i = 0; i < s.length(); i++)
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
	string s;
	cout << " Nhap chuoi s: ";
	getline(cin, s);
	cout << s << endl;
	Xoa_Khoang_Trang_O_Dau(s);
	Xoa_Khoang_Trang_O_Cuoi(s);
	Xoa_Khoang_Trang_Giua_Cac_Tu(s);
	In_Hoa_Ky_Tu_Dau_Moi_Tu(s);
	cout << s << endl;

	return 0;
}