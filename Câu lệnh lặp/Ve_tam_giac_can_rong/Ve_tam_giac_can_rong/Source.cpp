#include <iostream>
using namespace std;
int main()
{
	int h;
	cout << " Nhap do cao h: ";
	cin >> h;
	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < 2 * h - 1; j++)
		{
			if (j == h - i - 1 || j == h + i - 1)
			{
				cout << " * ";
			}
			else
				cout << "   ";
		}
		cout << "\n";
	}
	for (int i = 0; i < 2 * h - 1; i++)
	{
		cout << " * ";
	}

	return 0;
}