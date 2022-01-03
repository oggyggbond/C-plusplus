#include <iostream>
using namespace std;

int main()
{
	int n, tmp, solan;
	do
	{
		cout << " Nhap 1 <= n <= 10000: ";
		cin >> n;
		if (n < 1 || n > 10000)
		{
			cout << " Nhap lai! " << endl;
		}
	} while (n < 1 || n > 10000);
	tmp = n / 9;
	if (n % 9 == 0)
	{
		cout << " So lan hap banh la: " << tmp << endl;
	}
	else
	{
		solan = tmp + 1;
		cout << " So lan hap banh la: " << solan << endl;
	}

	return 0;
}