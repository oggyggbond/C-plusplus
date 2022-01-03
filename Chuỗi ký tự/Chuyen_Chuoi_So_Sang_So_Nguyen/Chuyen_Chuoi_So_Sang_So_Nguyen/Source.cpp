#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)
using namespace std;

int Chuyen_Dois1(char s1[])
{
	int mus1 = strlen(s1) - 1;
	int  tongs1 = 0;
	for (int i = 0; i < strlen(s1); i++)
	{
		tongs1 = tongs1 + ((s1[i] - 48) * pow(10, mus1));
		mus1--;
	}
	return tongs1;
}

int Chuyen_Dois2(char s2[])
{
	int mus2 = strlen(s2) - 1;
	int tongs2 = 0;
	for (int i = 0; i < strlen(s2); i++)
	{
		tongs2 = tongs2 + ((s2[i] - 48) * pow(10, mus2));
		mus2--;
	}
	return tongs2;
}

int main()
{
	char s1[30];
	char s2[30];
	cout << " Nhap chuoi s1: ";
	gets_s(s1);
	cout << "\n\n";
	cout << " Nhap chuoi s2: ";
	gets_s(s2);
	cout << "\n\n";
	cout << " Tong hai chuoi so la: " << (Chuyen_Dois1(s1) + Chuyen_Dois2(s2)) << endl;

	return 0;
}