#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << " Nhap canh a: ";
	cin >> a;
	for (int i = 0; i < a - 1; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (j == 0 || j == i)
			{
				cout << " * ";
			}
			else
				cout << "   ";
		}
		cout << "\n";
	}
	for (int i = 0; i < a; i++)
	{
		cout << " * ";
	}

	return 0;
}