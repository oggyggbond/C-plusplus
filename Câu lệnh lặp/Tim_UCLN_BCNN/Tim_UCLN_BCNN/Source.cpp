#include <iostream>
using namespace std;

int main()
{
	int a, b,tich = 1;
	cout << " Nhap 2 so a va b: ";
	cin >> a >> b;
	tich = a * b;
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	cout << " UCLN la: " << a << endl;
	cout << " BCNN la: " << tich / a << endl;

	return 0;
}