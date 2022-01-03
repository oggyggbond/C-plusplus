#include <iostream>
using namespace std;

int Do_dai_chuoi(char s[])
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return i;
}

void In_thuong_thanh_in_hoa(char s[])
{
	for (int i = 0; i < Do_dai_chuoi(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
}

void In_hoa_thanh_in_thuong(char s[])
{
	for (int i = 0; i < Do_dai_chuoi(s); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
	}
}

void Dao_nguoc_chuoi(char s[])
{
	for (int i = Do_dai_chuoi(s) - 1; i >= 0; i--)
	{
		cout << s[i];
	}
}

int main()
{
	char s[30];
	cout << " Nhap chuoi: ";
	gets_s(s);
	for (int i = 0; i < Do_dai_chuoi(s); i++)
	{
		cout << s[i];
	}
	cout << "\n\n";
	for (int i = 0; i < Do_dai_chuoi(s); i++)
	{
		In_thuong_thanh_in_hoa(s);
		cout << s[i];
	}
	cout << "\n\n";
	for (int i = 0; i < Do_dai_chuoi(s); i++)
	{
		In_hoa_thanh_in_thuong(s);
		cout << s[i];
	}
	cout << "\n\n";
	Dao_nguoc_chuoi(s);

	return 0;
}