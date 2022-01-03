#include <iostream>
using namespace std;

int STRLEN(char s[])
{
	int i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return i;
}

void Xoa(char s[], int vt)
{
	int n = STRLEN(s);
	for (int i = vt + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[STRLEN(s) - 1] = '\0';
}

void Xuat_Cac_Ky_Tu_Hien_Co_Trong_Chuoi(char s[])
{
	for (int i = 0; i < STRLEN(s) - 1; i++)
	{
		for (int j = i + 1; j < STRLEN(s); j++)
		{
			if (s[i] == s[j])
			{
				Xoa(s, j);
				i--;
			}
		}
	}
}

int main()
{
	char s[30];
	cout << " Nhap chuoi: ";
	gets_s(s);
	cout << endl;
	cout << s;
	cout << "\n\n";
	Xuat_Cac_Ky_Tu_Hien_Co_Trong_Chuoi(s);
	for (int i = 0; i < STRLEN(s); i++)
	{
		cout << "\n\n" << s[i] << endl;
	}

	return  0;
}