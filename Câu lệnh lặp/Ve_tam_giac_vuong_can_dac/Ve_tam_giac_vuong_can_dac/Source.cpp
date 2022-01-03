#include <iostream>
using namespace std;
int main()
{
	int a;
	cout << " Nhap canh a: ";
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (j <= i)
			{
				cout << " * ";
			}
			else
				cout << "   ";
		}
		cout << "\n";
	}

	return 0;
}