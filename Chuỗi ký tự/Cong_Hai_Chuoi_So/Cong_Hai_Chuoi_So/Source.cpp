#include <iostream>
#include <string.h>
#include <cmath>
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

int main()
{
	char s1[100];
	char s2[100];
	char kq[101] = "";
	int m = 0;
	int du = 0;
	cout << " Nhap chuoi s1: ";
	gets_s(s1);
	cout << s1 << endl;
	cout << " Nhap chuoi s2: ";
	gets_s(s2);
	cout << s2 << endl;
	if (strlen(s1) > strlen(s2))
	{
		int soluongthem = strlen(s1) - strlen(s2);
		for (int i = 1; i <= soluongthem; i++)
		{
			Them(s2, 0, '0');
		}
	}
	else if (strlen(s1) < strlen(s2))
	{
		int soluongthem = strlen(s2) - strlen(s1);
		for (int i = 1; i <= soluongthem; i++)
		{
			Them(s1, 0, '0');
		}
	}
	for (int i = strlen(s1) - 1; i >= 0; i--)
	{
		int x = (s1[i] - 48);
		int y = (s2[i] - 48);
		int s = x + y + du;
		kq[m] = s % 10 + 48;
		m++;
		du = s / 10;
	}
	if (du != 0)
	{
		kq[m] = du + 48;
		m++;
	}
	cout << " Tong Hai Chuoi So La: " << endl;
	for (int i = strlen(kq) - 1; i >= 0; i--)
	{
		cout << kq[i];
	}

	return 0;
}