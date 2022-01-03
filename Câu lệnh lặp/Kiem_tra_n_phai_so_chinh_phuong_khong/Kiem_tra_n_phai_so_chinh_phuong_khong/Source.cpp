#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	do
	{
		cout << " Nhap n > 0: ";
		cin >> n;
		if (n <= 0)
		{
			cout << " Nhap lai! ";
		}
	} while (n <= 0);
	if (sqrt((float)n) == (int)sqrt((float)n))
	{
		cout << n << " la so chinh phuong " << endl;
	}
	else
		cout << n << " khong phai so chinh phuong " << endl;

	return 0;
}