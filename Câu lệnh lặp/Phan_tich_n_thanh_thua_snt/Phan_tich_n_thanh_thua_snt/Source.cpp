#include <iostream>
using namespace std;

int main()
{
	int n, i = 2;
	cout << " Nhap n: ";
	cin >> n;
	while (n != 0)
	{
		if (n % i == 0)
		{
			cout << i;
			if (n != i)
			{
				cout << " x ";
			}
			else
				cout << endl;
			n = n / i;
		}
		else
			i++;
	}

	return 0;
}