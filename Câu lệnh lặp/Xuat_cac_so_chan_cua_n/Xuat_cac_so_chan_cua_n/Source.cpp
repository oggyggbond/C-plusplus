#include <iostream>
using namespace std;

int main()
{
	int n, x;

	do
	{
		cout << " Nhap n: ";
		cin >> n;
		if (n <= 0)
		{
			cout << " n phai lon hon 0! Nhap lai! " << endl;
		}
	} while (n <= 0);

	while (n > 0)
	{
		x = n % 10;
		if (x % 2 == 0)
		{
			cout << x << endl;
		}
		n = n / 10;
	}

	return 0;
}