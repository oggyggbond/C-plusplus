#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;

int main()
{
	char s[30];
	cout << " Nhap chuoi: ";
	gets_s(s);
	cout << s;
	cout << "\n\n";
	for (int i = 0; i < strlen(s); i++)
	{
		strlwr(s);
		cout << s[i];
	}

	return 0;
}