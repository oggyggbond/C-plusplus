#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

void Them(char s[], int vt, char x)
{
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
	{
		s[i + 1] = s[i];
	}
	s[vt] = x;
	s[n + 1] = '\0';
}

bool Kiem_Tra_Xau_Doi_Xung(char s[])
{
	for (int i = 0; i < strlen(s) / 2; i++)
	{
		if (s[i] != s[strlen(s) - i - 1])
		{
			return false;
		}
	}
	return true;
}

void Them_It_Ky_Tu_Nhat_De_Duoc_Xau_Doi_Xung(char s[])
{
	if (Kiem_Tra_Xau_Doi_Xung(s) == false)
	{
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			Them(s,n, s[i]);
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
	Them_It_Ky_Tu_Nhat_De_Duoc_Xau_Doi_Xung(s);
	cout << s << endl;

	return 0;
}